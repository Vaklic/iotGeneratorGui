#include "IoTThread.hpp"

IoTThread::IoTThread(void){
	uint8_t* defaultNetAdr;
	uint8_t* defaultDstAdr;
	uint8_t* defaultMask;
		
	this->scenarioType = 1;
	this->trafficType = 17;
		
	this->quantityOfPackage = 1;
	this->countOfPackage = 0;
	this->timeOfDelay = 1000000;
	
	this->dataFieldSize = 8;
		
	this->stopThreadFlag = 0;
		
	this->IPType = IPV4_ADDR_SIZE;
		
	if(this->IPType == IPV4_ADDR_SIZE){
		this->IPType = IPV4_ADDR_SIZE;
			
		defaultNetAdr = new uint8_t[this->IPType];
		defaultDstAdr = new uint8_t[this->IPType];
		defaultMask = new uint8_t[this->IPType];
	
		defaultNetAdr[0] = 0x7F;	defaultNetAdr[1] = 0x00;	defaultNetAdr[2] = 0x00;	defaultNetAdr[3] = 0x00;
		defaultMask[0] = 0xFF;	defaultMask[1] = 0x00;	defaultMask[2] = 0x00;	defaultMask[3] = 0x00;
		defaultDstAdr[0] = 0x7F;	defaultDstAdr[1] = 0x00;	defaultDstAdr[2] = 0x00;	defaultDstAdr[3] = 0x01;
	} else {
		this->IPType = IPV6_ADDR_SIZE;
		
		defaultNetAdr = new uint8_t[this->IPType];
		defaultDstAdr = new uint8_t[this->IPType];
		defaultMask = new uint8_t[this->IPType];
			
		defaultNetAdr[0] = 0x00;	defaultNetAdr[1] = 0x00;	defaultNetAdr[2] = 0x00;	defaultNetAdr[3] = 0x00;
		defaultMask[0] = 0xFF;	defaultMask[1] = 0xFF;	defaultMask[2] = 0xFF;	defaultMask[3] = 0xFF;
		defaultDstAdr[0] = 0x00;	defaultDstAdr[1] = 0x00;	defaultDstAdr[2] = 0x00;	defaultDstAdr[3] = 0x00;
			
		defaultNetAdr[4] = 0x00;	defaultNetAdr[5] = 0x00;	defaultNetAdr[6] = 0x00;	defaultNetAdr[7] = 0x00;
		defaultMask[4] = 0xFF;	defaultMask[5] = 0xFF;	defaultMask[6] = 0xFF;	defaultMask[7] = 0xFF;
		defaultDstAdr[4] = 0x00;	defaultDstAdr[5] = 0x00;	defaultDstAdr[6] = 0x00;	defaultDstAdr[7] = 0x00;
			
		defaultNetAdr[8] = 0x00;	defaultNetAdr[9] = 0x00;	defaultNetAdr[10] = 0x00;	defaultNetAdr[11] = 0x00;
		defaultMask[8] = 0x00;	defaultMask[9] = 0x00;	defaultMask[10] = 0x00;	defaultMask[11] = 0x00;
		defaultDstAdr[8] = 0x00;	defaultDstAdr[9] = 0x00;	defaultDstAdr[10] = 0x00;	defaultDstAdr[11] = 0x00;
			
		defaultNetAdr[12] = 0x00;	defaultNetAdr[13] = 0x00;	defaultNetAdr[14] = 0x00;	defaultNetAdr[15] = 0x01;
		defaultMask[12] = 0x00;	defaultMask[13] = 0x00;	defaultMask[14] = 0x00;	defaultMask[15] = 0x00;
		defaultDstAdr[12] = 0x00;	defaultDstAdr[13] = 0x00;	defaultDstAdr[14] = 0x00;	defaultDstAdr[15] = 0x01;
	}
		
	this->netAdr = new uint8_t[this->IPType];
	this->dstAdr = new uint8_t[this->IPType];
	this->mask = new uint8_t[this->IPType]; 
			
	for(int ix = 0; ix < this->IPType; ++ix){
		this->netAdr[ix] = defaultNetAdr[ix];
		this->dstAdr[ix] = defaultDstAdr[ix]; 
		this->mask[ix] = defaultMask[ix];
	}
		
	uniqueThing* copyThing = new uniqueThing();
	copyThing->generateRandomUniqueIPbyNetParam(this->IPType, this->netAdr, this->mask);
	copyThing->generateRandomSrcPort();
	copyThing->generateRandomDstIPbyNetParam(this->IPType, this->dstAdr, this->mask);
	copyThing->generateRandomDstPort();
	copyThing->setDataFieldLength(this->dataFieldSize);
		
	this->sendPackage = new sendThingMessages(copyThing);
		
	delete[] defaultNetAdr;
	delete[] defaultDstAdr;
	delete[] defaultMask;
}
	
