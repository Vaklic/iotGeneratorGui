#include "uniqueThing.hpp"

uniqueThing::uniqueThing(uniqueThing *_thing) : IPtype(_thing->IPtype), transportProtocol(_thing->transportProtocol), dataLength(_thing->dataLength), srcPort(_thing->srcPort), dstPort(_thing->dstPort){
	this->createThing(_thing->uniqueNetIP, _thing->uniqueIP, _thing->uniqueMAC, _thing->netmask, _thing->dstIP);
}

uniqueThing::uniqueThing(int8_t _IPtype, int8_t _transportProtocol, int16_t _dataLength, uint16_t _srcPort, uint16_t _dstPort, uint8_t* _uniqueNetIP, uint8_t* _uniqueIP, uint8_t* _uniqueMAC, uint8_t* _netmask, uint8_t* _dstIP) : IPtype(_IPtype), transportProtocol(_transportProtocol), dataLength(_dataLength), srcPort(_srcPort), dstPort(_dstPort){
	this->createThing(_uniqueNetIP, _uniqueIP, _uniqueMAC, _netmask, _dstIP);
}
	
uniqueThing::uniqueThing(int8_t _IPtype, int8_t _transportProtocol, int16_t _dataLength): IPtype(_IPtype), transportProtocol(_transportProtocol), dataLength(_dataLength) {
	this->srcPort = 10000; 
	this->dstPort = 10000;
		
	if(this->IPtype == IPV4_ADDR_SIZE){
		uint8_t expIP[IPV4_ADDR_SIZE] = {0x7F, 0x00, 0x00, 0x01};	
		uint8_t expMAC[MAC_ADDR_SIZE] = {0xFF, };	
		uint8_t expNetIP[IPV4_ADDR_SIZE] = {0x7F, 0x00, 0x00, 0x01};	
		uint8_t expNetmask[IPV4_ADDR_SIZE] = {0xFF, 0x00, 0x00, 0x00};
		uint8_t expDstIP[IPV4_ADDR_SIZE] = {0x7F, 0x00, 0x00, 0x01};
			
		this->createThing(expNetIP, expIP, expMAC, expNetmask, expDstIP);
	} else {
		uint8_t expIP[IPV6_ADDR_SIZE] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01};	
		uint8_t expMAC[MAC_ADDR_SIZE] = {0xFF, };	
		uint8_t expNetIP[IPV6_ADDR_SIZE] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01};
		uint8_t expNetmask[IPV6_ADDR_SIZE] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, };
		uint8_t expDstIP[IPV6_ADDR_SIZE] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01};
			
		this->createThing(expNetIP, expIP, expMAC, expNetmask, expDstIP);
	}	
}
	
uniqueThing::uniqueThing(void){
	this->IPtype = IPV4_ADDR_SIZE;
	this->dataLength = 8;
	this->transportProtocol = 17;
	this->srcPort = 10000; 
	this->dstPort = 10000;
		
	uint8_t expIP[IPV4_ADDR_SIZE] = {0x7F, 0x00, 0x00, 0x01};	
	uint8_t expMAC[MAC_ADDR_SIZE] = {0xFF, };	
	uint8_t expNetIP[IPV4_ADDR_SIZE] = {0x7F, 0x00, 0x00, 0x01};
	uint8_t expNetmask[IPV4_ADDR_SIZE] = {0xFF, 0x00, 0x00, 0x00};
			
	uint8_t expDstIP[IPV4_ADDR_SIZE] = {0x7F, 0x00, 0x00, 0x01};
		
	this->createThing(expNetIP, expIP, expMAC, expNetmask, expDstIP);
}

uniqueThing::~uniqueThing(){
	delete [] this->uniqueIP;
	delete [] this->uniqueMAC;
	delete [] this->netmask;
	delete [] this->dstIP;
}

