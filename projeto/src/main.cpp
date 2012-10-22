/*
 * main.cpp
 *
 *  Created on: Oct 22, 2012
 *      Author: rui
 */




#include "applicationlayer.h"
#include "linklayer.h"
#include <iostream>

using namespace std;

#define BAUDRATE 10
#define TIMEOUT 10
#define NUMTRANSMITIONS 10

unsigned char teste[MAX_SIZE];
int main(){
	applicationLayer * al= new applicationLayer(1, TRANSMITER);
	linkLayer * ll= new linkLayer('/dev/ttyS0', BAUDRATE,0,TIMEOUT,NUMTRANSMITIONS,teste);

	cout << "pilas no cu do paulo" << endl;
	return 0;
}
