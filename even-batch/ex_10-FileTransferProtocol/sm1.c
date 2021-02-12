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
  int sd, b, l, ad, len;
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

  // binding

  b = bind(sd, (struct sockaddr *)&server, sizeof(server));

  if (b == -1) {
    printf("Binding failed\n");
    exit(0);
  } else {
    printf("Binded\n");
  }

  // listen

  l = listen(sd, 5);
  if (l == -1) {
    printf("Listen failed\n");
    exit(0);
  } else {
    printf("Listening\n");
  }

  // accept

  len = sizeof(client);
  ad = accept(sd, (struct sockaddr *)&client, &len);
  if (ad == -1) {
    printf("Accept failed\n");
    exit(0);
  } else {
    printf("Accepted\n");
  }
  printf("Connection established\n------------Server Side--------------\n");
  int flag = 0;
  char r[100], rno[100], pass[100], temppass[100], m1[100], m2[100], m3[100];
  recv(ad, msg, 100, 0);
  strcpy(r, msg);
  printf("Roll Number : %s\n", msg);
  recv(ad, msg, 100, 0);
  FILE *f = fopen("login.txt", "r");
  while (!feof(f)) {
    fscanf(f, "%s", rno);
    fscanf(f, "%s", pass);
    if (strcmp(r, rno) == 0) {
      if (strcmp(msg, pass) == 0) {
        flag = 1;
        break;
      }
    }
  }
  fclose(f);
  int i = 0;
  if (flag == 1) {
    char msge[100] = "Correct password...";
    send(ad, msge, 100, 0);
    FILE *f1 = fopen("mark.txt", "r");
    // while(!feof(f1)){
    while (fscanf(f1, "%s %s %s %s", rno, m1, m2, m3) != EOF) {
      /*           fscanf(f1,"%s",rno);
                              fscanf(f1,"%s",m1);
                              fscanf(f1,"%s",m2);
                              fscanf(f1,"%s",m3);*/
      if (r[0] == 'F') {
        printf("rno :  %s\n", rno);
        printf("m1 : %s\n", m1);
        printf("m2 : %s\n", m2);
        printf("m3 : %s\n", m3);
        send(ad, rno, 100, 0);
        send(ad, m1, 100, 0);
        send(ad, m2, 100, 0);
        send(ad, m3, 100, 0);
        i = i + 1;
        printf("i is %d", i);
      } else {
        if (strcmp(r, rno) == 0) {
          /*	printf("rno :  %s\n",rno);
                  printf("m1 : %s\n",m1);
                  printf("m2 : %s\n",m2);
                  printf("m3 : %s\n",m3);*/
          send(ad, rno, 100, 0);
          send(ad, m1, 100, 0);
          send(ad, m2, 100, 0);
          send(ad, m3, 100, 0);
        }
      }
    }
    char t[100] = "bye";
    send(ad, t, 100, 0);
    fclose(f1);
  } else {
    char msge[100] = "Wrong password...";
    send(ad, msge, 100, 0);
  }
  close(sd);
}
