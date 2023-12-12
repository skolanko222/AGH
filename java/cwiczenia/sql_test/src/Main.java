import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.sql.Connection;
import com.jcraft.jsch.*;


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter username: ");
        String username = br.readLine();
        System.out.println("Enter password: ");
        String password = br.readLine();


        PostgresSQLConnection connection = new PostgresSQLConnection('u' + username, username);

        if (connection.forwardConnect(2137, "pascal.fis.agh.edu.pl",5432,username, password)) {
            System.out.println("Connection established");
        } else {
            System.out.println("Connection failed");
        }

        while (true) {
            System.out.println("Enter command: ");
            String command = br.readLine();
            if (command.equals("exit")) {
                connection.close();
                break;
            }
            connection.executeCommand(command);
        }
        System.out.println("Connection closed");
        System.exit(0);
    }
}