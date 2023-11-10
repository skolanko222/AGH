public class Ksiazka {
    private String tytul;
    private int id;
    private static int count = 0;

    public Ksiazka(String tytul, int id) {
        this.tytul = tytul;
        this.id = id;
        count++;
    }
    public int getID(){
        return id;
    }
    public String getTytul(){
        return tytul;
    }
    public void print(){
        System.out.println("Ksiazka: " + tytul + " id: " + id);
    }
    public static int getCount(){
        return count;
    }

}