IoTThread::IoTThread(int16_t _scenarioType, int16_t _trafficType, int16_t _dataFieldSize): scenarioType(_scenarioType), trafficType(_trafficType), dataFieldSize(_dataFieldSize){
	uint8_t* defaultNetAdr;
	uint8_t* defaultDstAdr;
	uint8_t* defaultMask;
		
	this->quantityOfPackage = 1;
	this->countOfPackage = 0;
	this->timeOfDelay = 1000000;
		
	this->stopThreadFlag = 0;
		
	this->IPType = IPV4_ADDR_SIZE;
		
	if(this->IPType == IPV4_ADDR_SIZE){
		this->IPType = IPV4_ADDR_SIZE;
			
		defaultNetAdr = new uint8_t[this->IPType];
		defaultDstAdr = new uint8_t[this->IPType];
		defaultMask = new uint8_t[this->IPType];
	
		defaultNetAdr[0] = 0x7F;	defaultNetAdr[1] = 0x00;	defaultNetAdr[2] = 0x00;	defaultNetAdr[3] = 0x00;
		defaultMask[0] = 0xFF;	defaultMask[1] = 0x00;	defaultMask[2] = 0x00;	defaultMask[3] = 0x00;
		defaultDstAdr[0] = 0x7F;	defaultDstAdr[1] = 0x00;	defaultDstAdr[2] = 0x00;	defaultDstAdr[3] = 0x01;
	} else {
		this->IPType = IPV6_ADDR_SIZE;
			
		defaultNetAdr = new uint8_t[this->IPType];
		defaultDstAdr = new uint8_t[this->IPType];
		defaultMask = new uint8_t[this->IPType];
			
		defaultNetAdr[0] = 0x00;	defaultNetAdr[1] = 0x00;	defaultNetAdr[2] = 0x00;	defaultNetAdr[3] = 0x00;
		defaultMask[0] = 0xFF;	defaultMask[1] = 0xFF;	defaultMask[2] = 0xFF;	defaultMask[3] = 0xFF;
		defaultDstAdr[0] = 0x00;	defaultDstAdr[1] = 0x00;	defaultDstAdr[2] = 0x00;	defaultDstAdr[3] = 0x00;
			
		defaultNetAdr[4] = 0x00;	defaultNetAdr[5] = 0x00;	defaultNetAdr[6] = 0x00;	defaultNetAdr[7] = 0x00;
		defaultMask[4] = 0xFF;	defaultMask[5] = 0xFF;	defaultMask[6] = 0xFF;	defaultMask[7] = 0xFF;
		defaultDstAdr[4] = 0x00;	defaultDstAdr[5] = 0x00;	defaultDstAdr[6] = 0x00;	defaultDstAdr[7] = 0x00;
			
		defaultNetAdr[8] = 0x00;	defaultNetAdr[9] = 0x00;	defaultNetAdr[10] = 0x00;	defaultNetAdr[11] = 0x00;
		defaultMask[8] = 0x00;	defaultMask[9] = 0x00;	defaultMask[10] = 0x00;	defaultMask[11] = 0x00;
		defaultDstAdr[8] = 0x00;	defaultDstAdr[9] = 0x00;	defaultDstAdr[10] = 0x00;	defaultDstAdr[11] = 0x00;
			
		defaultNetAdr[12] = 0x00;	defaultNetAdr[13] = 0x00;	defaultNetAdr[14] = 0x00;	defaultNetAdr[15] = 0x01;
		defaultMask[12] = 0x00;	defaultMask[13] = 0x00;	defaultMask[14] = 0x00;	defaultMask[15] = 0x00;
		defaultDstAdr[12] = 0x00;	defaultDstAdr[13] = 0x00;	defaultDstAdr[14] = 0x00;	defaultDstAdr[15] = 0x01;
	}
		
	this->netAdr = new uint8_t[this->IPType];
	this->dstAdr = new uint8_t[this->IPType];
	this->mask = new uint8_t[this->IPType]; 
			
	for(int ix = 0; ix < this->IPType; ++ix){
		this->netAdr[ix] = defaultNetAdr[ix];
		this->dstAdr[ix] = defaultDstAdr[ix]; 
		this->mask[ix] = defaultMask[ix];
	}
		
	uniqueThing* copyThing = new uniqueThing();
	copyThing->generateRandomUniqueIPbyNetParam(this->IPType, this->netAdr, this->mask);
	copyThing->generateRandomSrcPort();
	copyThing->generateRandomDstIPbyNetParam(this->IPType, this->dstAdr, this->mask);
	copyThing->generateRandomDstPort();
	copyThing->setDataFieldLength(this->dataFieldSize);
		
	this->sendPackage = new sendThingMessages(copyThing);
		
	delete[] defaultNetAdr;
	delete[] defaultDstAdr;
	delete[] defaultMask;
}
	
