#ifndef LINKLAYER_H
#define LINKLAYER_H


#define MAX_SIZE 10

class linkLayer{
	char port[20];					/*Dispositivo /dev/ttySx, x = 0, 1*/
	int baudrate;					/*Velocidade de transmissão*/
	unsigned int sequenceNumber;	/*Número de sequência da trama: 0, 1*/
	unsigned int timeout;			/*Valor do temporizador: 1 s*/
	unsigned int numTransmissions;	/*Número de tentativas em caso de falha*/
	char frame[MAX_SIZE];			/*trama*/
public:
	linkLayer(char port[20], int baudrate, unsigned int sequenceNumber, unsigned int timeout, unsigned int numTransmissions,char frame[MAX_SIZE]);
	void setFrame(char frame[MAX_SIZE]);
	char * getFrame();
};
#endif
