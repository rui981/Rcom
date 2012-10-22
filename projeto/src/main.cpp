/*Non-Canonical Input Processing*/


#include "linklayer.h"


int main(int argc, char** argv)
{
    int fd,c, res;
    struct termios oldtio,newtio;
    
   unsigned char buf[255]; //write/read

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
  
   //////////////////////////////////////////OPEN//////////////////////////// 
linkLayer lala;
lala.llopen(argv,fd,RECEIVER);
////////////////////////////////////////////////////////////////////</OPEN>/////////////////////////////////////////////////////////////////
int i=0;
char estado='I';
   /////////////////////////////////////////////////////////READ////////////////////////////////////////////////// 
       /* loop for input */
      res = read(fd,buf,5);   /* returns after 4 chars have been input */
     // buf[res]=0;               /* so we can printf... */
      printf(":%s:%d\n", buf, res);
	printf("res = %d\n", res);
	printf("buff 0 = %#x\n", buf[0]);
	printf("buff 1 = %#x\n", buf[1]);
	printf("buff 2 = %#x\n", buf[2]);
	printf("buff 3 = %#x\n", buf[3]);
	printf("buff 4 = %#x\n", buf[4]);
	

int counter=0;
do{
	
	switch(estado){
	

	case'I':
		printf("caso I\n");
		printf("Estado: %c\t", estado);

		//printf("recebi a flag");
		estado='F';
		printf("Novo estado: %c\n", estado);
		 
		break;

	case'F':
		printf("caso F\n");
		printf("Estado: %c\t", estado);
		if(buf[0]==0x7E){
			estado='A';
		}
		else{
			estado='I';
		}
		printf("Novo estado: %c\n", estado);
		counter++;		
		break;
	case'A':
			printf("caso A\n");
			printf("Estado: %c\t", estado);
			if(buf[1]==0x03){
				estado='C';
			}
			else{
				estado='p';
			}
			printf("Novo estado: %c\n", estado);
			counter++;
			break;
	case'C':
			printf("caso C\n");
			printf("Estado: %c\t", estado);
			if(buf[2]==0xf0){
				estado='B';
			}
			else{
				estado='p';
			}
			printf("Novo estado: %c\n", estado);
			counter++;
			break;




	case'B':
			printf("caso B\n");
			printf("Estado: %c\t", estado);
			//unsigned char bcc =0xfffffff3;
			if(buf[3]==0xf3){
				estado='f';
			}
			else{
				estado='p';
			}
			printf("Novo estado: %c\n", estado);
			counter++;
			break;

	
	case'f':
			printf("caso f\n");
			printf("Estado: %c\t", estado);
			
			if(buf[4]==FLAG){
				estado='e';
			}
			else{
				estado='p';
			}
			printf("Novo estado: %c\n", estado);
			
			break;

	case'p':
			printf("MERDOU\n");
			printf("Estado: %c\t", estado);
			sleep(50);
			
			
			break;
	
	

}
	
}while(estado!='e');
	printf("acabei");



	/*if (buf[i]=='O')
	{ 
	 printf("Recebi o O\n");
	i++;
    	}
	if (buf[i]=='l')
	{ 
	 printf("Recebi o l\n");
	i++;
    	}
	if (buf[i]=='a')
	{ 
	 printf("Recebi o a\n");
	i++;
    	}
	if (buf[i]=='\0')
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
}*/



  /* 
    O ciclo WHILE deve ser alterado de modo a respeitar o indicado no guião 
  */

//////////////////////////////////////////CLOSE///////////////////////////////////////////////
    tcsetattr(fd,TCSANOW,&oldtio);
    close(fd);
    return 0;
}
