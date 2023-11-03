public class Biblioteka {
    private Node root = null;

    public void dodaj(Ksiazka k){
        Node n = new Node(k);

        Node y = null; // rodzic aktualnego wezla
        Node x = root; // aktualny wezel
        while (x != null){
            if(k.getID() == x.getValue().getID()){
                System.out.println("Ksiazka o takim id juz istnieje");
                return;
            }
            y = x;
            if(k.getID() < x.getValue().getID()) {
                x = x.getLeft();
            }
            else {
                x = x.getRight();
            }
        }
        n.setParent(y);
        if(y == null){
            root = n;
        }
        else if(k.getID() < y.getValue().getID()){
            y.setLeft(n);
        }
        else{
            y.setRight(n);
        }

    }
    public void rysujBiblioteke(){
        root.printTree(0);

    }
    public Ksiazka wyszukajTytul(String wartosc){
        return root.findTitle(wartosc);

    }
    public Ksiazka wyszukajID(int ID){
        return root.findID(ID);

    }
}
