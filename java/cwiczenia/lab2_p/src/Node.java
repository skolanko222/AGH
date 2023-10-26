public class Node {
    final private Ksiazka value;
    private Node left = null;
    private Node right = null;
    private Node parent = null;


    public Node(Ksiazka value){
        this.value = value;

    }
    public void printNode(){
        System.out.println("value: " + value.getTytul());
    }
    public void setLeft(Node left){
        this.left = left;
    }
    public void setRight(Node right){
        this.right = right;
    }
    public void setParent(Node parent){
        this.parent = parent;
    }
    public Ksiazka getValue(){
        return value;
    }
    public Node getLeft(){
        return left;
    }
    public Node getRight(){
        return right;
    }
    public void printTree(int ile_spacji)
    {
        for (int i = 0; i < ile_spacji; i++)
            System.out.printf("... ");
        System.out.println(value.getTytul());
        if (left != null){
            left.printTree(ile_spacji + 1);
        }
        if (right != null) {
            right.printTree(ile_spacji + 1);
        }
    }
    public Ksiazka findTitle(String title)
    {
        if(title.equals(value.getTytul()) )
            return value;
        if(left != null)
            return left.findTitle(title);
        if(right != null)
            return right.findTitle(title);
        return null;
    }
    public Ksiazka findID(int id)
    {
        if(id == value.getID())
            return value;
        if(id > value.getID())
            return right.findID(id);
        if(id < value.getID())
            return left.findID(id);
        return null;
    }


}
