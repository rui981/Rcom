/*
 * applicationlayer.h
 *
 *  Created on: Oct 22, 2012
 *      Author: rui
 */
 

#ifndef APPLICATIONLAYER_H_
#define APPLICATIONLAYER_H_


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <stdio.h>








class applicationLayer{
	int fileDescriptor;		/*Descritor correspondente à porta série*/
	int status;  			 /*TRANSMITTER | RECEIVER*/
public:
	applicationLayer(int fileDescriptor, int status);
	void setStatus(int status);
	int getStatus();
	

};











#endif /* APPLICATIONLAYER_H_ */
