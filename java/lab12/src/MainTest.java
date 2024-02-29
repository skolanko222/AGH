import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

class MainTest {

    @Test
    void translate() {
        Main.translate("a", "b", "c", "+", "d", "e", "*", "+");

        assertEquals("(a+b)", Main.translate("a", "b", "+"));
        assertEquals("((a+b)*(g-h))", Main.translate("a", "b", "+", "g", "h", "-", "*"));
        assertEquals("((a+b)-(((c-d)*e)/f))", Main.translate("a", "b", "+", "c", "d", "-", "e", "*", "f", "/", "-"));
        assertEquals("BLAD DANYCH WEJSCIOWYCH! Bledny operator: ^", Main.translate("a","b","^"));
        assertEquals("BLAD DANYCH WEJSCIOWYCH! Na stosie jest za malo elementow, zeby wykonac operacje!", Main.translate("a","b","+","c","d","-","e","*","/","-"));
//        assertEquals("BLAD DANYCH WEJSCIOWYCH! Koniec algorytmu, a stos nie jest pusty: (a+b)", Main.translate("a","b","+","c","d","-","e","*","f","/"));


    }
}