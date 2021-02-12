import java.io.IOException;
import java.net.*;
import java.util.Scanner;
public class client
{
 public static void main(String[] args)
        {
                try
                {
                    byte[] line = new byte[100];
                    DatagramSocket s= new DatagramSocket();
                    Scanner sc=new Scanner(System.in);
                    System.out.print("");
                    System.out.print("\nEnter the Port no");
                    int port = sc.nextInt();
                    MulticastSocket ms = new MulticastSocket(port);
                    ms.joinGroup(InetAddress.getByName("239.255.255.255"));
                    String msg;
                    do
                    {
                        DatagramPacket pkt = new DatagramPacket(line, line.length);
                        ms.receive(pkt);
                        msg = new String(pkt.getData());
                        System.out.println("IP Address: "+pkt.getAddress()+" and Message: "+msg.trim());

                   System.out.print("\n Enter Msg : ");
                  int len=System.in.read(line);
                  InetAddress dest=InetAddress.getByName("239.255.255.255");
                  DatagramPacket pkt1=new DatagramPacket(line,len,dest,port);
                  s.send(pkt1);
		ms.receive(pkt1);
                        msg = new String(pkt1.getData());
                        System.out.println("IP Address: "+pkt1.getAddress()+" and Message: "+msg.trim());

                    } while (!msg.trim().equals("Bye"));
                }

                catch (IOException err)
                {
                    System.err.println(err);
                }
        }
}
