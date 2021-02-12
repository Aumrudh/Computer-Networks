import java.io.*;
import java.net.*;
import java.util.*;
import java.lang.*; 

public class Client{
  public static void main(String[] args) throws IOException{
    try{
      System.out.print("Enter port no : ");
      Scanner in=new Scanner(System.in);
      int  port=in.nextInt();
      DatagramSocket sd = new DatagramSocket();
      
      // Get the IP address of the server
      InetAddress IPAddress = InetAddress.getByName("localhost");
      
      // Creating corresponding buffers
      String sentence;
      while(true){
      //byte[] sendingDataBuffer = new byte[1000];
      //byte[] receivingDataBuffer = new byte[1000];
      
      /* Converting data to bytes and 
      storing them in the sending buffer */
      System.out.print("Enter message : ");
      sentence = in.next();
      
      int length=0;
      for(char c: sentence.toCharArray()) {
         length++;
      }
      byte[] sendingDataBuffer = new byte[length];
      byte[] receivingDataBuffer = new byte[length];
      sendingDataBuffer = sentence.getBytes();
      
      // Creating a UDP packet 
      DatagramPacket sendingPacket = new DatagramPacket(sendingDataBuffer,sendingDataBuffer.length,IPAddress, port);
      
      // sending UDP packet to the server
      sd.send(sendingPacket);
      if(sentence.equals("bye")){
            System.out.println("Closing Connection");
            sd.close();
            System.exit(0);              
      }
      // Get the server response .i.e. capitalized sentence
      DatagramPacket receivingPacket = new DatagramPacket(receivingDataBuffer,receivingDataBuffer.length);
      sd.receive(receivingPacket);
      
      // Printing the received data
      String receivedData = new String(receivingPacket.getData());
      receivedData.trim();
      System.out.println("Sent from the server: "+receivedData);
      
      }
      // Closing the socket connection with the server
      
    }
    catch(SocketException e) {
      e.printStackTrace();
    }
  }
}
