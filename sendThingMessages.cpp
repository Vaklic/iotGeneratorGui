#include "sendThingMessages.hpp"

sendThingMessages::sendThingMessages(void){
	this->thing = new uniqueThing();
	this->dataField = new char[this->thing->getDataLength()];
		
	for(int ix = 0; ix < this->thing->getDataLength(); ++ix){
		this->dataField[ix] = '0';
	}
}
	
sendThingMessages::sendThingMessages(uniqueThing *_thing){	
	this->thing = new uniqueThing(_thing);
	this->dataField = new char[this->thing->getDataLength()];
		
	for(int ix = 0; ix < this->thing->getDataLength(); ++ix){
		this->dataField[ix] = '0';
	}
}
	
sendThingMessages::sendThingMessages(uniqueThing _thing, char* _dataField){
	this->thing = new uniqueThing(_thing);
	this->dataField = new char[this->thing->getDataLength()];
		
	for(int ix = 0; ix < this->thing->getDataLength(); ++ix){
		this->dataField[ix] = _dataField[ix];
	}
}
	
sendThingMessages::~sendThingMessages(){
	delete this->thing;
	delete[] this->dataField;	
}
	
void sendThingMessages::generateRandomString(void){
	for(int ix = 0; ix < this->thing->getDataLength(); ++ix){
		this->dataField[ix] = generateRandomChar();
	}
}
	
char* sendThingMessages::getDataField(void){
	return this->dataField;	
}

