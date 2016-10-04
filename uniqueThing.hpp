#ifndef _UNIQUETHING_HPP
#define _UNIQUETHING_HPP

#include "library.hpp"

class uniqueThing {
private:
	
protected:
	int8_t IPtype;														// IPv4=4 IPv6=16
	int8_t transportProtocol; 											// UDP=17 TCP=6
	int16_t dataLength;
	
	uint8_t* uniqueMAC;
	uint8_t* uniqueNetIP;
	uint8_t* netmask;
	uint8_t* uniqueIP;
	uint8_t* dstIP;
	
	uint16_t dstPort;
	uint16_t srcPort;
public:
	uniqueThing(uniqueThing *_thing);
	uniqueThing(int8_t _IPtype, int8_t _transportProtocol, int16_t _dataLength, uint16_t _srcPort, uint16_t _dstPort, uint8_t* _uniqueNetIP, uint8_t* _uniqueIP, uint8_t* _uniqueMAC, uint8_t* _netmask, uint8_t* _dstIP);
	uniqueThing(int8_t _IPtype, int8_t _transportProtocol, int16_t _dataLength);
	uniqueThing(void);
	~uniqueThing();

	void createThing(uint8_t* _uniqueNetIP, uint8_t* _uniqueIP, uint8_t* _uniqueMAC, uint8_t* _netmask, uint8_t* _dstIP);
	void test_showUniqueIP(void);
	void test_showDstIP(void);
	void test_showSrcPort(void);
	void test_showDstPort(void);
	void generateRandomUniqueIPbyNetParam(int8_t _IPtype, uint8_t* _uniqueNetIP, uint8_t* _netmask);
	void generateRandomDstIPbyNetParam(int8_t _IPtype, uint8_t* _uniqueNetIP, uint8_t* _netmask);
	uint8_t* generateRandomIPbyNetParam(int8_t _IPtype, uint8_t* _uniqueNetIP, uint8_t* _netmask);
	void generateRandomSrcPort(void);
	void generateRandomDstPort(void);
	uint8_t* divideByte(uint8_t byte);
	uint8_t uniteByte(uint8_t* byte);
	void setTransportProtocol(int8_t _transportProtocol);
	void setUniqueIP(uint8_t* _uniqueIP);
	void setDstIP(uint8_t* _uniqueIP);
	int32_t getDataLength(void);
	int8_t getIPtype(void);
	int8_t getTransportProtocol(void);
	uint16_t getSrcPort(void);
	uint16_t getDstPort(void);
	uint8_t getFieldValueByIndex(uint8_t fieldType, int index);
	void setDataFieldLength(int16_t _dataLength);
};

#endif
