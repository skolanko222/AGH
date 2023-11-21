public class Main {
    public static void main(String[] args) {
        byte [] arr1 = {9,2,1};
        byte [] arr2 = {2,7,1};
        BigNumber a = new BigNumber(2932321,32320);
        BigNumber a2 = new BigNumber(2932321,32320);

        BigNumber b = new BigNumber(new byte [0],new byte [0]);
        BigNumber c = BigNumber.valueOf(arr1,arr2);

        System.out.println(BigNumber.ZERO);
        System.out.println(BigNumber.ONE);
        System.out.println(BigNumber.TWO);
        System.out.println(BigNumber.TEN);

        System.out.println();

        System.out.println(a);
        System.out.println(b);
        System.out.println(c);
        System.out.println("floor: " + c.floor());
        System.out.println(a.equals(a2));
        System.out.println(a.equals(c));
        System.out.println("hash: " + a.hashCode() + " " + a2.hashCode());
        System.out.println("hash: " + b.hashCode() + " " + c.hashCode());

    }
}