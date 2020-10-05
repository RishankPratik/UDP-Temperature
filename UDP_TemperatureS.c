#include<stdio.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<string.h>
#include<stdlib.h>
#define MAX 10
#define PORT 43454
#define SA struct sockaddr
void func(int sockfd)
{
char buff[MAX];
int i,clen,counter=0;
struct sockaddr_in cli;
clen=sizeof(cli);
char city[10][10]={"delhi","chennai","jamshedpur","ranchi"};
int temp[5]={40,41,42,43};
bzero(buff,MAX);
recvfrom(sockfd,buff,sizeof(buff),0,(SA *)&cli,&clen);

for(i=0;i<4;i++)
{
    if(strcmp(city[i],buff)==0)
    {
        printf("%s is %d degree ",city[i],temp[i]);
        
    }
    else     
    counter++;
}
if(counter==4)
{
printf("No such data found");}
//label:
bzero(buff,MAX);
}
int main()
{
int sockfd;
struct sockaddr_in servaddr;
sockfd=socket(AF_INET,SOCK_DGRAM,0);
if(sockfd==-1)
{
printf("socket creation failed...\n");
exit(0);
}
else
printf("Socket successfully created..\n");
bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
servaddr.sin_port=htons(PORT);
if((bind(sockfd,(SA *)&servaddr,sizeof(servaddr)))!=0)
{
printf("socket bind failed...\n");
exit(0);
}
else
printf("Socket successfully binded..\n");
func(sockfd);
close(sockfd);
}
