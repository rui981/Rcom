#ifndef LINKLAYER_H
#define LINKLAYER_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <stdio.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#define BAUDRATE B38400
#define _POSIX_SOURCE 1 /* POSIX compliant source */
#define FALSE 0
#define TRUE 1
#define FLAG 0x7e
#define TRANSMITER 0
#define RECEIVER 1




#define MAX_SIZE 10

class linkLayer{
	char port[20];					/*Dispositivo /dev/ttySx, x = 0, 1*/
	int baudrate;					/*Velocidade de transmissão*/
	unsigned int sequenceNumber;	/*Número de sequência da trama: 0, 1*/
	unsigned int timeout;			/*Valor do temporizador: 1 s*/
	unsigned int numTransmissions;	/*Número de tentativas em caso de falha*/
	char frame[MAX_SIZE];			/*trama*/
public:
linkLayer();
	//linkLayer(char * port, int baudrate, unsigned int sequenceNumber, unsigned int timeout, unsigned int numTransmissions,char frame[MAX_SIZE]);
	void setFrame(char frame[MAX_SIZE]);
	char * getFrame(); 
	int llopen(char ** arg, int &fd, int status);
	int llwrite(int fd, unsigned char * buffer);
	int llread(int fd, unsigned char * buffer);
	int llclose(int &fd);
	
};
#endif
