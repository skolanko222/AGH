import java.util.Random;

public class Deck {
    final private Card[] cards;
    final private int startSize = 24;
    private int currentSize = startSize;
    final private Random random = new Random();

    public Deck() {
        cards = new Card[startSize];
        int i = 0;
        for (Card.Suit suit : Card.Suit.values()) {
            for (Card.Rank rank : Card.Rank.values()) {
                cards[i++] = new Card(rank, suit);
            }
        }
    }
    public void deleteCard(Card card) {
        for (int i = 0; i < currentSize; i++) {
            if(cards[i].equals(card)) {
                cards[i] = cards[currentSize - 1];
                cards[currentSize - 1] = null;
                currentSize--;
                return;
            }
        }
    }
    public Card randomCard() {
        if(currentSize == 0) {
            return null;
        }
        int index = random.nextInt(currentSize);

        return new Card(cards[index]);
    }
}
