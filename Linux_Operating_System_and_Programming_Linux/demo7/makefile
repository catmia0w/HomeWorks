all:7-1 7-2 7-3
7-1:7-1.c
	gcc 7-1.c -o 7-1  -lmysqlclient -I/usr/include/mysql/ -L/usr/lib/mysql
7-2:7-2.c
	gcc 7-2.c -o 7-2  -lmysqlclient -I/usr/include/mysql/ -L/usr/lib/mysql
7-3:7-3.c
	gcc 7-3.c -o 7-3  -lmysqlclient -I/usr/include/mysql/ -L/usr/lib/mysql
.PHONY : clean
clean :
	-rm edit $(objects)