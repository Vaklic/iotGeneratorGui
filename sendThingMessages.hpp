#ifndef _SENDTHINGMESSAGES_HPP
#define _SENDTHINGMESSAGES_HPP

#include "library.hpp"
#include "uniqueThing.hpp"

class sendThingMessages {
private:
	
protected:
	uniqueThing* thing;
	char* dataField;
public:
	sendThingMessages(void);
	sendThingMessages(uniqueThing *_thing);
	sendThingMessages(uniqueThing _thing, char* _dataField);
	~sendThingMessages();
	
	void generateRandomString(void);
	char* getDataField(void);
	void sendUDPPacket(void);
	
	void test_showUniqueIP(void);
	void test_showDstIP(void);
	
	uint16_t getDstPort(void);
	uint16_t getSrcPort(void);
};

#endif
