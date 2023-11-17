import java.io.File;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) {
        MovieRental movieRental = new MovieRental();
        movieRental.loadFromFile(new File("").getAbsolutePath() + "\\out\\production\\lab5_c\\VHS.csv");
//        System.out.println(movieRental.toString());

        System.out.println(movieRental.getVHSArr()[1]);

    }
}