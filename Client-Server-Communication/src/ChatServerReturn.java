import java.io.*;
import java.net.*;
import java.util.Scanner;

public class ChatServerReturn implements Runnable {

	private Socket sock;
	private Scanner input;
	private PrintWriter out;
	private String message = "";
	
	public ChatServerReturn(Socket sock) {
		this.sock = sock;
	}
	
	public void checkConnection() throws IOException {
		if (!this.sock.isConnected()) {
			for (Socket socket : ChatServer.connectionArray) {
				if (socket == this.sock) {
					ChatServer.connectionArray.remove(socket);
				}
			}
			
			for (Socket socket : ChatServer.connectionArray) {
				PrintWriter print = new PrintWriter(socket.getOutputStream());
				String message = socket.getLocalAddress().getHostName() + " disconnected!";
				print.println(message);
				print.flush();
				System.out.println(message);
			}
		}
	}

	@Override
	public void run() {
		try {
			try {
				this.input = new Scanner(this.sock.getInputStream());
				this.out = new PrintWriter(this.sock.getOutputStream());
				
				while (true) {
					this.checkConnection();
					
					if (!this.input.hasNext()) {
						return;
					}
					
					this.message = input.nextLine();
					
					System.out.println("Client said: " + this.message);
					
					for (Socket socket : ChatServer.connectionArray) {
						PrintWriter print = new PrintWriter(socket.getOutputStream());
						print.println(this.message);
						print.flush();
						System.out.println("Sent to: " + socket.getLocalAddress().getHostName());
					}
				}
			} finally {
				this.sock.close();
			}
		} catch (Exception e) {
			System.out.println(e);
		}
	}

}
