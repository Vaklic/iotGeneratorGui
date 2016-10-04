#include "controlIoTThreads.hpp"

controlIoTThreads::controlIoTThreads(void) {
	this->quantityOfThreads = 1;
	this->quantityOfPackage = 1;
		
	this->scenarioType = 1; 
	this->trafficType = 17;
	this->dataFieldSize = 8;
	
	this->baseDelay = 2000000;
	this->antipersistentDelay = 0;
	this->sendDuration = 0;
	
	this->antipersistentSendFlag = 0;
	this->antipersistentEndFlag = 0;	
	this->controlStopFlag = 0;
			
	this->threadIoT = new std::thread[this->quantityOfThreads];
	this->threadEndFlag = new int8_t[this->quantityOfThreads];
	this->restartThreadsEndFlag();
		
	this->iot =  new IoTThread*[this->quantityOfThreads];
	for(int ix = 0; ix < this->quantityOfThreads; ++ix){
		this->iot[ix] = new IoTThread(this->scenarioType, this->trafficType, this->dataFieldSize);
	}
		
	this->controlThread = std::thread(&controlIoTThreads::runStopControlThread, this);
	if(this->scenarioType == 2)  this->antipersistentControlThread = std::thread(&controlIoTThreads::runAntipersistentControlThread, this);
	for(int ix = 0; ix < quantityOfThreads; ++ix){
		this->threadIoT[ix] = std::thread(&controlIoTThreads::runThread, this, iot[ix], ix);
	}
}
	
controlIoTThreads::controlIoTThreads(int32_t _quantityOfThreads, int64_t _quantityOfPackage, int16_t _dataFieldSize, int16_t _scenarioType, int16_t _trafficType, uint64_t _baseDelay, uint64_t _sendDuration, uint64_t _antipersistentDelay): quantityOfThreads(_quantityOfThreads), quantityOfPackage(_quantityOfPackage), dataFieldSize(_dataFieldSize), scenarioType(_scenarioType), trafficType(_trafficType), baseDelay(_baseDelay), sendDuration(_sendDuration), antipersistentDelay(_antipersistentDelay){
	this->controlStopFlag = 0;
	this->antipersistentSendFlag = 0;	
	this->antipersistentEndFlag = 0;
			
	this->threadIoT = new std::thread[this->quantityOfThreads];
	this->threadEndFlag = new int8_t[this->quantityOfThreads];
	this->restartThreadsEndFlag();
		
	this->iot =  new IoTThread*[this->quantityOfThreads];
	for(int ix = 0; ix < this->quantityOfThreads; ++ix){
		this->iot[ix] = new IoTThread(this->scenarioType, this->trafficType, this->dataFieldSize);
	}
		
	this->controlThread = std::thread(&controlIoTThreads::runStopControlThread, this);
	if(this->scenarioType == 2)  this->antipersistentControlThread = std::thread(&controlIoTThreads::runAntipersistentControlThread, this);
	for(int ix = 0; ix < quantityOfThreads; ++ix){
		this->threadIoT[ix] = std::thread(&controlIoTThreads::runThread, this, iot[ix], ix);
	}
}
	
controlIoTThreads::controlIoTThreads(int32_t _quantityOfThreads, int64_t _quantityOfPackage, int16_t _dataFieldSize, int16_t _scenarioType, int16_t _trafficType, uint64_t _baseDelay, uint64_t _sendDuration, uint64_t _antipersistentDelay, int8_t _IPType, uint8_t* _netAdr, uint8_t* _dstAdr, uint8_t* _mask): quantityOfThreads(_quantityOfThreads), quantityOfPackage(_quantityOfPackage), dataFieldSize(_dataFieldSize), scenarioType(_scenarioType), trafficType(_trafficType), baseDelay(_baseDelay), sendDuration(_sendDuration), antipersistentDelay(_antipersistentDelay) {
	this->controlStopFlag = 0;
	this->antipersistentEndFlag = 0;
			
	this->threadIoT = new std::thread[this->quantityOfThreads];
	this->threadEndFlag = new int8_t[this->quantityOfThreads];
	this->restartThreadsEndFlag();
		
	this->iot =  new IoTThread*[this->quantityOfThreads];
	for(int ix = 0; ix < this->quantityOfThreads; ++ix){
		this->iot[ix] = new IoTThread(_IPType, _netAdr, _dstAdr, _mask, this->scenarioType, this->trafficType, this->dataFieldSize);
	}
		
	this->controlThread = std::thread(&controlIoTThreads::runStopControlThread, this);
	if(this->scenarioType == 2)  this->antipersistentControlThread = std::thread(&controlIoTThreads::runAntipersistentControlThread, this);
	for(int ix = 0; ix < quantityOfThreads; ++ix){
		this->threadIoT[ix] = std::thread(&controlIoTThreads::runThread, this, iot[ix], ix);
	}
}
	
