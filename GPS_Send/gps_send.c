#include"gps.h"

void network_send(){//发送数据
	
	struct sockaddr_in server_addr;
	int sockfd, sockaddr_size, send_byte;
	int ret;
	//char buff[512];	
	//sockaddr_size = sizeof(struct sockaddr_in);
	if(sockfd == -1){
		perror("socket");
		exit(1);
	}

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT);
	server_addr.sin_addr.s_addr = inet_addr("192.168.1.101");//i服务器p地址
	bzero(&(server_addr.sin_zero),8);
	while(1){
	
		sockfd = socket(AF_INET,SOCK_STREAM,0);
		ret = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr));
		if(ret == -1){
			perror("connect");
			//exit(1);
		}
		printf("\nto connect successfuly\n");
		printf("send the inforeadly:");
		while(1){
			send_byte = send(sockfd, &p, sizeof(struct gps), 0);
			if(send_byte == -1){
				perror("send");
				//exit(1);
				break;
			}
			if(send_byte == 0){
				printf("send end\n");
				break;
			}
			if(send_byte > 0){
				//printf("the byte of the gps info:%d\n",send_byte);
			}
			sleep(100);
		}
		close(sockfd);	
	}
}
