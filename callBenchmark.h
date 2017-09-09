#ifndef _CALLBENCHMARK_HPP
#define _CALLBENCHMARK_HPP
#include "library.hpp"
#include "controlIoTThreads.hpp"

//This class responsible for call traffic generation functions from GUI 
class callBenchmark{
	public:
		callBenchmark(int32_t _quantityOfThreads = 1000, int64_t _quantityOfPackage = 100, int16_t _scenarioType = 1, int16_t _trafficType = 17, int16_t _dataFieldSize = 8, uint64_t _baseDelay = 500000, uint64_t _antipersistantDelay = 30000000, uint64_t _sendDuration = 3000000, int8_t _IPType = 4, std::string _netAdr = "127.0.0.0", std::string _dstAdr = "127.0.0.0", std::string _mask = "255.255.255.0");
		~callBenchmark();
		
		void initFunction(void);															//Define controlIoTThread object
		void setControlFlagCycle(bool value);												//Define value for controlIoTThreads label
		bool controlFlag;																	//Control label for controlIoTThreads object
		void stopControlThread(controlIoTThreads** _controlFunction, bool* _controlFlag); 	//Stop controlIoTThreads object
	protected:
		controlIoTThreads* controlFunction;							//Pointer to controlIoTThreads objects 
	
		int32_t quantityOfThreads; 									//Quantity of using programm threads
																	//Every thread uses as virtual device
		int64_t quantityOfPackage; 									//Quantity of packages which every device
																	//send for different scenarios
		int16_t scenarioType; 										//Antipersistant or selfsimular traffic 
																	//generation scenario
		int16_t trafficType;										//Using protocol (udp 17, tcp 6, http etc.)
		int16_t dataFieldSize;										//Size of every package data field size
		uint64_t baseDelay; 										//Delay between sending packages
		uint64_t antipersistantDelay; 								//Delay for Antipersistant scenario
		uint64_t sendDuration;										//Send duartion for selfpersistant scenario
		int8_t IPType;												//IP type (IPv4, IPv6)
		std::string netAdr; 										//Source net address 
		std::string dstAdr; 										//Destanition address
		std::string mask;											//Netmask for source or destianation net address
	
		//Form random address
		uint8_t* formAdrArray(int8_t _IPType = 4, std::string transformAdr = "127.0.0.1");
};

#endif