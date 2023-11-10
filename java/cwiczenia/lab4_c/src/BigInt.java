import java.util.Arrays;
import java.util.Objects;

public final class BigInt {
    private final byte[] number;
    private final boolean sign;
    private final int hashCode;

    public static final BigInt ZERO = new BigInt(0);
    public static final BigInt ONE = new BigInt(1);
    public static final BigInt TEN = new BigInt(10);
    public static final BigInt TWO = new BigInt(2);

    private BigInt(BigInt obj, boolean sign){
        this.sign = sign;
        this.number = obj.number;
        hashCode = Objects.hash(sign) + Arrays.hashCode(number);
    }

    public BigInt(int num) {
        if (num < 0) {
            this.sign = false;
            number = new byte[Integer.toString(num).length() - 1];
            num = -num;

        } else {
            this.sign = true;
            number = new byte[Integer.toString(num).length()];

        }
        for (int i = 0; i < number.length; i++) {
            number[i] = (byte) (num % 10);
            num /= 10;
        }
        hashCode = Objects.hash(sign) + Arrays.hashCode(number);
    }
    public BigInt(String napis){
        this(Integer.parseInt(napis));
    }
    public BigInt negate(){
        return new BigInt(this, !this.sign);
    }
    public boolean getSign(){
        return sign;
    }
    public byte[] getNumber(){
        return number;
    }
    @Override
    public boolean equals(Object o){
        if(o == this) return true;
        if(!(o instanceof BigInt)) return false;
        BigInt b = (BigInt) o;
        if(this.sign != b.sign) return false;
        if(this.number.length != b.number.length) return false;
        for (int i = 0; i < this.number.length; i++) {
            if(this.number[i] != b.number[i]){
                return false;
            }
        }
        return true;
    }
    public static BigInt valueOf(String val){
        if(val.compareTo("0") == 0){
            return ZERO;
        }
        if(val.compareTo("1") == 0){
            return ONE;
        }
        if(val.compareTo("2") == 0){
            return TWO;
        }
        if(val.compareTo("10") == 0){
            return TEN;
        }
        return new BigInt(val);
    }
    public int hashCode(){
        return hashCode;
    }

    public String toString(){
            StringBuilder str = new StringBuilder();
            if(!sign){
                str.append("-");
            }
            for (int i = 0; i < number.length; i++) {
                str.append(number[number.length - i - 1]);
            }
            return str.toString();
    }


}
