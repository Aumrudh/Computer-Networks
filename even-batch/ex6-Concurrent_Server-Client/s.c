 #include<stdio.h>

  #include<stdlib.h>

  #include<unistd.h>

  #include<sys/types.h>

  #include<arpa/inet.h>

  #include<sys/socket.h>

  #include<netinet/in.h>

  #include<string.h>

  int main() {
    int sid, sid1, len, r, cid, c;
    char * buf;
    struct sockaddr_in ser, cli;
    buf = (char * ) malloc(50 * sizeof(char));
    sid = socket(AF_INET, SOCK_DGRAM, 0);
    if (sid == -1) {
      perror("socket");
      exit(1);
    }
    ser.sin_family = AF_INET;
    ser.sin_port = htons(2029);
    inet_aton("127.0.0.1", & ser.sin_addr);
    r = bind(sid, (struct sockaddr * ) & ser, sizeof(ser));
    if (r == -1) {
      perror("bind");
    }
    c = sizeof(cli);
    r = recvfrom(sid, buf, sizeof(buf), 0, (struct sockaddr * ) & cli, & c);
    if (r == -1) {
      perror("recvfrom");
    }
    printf("the received data:\n");
    printf("%s\n", buf);
    cid = fork();
    {         {
      if (cid != 0) {
        while (strcmp(buf, "over")) {
          r = recvfrom(sid, buf, sizeof(buf), 0, (struct sockaddr * ) & cli, & c);
          if (r == -1) {
            perror("recvfrom");
          }
          printf("Client's data:\n");
          printf("%s\n", buf);
        }
      } else {
        while (strcmp(buf, "over")) {
          printf("enter the data:\n");
          scanf("%s", buf);

          r = sendto(sid, buf, sizeof(buf), 0, (struct sockaddr * ) & cli, sizeof(cli));
          if (r == -1) {
            perror("sendto");
          }
        }
        r = shutdown(sid, 2);
        if (r == -1) {
          perror("shutdown");
        }
        r = close(sid);
        if (r == -1) {
          perror("close");
        }
        //       }
      }
    }
  }
}
