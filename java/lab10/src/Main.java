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


}