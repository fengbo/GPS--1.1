#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<termios.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>

#define PORT 5000


#define baudrate B9600
#define MODEMDEVICE "/dev/ttySAC2"
#define _POSIX_SOURCE 1

void receive_gps_info(char *buf);
void set_uart_conifg();
void network_send();

/*
struct gps{//数据保存到结构体
	int *tim, *satel;//获取时间和卫星数
	char *longitu, *latitu, *precis, *high, *righ;//精度和纬度 精确度 海拔 精度
} *gps_info;
*/
struct gps{//将采集的数据放到结构体中
	int time[20];//时间
	char longitude[12];//经度
	char earth_E_W;//半球
	char latitude[12];//纬度
	char earth_N_S;//半球
	int satellite[2];//卫星数
	char precision[4];//水平精度
	char hight[8];//离海平面的水平高度
	char right;//精度
	char danwei ;//单位

} p;
