import java.io.*;
import java.net.*;
import java.util.ArrayList;
import java.util.Scanner;

public class ChatServer {

	public static ArrayList<Socket> connectionArray = new ArrayList<Socket>();
	public static ArrayList<String> currentUsers = new ArrayList<String>();
	
	public static void main(String[] args) {
		try {
			final int PORT = 4444;
			ServerSocket server = new ServerSocket(PORT);
			System.out.println("Waiting for clients...");
			
			while (true) {
				Socket sock = server.accept();
				connectionArray.add(sock);
				
				System.out.println("Client connected from: " + sock.getLocalAddress().getHostName());
				
				addUsername(sock); // TODO
				
				ChatServerReturn chat = new ChatServerReturn(sock); // TODO
				Thread newThread = new Thread(chat);
				newThread.start();
			}
			
			
			
		} catch (Exception e) {
			System.out.println(e);
		}
	}

	private static void addUsername(Socket sock) throws IOException {
		Scanner input = new Scanner(sock.getInputStream());
		String username = input.nextLine();
		currentUsers.add(username);
		
		for (Socket socket : connectionArray) {
			PrintWriter out = new PrintWriter(socket.getOutputStream());
			out.println(currentUsers);
			out.flush();
		}
	}
}
