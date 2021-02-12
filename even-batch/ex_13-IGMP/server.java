import java.io.IOException;
import java.net.*;
import java.util.Scanner;

public class server
{
  public static void main(String[] args)
  {
    try
    {
  String msg;
  DatagramSocket s = new DatagramSocket();
  byte[] line = new byte[100];
  Scanner sc=new Scanner(System.in);
  System.out.print("");
   System.out.print("How many times to communicate\n");
                    int n=sc.nextInt();
                    System.out.print("\nEnter the port no");
               int port = sc.nextInt();
      MulticastSocket ms=new MulticastSocket(port);
                   // while(n>0)
                   // {
    System.out.print("Enter the Message to send: ");
    int len = System.in.read(line);
    InetAddress dest = InetAddress.getByName("239.255.255.255");
    DatagramPacket pkt = new DatagramPacket(line, len, dest, port);
    s.send(pkt);
    do{
    DatagramPacket pkt1 = new DatagramPacket(line, len, dest, port);
     ms.receive(pkt1);
     msg =new String(pkt1.getData());
     System.out.println("\n The mSg is "+pkt1.getAddress()+"and message is"+msg.trim());
    }while(!msg.trim().equals("Bye"));
//  n--;
    }               // }

     catch (IOException err)
    {
      System.err.println(err);
    }
  }
}

