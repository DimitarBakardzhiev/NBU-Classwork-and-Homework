import java.io.*;
import java.net.*;

public class Client {

	public static void main(String[] args) throws UnknownHostException, IOException {
		Socket sock = new Socket("localhost", Server.PORT);
		
		OutputStream out = sock.getOutputStream();
		InputStream in = sock.getInputStream();
		
		PrintStream ps = new PrintStream(out);
		ps.println("Hello to server from client!");
		
		InputStreamReader inputStreamReader = new InputStreamReader(in);
		BufferedReader bufferedReader = new BufferedReader(inputStreamReader);
		
		String message = bufferedReader.readLine();
		System.out.println(message);
		
		out.close();
		in.close();
		sock.close();

	}

}
