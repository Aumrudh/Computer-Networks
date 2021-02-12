import java.net.*; 
import java.io.*; 
import java.util.Scanner;
public class Server{  
    private int port;
	private Socket sd=null;
	private ServerSocket server= null; 
	private DataInputStream in=null;

	public Server(int port){
		try{
            //creation of socket
			server=new ServerSocket(port);

            System.out.println("Server started"); 
  
            System.out.println("Waiting for a client ..."); 
            
            //accepting client request
            sd = server.accept(); 

            System.out.println("Client accepted"); 
		      
             // takes input from the client socket 
            in = new DataInputStream(new BufferedInputStream(sd.getInputStream())); 
            String msg = "";
            // reads message from client until "bye" is sent 
            while (!msg.equals("bye")){ 
            	try{ 
                    msg = in.readUTF(); 
                    System.out.println("Client Message : "+msg);
                    int i = 0, j = msg.length() - 1; 
                    String result=msg;
                    //check for palindrom
        			while (i < j) {   
            			if (msg.charAt(i++) != msg.charAt(j--)){
            				result=" is not palindrome!";
               				break;
            			}
            			result=" is palindrome!";
                	}
                    //send result to client
                    PrintWriter out=new PrintWriter(sd.getOutputStream(),true);
                    out.println(result); 
                }
                catch(Exception i){ 
                    	System.out.println(i); 
               	}             
			}
            System.out.println("Closing connection");
            sd.close();		

		}
        catch(Exception i){ 
            System.out.println(i); 
        }
         
	}
    public static void main(String args[]){
        Scanner input=new Scanner(System.in);
        System.out.print("Enter port no : ");
        int portno=input.nextInt();
        Server obj=new Server(portno);
    }
}