void uniqueThing::createThing(uint8_t* _uniqueNetIP, uint8_t* _uniqueIP, uint8_t* _uniqueMAC, uint8_t* _netmask, uint8_t* _dstIP){
	if(this->IPtype == IPV4_ADDR_SIZE){
		this->uniqueIP = new uint8_t[IPV4_ADDR_SIZE];
		this->uniqueMAC = new uint8_t[MAC_ADDR_SIZE];
		this->uniqueNetIP = new uint8_t[IPV4_ADDR_SIZE];
		this->netmask = new uint8_t[IPV4_ADDR_SIZE];
		this->dstIP = new uint8_t[IPV4_ADDR_SIZE];
			
		for(int ix = 0; ix < IPV4_ADDR_SIZE; ++ix){
			this->uniqueIP[ix] = _uniqueIP[ix];
			this->uniqueNetIP[ix] = _uniqueNetIP[ix];
			this->netmask[ix] = _netmask[ix];
			this->dstIP[ix] = _dstIP[ix];
		}
		for(int ix = 0; ix < MAC_ADDR_SIZE; ++ix){
			this->uniqueMAC[ix] = _uniqueMAC[ix];
		}
	} else {
		this->uniqueIP = new uint8_t[IPV6_ADDR_SIZE];
		this->uniqueMAC = new uint8_t[MAC_ADDR_SIZE];
		this->uniqueNetIP = new uint8_t[IPV6_ADDR_SIZE];
		this->netmask = new uint8_t[IPV6_ADDR_SIZE];
		this->dstIP = new uint8_t[IPV6_ADDR_SIZE];
			
		for(int ix = 0; ix < IPV6_ADDR_SIZE; ++ix){
			this->uniqueIP[ix] = _uniqueIP[ix];
			this->uniqueNetIP[ix] = _uniqueNetIP[ix];
			this->netmask[ix] = _netmask[ix];
			this->dstIP[ix] = _dstIP[ix];
		}
		for(int ix = 0; ix < MAC_ADDR_SIZE; ++ix){
			this->uniqueMAC[ix] = _uniqueMAC[ix];
		}
	}
}
	
void uniqueThing::test_showUniqueIP(void){
	int8_t border = 0;
	if(this->IPtype == IPV4_ADDR_SIZE) border = IPV4_ADDR_SIZE;
	else border = IPV6_ADDR_SIZE;
		
	for(int ix = 0; ix < border; ++ix){
		fprintf(stdout, "%d", this->uniqueIP[ix]);
		if(ix < (border-1)) fprintf(stdout, ".");
	}
}
	
void uniqueThing::test_showDstIP(void){
	int8_t border = 0;
	if(this->IPtype == IPV4_ADDR_SIZE) border = IPV4_ADDR_SIZE;
	else border = IPV6_ADDR_SIZE;
		
	for(int ix = 0; ix < border; ++ix){
		fprintf(stdout, "%d", this->dstIP[ix]);
		if(ix < (border-1)) fprintf(stdout, ".");
	}
}
	
void uniqueThing::test_showSrcPort(void){
	fprintf(stdout, "%d", this->srcPort);
}
	
void uniqueThing::test_showDstPort(void){
	fprintf(stdout, "%d", this->dstPort);
}
	
void uniqueThing::generateRandomUniqueIPbyNetParam(int8_t _IPtype, uint8_t* _uniqueNetIP, uint8_t* _netmask){
	int8_t typeLength = 0;
	this->IPtype = _IPtype;
		
	if(_IPtype == 4) typeLength = IPV4_ADDR_SIZE;
	else typeLength = IPV6_ADDR_SIZE;
			
	uint8_t* generatedIP = generateRandomIPbyNetParam(this->IPtype, _uniqueNetIP, _netmask);
			
	for(int ix = 0; ix < typeLength; ++ix){
		this->uniqueIP[ix] = generatedIP[ix];
		this->uniqueNetIP[ix] = _uniqueNetIP[ix];
		this->netmask[ix] = _netmask[ix];
	}
}
	
void uniqueThing::generateRandomDstIPbyNetParam(int8_t _IPtype, uint8_t* _uniqueNetIP, uint8_t* _netmask){
	int8_t typeLength = 0;
		
	if(_IPtype == 4) typeLength = IPV4_ADDR_SIZE;
	else typeLength = IPV6_ADDR_SIZE;
			
	uint8_t* generatedIP = generateRandomIPbyNetParam(this->IPtype, _uniqueNetIP, _netmask);
			
	for(int ix = 0; ix < typeLength; ++ix){
		this->dstIP[ix] = generatedIP[ix];
	}
}
	