controlIoTThreads::~controlIoTThreads(void){
	for(int ix = 0; ix < this->quantityOfThreads; ++ix){
		delete this->iot[ix];
	}
		
	delete[] this->iot;
	delete[] this->threadIoT;
}
	
void controlIoTThreads::runStopControlThread(void){
	while(true){
		int8_t controlByte = 1;
			
		for(int ix = 0; ix < this->quantityOfThreads; ++ix){
			controlByte = controlByte & this->threadEndFlag[ix];
		}
			
		if(controlByte == 1){
			this->controlStopFlag = 1;
			this->antipersistentEndFlag = 0;
			break;
		} 
	}
	this->restartThreadsEndFlag();
}
	
void controlIoTThreads::runThread(IoTThread* iot, int64_t threadNumber){
	if(scenarioType == 1){
		for(int ix = 0; ix < this->quantityOfPackage; ++ix){
			this->iot[threadNumber]->sendMessage();
			usleep(this->baseDelay + JITTER_COFF * generateRandomDouble(0, 1));
		}
	} else if(scenarioType == 2){
		//fprintf(stderr, "err\n");
		while(!this->antipersistentEndFlag){
			double chanceOfSending = generateRandomDouble(0,1);
			if(chanceOfSending < ANTIPERSISTENT_CHANCE_OF_SENDING_PACKAGE){
				while(this->antipersistentSendFlag){
					//fprintf(stderr, "err\n");
					this->iot[threadNumber]->sendMessage();
					usleep(this->baseDelay + JITTER_COFF * generateRandomDouble(0, 1));
				}
			}
			usleep(DELAY_TIME);
		}
	} else {
		for(int ix = 0; ix < this->quantityOfPackage; ++ix){
			this->iot[threadNumber]->sendMessage();
			usleep(this->baseDelay + JITTER_COFF * generateRandomDouble(0, 1));
		}
	}
	this->threadEndFlag[threadNumber] = 1;
}
	
void controlIoTThreads::restartThreadsEndFlag(void){
	for(int ix = 0; ix < this->quantityOfThreads; ++ix)
		this->threadEndFlag[ix] = 0;
}
	
void controlIoTThreads::startThreads(void){
	for(int ix = 0; ix < this->quantityOfThreads; ++ix){
		this->threadIoT[ix].detach();
		usleep(THREAD_START_DELAY);
	}
		
	this->controlThread.detach();
		
	while(!this->controlStopFlag){}
	this->controlStopFlag = 0;
}
	
void controlIoTThreads::test_showAllThingsAdr(void){
	for(int ix = 0; ix < this->quantityOfThreads; ++ix){
		this->iot[ix]->test_showUniqueIP();
		fprintf(stdout, ":%d\n", this->iot[ix]->getSrcPort());
	}
}

void controlIoTThreads::setScenarioAndTrafficType(int16_t _scenarioType, int16_t _trafficType){
	this->scenarioType = _scenarioType;
	this->trafficType = _trafficType;
}

void controlIoTThreads::runAntipersistentControlThread(void){
	uint64_t randomAntipersistentDelay, randomSendDuration;
	time_t startATime, currentATime;
	time_t startSendTime, currentSendTime;
	
	for(int ix = 0; ix < this->quantityOfPackage; ++ix){
		time(&startATime);
		int64_t sendCount = 0;
		
		randomAntipersistentDelay = generateRandomUInt64((uint64_t)((this->antipersistentDelay - this->antipersistentDelay*TIME_DELAY_PERSENT)/1000000), (uint64_t)((this->antipersistentDelay + this->antipersistentDelay*TIME_DELAY_PERSENT)/1000000));
		randomSendDuration = generateRandomUInt64((uint64_t)((this->sendDuration - this->sendDuration*TIME_DELAY_PERSENT)/1000000), (uint64_t)((this->sendDuration + this->sendDuration*TIME_DELAY_PERSENT)/1000000));
		
		fprintf(stdout, "1, %d, %d\n", randomAntipersistentDelay, randomSendDuration);
		do{
			time(&currentATime);
			usleep(DELAY_TIME);
		} while((currentATime - startATime) < randomAntipersistentDelay);
		
		this->antipersistentSendFlag = 1;
		time(&startSendTime);
		do{
			time(&currentSendTime);
			usleep(DELAY_TIME);
		} while((currentSendTime - startSendTime) < randomSendDuration);
		
		this->antipersistentSendFlag = 0;
	}
	this->antipersistentEndFlag = 1;
}

void controlIoTThreads::switchOffThreads(void){
	for(int ix = 0; ix < this->quantityOfThreads; ++ix){
		this->threadEndFlag[ix] = 1;
	}
	
	this->antipersistentEndFlag = 1;
	this->controlStopFlag = 1;
}