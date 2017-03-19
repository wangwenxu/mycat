#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#define BUFFERSIZE 1024
int main(int argc,char *argv[])
{
  int openfile;
  int byteread;
  char buffer[BUFFERSIZE];
  char *ptr;
  
  if(argc!=2)
  {
    printf("parameter fault");
    exit(1);
  }
  if((openfile=open(argv[1],O_RDONLY))==-1)
  {
    printf("open file %s error!!!\n",argv[1]);
    exit(1);
  }
  while(byteread=read(openfile,buffer,BUFFERSIZE))
  {
    if((byteread==-1))
      break;
    else if(byteread>0)
    {
      if(byteread<1024)
        buffer[byteread+1]='\0';
      printf("%s",buffer);
    }
  }
  close(openfile);
  exit(0);
}
