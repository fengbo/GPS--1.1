CC = arm-linux-gcc
send:gps_main.o gps_info.o gps_send.o 
	$(CC) -o send gps_main.o gps_info.o gps_send.o
gps_main.o:gps_main.c gps_info.c gps_send.c gps.h
	$(CC) -c gps_main.c
gps_info.o:gps_info.c gps.h
	$(CC) -c gps_info.c
gps_send.o:gps_send.c gps.h
	$(CC) -c gps_send.c
clean: 
	rm send
	rm *.o
