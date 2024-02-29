public class Node<T>{
    private final T value;
    private final Node<T> next;

    public Node(T value){
        this.value = value;
        this.next = null;
    }

    public Node(T value, Node<T> next){
        this.value = value;
        this.next = next;
    }

    public T getValue(){
        return this.value;
    }

    public Node<T> getNext(){
        return this.next;
    }

}