IoTThread::IoTThread(int8_t _IPType, uint8_t* _netAdr, uint8_t* _dstAdr, uint8_t* _mask, int16_t _scenarioType, int16_t _trafficType, int16_t _dataFieldSize): IPType(_IPType), scenarioType(_scenarioType), trafficType(_trafficType), dataFieldSize(_dataFieldSize){
	this->quantityOfPackage = 1;
	this->countOfPackage = 0;
	this->timeOfDelay = 1000000;
		
	this->stopThreadFlag = 0;
		
	if(this->IPType == IPV4_ADDR_SIZE){
		this->IPType = IPV4_ADDR_SIZE;
	} else {
		this->IPType = IPV6_ADDR_SIZE;
	}
		
	this->netAdr = new uint8_t[this->IPType];
	this->dstAdr = new uint8_t[this->IPType];
	this->mask = new uint8_t[this->IPType]; 
			
	for(int ix = 0; ix < this->IPType; ++ix){
		this->netAdr[ix] = _netAdr[ix];
		this->dstAdr[ix] = _dstAdr[ix]; 
		this->mask[ix] = _mask[ix];
	}
		
	uniqueThing* copyThing = new uniqueThing();
	copyThing->generateRandomUniqueIPbyNetParam(this->IPType, this->netAdr, this->mask);
	copyThing->generateRandomSrcPort();
	copyThing->generateRandomDstIPbyNetParam(this->IPType, this->dstAdr, this->mask);
	copyThing->generateRandomDstPort();
	copyThing->setDataFieldLength(this->dataFieldSize);
		
	this->sendPackage = new sendThingMessages(copyThing);
}
	
IoTThread::~IoTThread(void){
	delete[] this->netAdr;
	delete[] this->dstAdr;
	delete[] this->mask;
		
	delete this->sendPackage;
}
	
void IoTThread::setScenarioAndTrafficTypes(int16_t _scenarioType, int16_t _trafficType){
	this->scenarioType = _scenarioType;
	this->trafficType = _trafficType;
}

void IoTThread::stopOrStartThread(int8_t command){
	if(command == 0) this->stopThreadFlag = 0;
	else this->stopThreadFlag = 1;
}
	
void IoTThread::setTimeOfDelay(uint64_t _timeOfDelay){
	this->timeOfDelay = _timeOfDelay;
}
	
uint64_t IoTThread::getTimeOfDelay(void){
	return this->timeOfDelay;
}
	
void IoTThread::setQuantityOfPackage(int64_t _quantityOfPackage){
	this->quantityOfPackage = _quantityOfPackage;
}
	
void IoTThread::randomQuantityOfPackage(int64_t minQuantityOfPackage, int64_t maxQuantityOfPackage){
	this->quantityOfPackage = generateRandomUInt64(minQuantityOfPackage, maxQuantityOfPackage);
}
	
int8_t IoTThread::getStopThreadFlag(void){
	return this->stopThreadFlag;
}
	
void IoTThread::sendMessage(void){
	//if(this->scenarioType == 1 && this->trafficType == 17){
	if(this->trafficType == 17){
		this->sendPackage->generateRandomString();
		this->sendPackage->sendUDPPacket();
		++this->countOfPackage;
	} else {
		this->sendPackage->generateRandomString();
		this->sendPackage->sendUDPPacket();
		++this->countOfPackage;
	}
	if(this->countOfPackage >= this->quantityOfPackage)
		this->stopOrStartThread(1);
}

void IoTThread::test_showNetAdr(void){
	for(int ix = 0; ix < this->IPType; ++ix){
		fprintf(stdout, "%d", this->netAdr[ix]);
		if(ix < (this->IPType-1)) fprintf(stdout, ".");
	}
}
	
void IoTThread::test_showDstAdr(void){
	for(int ix = 0; ix < this->IPType; ++ix){
		fprintf(stdout, "%d", this->dstAdr[ix]);
		if(ix < (this->IPType-1)) fprintf(stdout, ".");
	}
}
	
void IoTThread::test_showMask(void){
	for(int ix = 0; ix < this->IPType; ++ix){
		fprintf(stdout, "%d", this->mask[ix]);
		if(ix < (this->IPType-1)) fprintf(stdout, ".");
	}
}
	
void IoTThread::test_showUniqueIP(void){
	sendPackage->test_showUniqueIP();
}

void IoTThread::test_showDstIP(void){
	sendPackage->test_showDstIP();
}

uint16_t IoTThread::getDstPort(void){
	return sendPackage->getDstPort();
}

uint16_t IoTThread::getSrcPort(void){
	return sendPackage->getSrcPort();
}
