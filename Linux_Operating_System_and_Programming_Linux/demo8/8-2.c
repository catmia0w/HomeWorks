//程序清单 8-2
/*  Make the necessary includes and set up the variables.  */

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    int server_sockfd, client_sockfd;
    int server_len, client_len;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;
    char string[256];
    char *ans = "yes!";

/*  Create an unnamed socket for the server.  */

    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

/*  Name the socket.  */

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = htons(9734);
    server_len = sizeof(server_address);
    bind(server_sockfd, (struct sockaddr *)&server_address, server_len);

/*  Create a connection queue and wait for clients.  */

    listen(server_sockfd, 5);
    while(1) {
        char ch;

        printf("server waiting\n");

/*  Accept a connection.  */

        client_len = sizeof(client_address);
        client_sockfd = accept(server_sockfd, 
            (struct sockaddr *)&client_address, &client_len);

	printf("Now,client request come in.\n");
	printf("client_address = %s\tclient_port = %u\n",inet_ntoa(client_address.sin_addr),htons(client_address.sin_port));

/*  We can now read/write to client on client_sockfd.  */

        read(client_sockfd, string, sizeof(string));
	printf("client send: %s\n",string);
        write(client_sockfd, ans, sizeof(ans));
        close(client_sockfd);
    }
    close(server_sockfd);
}

