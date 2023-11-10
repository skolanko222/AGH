// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) {
        Ksiazka a = new Ksiazka("Rok", 5);
        Ksiazka b = new Ksiazka("Heart", 3);
        Ksiazka c = new Ksiazka("Proces", 2);
        Ksiazka d = new Ksiazka("Dżuma", 4);
        Ksiazka e = new Ksiazka("Imie Rózy", 6);
        Biblioteka lib = new Biblioteka();
        lib.dodaj(a);
        lib.dodaj(b);
        lib.dodaj(c);
        lib.dodaj(d);
        lib.dodaj(e);

        lib.rysujBiblioteke();
        Ksiazka ret = lib.wyszukajID(2);

            ret.print();

    }
}