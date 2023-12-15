package pl.edu.agh.fis.lab7;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class StudentTest extends PersonTest {
    protected static final int testingIdNumber1 = 452236;
    protected static final double testingAverage1 = 3.67;

    protected static final int testingIdNumber2 = 211152;
    protected static final double testingAverage2 = 5.0;


    @Override
    @BeforeEach
    void setUp() {
        p1 = new Student(testingFirstName1, testingLastName1, testingIdNumber1, testingAverage1);
        p2 = new Student(testingFirstName2, testingLastName2, testingIdNumber2, testingAverage2);
    }

    @Override
    @Test
    void testConstructor() {
        assertThrows(NullPointerException.class,
                () -> new Student(null, testingLastName1, testingIdNumber1, testingAverage1),
                getMessage("Konstruktor", "pierwszy parametr jest rowny null", hintExt)
        );
        assertThrows(NullPointerException.class,
                () -> new Student(testingFirstName1, null, testingIdNumber1, testingAverage1),
                getMessage("Konstruktor", "pierwszy parametr jest rowny null", hintExt)
        );
    }

    @Test
    void testGetIdNumber() {
        assertEquals(testingIdNumber1, ((Student) p1).getIdNumber(), "getIdNumber zwraca inna wartosc (lub konstruktor zle przypisuje)!");
        assertEquals(testingIdNumber2, ((Student) p2).getIdNumber(), "getIdNumber zwraca inna wartosc (lub konstruktor zle przypisuje)!");
    }

    @Test
    void testGetAverage() {
        assertEquals(testingAverage1, ((Student) p1).getAverage(), "getAverage zwraca inna wartosc (lub konstruktor zle przypisuje)!");
        assertEquals(testingAverage2, ((Student) p2).getAverage(), "getAverage zwraca inna wartosc (lub konstruktor zle przypisuje)!");
    }

    @Test
    void testSetAverage() {
        ((Student) p1).setAverage(testingAverage2);
        assertEquals(testingAverage2, ((Student) p1).getAverage(), "setAverage zle przypisuje? Albo getAverage zle zwraca.");

        ((Student) p2).setAverage(testingAverage1);
        assertEquals(testingAverage1, ((Student) p2).getAverage(), "setAverage zle przypisuje? Albo getAverage zle zwraca.");
    }

    protected String getHintGraduate() {
        return "";
    }

    @Test
    void testGreater() {
        assertSame(p1, p1.greater(p1), "Jesli metoda greater porownuje studentow (lub obiekty klas pochodnych) o tej samej sredniej, to musi zwrocic ktorakolwiek referencje!" + getHintGraduate());

        assertSame(p2, p2.greater(p1), "Metoda greater musi zwrocic referencje do studenta o wyzszej sredniej!" + getHintGraduate());
        assertSame(p2, p1.greater(p2), "Metoda greater musi zwrocic referencje do studenta o wyzszej sredniej!" + getHintGraduate());

        Person p3 = new Person("Testowa", "Osoba") {
            @Override
            public Person greater(Person ob) {
                return null;
            }
        };
        assertNull(p1.greater(p3), "Jesli przekazany do greater obiekt nie jest obiektem klasy Student (lub pochodnej), to nalezy zwrocic null!" + getHintGraduate());
    }

    @Override
    @Test
    void testToString() {
        String expectedString1 = testingFirstName1 + " " + testingLastName1 +
                ", id number: " + testingIdNumber1 +
                ", average: " + testingAverage1;
        assertEquals(expectedString1, p1.toString(), "toString zwraca zly lancuch lub konstruktor zle przypisuje!");

        String expectedString2 = testingFirstName2 + " " + testingLastName2 +
                ", id number: " + testingIdNumber2 +
                ", average: " + testingAverage2;
        assertEquals(expectedString2, p2.toString(), "toString zwraca zly lancuch lub konstruktor zle przypisuje!");
    }
}