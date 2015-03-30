import java.io.*;
import java.net.*;


public class Server {
	public static final int PORT = 4444;
	
	public static void main(String[] args) throws IOException {
		ServerSocket serverSocket = new ServerSocket(PORT);
		while (true) {
			Socket sock = serverSocket.accept();
		
			OutputStream out = sock.getOutputStream();
			InputStream in = sock.getInputStream();
			
			InputStreamReader inputStreamReader = new InputStreamReader(in);
			BufferedReader bufferedReader = new BufferedReader(inputStreamReader);
			
			String message = bufferedReader.readLine();
			System.out.println(message);
			
			if (message != null) {
				PrintStream ps = new PrintStream(out);
				ps.println("Message received!");
			}
		}
		
		/*in.close();
		out.close();
		inputStreamReader.close();
		bufferedReader.close();
		sock.close();
		serverSocket.close();*/
	}

}
