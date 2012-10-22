/*
 * linklayer.cpp
 *
 *  Created on: Oct 22, 2012
 *      Author: rui
 */

#include "linklayer.h"



linkLayer::linkLayer(char * port, int baudrate,  unsigned int timeout, unsigned int sequenceNumber, unsigned int numTransmissions, char * frame){

	this->port=port;
	this->baudrate=baudrate;
	this->sequenceNumber=sequenceNumber;
	this->timeout=timeout;
	this->numTransmissions=numTransmissions;
	this->frame=frame;
}


void linkLayer::setFrame(char frame[MAX_SIZE]){
	this->frame=frame;
}


char * linkLayer::getFrame(){
	return frame;
}



