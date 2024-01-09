import java.util.Random;
import java.util.Scanner;

public class Game {
    private final int size;
    private final char[][] board;

    private int xCoord;
    private int yCoord;

    interface CheckStep {
        boolean check(char[][] board, int i0, int j0, Direction direction);
    }

    static class OptionNotRecognizedException extends Exception {
        public OptionNotRecognizedException(String message) {
            super(message);
        }
    }
    static class IllegalMoveException extends Exception {
        public IllegalMoveException(String message) {
            super(message);
        }
    }
    public Game(int size) {
        this.size = size;
        this.board = new char[size][2*size];

        Random random = new Random();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < 2*size; j++) {
                if (random.nextDouble() < 0.3) {
                    board[i][j] = 'X';
                } else {
                    board[i][j] = ' ';
                }
            }
        }
        xCoord = random.nextInt(2*size);
        yCoord = random.nextInt(size);
        board[yCoord][xCoord] = 'O';
    }

    public void printBoard() {
        for (int i = 0; i < size; i++) {
            System.out.print("|");
            for (int j = 0; j < 2*size; j++) {
                System.out.print(board[i][j]);
            }
            System.out.println("|");
        }
    }

    private boolean move(Direction direction) {
        CheckStep checkBoundaries = (char[][] board, int i0, int j0, Direction dir) -> {
            int i = i0 + dir.xDir;
            int j = j0 + dir.yDir;
            return i >= 0 && i < 2*size && j >= 0 && j < size;
        };

        CheckStep checkObstacle = (char[][] board, int i0, int j0, Direction dir) -> {
            int i = i0 + dir.xDir;
            int j = j0 + dir.yDir;
            return board[j][i] != 'X';
        };

        if (checkBoundaries.check(board, xCoord, yCoord, direction) && checkObstacle.check(board, xCoord, yCoord, direction)) {
            board[yCoord][xCoord] = ' ';
            xCoord = xCoord + direction.xDir;
            yCoord = yCoord + direction.yDir;
            board[yCoord][xCoord] = 'O';
            return true;
        }
        return false;
    }
    public void runGame(Scanner sc){

        label:
        while (true) {
            printBoard();
            System.out.print("> Podaj kierunek ruchu (l, r, u, d), aby zakończyć wyślij (q): ");
            // throw OptionNotRecognizedException if input is not l, r, u, d or q
            try {
                String input = sc.next();
                switch (input) {
                    case "q":
                        break label;
                    case "l":
                        if(!move(Direction.LEFT))
                            throw new IllegalMoveException("BŁĄD: Nie można wykonać ruchu w lewo!");
                        break;
                    case "r":
                        if(!move(Direction.RIGHT))
                            throw new IllegalMoveException("BŁĄD: Nie można wykonać ruchu w prawo!");
                        break;
                    case "u":
                        if(!move(Direction.UP))
                            throw new IllegalMoveException("BŁĄD: Nie można wykonać ruchu w górę!");
                        break;
                    case "d":
                        if(!move(Direction.DOWN))
                            throw new IllegalMoveException("BŁĄD: Nie można wykonać ruchu w dół!");
                        break;
                    default:
                        throw new OptionNotRecognizedException("BŁĄD: Podaj jeszcze raz!");
                }
            } catch (OptionNotRecognizedException | IllegalMoveException e) {
                System.out.println(e.getMessage());
            }
        }
    }
}
