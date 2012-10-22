/*
 * linklayer.cpp
 *
 *  Created on: Oct 22, 2012
 *      Author: rui
 */

#include "linklayer.h"

linkLayer::linkLayer(){
}
/*
linkLayer::linkLayer(char port[20], int baudrate,  unsigned int timeout, unsigned int sequenceNumber, unsigned int numTransmissions, char frame[MAX_SIZE]){

	this->port[20]=port[20];
	this->baudrate=baudrate;
	this->sequenceNumber=sequenceNumber;
	this->timeout=timeout;
	this->numTransmissions=numTransmissions;
	this->frame[MAX_SIZE]=frame[MAX_SIZE];
}
*/

void linkLayer::setFrame(char frame[MAX_SIZE]){
	this->frame[MAX_SIZE]=frame[MAX_SIZE];
}


char * linkLayer::getFrame(){
	return frame;
}


int linkLayer::llopen(char ** arg, int &fd, int status){
	
	struct termios oldtio,newtio;
	   fd = open(arg[1], O_RDWR | O_NOCTTY );
    if (fd <0) {perror(arg[1]); exit(-1); }

    if ( tcgetattr(fd,&oldtio) == -1) { /* save current port settings */
      perror("tcgetattr");
      exit(-1);
    }

    bzero(&newtio, sizeof(newtio));
    newtio.c_cflag = BAUDRATE | CS8 | CLOCAL | CREAD;
    newtio.c_iflag = IGNPAR;
    newtio.c_oflag = 0;

    /* set input mode (non-canonical, no echo,...) */
    newtio.c_lflag = 0;

    newtio.c_cc[VTIME]    = 0;   /* inter-character timer unused */
    newtio.c_cc[VMIN]     = 5;   /* blocking read until 4 chars received */



  /* 
    VTIME e VMIN devem ser alterados de forma a proteger com um temporizador a 
    leitura do(s) próximo(s) caracter(es)
  */



    tcflush(fd, TCIOFLUSH);
    

    if ( tcsetattr(fd,TCSANOW,&newtio) == -1) {
      perror("tcsetattr");
      exit(-1);
    }

    printf("New termios structure set\n");
}
