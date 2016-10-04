#ifndef _LIBRARY_HPP
#define _LIBRARY_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <thread>
#include <random>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstdbool>

#include <stdint.h>
#include <errno.h>  
#include <unistd.h>

#include <sys/socket.h>
#include <netinet/udp.h>   
#include <netinet/in.h>
#include <netinet/ip.h>    
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in_systm.h>
#include <netinet/ip6.h>

#define IPV4_ADDR_SIZE 4
#define IPV6_ADDR_SIZE 16
#define MAC_ADDR_SIZE 6

#define MAX_MESSAGE_SIZE 1024
#define TTL_UDP 99

#define MAX_PACKAGE_ID_NUM 4294967295
#define MIN_PACKAGE_ID_NUM 10

#define MICROSEC_TO_SEND_AGAIN 1000000
#define MICROSEC_FOR_RANDOM_DELAY 100000

#define THINGS_NUMBER 10

#define TEST_NUMBER_OF_THING_PACKET 50

#define MIN_PACKAGE_QUANTITY 10
#define MAX_PACKAGE_QUANTITY 20

#define TIME_DELAY_PERSENT 0.3
#define ANTIPERSISTENT_CHANCE_OF_SENDING_PACKAGE 0.6
#define DELAY_TIME 50000

#define JITTER_COFF 100000

#define THREAD_START_DELAY 1000

struct opacket4 {
    struct ip       ip;
    struct udphdr   udp;
    char            payload[MAX_MESSAGE_SIZE];
} __attribute__ ((packed));

struct opacket6 {
    struct ip6_hdr  ip;
    struct udphdr   udp;
    char            payload[MAX_MESSAGE_SIZE];
} __attribute__ ((packed));

uint8_t generateRandomUInt8(uint8_t lowBorder, uint8_t highBorder);
uint16_t generateRandomUInt16(uint16_t lowBorder, uint16_t highBorder);
double generateRandomDouble(double lowBorder, double highBorder);
char generateRandomChar(void);
uint32_t generateRandomUInt32(uint32_t lowBorder, uint32_t highBorder);
uint64_t generateRandomUInt64(uint64_t lowBorder, uint64_t highBorder);

class uniqueThing;
class sendThingMessages;
class IoTThread;
class controlIoTThreads;

#endif // _LIBRARY_HPP
