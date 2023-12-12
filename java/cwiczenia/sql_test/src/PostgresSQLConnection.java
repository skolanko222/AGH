import com.jcraft.jsch.JSch;
import com.jcraft.jsch.JSchException;
import com.jcraft.jsch.Session;

import java.sql.*;
import java.util.Arrays;
import java.util.Properties;

public class PostgresSQLConnection {
    private Connection connection = null;
    final String urlParam = "jdbc:postgresql://";
    final String localHost = "localhost";

    final private Properties props;

    PostgresSQLConnection(String username, String password) {

        props = new Properties();
        props.setProperty("user", username);
        props.setProperty("password", password);
//      props.setProperty("ssl", "true");

    }

    public boolean forwardConnect(int localPort, String remoteHost, int remotePort, String username, String password) {
        try {
            forwardPort(localPort, remoteHost, remotePort, username, password);
            String fullURL = urlParam + localHost + ":" + localPort + "/";
            this.connection = DriverManager.getConnection(fullURL, props);
            return true;
        } catch (Exception e) {
            System.out.println(e.getMessage());
            return false;
        }
    }
    public void close() {
        try {
            connection.close();
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
    }

    public void executeCommand(String command) {
        try {
            Statement statement = connection.createStatement();
            ResultSet resultSet = statement.executeQuery(command);
            ResultSetMetaData resultSetMetaData = resultSet.getMetaData();
            int columnsNumber = resultSetMetaData.getColumnCount();
            while (resultSet.next()) {
                for (int i = 1; i <= columnsNumber; i++) {
                    if (i > 1) System.out.print(",  ");
                    String columnValue = resultSet.getString(i);
                    System.out.print(columnValue + " " + resultSetMetaData.getColumnName(i));
                }
                System.out.println();
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    private void forwardPort(int localPort, String remoteHost, int remotePort, String username, String password) {
        System.out.println("Forwarding port " + localPort + " to " + remoteHost + ":" + remotePort);
        Session session;
        java.util.Properties config = new java.util.Properties();
        config.put("StrictHostKeyChecking", "no");
        try {
            session = new JSch().getSession(username, "pascal.fis.agh.edu.pl", 22);
            session.setConfig(config);
            session.setPassword(password);
            session.connect();
            session.setPortForwardingL(localPort, remoteHost, remotePort);
            System.out.println("Port Forwarded");
        } catch (JSchException e) {
                System.out.println("ERROR: while forwarding port:" +e.getMessage());
        }
    }


}
