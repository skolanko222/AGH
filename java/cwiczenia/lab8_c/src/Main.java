import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        RandomString randomString = new RandomHex(10);
        System.out.println(randomString.rand());
        randomString = new RandomOct(10);
        System.out.println(randomString.rand());
        Scanner scanner = new Scanner(new RandomHexAdapter(120, 10));
        while (scanner.hasNext()) {
            System.out.println(scanner.next());
        }

    }
}