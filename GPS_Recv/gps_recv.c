#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<errno.h>

#define PORT 5000
////////////////////////////////////////////////
int main(void){
	int sockfd, accept_fd;
	int size, numbytes;
	int ret_b, ret_l;
	char buf[512];
 	struct sockaddr_in myaddr;
 	struct sockaddr_in theiraddr;
 	//pid_t pid;
 	sockfd = socket(AF_INET,SOCK_STREAM,0);
 	if(sockfd < 0){
   		perror("sockfd\n");
   		exit(1);
  	}
 //////////初始结构体
  	myaddr.sin_family = AF_INET;
  	myaddr.sin_port = htons(PORT);
  	myaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  	bzero(&(myaddr.sin_zero),8); 
  
  	ret_b = bind(sockfd,(struct sockaddr *)&myaddr,sizeof(struct sockaddr));//绑定
  	if(ret_b < 0){
   		perror(" binding\n");
   		exit(1);
  	}
////////////////////////////////////////////////////////////////////////
  	ret_l = listen(sockfd, 8);///监听函数
  	if(ret_l < 0){
    		perror("listening\n");
    		exit(1);
  	}
  
  	printf("等待连接.............\n");  
  	while(1){
  		size=sizeof(struct sockaddr_in);
  		accept_fd=accept(sockfd,(struct sockaddr *)&theiraddr,&size);//连接收听端口
  		if(accept_fd < 0){
    			perror(" accept\n");
    			exit(1);
 		 }
   		printf("连接成功\n"); 	 
		memset(buf,0,sizeof(buf)); //清零
		while(1){
			numbytes = recv(accept_fd, buf, 100, 0);//接收函数
			if(numbytes == -1){
				perror("not accept the data!\n");
			}
			printf("received a message: %s\n",buf);
			if(numbytes == 0){//判断是否接收完
				break;
			}
		}
  	}
    	close(sockfd);
    	exit(0);
}
