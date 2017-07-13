/*
 * FILE: prime_factor.cpp
 * AUTHOR: William Willie Wells
 * DATE: July 2017 ...
 */
 
 // class include
#include "../include/prime_factor.h"

// constructor -- checks input and calls method factor for all numbers in given range.
PrimeFactor::PrimeFactor(int start, int finish){
  if(finish < start){ factoredNumber= start; start= finish; finish= factoredNumber; }
  for(int i=start; i<=finish; i++){ cout<<i<<": "; factor(i); }
}

// destructor
PrimeFactor::~PrimeFactor(){}
	
// TODO: change estimate to searchLimit make void?
// returns and approximation to the square root of a number based on required precision 
float PrimeFactor::approxSquareRoot(int n,float precision){
  estimate= 1.0;
  tmp= (float)n;
  while(estimate < tmp){ tmp /= 2.0; estimate *= 2.0; }
  if(estimate == tmp){ return tmp; }
  
  boundTwo= estimate/2.0;
  boundOne= estimate;
  tmp= (float)n;
  if(precision < 0.0){ precision*=-1.0; }
  else if(precision == 0.0){ precision = 0.5; }
  
  while(fabs(tmp/estimate - estimate) > precision){
    estimate= (boundOne + boundTwo)/2; 
    if(tmp/estimate < estimate){ boundOne= estimate; }
    else if(tmp/estimate > estimate){ boundTwo= estimate; }
    else{ return estimate; }
  }
  
  return (tmp/estimate < estimate) ? tmp/estimate : estimate;
}
		
// factors any number into its prime factors and outputs to stdout
void PrimeFactor::factor(int n){
  if(n < 0){ n *= -1; }
  if(n == 1 || n == 0){ cout<<n<<" is not prime"<<endl; return; }

  searchLimit= approxSquareRoot(n,0.5); //cout<<searchLimit<<", ";
  divisor=2;
  factoredNumber= n;
  while((float)divisor <= searchLimit){
    while(factoredNumber % divisor == 0){
      cout<<divisor<<" ";
      factoredNumber /= divisor;
    }
    if(divisor==2){ divisor++; }else{ divisor += 2; }
  }
  if(factoredNumber == 1){ cout<<endl; }
  else{ cout<<factoredNumber<<endl; }
}

// checks input and calls method factor for all numbers in given range.
/*void PrimeFactor::factorMultiple(int start,int finish){
  for(int i=start; i<finish; i++){ factor(i); }
}*/
