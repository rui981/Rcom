/*
 * applicationlayer.cpp
 *
 *  Created on: Oct 22, 2012
 *      Author: rui
 */


#include "applicationlayer.h"



applicationLayer::applicationLayer(int fileDescriptor, int status){
	this->fileDescriptor=fileDescriptor;
	this->status=status;
}


void applicationLayer::setStatus(int status){
	this->status=status;
}


int applicationLayer::getStatus(){
	return status;
}
