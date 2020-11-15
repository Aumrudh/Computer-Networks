#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include<time.h>
#define cls() printf("\n")

// structure definition for designing the packet.

struct frame

{

  int packet[40];
};

// structure definition for accepting the acknowledgement.

struct ack

{

  int acknowledge[40];
};

int main()

{

  int serversocket;

  struct sockaddr_in serveraddr, clientaddr;

  socklen_t len;

  int windowsize, totalpackets, totalframes, framessend = 0, i = 0, j = 0, k, l,
                                             m, n, repacket[40];

  struct ack acknowledgement;

  struct frame f1;

  char req[50];
 
   time_t begin , end ;

  serversocket = socket(AF_INET, SOCK_DGRAM, 0);

  bzero((char *)&serveraddr, sizeof(serveraddr));

  serveraddr.sin_family = AF_INET;

  serveraddr.sin_port = htons(5018);

  serveraddr.sin_addr.s_addr = INADDR_ANY;

  bind(serversocket, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
  
  bzero((char *)&clientaddr, sizeof(clientaddr));

  len = sizeof(clientaddr);

  // connection establishment.

  printf("\nWaiting for client connection.\n");

  recvfrom(serversocket, req, sizeof(req), 0, (struct sockaddr *)&clientaddr,
           &len);

  printf("\nThe client connection obtained.\t%s\n", req);

  // sending request for windowsize.

  printf("\nSending request for window size.\n");

  sendto(serversocket, "REQUEST FOR WINDOWSIZE.",
         sizeof("REQUEST FOR WINDOWSIZE."), 0, (struct sockaddr *)&clientaddr,
         sizeof(clientaddr));

  // obtaining windowsize.

  printf("\nWaiting for the windowsize.\n");

  recvfrom(serversocket, (char *)&windowsize, sizeof(windowsize), 0,
           (struct sockaddr *)&clientaddr, &len);

  cls();

  printf("\nThe windowsize obtained as:\t%d\n", windowsize);

  printf("\nObtaining packets from network layer.\n");

  printf("\nTotal packets obtained:\t%d\n", (totalpackets = windowsize * 5));

  printf("\nTotal frames or windows to be transmitted:\t%d\n",
         (totalframes = 5));

  // sending details to client.

  printf("\nSending total number of packets.\n");

  sendto(serversocket, (char *)&totalpackets, sizeof(totalpackets), 0,
         (struct sockaddr *)&clientaddr, sizeof(clientaddr));

  recvfrom(serversocket, req, sizeof(req), 0, (struct sockaddr *)&clientaddr,
           &len);

  printf("\nSending total number of frames.\n");

  sendto(serversocket, (char *)&totalframes, sizeof(totalframes), 0,
         (struct sockaddr *)&clientaddr, sizeof(clientaddr));

  recvfrom(serversocket, req, sizeof(req), 0, (struct sockaddr *)&clientaddr,
           &len);

  printf("\nPRESS ENTER TO START THE PROCESS.\n");

  fgets(req, 2, stdin);

  cls();

  j = 0;

  l = 0; // starting the process of sending

  while (l < totalpackets)

  {

    // initialising the transmit buffer.

    bzero((char *)&f1, sizeof(f1));

    printf("\nInitialising the transmit buffer.\n");

    printf("\nThe frame to be send is %d with packets:\t", framessend);

    // Builting the frame.

    for (m = 0; m < j; m++)

    {

      // including the packets for which negative acknowledgement was received.

      printf("printing repacket :  %d  ", repacket[m]);

      f1.packet[m] = repacket[m];
    }

    while (j < windowsize && i < totalpackets)

    {

      printf("\nassigning vlaue to pakcet : %d  ", i);

      f1.packet[j] = i;

      i++;

      j++;
    }

label:  //printf("\nSending frame %d\n", framessend);

    // sending the frame.

   sendto(serversocket, (char *)&f1, sizeof(f1), 0,
           (struct sockaddr *)&clientaddr, sizeof(clientaddr));

    // Waiting for the acknowledgement.

  //  printf("\nWaiting for the acknowledgement.\n");
    begin = time(NULL);
    char msg[10];
    recvfrom(serversocket, msg, sizeof(msg), 0,
             (struct sockaddr *)&clientaddr, &len);
    end = time(NULL);
    cls();

    // Checking acknowledgement of each packet.

    if (difftime(end,begin) >= 10 ){
      printf("retrainsmitting\n");
      goto label;
    }


    j = 0;

    k = 0;

    m = 0;

    n = l;

    while (m < windowsize && n < totalpackets)

    {
   	
      if (acknowledgement.acknowledge[m] == -1)

      {

        printf("\nNegative acknowledgement received for packet: %d\n",
               f1.packet[m]);

        k = 1;

        repacket[j] = f1.packet[m];

        j++;

      }

      else

      {

        l++;
      }

      m++;

      n++;
    }

    if (k == 0)

    {

      printf("\nPositive acknowledgement received for all packets within the "
             "frame: %d\n",
             framessend);
    }

    framessend++;

    printf("\nPRESS ENTER TO PROCEED……\n");

    fgets(req, 2, stdin);

    cls();
  }

  printf("\nAll frames send successfully.\n\nClosing connection with the "
         "client.\n");

  close(serversocket);
}
