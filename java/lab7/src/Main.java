import pl.edu.agh.fis.lab7.Person;
import pl.edu.agh.fis.lab7.Dean;
import pl.edu.agh.fis.lab7.Graduate;
import pl.edu.agh.fis.lab7.Person;
import pl.edu.agh.fis.lab7.Student;

public class Main {
    public static void main(String[] args) {
        Person[] people = new Person[5];
        people[0] = new Dean("mgr inż.", "Jan", "Kowalski", 2000, 2005);
        people[1] = new Student("Maria", "Nowak", 1, 4.5);
        people[2] = new Graduate("Jan", "Nowak", 2, 4.5, java.time.LocalDate.now());
        people[3] = new Dean("prof.", "Magdalena", "Nowak", 2005, 2010);
        people[4] = new Student("Jan", "Abacki", 3, 4.5);

        for(Person a : people){
            System.out.println(a);
        }


    }
}
