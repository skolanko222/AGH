import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int size;

        while (true) {
            System.out.print("> Podaj rozmiar planszy: ");
            try {
                size = sc.nextInt();
                if (size < 2) {
                    throw new InputMismatchException();
                }
                break;
            } catch (NoSuchElementException e) {
                System.out.println("BŁĄD: Podaj jeszcze raz! (No such element)");
                sc.nextLine();
            } catch (IllegalStateException e) {
                System.out.println("BŁĄD: Podaj jeszcze raz! (Scanner closed)");
                sc.nextLine();
            }
        }

        Game game = new Game(size);
        game.runGame(sc);
        sc.close();
    }
}