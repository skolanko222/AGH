import java.util.Arrays;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        String testString = args[0];
        String [] arr =  Arrays.stream(testString.split("")).filter(w -> !w.isEmpty() && !w.isBlank()).toArray(String[]::new);
        Main.translate(arr);

    }

    public static String translate(String ... var){
        Stack<String> charStack = new Stack<>();

        for(String i : var){
//            System.out.println(charStack.toString());
            try {
                if (!i.matches("[a-zA-Z+*/-]")) {
                    System.out.println("BLAD DANYCH WEJSCIOWYCH! Bledny operator: " + i);
                    return "BLAD DANYCH WEJSCIOWYCH! Bledny operator: " + i;
                }
                if (i.matches("[+*/-]")) {
                    String x = charStack.pop();
                    String y = charStack.pop();
                    String toBePushed = "(" + y +  i + x + ")";
                    //                System.out.println(toBePushed);
                    charStack.push(toBePushed);
                } else {
                    charStack.push(i);
                }
            }catch (Exception e){
                System.out.println("BLAD DANYCH WEJSCIOWYCH! Na stosie jest za malo elementow, zeby wykonac operacje!");
                return "BLAD DANYCH WEJSCIOWYCH! Na stosie jest za malo elementow, zeby wykonac operacje!";
            }
        }
//        if(!charStack.isEmpty()) {
//            System.out.println("BLAD DANYCH WEJSCIOWYCH! Koniec algorytmu, a stos nie jest pusty: " + charStack.pop());
//            return "BLAD DANYCH WEJSCIOWYCH! Koniec algorytmu, a stos nie jest pusty: " + charStack.pop();
//        }
        String ret = charStack.pop();
        System.out.println(ret);
        return ret;

    }
}