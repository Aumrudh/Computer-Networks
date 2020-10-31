#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  int sd, c, len;
  char msg[100];
  struct sockaddr_in server, client;
  server.sin_family = AF_INET;
  printf("Enter the port no : ");
  int portno;
  scanf("%d", &portno);
  server.sin_port = htons(portno);
  server.sin_addr.s_addr = htonl(INADDR_ANY);

  // socket creation

  sd = socket(AF_INET, SOCK_STREAM, 0);
  if (sd == -1) {
    printf("Socker=t creation failed\n");
    exit(0);
  } else {
    printf("Socket Created\n");
  }

  // connection establishment

  len = sizeof(server);
  c = connect(sd, (const struct sockaddr *)&server, len);
  if (c == -1) {
    printf("Connection failed\n");
    exit(0);
  } else {
    printf("Connection established\n");
  }
  printf("Enter client message : ");
  scanf("%s", msg);
  send(sd, msg, 100, 0);
  recv(sd, msg, 100, 0);
  int n = atoi(msg);
  printf("n= %d\n", n);
  int hope[25], coste[25];
  if (recv(sd, hope, 20, 0) < 0) {
    printf("Error");
  }
  recv(sd, coste, 20, 0);
  printf("\nDEST\tNEXTHOP\tCOST\n");
  for (int i = 0; i < n; i++) {
    printf("%d\t%d\t%d\n", i + 1, hope[i], coste[i]);
  }
  close(sd);
}
