#ifndef _CONTROLIOTTHREADS_HPP
#define _CONTROLIOTTHREADS_HPP
#include "library.hpp"
#include "IoTThread.hpp"

class controlIoTThreads {
private:
	int64_t quantityOfThreads;
	int64_t quantityOfPackage;
	
	int16_t scenarioType; 
	int16_t trafficType;
	
	int16_t dataFieldSize;

	std::thread* threadIoT;
	std::thread controlThread;
	std::thread antipersistentControlThread;

	int8_t controlStopFlag;
	int8_t* threadEndFlag;
	IoTThread** iot;

	uint64_t baseDelay;
	
	uint64_t antipersistentDelay;
	uint64_t sendDuration;
	int8_t antipersistentSendFlag;
	int8_t antipersistentEndFlag;
	
public:
	controlIoTThreads(void);
	controlIoTThreads(int32_t _quantityOfThreads, int64_t _quantityOfPackage, int16_t _dataFieldSize, int16_t _scenarioType, int16_t _trafficType, uint64_t _baseDelay, uint64_t _sendDuration, uint64_t _antipersistantDelay);
	controlIoTThreads(int32_t _quantityOfThreads, int64_t _quantityOfPackage, int16_t _dataFieldSize, int16_t _scenarioType, int16_t _trafficType, uint64_t _baseDelay, uint64_t _sendDuration, uint64_t _antipersistantDelay, int8_t _IPType, uint8_t* _netAdr, uint8_t* _dstAdr, uint8_t* _mask);
	~controlIoTThreads(void);
	
	void runStopControlThread(void);
	void runAntipersistentControlThread(void);
	void switchOffThreads(void);
	void runThread(IoTThread* iot, int64_t threadNumber);
	void restartThreadsEndFlag(void);
	void startThreads(void);
	void test_showAllThingsAdr(void);
	void setScenarioAndTrafficType(int16_t _scenarioType, int16_t _trafficType);
	int8_t getControlStopFlag(void);
};

#endif
