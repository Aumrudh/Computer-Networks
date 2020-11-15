#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#define cls() printf("\n")

// structure definition for accepting the packets.

struct frame

{

  int packet[40];
};

// structure definition for constructing the acknowledgement frame

struct ack

{

  int acknowledge[40];
};

int main()

{

  int clientsocket;

  struct sockaddr_in serveraddr;

  socklen_t len;

  struct hostent *server;

  struct frame f1;

  int windowsize, totalpackets, totalframes, i = 0, j = 0, framesreceived = 0,
                                             k, l, m, repacket[40];

  struct ack acknowledgement;

  char req[50];

  char name[20] = {0}; // in case of single character input
  fd_set input_set;
  struct timeval timeout;
  int ready_for_reading = 0;

  clientsocket = socket(AF_INET, SOCK_DGRAM, 0);

  bzero((char *)&serveraddr, sizeof(serveraddr));

  serveraddr.sin_family = AF_INET;

  serveraddr.sin_port = htons(5018);

  server = gethostbyname("127.0.0.1");

  bcopy((char *)server->h_addr, (char *)&serveraddr.sin_addr.s_addr,
        sizeof(server->h_addr));

  // establishing the connection.

  printf("\nSending request to the client.\n");

  sendto(clientsocket, "HI I AM CLIENT.", sizeof("HI I AM CLIENT."), 0,
         (struct sockaddr *)&serveraddr, sizeof(serveraddr));

  printf("\nWaiting for reply.\n");

  recvfrom(clientsocket, req, sizeof(req), 0, (struct sockaddr *)&serveraddr,
           &len);

  printf("\nThe server has send:\t%s\n", req);

  // accepting window size from the user.

  printf("\nEnter the window size:\t");

  scanf("%d", &windowsize);

  // sending the window size.

  printf("\n\nSending the window size.\n");

  sendto(clientsocket, (char *)&windowsize, sizeof(windowsize), 0,
         (struct sockaddr *)&serveraddr, sizeof(serveraddr));

  cls();

  // collecting details from server.

  printf("\nWaiting for the server response.\n");

  recvfrom(clientsocket, (char *)&totalpackets, sizeof(totalpackets), 0,
           (struct sockaddr *)&serveraddr, &len);

  printf("\nThe total packets are:\t%d\n", totalpackets);

  sendto(clientsocket, "RECEIVED.", sizeof("RECEIVED."), 0,
         (struct sockaddr *)&serveraddr, sizeof(serveraddr));

  recvfrom(clientsocket, (char *)&totalframes, sizeof(totalframes), 0,
           (struct sockaddr *)&serveraddr, &len);

  printf("\nThe total frames/windows are:\t%d\n", totalframes);

  sendto(clientsocket, "RECEIVED.", sizeof("RECEIVED."), 0,
         (struct sockaddr *)&serveraddr, sizeof(serveraddr));

  // starting the process.

  printf("\nStarting the process of receiving.\n");

  j = 0;

  l = 0;

  while (l < totalpackets)

  { // initialising the receive buffer.

    printf("\nInitialising the receive buffer.\n");

    printf("\nThe expected frame is %d with packets:  ", framesreceived);

    for (m = 0; m < j; m++)

    { // readjusting for packets with negative acknowledgement.

      printf("%d  ", repacket[m]);
    }

    while (j < windowsize && i < totalpackets)

    {

      printf("%d  ", i);

      i++;

      j++;
    }

    printf("\n\nWaiting for the frame.\n");

    // accepting the frame.

  label:
    recvfrom(clientsocket, (char *)&f1, sizeof(f1), 0,
             (struct sockaddr *)&serveraddr, &len);

    printf("\nReceived frame %d\n\nEnter -1 to send negative acknowledgement "
           "for the following packets.\n",
           framesreceived);

    // constructing the acknowledgement frame.

    // printf("1-no ack(after 10 sec type )\n2-ack..enter choice : ");
    // int choice;
    // scanf("%d",&choice);
    // if( choice == 1 ){
    timeout.tv_sec = 5;
    timeout.tv_usec = 0;
    printf("Enter name : \n");
    FD_SET(0, &input_set);
    ready_for_reading = select(1, &input_set, NULL, NULL, &timeout);
    if (ready_for_reading) {
      scanf("%s", name);
    } else {
      printf(" 5 Seconds are over - no data input \n");
      char msg[10] = "-2";
      sendto(clientsocket, msg, sizeof(msg), 0, (struct sockaddr *)&serveraddr,
             sizeof(serveraddr));
      goto label;
      //}

      j = 0;

      m = 0;

      k = l;
      while (m < windowsize && k < totalpackets)

      {

        printf("\nPacket: %d\n", f1.packet[m]);

        // accepting acknowledgement from the user.
        /* timeout.tv_sec = 5;
         timeout.tv_usec = 0;
         printf("Enter name : \n");
         FD_SET(0, &input_set);
         ready_for_reading = select(1, &input_set, NULL, NULL, &timeout);
         if (ready_for_reading) {
           scanf("%s" , name);
           }
         else {
             printf(" 5 Seconds are over - no data input \n");
             acknowledgement.acknowledge[m] = -2;
             sendto(clientsocket, (char *)&acknowledgement,
         sizeof(acknowledgement), 0, (struct sockaddr *)&serveraddr,
         sizeof(serveraddr)); goto label;
           }
           */
        scanf("%d", &acknowledgement.acknowledge[m]);
        // sprintf(acknowledgement.acknowledge[m],"%s",name);
        // acknowledgement.acknowledge[m]=atoi(name);
        if (acknowledgement.acknowledge[m] == -1)

        {

          repacket[j] = f1.packet[m];

          j++;

        }

        else

        {

          l++;
        }

        m++;

        k++;
      }

      framesreceived++;

      // sending acknowledgement to the server.

      sendto(clientsocket, (char *)&acknowledgement, sizeof(acknowledgement), 0,
             (struct sockaddr *)&serveraddr, sizeof(serveraddr));

      cls();
    }

    printf("\nAll frames received successfully.\n\nClosing connection with the "
           "server.\n");

    close(clientsocket);
  }
