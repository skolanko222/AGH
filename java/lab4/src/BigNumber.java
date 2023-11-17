import java.util.Arrays;
public final class BigNumber {

    private final byte[] integer;
    private final byte[] frac;

    private boolean isHash = false;
    private int hash;

    public static final BigNumber ZERO = new BigNumber(0, 0);
    public static final BigNumber ONE = new BigNumber(1, 0);
    public static final BigNumber TWO = new BigNumber(2, 0);
    public static final BigNumber TEN = new BigNumber(10, 0);

    public BigNumber(int x, int y) {
        integer = new byte[Integer.toString(x).length()];
        frac = new byte[Integer.toString(y).length()];
        for (int i = Integer.toString(x).length() - 1; i >= 0; i--) {
            integer[i] = (byte) (x % 10);
            x /= 10;
        }
        for (int i = Integer.toString(y).length() - 1; i >= 0; i--) {
            frac[i] = (byte) (y % 10);
            y /= 10;
        }
    }
    public BigNumber(byte[] x, byte[] y) {
        integer = Arrays.copyOf(x, x.length);
        frac = Arrays.copyOf(y, y.length);
    }
    private BigNumber(byte[] x) {
        integer = x;
        frac = new byte[]{0};
    }
    @Override
    public String toString() {
        StringBuilder retStr = new StringBuilder();
        if (integer.length == 0) retStr.append('0');
        for (byte b : integer) {
            retStr.append(b);
        }
        retStr.append('.');
        if (frac.length == 0) retStr.append('0');
        for (byte b : frac) {
            retStr.append(b);
        }
        return retStr.toString();
    }
    public static BigNumber valueOf(byte[] t1, byte[] t2) {
        if (Arrays.equals(t1, ONE.getInteger()) && Arrays.equals(t2, ONE.getFrac())) return ONE;
        if (Arrays.equals(t1, ZERO.getInteger()) && Arrays.equals(t2, ZERO.getFrac())) return ZERO;
        if (Arrays.equals(t1, TWO.getInteger()) && Arrays.equals(t2, TWO.getFrac())) return TWO;
        if (Arrays.equals(t1, TEN.getInteger()) && Arrays.equals(t2, TEN.getFrac())) return TEN;
        return new BigNumber(t1, t2);
    }
    public byte[] getInteger() {
        return Arrays.copyOf(integer, integer.length);
    }
    public byte[] getFrac() {
        return Arrays.copyOf(frac, frac.length);
    }
    public BigNumber floor() {
        return new BigNumber(this.integer);
    }
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        BigNumber bigNumber = (BigNumber) o;
        return Arrays.equals(integer, bigNumber.integer) && Arrays.equals(frac, bigNumber.frac);
    }
    @Override
    public int hashCode() {
        if (!isHash) {
            isHash = true;
            this.hash = 31 * this.hash + Arrays.hashCode(frac);
            return this.hash;
        }
        return hash;
    }
}