uint8_t* uniqueThing::generateRandomIPbyNetParam(int8_t _IPtype, uint8_t* _uniqueNetIP, uint8_t* _netmask){
	int prevFlag = 0;
	int8_t typeLength = 0;
		
	if(_IPtype == 4) typeLength = IPV4_ADDR_SIZE;
	else typeLength = IPV6_ADDR_SIZE;
		
	uint8_t* retIP = new uint8_t[typeLength];
	for(int ix = 0; ix < typeLength; ++ix){
		retIP[ix] = 0;
		if(_netmask[ix] == 0xFF){
			retIP[ix] = _uniqueNetIP[ix];
		} else if(_netmask[ix] == 0x00){
			retIP[ix] = generateRandomUInt8(1, 254);
		} else {
			uint8_t *byte = new uint8_t[8];
			uint8_t *byteNetIP = divideByte(_uniqueNetIP[ix]);
			uint8_t *byteNetmask = divideByte(_netmask[ix]);
				
			for(int iy = 0; iy < 8; ++iy){
				if(byteNetmask[iy] == 0){
					uint8_t randNum = generateRandomUInt8(0, 100);
					if(randNum > 50) 
						byte[iy] = 0x01;
					else 
						byte[iy] = 0x00; 
					byte[iy] = (uint8_t)(byte[iy] << (7-iy));
				} else {
					byte[iy] = byteNetIP[iy];
				} 
			}
			retIP[ix] = uniteByte(byte);

			delete [] byte;
			delete [] byteNetIP;
			delete [] byteNetmask;
		}
	}
	return retIP;
}
	
void uniqueThing::generateRandomSrcPort(void){
	this->srcPort = generateRandomUInt16(1000, 65535);
}
	
void uniqueThing::generateRandomDstPort(void){
	this->dstPort = generateRandomUInt16(1000, 65535);
}
	
uint8_t* uniqueThing::divideByte(uint8_t byte){
	uint8_t *retBytes = new uint8_t[8];
		
	for(int ix = 0; ix <= 7; ++ix){
		retBytes[ix] = (uint8_t)((uint8_t)((byte << ix) >> 7) << (7-ix));
	}
		
	return retBytes;
}
	
uint8_t uniqueThing::uniteByte(uint8_t* byte){
	
	uint8_t retByte = 0x00;
		
	for(int ix = 0; ix < 8; ++ix)
		retByte = retByte | byte[ix];
		
	return retByte;
}

void uniqueThing::setTransportProtocol(int8_t _transportProtocol){
	this->transportProtocol = _transportProtocol;
}
	
void uniqueThing::setUniqueIP(uint8_t* _uniqueIP){
	uint8_t typeLength = 0;
	if(this->IPtype == 4) typeLength = IPV4_ADDR_SIZE;
	else typeLength = IPV6_ADDR_SIZE;
		
	for(int ix = 0; ix < typeLength; ++ix)
		this->uniqueIP[ix] = _uniqueIP[ix];
}
	
void uniqueThing::setDstIP(uint8_t* _uniqueIP){
	uint8_t typeLength = 0;
	if(this->IPtype == 4) typeLength = IPV4_ADDR_SIZE;
	else typeLength = IPV6_ADDR_SIZE;
		
	for(int ix = 0; ix < typeLength; ++ix)
		this->uniqueIP[ix] = _uniqueIP[ix];
}
	
int32_t uniqueThing::getDataLength(void){
	return this->dataLength;
}
	
int8_t uniqueThing::getIPtype(void){
	return this->IPtype;
}
	
int8_t uniqueThing::getTransportProtocol(void){
	return this->transportProtocol;
}
	
uint16_t uniqueThing::getSrcPort(void){
	return this->srcPort;
}
	
uint16_t uniqueThing::getDstPort(void){
	return this->dstPort;
}
	
uint8_t uniqueThing::getFieldValueByIndex(uint8_t fieldType, int index){
	uint8_t retValue = 0x00;
		
	if(fieldType == 1) retValue = this->uniqueIP[index];
	else if(fieldType == 2) retValue = this->dstIP[index];
	else if(fieldType == 3) retValue = this->netmask[index];
	else if(fieldType == 4) retValue = this->uniqueNetIP[index];
	else if(fieldType == 5) retValue = this->uniqueMAC[index];
		
	return retValue;
}

void uniqueThing::setDataFieldLength(int16_t _dataLength){
	this->dataLength = _dataLength;
}
