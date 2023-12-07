public non-sealed class RandomHex extends RandomString {
    public RandomHex(int length) {
        super(length);
    }

    @Override
    public String rand() {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < getLength(); i++) {
            sb.append(Integer.toHexString(nextInt(16)).toUpperCase());
        }
        return sb.toString();
    }
}
