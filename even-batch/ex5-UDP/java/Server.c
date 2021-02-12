import java.io.*;
import java.net.*;
import java.util.*;
import java.lang.*; 

public class Server{
  // Server UDP socket runs at this port
 
  public static void main(String[] args) throws IOException{
    System.out.print("Enter port no : ");
    Scanner in=new Scanner(System.in);
    int  port=in.nextInt();
    try{
        // Instantiate a new DatagramSocket to receive responses from the client
        DatagramSocket sd = new DatagramSocket(port);
        System.out.println("Waiting for a client to connect...");
        /* Create buffers to hold sending and receiving data.
        It temporarily stores data in case of communication delays */
        String receivedData;
        while(true){
        byte[] receivingDataBuffer = new byte[1000];
        //byte[] sendingDataBuffer = new byte[1000];
      
        /* Instantiate a UDP packet to store the 
        client data using the buffer for receiving data*/
        DatagramPacket inputPacket = new DatagramPacket(receivingDataBuffer, receivingDataBuffer.length);
        
      
        // Receive data from the client and store in inputPacket
        sd.receive(inputPacket);
      
        // Printing out the client sent data
        receivedData = new String(inputPacket.getData());
        receivedData=receivedData.trim();        
        System.out.println("Client Message : "+receivedData);
        if(receivedData.equals("bye")){
            System.out.println("Closing Connection");
            sd.close();
            System.exit(0);              
        }
        int length=0;
        String temp="";
        for(char c: receivedData.toCharArray()) {
         length++;
        }
        //System.out.println("Length : "+length);
        for(int i=length-1;i>=0;i--){
            temp= temp+ receivedData.charAt(i);
        }
         //System.out.println(temp);
        
        byte[] sendingDataBuffer = new byte[length];
        /*Convert client sent data string reverse,Convert it to bytes
        and store it in the corresponding buffer. */
        sendingDataBuffer = temp.getBytes();
      
        // Obtain client's IP address and the port
        InetAddress senderAddress = inputPacket.getAddress();
        int senderPort = inputPacket.getPort();
      
        // Create new UDP packet with data to send to the client
        DatagramPacket outputPacket = new DatagramPacket(
        sendingDataBuffer, sendingDataBuffer.length,
        senderAddress,senderPort
        );      
        // Send the created packet to client
        sd.send(outputPacket);        
        // Close the socket connection        
      }
    }
    catch (Exception e){
      System.out.println(e);
    }
  }
}
