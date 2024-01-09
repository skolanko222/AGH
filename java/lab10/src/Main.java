<<<<<<< HEAD
import javax.sound.midi.SysexMessage;
import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;

public class Main {
    public static void main(String[] args) {

        try {
            //HackMe temp = new HackMe();
            Class c = HackMe.class;
            Constructor[] constArr = c.getDeclaredConstructors();

            Constructor myConst = HackMe.class.getDeclaredConstructor(int.class, int.class);
            myConst.setAccessible(true);
            //Object objHack = myConst.newInstance(1,1); //InvocationTargetException
            //System.out.println(objHack.toString());
            Method[] allMethods = HackMe.class.getDeclaredMethods();
            for(Method t : allMethods){
                if(Modifier.isStatic(t.getModifiers()))
                    System.out.println(t.toString());
            }
            Method myMethod = HackMe.class.getDeclaredMethod("getInstance");
            myMethod.setAccessible(true);
            //Object myHack = myMethod.invoke(HackMe.class);

            Method workingMethod = HackMe.class.getDeclaredMethod("hackMeOf",int.class,String[].class);
            workingMethod.setAccessible(true);
            Object objHack = workingMethod.invoke(HackMe.class,1,new String[]{"sffs"});
            System.out.println(objHack.toString());

            Class[] nestedClasses = c.getDeclaredClasses();
            for(Class t : nestedClasses){
                System.out.println();
                System.out.println("Name: " + t.getName());
                System.out.println("Type: " + (t.isEnum() ? "Enum" : "Class"));
                System.out.println("Modifiers: " + Modifier.toString(t.getModifiers()));
                System.out.println("Fields: ");
                for(Field f : t.getDeclaredFields()){
                    System.out.println("\tName of field: " + f.getName());
                    System.out.println("\tModifiers: " + Modifier.toString(f.getModifiers()));
                }
            }




        } catch(Exception e){
            System.out.println(e.toString());
        }
    }


=======
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int size;

        while (true) {
            System.out.print("> Podaj rozmiar planszy: ");
            try {
                size = sc.nextInt();
                if (size < 2) {
                    throw new InputMismatchException();
                }
                break;
            } catch (NoSuchElementException e) {
                System.out.println("BŁĄD: Podaj jeszcze raz! (No such element)");
                sc.nextLine();
            } catch (IllegalStateException e) {
                System.out.println("BŁĄD: Podaj jeszcze raz! (Scanner closed)");
                sc.nextLine();
            }
        }

        Game game = new Game(size);
        game.runGame(sc);
        sc.close();
    }
>>>>>>> 1f58c7e57c129cd5f282a5ce65e55136147bea90
}