void sendThingMessages::sendUDPPacket(void){
	char message[this->thing->getDataLength()+1];
		
	char src_ip[32], dst_ip[32];
	int8_t status;
	struct addrinfo hints_numeric, hints;
	struct addrinfo *result, *source;
	size_t packetsize, headersize, extraipheadersize;
	struct opacket4 op4;
	struct opacket6 op6;
	struct sockaddr_in *sockaddr4;
	struct sockaddr_in6 *sockaddr6;
	void *packet;
	int8_t on = 1;
	int8_t sd;
	int8_t ipSize = 0;
	char buf[5];
	ssize_t num;
		
	strcpy(message, this->dataField);
		
	if(this->thing->getIPtype() == IPV4_ADDR_SIZE){
		ipSize = IPV4_ADDR_SIZE;
	} else if(this->thing->getIPtype() == 6){
		ipSize = IPV6_ADDR_SIZE;
	} else ipSize = IPV4_ADDR_SIZE;
	sprintf(buf, "%d", this->thing->getFieldValueByIndex(1, 0));
	strcpy(src_ip, buf);
	for(int ix = 1; ix < ipSize; ++ix){
		strcat(src_ip, ".");
		sprintf(buf, "%d", this->thing->getFieldValueByIndex(1, ix));
		strcat(src_ip, buf);
	}
     
	sprintf(buf, "%d", this->thing->getFieldValueByIndex(2, 0));
	strcpy(dst_ip, buf);
	for(int ix = 1; ix < ipSize; ++ix){
		strcat(dst_ip, ".");
		sprintf(buf, "%d", this->thing->getFieldValueByIndex(2, ix));
		strcat(dst_ip, buf);
	}

	memset(&hints_numeric, 0, sizeof(hints_numeric));
	hints_numeric.ai_flags = AI_NUMERICHOST;
	hints_numeric.ai_socktype = SOCK_RAW;
	hints_numeric.ai_protocol = IPPROTO_RAW;
	if (strcmp(src_ip, "") != 0) {
		source = (addrinfo*)malloc(sizeof(struct addrinfo));
		status = getaddrinfo(src_ip, NULL, &hints_numeric, &source);
		if (status) {
			fprintf(stderr, "Not an IP address: %s\n", src_ip);
			return;
		}
	} else {
		source = NULL;
	}

	memset(&hints, 0, sizeof(hints));
	if(ipSize == IPV4_ADDR_SIZE) {
		hints.ai_family = AF_INET;
	} else if(ipSize == IPV6_ADDR_SIZE) {
		hints.ai_family = AF_INET6;
	} else {
		hints.ai_family = AF_UNSPEC;
	}
	hints.ai_socktype = SOCK_RAW;
	hints.ai_protocol = IPPROTO_RAW;
	result = (addrinfo*)malloc(sizeof(struct addrinfo));
	status = getaddrinfo(dst_ip, NULL, &hints_numeric, &result);
		
	if(status && status == EAI_NONAME){
		status = getaddrinfo(dst_ip, NULL, &hints, &result);
		if(status){
			fprintf(stderr, "Nothing found about host name %s\n", dst_ip);
			close(sd);
			return;
		}
	}
	if(result->ai_family != AF_INET && result->ai_family != AF_INET6){
		fprintf(stderr, "Only IPv4 and IPv6: family %i unsupported\n",result->ai_family);
		close(sd);
		return;
	}
	sd = socket(result->ai_family, SOCK_RAW, IPPROTO_RAW);
	if(sd < 0){
		fprintf(stderr, "Cannot create raw socket: %s\n", strerror(errno));
		close(sd);
		return;
	}
	if(source != NULL
		&& ((result->ai_family == AF_INET && source->ai_family != AF_INET)
			|| (result->ai_family == AF_INET6 && source->ai_family != AF_INET6))) {
		fprintf(stderr,"The IP source address you specified (%s) must be the same IP address family than the target\n",src_ip);
		close(sd);
		return;
	}
	if (result->ai_family == AF_INET) {
		if (setsockopt(sd, IPPROTO_IP, IP_HDRINCL, (char *) &on, sizeof(on)) < 0) {
			fprintf(stderr, "Cannot set IP_HDRINCL: %s\n", strerror(errno));
			close(sd);
			return;
		}
	}
		
	if (result->ai_family == AF_INET) {
		sockaddr4 = (struct sockaddr_in *) result->ai_addr;
		memset(&op4.ip, '\0', sizeof(op4.ip));
		op4.ip.ip_v = 4;
		op4.ip.ip_hl = sizeof(op4.ip) >> 2;
		op4.ip.ip_dst = sockaddr4->sin_addr;
		if (source == NULL) {
		} else {
			sockaddr4 = (struct sockaddr_in *) source->ai_addr;
			op4.ip.ip_src = sockaddr4->sin_addr;
		}
		op4.ip.ip_p = this->thing->getTransportProtocol();
		op4.ip.ip_ttl = TTL_UDP;
		headersize = sizeof(op4.ip) + sizeof(op4.udp);
		packetsize = headersize + strlen(message);
		op4.ip.ip_len = htons(packetsize);
		memset(&op4.udp, '\0', sizeof(op4.udp));
		op4.udp.uh_dport = htons(this->thing->getDstPort());
		op4.udp.uh_sport = htons(this->thing->getSrcPort());
		op4.udp.uh_ulen = htons(strlen(message) + sizeof(op4.udp));
		op4.udp.uh_sum = 0;
			
		memset(op4.payload, '\0', this->thing->getDataLength()+1);
		strcpy(op4.payload, message);
		packet = &op4;
		extraipheadersize = 0;
	} else if (result->ai_family == AF_INET6) {
		sockaddr6 = (struct sockaddr_in6 *) result->ai_addr;
		memset(&op6.ip, '\0', sizeof(op6.ip));
		op6.ip.ip6_vfc = 6 << 4;
		op6.ip.ip6_dst = sockaddr6->sin6_addr;
		if (source == NULL) {
		} else {
			sockaddr6 = (struct sockaddr_in6 *) source->ai_addr;
			op6.ip.ip6_src = sockaddr6->sin6_addr;
		}
		op6.ip.ip6_nxt = this->thing->getTransportProtocol();
		op6.ip.ip6_hlim = TTL_UDP;
		headersize = sizeof(op6.ip) + sizeof(op6.udp);
		packetsize = headersize + strlen(message);
		op6.ip.ip6_plen = htons((uint16_t) packetsize);
		memset(&op6.udp, '\0', sizeof(op6.udp));
		op6.udp.uh_dport = htons(this->thing->getDstPort());
		op6.udp.uh_sport = htons(this->thing->getSrcPort());
		op6.udp.uh_ulen = htons(strlen(message) + sizeof(op6.udp));
		op6.udp.uh_sum = 0;
		memset(op6.payload, '\0', this->thing->getDataLength()+1);
		strcpy(op6.payload, message);
		packet = &op6;
		extraipheadersize = sizeof(op6.ip);
	}
	num = sendto(sd, packet, packetsize + extraipheadersize, 0, result->ai_addr, result->ai_addrlen);
	if(num < 0){
		fprintf(stderr, "Cannot send message:  %s\n", strerror(errno));
		close(sd);
		return;
	}	
	close(sd);
}

void sendThingMessages::test_showUniqueIP(void){
	thing->test_showUniqueIP();
}

void sendThingMessages::test_showDstIP(void){
	thing->test_showDstIP();
}

uint16_t sendThingMessages::getDstPort(void){
	return thing->getDstPort();
}

uint16_t sendThingMessages::getSrcPort(void){
	return thing->getSrcPort();
}
