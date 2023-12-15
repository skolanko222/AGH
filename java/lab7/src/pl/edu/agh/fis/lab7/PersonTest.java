package pl.edu.agh.fis.lab7;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class PersonTest {
    protected Person p1;
    protected Person p2;
    protected static final String testingFirstName1 = "Kazimierz";
    protected static final String testingLastName1 = "Nowak";

    protected static final String testingFirstName2 = "Mariola";
    protected static final String testingLastName2 = "Kwiatkowska";

    protected static final String hintObjects = "gotowe metody z klasy Objects, patrz: omowienie materialow z lab. 6 na UPeL-u.";
    protected static final String hintExt = "zgloszenie tego wyjatku powinno wynikac z wywolania odziedziczonego konstruktora.";
    protected String getMessage(String methodName, String parameterInfo, String hint) {
        return methodName + " musi zglosic wyjatek, jesli " + parameterInfo + "!\n" +
                "Wskazowka: " + hint;
    }

    @BeforeEach
    void setUp() {
        p1 = new Person(testingFirstName1, testingLastName1) {
            @Override
            public Person greater(Person ob) {
                return null;
            }
        };

        p2 = new Person(testingFirstName2, testingLastName2) {
            @Override
            public Person greater(Person ob) {
                return null;
            }
        };
    }

    @Test
    void testConstructor() {
        assertThrows(NullPointerException.class, () -> {
                    new Person(null, testingLastName1) {
                        @Override
                        public Person greater(Person ob) {
                            return null;
                        }
                    };
                },
                getMessage("Konstruktor", "pierwszy parametr jest rowny null", hintObjects)
        );

        assertThrows(NullPointerException.class, () -> {
                    new Person(testingFirstName1, null) {
                        @Override
                        public Person greater(Person ob) {
                            return null;
                        }
                    };
                },
                getMessage("Konstruktor", "drugi parametr jest rowny null", hintObjects)
        );

        assertThrows(NullPointerException.class, () -> {
                    new Person(null, null) {
                        @Override
                        public Person greater(Person ob) {
                            return null;
                        }
                    };
                },
                getMessage("Konstruktor", "oba parametry sa rowne null", hintObjects)
        );
    }

    @Test
    void testGetFirstName() {
        assertEquals(testingFirstName1, p1.getFirstName(), "getFirstName zwraca inny lancuch (lub konstruktor zle przypisuje)!");
        assertSame(testingFirstName1, p1.getFirstName(), "getFirstName zwraca inna referencje (lub konstruktor zle przypisuje)!");

        assertEquals(testingFirstName2, p2.getFirstName(), "getFirstName zwraca inny lancuch (lub konstruktor zle przypisuje)!");
        assertSame(testingFirstName2, p2.getFirstName(), "getFirstName zwraca inna referencje (lub konstruktor zle przypisuje)!");
    }

    @Test
    void testGetLastName() {
        assertEquals(testingLastName1, p1.getLastName(), "getLastName zwraca inny lancuch (lub konstruktor zle przypisuje)!");
        assertSame(testingLastName1, p1.getLastName(), "getLastName zwraca inna referencje (lub konstruktor zle przypisuje)!");

        assertEquals(testingLastName2, p2.getLastName(), "getLastName zwraca inny lancuch! (lub konstruktor zle przypisuje)");
        assertSame(testingLastName2, p2.getLastName(), "getLastName zwraca inna referencje! (lub konstruktor zle przypisuje)");
    }

    @Test
    void testSetFirstName() {
        assertThrows(NullPointerException.class, () -> p1.setFirstName(null),
                getMessage("Metoda setFirstName", "parametr jest rowny null", hintObjects));

        p1.setFirstName(testingFirstName2);
        assertEquals(testingFirstName2, p1.getFirstName(), "setFirstName zle przypisuje? Albo getFirstName zle zwraca.");
        assertSame(testingFirstName2, p1.getFirstName(), "setFirstName nie przepisuje referencji? Albo getFirstName zle zwraca.");

        p2.setFirstName(testingFirstName1);
        assertEquals(testingFirstName1, p2.getFirstName(), "setFirstName zle przypisuje? Albo getFirstName zle zwraca.");
        assertSame(testingFirstName1, p2.getFirstName(), "setFirstName nie przepisuje referencji? Albo getFirstName zle zwraca.");
    }

    @Test
    void testSetLastName() {
        assertThrows(NullPointerException.class, () -> p1.setLastName(null),
                getMessage("Metoda setLastName", "parametr jest rowny null", hintObjects));

        p1.setLastName(testingLastName2);
        assertEquals(testingLastName2, p1.getLastName(), "setLastName zle przypisuje? Albo getLastName zle zwraca.");
        assertSame(testingLastName2, p1.getLastName(), "setLastName nie przepisuje referencji? Albo getLastName zle zwraca.");

        p2.setLastName(testingLastName1);
        assertEquals(testingLastName1, p2.getLastName(), "setLastName zle przypisuje? Albo getLastName zle zwraca.");
        assertSame(testingLastName1, p2.getLastName(), "setLastName nie przepisuje referencji? Albo getLastName zle zwraca.");
    }

    @Test
    void testToString() {
        String expectedString1 = testingFirstName1 + " " + testingLastName1;
        assertEquals(expectedString1, p1.toString(), "toString zwraca zly lancuch lub konstruktor zle przypisuje!");
        String expectedString2 = testingFirstName2 + " " + testingLastName2;
        assertEquals(expectedString2, p2.toString(), "toString zwraca zly lancuch lub konstruktor zle przypisuje!");
    }
}