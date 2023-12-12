import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class DeanTest extends PersonTest {
    private static final int testingStartYear1 = 2012;
    private static final int testingEndYear1 = 2016;
    private static final String testingDegree1 = "prof. hab. inz.";

    private static final int testingStartYear2 = 2016;
    private static final int testingEndYear2 = 2024;
    private static final String testingDegree2 = "dr hab.";

    @Override
    @BeforeEach
    void setUp() {
        p1 = new Dean(testingDegree1, testingFirstName1, testingLastName1, testingStartYear1, testingEndYear1);
        p2 = new Dean(testingDegree2, testingFirstName2, testingLastName2, testingStartYear2, testingEndYear2);
    }

    @Override
    @Test
    void testConstructor() {
        assertThrows(NullPointerException.class,
                () -> new Dean(null, testingFirstName1, testingLastName1, testingStartYear1, testingEndYear1),
                getMessage("Konstruktor", "pierwszy parametr jest rowny null", hintObjects)
        );
        assertThrows(NullPointerException.class,
                () -> new Dean(testingDegree1, null, testingLastName1, testingStartYear1, testingEndYear1),
                getMessage("Konstruktor", "drugi parametr jest rowny null", hintExt)
        );
        assertThrows(NullPointerException.class,
                () -> new Dean(testingDegree1, testingFirstName1, null, testingStartYear1, testingEndYear1),
                getMessage("Konstruktor", "ostatni parametr jest rowny null", hintExt)
        );
    }

    @Test
    void testGetStartYear() {
        assertEquals(testingStartYear1, ((Dean) p1).getStartYear(), "getStartYear zwraca inna wartosc (lub konstruktor zle przypisuje)!");
        assertEquals(testingStartYear2, ((Dean) p2).getStartYear(), "getStartYear zwraca inna wartosc (lub konstruktor zle przypisuje)!");
    }

    @Test
    void testGetEndYear() {
        assertEquals(testingEndYear1, ((Dean) p1).getEndYear(), "getStartYear zwraca inna wartosc (lub konstruktor zle przypisuje)!");
        assertEquals(testingEndYear2, ((Dean) p2).getEndYear(), "getStartYear zwraca inna wartosc (lub konstruktor zle przypisuje)!");
    }

    @Test
    void testGetDegree() {
        assertEquals(testingDegree1, ((Dean) p1).getDegree(), "getDegree zwraca inny lancuch (lub konstruktor zle przypisuje)!");
        assertSame(testingDegree1, ((Dean) p1).getDegree(), "getDegree zwraca inna referencje (lub konstruktor zle przypisuje)!");

        assertEquals(testingDegree2, ((Dean) p2).getDegree(), "getDegree zwraca inny lancuch (lub konstruktor zle przypisuje)!");
        assertSame(testingDegree2, ((Dean) p2).getDegree(), "getDegree zwraca inna referencje (lub konstruktor zle przypisuje)!");
    }

    @Test
    void testSetDegree() {
        assertThrows(NullPointerException.class, () -> ((Dean) p1).setDegree(null),
                getMessage("Metoda setDegree", "parametr jest rowny null", hintObjects));

        ((Dean) p1).setDegree(testingDegree2);
        assertEquals(testingDegree2, ((Dean) p1).getDegree(), "setDegree zle przypisuje? Albo getDegree zle zwraca.");
        assertSame(testingDegree2, ((Dean) p1).getDegree(), "setDegree nie przepisuje referencji? Albo getDegree zle zwraca.");

        ((Dean) p2).setDegree(testingDegree1);
        assertEquals(testingDegree1, ((Dean) p2).getDegree(), "setDegree zle przypisuje? Albo getDegree zle zwraca.");
        assertSame(testingDegree1, ((Dean) p2).getDegree(), "setDegree nie przepisuje referencji? Albo getDegree zle zwraca.");
    }

    @Test
    void testSetEndYear() {
        ((Dean) p1).setEndYear(testingEndYear2);
        assertEquals(testingEndYear2, ((Dean) p1).getEndYear(), "setEndYear zle przypisuje? Albo getEndYear zle zwraca.");

        ((Dean) p2).setEndYear(testingEndYear1);
        assertEquals(testingEndYear1, ((Dean) p2).getEndYear(), "setEndYear zle przypisuje? Albo getEndYear zle zwraca.");
    }

    @Test
    void testGreater() {
        assertSame(p1, p1.greater(p1), "Jesli metoda greater porownuje dziekanow o tym samym stazu, to musi zwrocic ktorakolwiek referencje!");

        assertSame(p2, p2.greater(p1), "Metoda greater musi zwrocic referencje do dziekana o dluzszym stazu!");
        assertSame(p2, p1.greater(p2), "Metoda greater musi zwrocic referencje do dziekana o dluzszym stazu!");

        Person p3 = new Student("Testowy", "Student", 888888, 2.0);
        assertNull(p1.greater(p3), "Jesli przekazany do greater obiekt nie jest obiektem klasy Dean (lub pochodnej), to nalezy zwrocic null!");

        p3 = new Dean("prof.", "Pochodny", "Dziekan", 2024, 2028) {
        };
        assertNotNull(p1.greater(p3), "Jesli przekazany do greater obiekt jest obiektem klasy pochodnej do Dean, to nalezy go normalnie porownac!");
    }

    @Override
    @Test
    void testToString() {
        String expectedString1 = testingDegree1 + " " +
                testingFirstName1 + " " + testingLastName1 +
                ", Dean of the Faculty since " + testingStartYear1 +
                " to " + testingEndYear1;
        assertEquals(expectedString1, p1.toString(), "toString zwraca zly lancuch lub konstruktor zle przypisuje!");

        String expectedString2 = testingDegree2 + " " +
                testingFirstName2 + " " + testingLastName2 +
                ", Dean of the Faculty since " + testingStartYear2 +
                " to " + testingEndYear2;
        assertEquals(expectedString2, p2.toString(), "toString zwraca zly lancuch lub konstruktor zle przypisuje!");
    }
}