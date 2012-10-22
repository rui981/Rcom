/*
 * linklayer.cpp
 *
 *  Created on: Oct 22, 2012
 *      Author: rui
 */

#include "linklayer.h"



linkLayer::linkLayer(char port[20], int baudrate,  unsigned int timeout, unsigned int sequenceNumber, unsigned int numTransmissions, char frame[MAX_SIZE]){

	this->port[20]=port[20];
	this->baudrate=baudrate;
	this->sequenceNumber=sequenceNumber;
	this->timeout=timeout;
	this->numTransmissions=numTransmissions;
	this->frame[MAX_SIZE]=frame[MAX_SIZE];
}


void linkLayer::setFrame(char frame[MAX_SIZE]){
	this->frame[MAX_SIZE]=frame[MAX_SIZE];
}


char * linkLayer::getFrame(){
	return frame;
}



