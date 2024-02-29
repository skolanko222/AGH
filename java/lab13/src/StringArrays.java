import java.util.Arrays;
import java.util.List;
import java.util.Objects;
import java.util.Random;

public final class StringArrays {
    private final String[] t1;
    private final String[] t2;
    private final String[] t3;
    private final int lengthOfStrings;
    private final static Random random = new Random();
    private final static String smallLetters = "abcdefghijklmnopqrstuvwxyz";
    private final static String letters = smallLetters + smallLetters.toUpperCase();

    public String[] getT1() {
        return t1;
    }

    public String[] getT2() {
        return t2;
    }

    public String[] getT3() {
        return t3;
    }

    public StringArrays() {
        int n = 100000;
        int m = 1000;
        this.lengthOfStrings = 20;
        this.t1 = fillArrayWithRandomStrings(n);
        this.t2 = fillArrayWithStringsFromArray(m, t1);
        this.t3 = fillArrayWithRandomStringsNotContainedInArray(m, t1);
    }

    public static String nextString(int length) {
        if (length < 0)
            throw new IllegalArgumentException("Length of a String can't be negative!");
        StringBuilder str = new StringBuilder();
        for (int i = 0; i < length; ++i) {
            str.append(letters.charAt(random.nextInt(letters.length())));
        }
        return str.toString();
    }

    private String[] fillArrayWithRandomStrings(int length) {
        if (length <= 0)
            throw new IllegalArgumentException("Length of an array must be positive!");
        String[] array = new String[length];
        for (int i = 0; i < length; ++i) {
            array[i] = nextString(lengthOfStrings);
        }
        return array;
    }

    private String[] fillArrayWithStringsFromArray(int length, String[] t1) {
        Objects.requireNonNull(t1);
        if (length <= 0 || t1.length == 0)
            throw new IllegalArgumentException("Length of an array must be positive!");
        Random random = new Random();
        String[] array = new String[length];
        for (int i = 0; i < length; ++i) {
            int randomIndex = random.nextInt(t1.length);
            array[i] = t1[randomIndex];
        }
        return array;
    }

    private String[] fillArrayWithRandomStringsNotContainedInArray(int length, String[] t1) {
        Objects.requireNonNull(t1);
        if (length <= 0 || t1.length == 0)
            throw new IllegalArgumentException("Length of an array must be positive!");
        List<String> list = Arrays.stream(t1).toList();
        String[] array = new String[length];
        for (int i = 0; i < length; ++i) {
            String str = nextString(lengthOfStrings);
            if (!list.contains(str)) {
                array[i] = str;
            } else {
                --i;
            }
        }
        return array;
    }
}