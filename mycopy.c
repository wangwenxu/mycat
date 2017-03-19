#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<unistd.h>
#include<stdio.h>
int main(int argc,char *argv[])
{
  int fromfd,tofd;
  int byteread,bytewrite;
  char buffer[1024];
  char *ptr;
  if(argc!=3)
  {
    printf("parameter fault");
    exit(1);
  }
  if((fromfd=open(argv[1],O_RDONLY))==-1)
  {
    printf("fail to open source file");
    exit(1);
  }
  if((tofd=open(argv[2],O_WRONLY|O_CREAT,S_IWUSR))==-1)
  {
    printf("fail to create target file");
    exit(1);
  }
  while(byteread=read(fromfd,buffer,1024))
  {
    if((byteread==-1)&&(errno!=EINTR)) break;
    else if(byteread>0)
    {
      ptr=buffer;
      while(bytewrite=write(tofd,ptr,byteread))
      {
        if((bytewrite==-1)&&(errno!=EINTR)) break;
        else if(bytewrite==byteread) break;
        else if(bytewrite>0)
        {
          ptr+=bytewrite;
          byteread-=bytewrite;
        }
      }
      if(bytewrite==-1) break;

    }
  }
  close(fromfd);
  close(tofd);
  exit(0);
}
