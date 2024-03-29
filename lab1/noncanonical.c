/*Non-Canonical Input Processing*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <stdio.h>

#define BAUDRATE B38400
#define _POSIX_SOURCE 1 /* POSIX compliant source */
#define FALSE 0
#define TRUE 1
#define A 0x01
#define FLAG 0x10F46

volatile int STOP=FALSE;

int main(int argc, char** argv)
{
    int fd,c, res;
    struct termios oldtio,newtio;
    char buf[255];

    if ( (argc < 2) || 
  	     ((strcmp("/dev/ttyS0", argv[1])!=0) && 
  	      (strcmp("/dev/ttyS1", argv[1])!=0) )) {
      printf("Usage:\tnserial SerialPort\n\tex: nserial /dev/ttyS1\n");
      exit(1);
    }


  /*
    Open serial port device for reading and writing and not as controlling tty
    because we don't want to get killed if linenoise sends CTRL-C.
  */
  
    
    fd = open(argv[1], O_RDWR | O_NOCTTY );
    if (fd <0) {perror(argv[1]); exit(-1); }

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
    newtio.c_cc[VMIN]     = 4;   /* blocking read until 4 chars received */



  /* 
    VTIME e VMIN devem ser alterados de forma a proteger com um temporizador a 
    leitura do(s) pr�ximo(s) caracter(es)
  */



    tcflush(fd, TCIOFLUSH);
    

    if ( tcsetattr(fd,TCSANOW,&newtio) == -1) {
      perror("tcsetattr");
      exit(-1);
    }

    printf("New termios structure set\n");


  //while (STOP==FALSE) {       /* loop for input */
    //res = read(fd,buf,4);   /* returns after 4 chars have been input */
    //buf[res]=0;               /* so we can printf... */
    //printf(":%s:%d\n", buf, res);
/*
	if (buf[res]=='O')
	{ 
	 printf("Recebi o O\n");
	res++;
    	}
	if (buf[res]=='l')
	{ 
	 printf("Recebi o l\n");
	res++;
    	}
	if (buf[res]=='a')
	{ 
	 printf("Recebi o a\n");
	res++;
    	}
	if (buf[res]=='\0')
	{ 
	 STOP=TRUE;
	printf("Done: ");
	printf("%s", buf);
    	}
	else
	{
	printf("FUUU\n");
	STOP=TRUE;
	}
}
*/
res = read(fd,buf,5);
if(buf[0]=FLAG && buf[1]=A && buf[2]=C && buf[3]=BCC && buf[4]=FLAG){
printf("okapa");
}else{
printf("non okapa");
}





/*char state=I;
switch(state){
case 'I':
	printf("Comecar a transmicao");
	if(buf[0]=FLAG)
	state='F';
	state= 'I';
	break;	

case 'F' : 
	printf("Estado  FLAG");
	if(buf[1]=A)
	state 'A';
	break;
case 'A' : 
	buf[2]=C
	break;
case 'C' : 
	break;
case 'B' : 
	break;
case 'f' : 
	break;
default: state ='I' ;
break;
}*/

  /* 
    O ciclo WHILE deve ser alterado de modo a respeitar o indicado no gui�o 
  */


    tcsetattr(fd,TCSANOW,&oldtio);
    close(fd);
    return 0;
}
