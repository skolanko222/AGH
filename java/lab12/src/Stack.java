import java.util.EmptyStackException;

public class Stack<T extends CharSequence> implements StackInterface<T>{

    private Node<T> top = null;

    @Override
    public boolean isEmpty() {
        return top == null;
    }

    @Override
    public void push(T x) throws NullPointerException {
        if(x == null) throw new NullPointerException();
        top = new Node<T>(x, top);
    }
    @Override
    public T pop() throws EmptyStackException {
        if(top == null) throw new EmptyStackException();
        Node<T> temp = top;
        top = top.getNext();
        return temp.getValue();
    }

    @Override
    public T peek() throws EmptyStackException {
        if(top == null) throw new EmptyStackException();
        return top.getValue();
    }

    @Override
    public int find(T el) throws NullPointerException {
        if(el == null) throw new NullPointerException();
        Node<T> temp = top;
        int counter = 0;
        while(temp != null){
            if(temp.getValue().equals(el)) return counter;
            counter++;
            temp = temp.getNext();
        }
        return -1;
    }

    @Override
    public String toString(){
        StringBuilder retStr = new StringBuilder(50);
        Node<T> temp = top;
        int counter = 0;
        while(temp != null){
            retStr.append(counter).append(": ").append(temp.getValue()).append("\n");
            //System.out.println(counter);
            counter++;
            temp = temp.getNext();
        }
        return retStr.toString();
    }
}
