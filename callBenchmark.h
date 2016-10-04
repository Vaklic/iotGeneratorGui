#ifndef _CALLBENCHMARK_HPP
#define _CALLBENCHMARK_HPP
#include "library.hpp"
#include "controlIoTThreads.hpp"

class callBenchmark{
	public:
		callBenchmark(int32_t _quantityOfThreads = 1000, int64_t _quantityOfPackage = 100, int16_t _scenarioType = 1, int16_t _trafficType = 17, int16_t _dataFieldSize = 8, uint64_t _baseDelay = 500000, uint64_t _antipersistantDelay = 30000000, uint64_t _sendDuration = 3000000, int8_t _IPType = 4, std::string _netAdr = "127.0.0.0", std::string _dstAdr = "127.0.0.0", std::string _mask = "255.255.255.0");
		~callBenchmark();
		
		void initFunction(void);
		void setControlFlagCycle(bool value);
		bool controlFlag;
		void stopControlThread(controlIoTThreads** _controlFunction, bool* _controlFlag);
	protected:
		controlIoTThreads* controlFunction;
	
		int32_t quantityOfThreads; 
		int64_t quantityOfPackage; 
		int16_t scenarioType; 
		int16_t trafficType; 
		int16_t dataFieldSize; 
		uint64_t baseDelay; 
		uint64_t antipersistantDelay; 
		uint64_t sendDuration;
		int8_t IPType;
		std::string netAdr; 
		std::string dstAdr; 
		std::string mask;
	
		uint8_t* formAdrArray(int8_t _IPType = 4, std::string transformAdr = "127.0.0.1");
};

#endif