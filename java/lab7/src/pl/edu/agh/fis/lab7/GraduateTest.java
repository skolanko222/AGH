package pl.edu.agh.fis.lab7;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.time.LocalDate;

import static org.junit.jupiter.api.Assertions.*;

class GraduateTest extends StudentTest {
    private static final LocalDate testingGraduationDate1 = LocalDate.now();
    private static final LocalDate testingGraduationDate2 = LocalDate.of(2012, 07, 31);

    @Override
    @BeforeEach
    void setUp() {
        p1 = new Graduate(testingFirstName1, testingLastName1, testingIdNumber1, testingAverage1,
                testingGraduationDate1);
        p2 = new Graduate(testingFirstName2, testingLastName2, testingIdNumber2, testingAverage2,
                testingGraduationDate2);
    }

    @Override
    @Test
    void testConstructor() {
        assertThrows(NullPointerException.class,
                () -> new Graduate(null, testingLastName1, testingIdNumber1, testingAverage1, testingGraduationDate1),
                getMessage("Konstruktor", "pierwszy parametr jest rowny null", hintExt)
        );
        assertThrows(NullPointerException.class,
                () -> new Graduate(testingFirstName1, null, testingIdNumber1, testingAverage1, testingGraduationDate1),
                getMessage("Konstruktor", "drugi parametr jest rowny null", hintExt)
        );
        assertThrows(NullPointerException.class,
                () -> new Graduate(testingFirstName1, testingLastName1, testingIdNumber1, testingAverage1, null),
                getMessage("Konstruktor", "ostatni parametr jest rowny null", hintObjects)
        );
    }

    @Test
    void testGetGraduationDate() {
        assertEquals(testingGraduationDate1, ((Graduate) p1).getGraduationDate(), "getGraduationDate zwraca inna date (lub konstruktor zle przypisuje)!");
        assertSame(testingGraduationDate1, ((Graduate) p1).getGraduationDate(), "getGraduationDate zwraca inna referencje (lub konstruktor zle przypisuje)!");

        assertEquals(testingGraduationDate2, ((Graduate) p2).getGraduationDate(), "getGraduationDate zwraca inna date (lub konstruktor zle przypisuje)!");
        assertSame(testingGraduationDate2, ((Graduate) p2).getGraduationDate(), "getGraduationDate zwraca inna referencje (lub konstruktor zle przypisuje)!");
    }

    @Override
    @Test
    void testToString() {
        String expectedString1 = testingFirstName1 + " " + testingLastName1 +
                ", id number: " + testingIdNumber1 +
                ", average: " + testingAverage1 +
                ", graduation date: " + testingGraduationDate1;
        assertEquals(expectedString1, p1.toString(), "toString zwraca zly lancuch lub konstruktor zle przypisuje!");

        String expectedString2 = testingFirstName2 + " " + testingLastName2 +
                ", id number: " + testingIdNumber2 +
                ", average: " + testingAverage2 +
                ", graduation date: " + testingGraduationDate2;
        assertEquals(expectedString2, p2.toString(), "toString zwraca zly lancuch lub konstruktor zle przypisuje!");
    }

    @Override
    protected String getHintGraduate() {
        return "\nWskazowka: poprawic trzeba metode greater w klasie Student, klasa Graduate powinna ja tylko dziedziczyc!";
    }
}