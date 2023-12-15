
public class Main {
    public static void main(String[] args) {

        Deck deck = new Deck();
        for (int i = 0; i < 24; i++) {
            System.out.println(deck.randomCard());
        }
    }
}