/*
 * File: prime_factor.h
 * AUTHOR: William Willie Wells
 * DATE: July 2017 ...
 */

#ifndef _PRIME_FACTOR_H_
#define _PRIME_FACTOR_H_

// package message/structs include  
#include <iostream>
#include <cmath>

// namespace
using namespace std;

// class
class PrimeFactor{
  public:
    // con(de)structors
	PrimeFactor(int, int);
    ~PrimeFactor();
	
	float approxSquareRoot(int,float);
	void factor(int);
	//void factorMultiple(int,int);
	
  private:
    // in(ex)ternal parameters
	int factoredNumber;
    int divisor;
    float searchLimit;
	float boundOne;
	float estimate;
	float boundTwo;
	float tmp;
};
#endif // prime_factor
