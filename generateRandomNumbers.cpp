#include "library.hpp"

uint8_t generateRandomUInt8(uint8_t lowBorder, uint8_t highBorder){
	return (uint8_t)(lowBorder + rand() % highBorder);
}
	
uint16_t generateRandomUInt16(uint16_t lowBorder, uint16_t highBorder){
	return (uint16_t)(lowBorder + rand() % highBorder);
}
	
double generateRandomDouble(double lowBorder, double highBorder){
	double f = (double)rand() / RAND_MAX;
	return (lowBorder + f * (highBorder - lowBorder));
}

char generateRandomChar(void){
	return 0x40 + (char)rand()%16;
}

uint32_t generateRandomUInt32(uint32_t lowBorder, uint32_t highBorder){
	return (uint32_t)(lowBorder + rand() % highBorder);
}

uint64_t generateRandomUInt64(uint64_t lowBorder, uint64_t highBorder){
	return (uint64_t)(lowBorder + rand() % highBorder);
}
