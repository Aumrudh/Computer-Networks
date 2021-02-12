import java.net.*; 
import java.io.*; 
import java.util.Scanner;

public class Client{
	private static final String Server_IP="127.0.0.1";
	private int port;
	private Socket sd=null;
	private ServerSocket server=null;
	private DataInputStream input= null; 
	private DataOutputStream out = null;  
	Client(int port){
		try{
			sd=new Socket(Server_IP,port);
			System.out.println("Connected");
			// takes input from terminal 
            input = new DataInputStream(System.in); 
  
            // sends output to the socket 
            out = new DataOutputStream(sd.getOutputStream()); 
        }
        catch(Exception i) 
        { 
            System.out.println(i); 
        } 
		// string to read message from input 
        
        String line = ""; 
  
        // keep reading until "bye" is input 
        while (!line.equals("bye")){ 
           	try{
           		System.out.print("Enter the word : ");
               	line = input.readLine();
               	//send input data to server for processing 
               	out.writeUTF(line);
               	//read input got from server
				BufferedReader ip=new BufferedReader(new InputStreamReader(sd.getInputStream()));
				String serverResponse=ip.readLine();
				System.out.println("Server output : "+line+serverResponse);
 
           	} 
           	catch(IOException i){ 
               	System.out.println(i); 
           	} 
        } 
 		try{
            input.close(); 
            out.close(); 
            sd.close(); 
        } 
        catch(IOException i){ 
            System.out.println(i); 
        } 
    } 
  
    public static void main(String args[]){ 
        Scanner input=new Scanner(System.in);
        System.out.print("Enter port no : ");
        int portno=input.nextInt();
        Client obj=new Client(portno);
    } 
}


//read input from keyboard

			//BufferedReader keyboard=new BufferedReader(new InputStreamReader(System.in()));
			//PrintWriter out = new PrintWriter(sd.getOutputStream(),true);
			//String command=keyboard.readLine();
			//out.println(command)

