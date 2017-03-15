#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    struct in_addr inaddr;
    int rc;

    if(argc != 2){
	perror("usage: ./dd2hex <dotted-decimal>\n");
	exit(1);
    }

    rc = inet_pton(AF_INET, argv[1], &inaddr);

    if(rc == 0)
	perror("invalid address");
    else if (rc < 0)
	perror("inet_pton");

    printf("0x%x\n", ntohl(inaddr.s_addr));
    return 0;
}
