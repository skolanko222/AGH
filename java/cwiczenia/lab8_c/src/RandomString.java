import java.util.Random;

public sealed abstract class RandomString permits RandomOct, RandomHex{
    final private int length;

    abstract public String rand();
    private Random random = new Random();

    public RandomString(int length) {
        this.length = length;
    }

    public int getLength() {
        return length;
    }

    protected int nextInt(int bound) {
        return random.nextInt(bound);
    }
}
