import java.io.BufferedReader;
import java.io.*;

/**
 * Klasa reprezentujaca tablice uzytkownikow z funkcja wczytywania z pliku
 * @author Szymon Kolanko
 */
public class DatabaseReader {
    /**
     * Tabela uzytkownikow
     */
    private User [] users;

    public DatabaseReader() {
        users = new User[0];
    }

    /**
     * Metoda wczytujaca uzytkownikow z pliku do tablicy w obiekcie klasy DatabaseReader
     * @param filepath nazwa pliku z danymi
     */
    public void readFromFile(String filepath){

        try{
            BufferedReader f = new BufferedReader(new FileReader(filepath));
            String line;
            String[] strArr;
            int i = 0;
            while(f.readLine() != null) {i++;}
            users = new User[i - 1];
            f.close();
            i = 0;
            f = new BufferedReader(new FileReader(filepath));
            f.readLine();
            while((line = f.readLine()) != null){
                strArr = line.split(",");
                users[i] = User.valueOf(strArr[0],strArr[1],strArr[2],strArr[3],strArr[4],strArr[5]);
                i++;
            }

        }
        catch(Throwable e )
        {
            System.out.println("Blad w otwieraniu pliku!");
        }
    }

    @Override
    public String toString() {
        StringBuilder returnStr = new StringBuilder();
        for(User v : users){
            returnStr.append(v.toString()).append('\n');
        }
        return returnStr.toString();
    }
}
