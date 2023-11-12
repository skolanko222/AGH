import java.util.*;

public class Main {
    public static void main(String[] args) {
        int aa = 123;
        BigInt a = new BigInt(aa);
        BigInt b = new BigInt("-99");
        aa =12341234;
        System.out.println(a);
        System.out.println(b);
        BigInt c = BigInt.valueOf("2323");
        BigInt d = BigInt.valueOf("243");
        System.out.println(c);
        System.out.println(d.negate());
    }
}