import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class Blackjack {

    public static class Card {
        public Rank getRank() {
            return rank;
        }

        public Suit getSuit() {
            return suit;
        }

        public enum Suit {
            CLUBS, DIAMONDS, HEARTS, SPADES
        }

        public enum Rank {
            NINE(9, "9"), TEN(10, "10"), JACK(2, "J"), QUEEN(3, "Q"), KING(4, "K"), ACE(11, "A");

            private final int weight;
            private final String symbol;

            Rank(int weight, String symbol) {
                this.weight = weight;
                this.symbol = symbol;
            }


            public int getWeight() {
                return weight;
            }

            @Override
            public String toString() {
                return symbol;
            }
        }
        private final Rank rank;
        private final Suit suit;
        public Card(Rank rank, Suit suit) {
            this.rank = rank;
            this.suit = suit;
        }
    }

    public static class Deck {
        private Card[] cards;


        public Deck() {
            cards = new Card[24];
            int index = 0;
            for (Card.Suit suit : Card.Suit.values()) {
                for (Card.Rank rank : Card.Rank.values()) {
                    cards[index++] = new Card(rank, suit);
                }
            }
        }

        public Card drawCard() {
            Random random = new Random();
            int index;
            do {
                index = random.nextInt(cards.length);
            } while (cards[index] == null);
            Card drawnCard = cards[index];
            cards[index] = null;
            return drawnCard;
        }

        public void removeCard(Card card) {
            for (int i = 0; i < cards.length; i++) {
                if (cards[i] == card) {
                    cards[i] = null;
                    break;
                }
            }
        }

        @Override
        public String toString() {
            return Arrays.toString(cards);
        }
    }

    private final String playerName;
    private final int maxIterations;
    private int userAccount;
    private int computerAccount;
    private final Deck deck;

    public Blackjack(String playerName, int maxIterations) {
        this.playerName = playerName;
        this.maxIterations = maxIterations;
        this.userAccount = 0;
        this.computerAccount = 0;
        this.deck = new Deck();
    }

    public void playGame() {
        Scanner scanner = new Scanner(System.in);
        for (int iteration = 0; iteration < maxIterations; iteration++) {
            System.out.println("Options: PLAY, STOP, QUIT");
            String option = scanner.next().toUpperCase();

            switch (option) {
                case "PLAY":
                    playRound();
                    break;
                case "STOP":
                    stopGame();
                    break;
                case "QUIT":
                    quitGame();
                    break;
                default:
                    System.out.println("Invalid option. Please choose again.");
            }
        }
    }

    private void playRound() {
        Card userCard = deck.drawCard();
        Card computerCard = deck.drawCard();

        userAccount += userCard.getRank().getWeight();
        computerAccount += computerCard.getRank().getWeight();

        deck.removeCard(userCard);
        deck.removeCard(computerCard);

        System.out.println("User's card: " + userCard);
        System.out.println("Computer's card: " + computerCard);

        System.out.println("User's account: " + userAccount);
        System.out.println("Computer's account: " + computerAccount);

        if (userAccount == 21 || computerAccount == 21) {
            endGame();
        } else if (userAccount > 21 || computerAccount > 21) {
            loseGame();
        }
    }

    private void stopGame() {
        endGame();
    }

    private void quitGame() {
        System.out.println("Game over. Quitting...");
        System.exit(0);
    }

    private void endGame() {
        System.out.println("Game over.");

        if (userAccount == 21 && computerAccount == 21) {
            System.out.println("It's a tie!");
        } else if (userAccount == 21) {
            System.out.println(playerName + " wins!");
        } else if (computerAccount == 21) {
            System.out.println("Computer wins!");
        } else {
            System.out.println("Unexpected end of the game.");
        }

        System.out.println("User's account: " + userAccount);
        System.out.println("Computer's account: " + computerAccount);

        System.exit(0);
    }

    private void loseGame() {
        System.out.println("Game over. You lose!");
        System.out.println("User's account: " + userAccount);
        System.out.println("Computer's account: " + computerAccount);
        System.exit(0);
    }

    public static void main(String[] args) {
        Blackjack blackjack = new Blackjack("Player", 5);
        blackjack.playGame();
    }
}