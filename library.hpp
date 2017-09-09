#ifndef _LIBRARY_HPP
#define _LIBRARY_HPP

//Include C++ libraries
#include <iostream>
#include <string>
#include <sstream>
#include <thread>
#include <random>

//Include C libraries
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

//Define default constants
#define IPV4_ADDR_SIZE 4													//IPv4 address size (bytes)
#define IPV6_ADDR_SIZE 16													//IPv6 address size (bytes)
#define MAC_ADDR_SIZE 6														//MAC address size	(bytes)

#define MAX_MESSAGE_SIZE 1024												//MAX data field size 
#define TTL_UDP 99															//TTL for UDP package

#define MAX_PACKAGE_ID_NUM 4294967295										//Upper ID border for packages
#define MIN_PACKAGE_ID_NUM 10												//Bottom ID border for packages

#define MICROSEC_TO_SEND_AGAIN 1000000										//Delay between sending packages for
																			//Antipersistent and Selfsimular scenarios 
#define MICROSEC_FOR_RANDOM_DELAY 100000									//Delay between sending packages for
																			//Antipersistent scenario 

#define THINGS_NUMBER 10													//Number of existing virtual devices

#define TEST_NUMBER_OF_THING_PACKET 50										//Number of package which every device 
																			//send for Selfsimular scenario

#define MIN_PACKAGE_QUANTITY 10												//Minimum number of package which every 
																			//device send for Antipersistent scenario
#define MAX_PACKAGE_QUANTITY 20												//Maximum number of package which every 
																			//device send for Antipersistent scenario

//Some constants for antipersistant scenario generation
#define TIME_DELAY_PERSENT 0.3
#define ANTIPERSISTENT_CHANCE_OF_SENDING_PACKAGE 0.6
#define DELAY_TIME 50000

//Jitter coefficient between packages for Antipersistent scenario
#define JITTER_COFF 100000

//Delay between packet generation
#define THREAD_START_DELAY 1000

//Structure for creating raw IP4 packet
struct opacket4 {
    struct ip       ip;
    struct udphdr   udp;
    char            payload[MAX_MESSAGE_SIZE];
} __attribute__ ((packed));

//Structure for creating raw IP6 packet
struct opacket6 {
    struct ip6_hdr  ip;
    struct udphdr   udp;
    char            payload[MAX_MESSAGE_SIZE];
} __attribute__ ((packed));

//Generate random number functions
uint8_t generateRandomUInt8(uint8_t lowBorder, uint8_t highBorder);			//Generate random UInt8_t number
uint16_t generateRandomUInt16(uint16_t lowBorder, uint16_t highBorder);		//Generate random UInt16_t number
uint32_t generateRandomUInt32(uint32_t lowBorder, uint32_t highBorder);		//Generate random UInt32_t number
uint64_t generateRandomUInt64(uint64_t lowBorder, uint64_t highBorder);		//Generate random UInt64_t number
double generateRandomDouble(double lowBorder, double highBorder);			//Generate random Double number
char generateRandomChar(void);												//Generate random Char symbol

//Define classes
class uniqueThing;
class sendThingMessages;
class IoTThread;
class controlIoTThreads;

#endif // _LIBRARY_HPP
