#ifndef _IOTTHREAD_HPP
#define _IOTTHREAD_HPP
#include "library.hpp"
#include "sendThingMessages.hpp"

class IoTThread {
private:
	int8_t IPType;
	uint8_t* netAdr;
	uint8_t* dstAdr;
	uint8_t* mask;
	
	sendThingMessages* sendPackage;
	
	int16_t scenarioType;
	int16_t trafficType;
	
	int16_t dataFieldSize;
	
	int8_t stopThreadFlag;
	
	int64_t quantityOfPackage;
	int64_t countOfPackage;
	
	uint64_t timeOfDelay;
public:	
	IoTThread(void);
	IoTThread(int16_t _scenarioType, int16_t _trafficType, int16_t _dataFieldSize);
	IoTThread(int8_t _IPType, uint8_t* _netAdr, uint8_t* _dstAdr, uint8_t* _mask, int16_t _scenarioType, int16_t _trafficType, int16_t _dataFieldSize);
	~IoTThread(void);
	
	void setScenarioAndTrafficTypes(int16_t _scenarioType, int16_t _trafficType);
	void stopOrStartThread(int8_t command);
	void setTimeOfDelay(uint64_t _timeOfDelay);
	uint64_t getTimeOfDelay(void);
	void setQuantityOfPackage(int64_t _quantityOfPackage);
	void randomQuantityOfPackage(int64_t minQuantityOfPackage, int64_t maxQuantityOfPackage);
	int8_t getStopThreadFlag(void);
	void sendMessage(void);
	void test_showNetAdr(void);
	void test_showDstAdr(void);
	void test_showMask(void);
	
	void test_showUniqueIP(void);
	void test_showDstIP(void);
	
	uint16_t getDstPort(void);
	uint16_t getSrcPort(void);
};

#endif
