public final class Card {
    public static enum Rank {
        NINE (9, '9'),
        TEN (10, 'T'),
        JACK (3, 'J'),
        QUEEN (4, 'Q'),
        KING (5, 'K'),
        AC (11, 'A'),;
        private final int weight;
        private final char symbol;
        private Rank(int weight, char symbol) {
            this.weight = weight;
            this.symbol = symbol;
        }

        @Override
        public String toString() {
            return "Rank{" +
                    "weight=" + weight +
                    ", symbol=" + symbol +
                    '}';
        }

        public int getWeight() {
            return weight;
        }

        public char getSymbol() {
            return symbol;
        }
    }
    public static enum Suit {
        CLUBS,
        DIAMONDS,
        HEARTS,
        SPADES

    }
    private final Rank rank;
    private final Suit suit;

    public Card(Rank rank, Suit suit) {
        this.rank = rank;
        this.suit = suit;
    }
    public Card(Card card) {
        this.rank = card.rank;
        this.suit = card.suit;
    }

    @Override
    public String toString() {
        return "Card{" +
                "rank=" + rank +
                ", suit=" + suit +
                '}';
    }
}
