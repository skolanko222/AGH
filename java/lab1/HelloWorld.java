public class HelloWorld {
    public static void main(String[] args) {

        System.out.println("Hello " + "world!");

        Examples ob = new Examples();
		Examples ob2 = new Examples();
		System.out.println(ob == ob2);
		System.out.println(ob.equals(ob2));

    }

}

class Examples {
    float x1;

    public double run() {
        // System.out.println(2 + 4); // ex. 1
        // System.out.println("2 + 4 = " + 2 + 4); // ex. 1

        float x2 = 4.5f; // ex. 2
        System.out.println("x1 = " + x1); // ex. 2
        System.out.println("x2 = " + x2); // ex. 2

        return Math.sqrt(36.0);
        // System.out.println("sqrt(36.0) calculated."); // ex. 3
    }

    
    public void stringsV1(){ // ex. 4
        String s1 = new String("Hello");
        String s2 = new String("Hello");
        System.out.print(s1 == s2); // referencje w typach obiektowych
        System.out.println(" " + s1.equals(s2)); // wartosci
    }

    public void stringsV2(){ // ex. 5
        String s1 = "Hello";
        String s2 = "Hello";
		s2 += "1";
        System.out.print(s1 == s2);
        System.out.println(" " + s1.equals(s2));
    }

}