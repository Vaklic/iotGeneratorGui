//#include "library.hpp"
#include "callBenchmark.h"

callBenchmark::callBenchmark(int32_t _quantityOfThreads, int64_t _quantityOfPackage, int16_t _scenarioType,int16_t _trafficType, int16_t _dataFieldSize, uint64_t _baseDelay, uint64_t _antipersistantDelay, uint64_t _sendDuration, int8_t _IPType, std::string _netAdr, std::string _dstAdr, std::string _mask) : quantityOfThreads(_quantityOfThreads), quantityOfPackage(_quantityOfPackage), scenarioType(_scenarioType), trafficType(_trafficType), dataFieldSize(_dataFieldSize), baseDelay(_baseDelay), antipersistantDelay(_antipersistantDelay), sendDuration(_sendDuration), IPType(_IPType), netAdr(_netAdr), dstAdr(_dstAdr), mask(_mask) {
	this->controlFlag = 0;
}

callBenchmark::~callBenchmark() {
	delete controlFunction;
}

void callBenchmark::initFunction(void) {
	srand((unsigned)time(NULL));
	fprintf(stderr, "err\n");
	this->controlFunction = new controlIoTThreads(this->quantityOfThreads, this->quantityOfPackage, this->dataFieldSize, this->scenarioType, this->trafficType, this->baseDelay, this->sendDuration, this->antipersistantDelay, this->IPType, formAdrArray(this->IPType, this->netAdr), formAdrArray(this->IPType, this->dstAdr), formAdrArray(this->IPType, this->mask));
	std::thread monitoringControlThread = std::thread(&callBenchmark::stopControlThread, this, &this->controlFunction, &this->controlFlag);
	monitoringControlThread.detach();
	
	this->controlFunction->startThreads();
}

void callBenchmark::setControlFlagCycle(bool value){
	this->controlFlag = value;
}

void callBenchmark::stopControlThread(controlIoTThreads** _controlFunction, bool* _controlFlag){
	//fprintf(stdout, "%d\n", (*_controlFunction)->quantityOfThreads);
	while(*_controlFlag != true) {}
	(*_controlFunction)->switchOffThreads();
}

uint8_t* callBenchmark::formAdrArray(int8_t _IPType, std::string transformAdr) {
	int adrSize = NULL;
	if(_IPType = 6) 
		adrSize = 16;
	else adrSize = 4;
	
	uint8_t* retAdrArray = new uint8_t[adrSize];
	
	for(int ix = 0; ix < adrSize; ++ix)
		retAdrArray[ix] = 0x00;
	
	std::size_t lastFound = transformAdr.find(".");
	if (lastFound != std::string::npos) {
		retAdrArray[0] = (uint8_t)std::stoi(transformAdr.substr(0, lastFound));
		
		for(int ix = 1; ix < adrSize; ++ix) {
			std::size_t found = transformAdr.find(".", lastFound+1);
			if (found != std::string::npos) {
				retAdrArray[ix] = (uint8_t)std::stoi(transformAdr.substr(lastFound+1, found));
				lastFound = found;
			} else if ((found == std::string::npos) && (ix == adrSize-1)) {
				retAdrArray[ix] = (uint8_t)std::stoi(transformAdr.substr(lastFound+1, transformAdr.length()));
			} else break;
		}
	}
	
	return retAdrArray;
}
/*
	int32_t _quantityOfThreads = 10000; //Количество вещей
	int64_t _quantityOfPackage = 10000000000; //Количество пакетов
	int16_t _scenarioType = 1; // 1 - самоподобный сценарий, 2 - антиперсистентный сценарий
	int16_t _trafficType = 17; // 17 - UDP, 4 - TCP
	int16_t _dataFieldSize = 8; //Размер поля данных пакета
	uint64_t _baseDelay = 100000; //Время между отправкой
	uint64_t _antipersistantDelay = 30000000; //Базовая задержка перед антиперсистентной отправкой
	uint64_t _sendDuration = 3000000; // Базовая длительность перед антиперсистентной отправкой
	int8_t _IPType = 4;
	uint8_t _netAdr[] = {0xC0, 0xA8, 0x01, 0x8A}; //Адрес локальной подсети 
	uint8_t _dstAdr[] = {0x1F, 0x94, 0x63, 0x41}; //Адрес подсети устройства назначения
	uint8_t _mask[] = {0xFF, 0xFF, 0xFF, 0x00}; //Маска подсети
*/