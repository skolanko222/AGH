non-sealed public class RandomOct extends RandomString{
    public RandomOct(int length) {
        super(length);
    }

    @Override
    public String rand() {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < getLength(); i++) {
            sb.append(Integer.toOctalString(nextInt(8)));
        }
        return sb.toString();
    }
}
