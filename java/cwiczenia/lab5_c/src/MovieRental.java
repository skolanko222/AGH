import java.io.BufferedReader;
import java.io.FileReader;

/**
 * MovieRental class, holds array of VHS objects.
 * Has method to load data from file.
 */
public class MovieRental {
    VHS[] vhs;

    /**
     * MovieRental constructor
     */
    public MovieRental() {
        vhs = new VHS[0];

    }
    /**
     * Reads all record from file and adds VHS objects to the array
     * @param filename path to file
     */
    public void loadFromFile(String filename){
        try{
            BufferedReader f = new BufferedReader(new FileReader(filename));
            String line;
            String [] splited;
            int i = 0;
            while(f.readLine() != null) { i++;}
            vhs = new VHS[i];
            i = 0;
            f.close();
            f = new BufferedReader(new FileReader(filename));
            while((line = f.readLine()) != null) {
                splited = line.split(",");
                VHS newVHS = VHS.valueOf(splited[0], splited[1], splited[2], splited[3], splited[4], splited[5]);
                vhs[i] = newVHS;
                i++;
            }
            f.close();
        }
        catch (Throwable o){
            System.out.println("Error while opening file!");
        }
    }
    /**
     * Returns string representation of MovieRental object
     * @return string representation of MovieRental object
     */
    @Override
    public String toString() {
        StringBuilder retStr = new StringBuilder();
        for (VHS vh : vhs) {
            retStr.append(vh.toString());
            retStr.append('\n');
        }
        return retStr.toString();
    }

    public VHS[] getVHSArr() {
        return vhs;
    }
}
