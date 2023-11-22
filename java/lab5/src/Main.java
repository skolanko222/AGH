public class Main {
    public static void main(String[] args) {
        DatabaseReader reader = new DatabaseReader();
        reader.readFromFile("shop.csv");
        System.out.println(reader.toString());

    }
}