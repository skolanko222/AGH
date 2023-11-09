/**
 * Napisz program, kt�ry m.in. przy u�yciu klas LocalDate, Month i DayOfWeek wy�wietli
 * aktualn� dat�, liczb� dni pozosta�ych do sylwestra aktualnego roku oraz kalendarz dla odpowiedniego miesi�ca roku, kt�rego wyj�cie b�dzie dok�adnie identyczne z poni�szym. Dodatkowe ograniczenie: w p�tli wypisuj�cej etykiety nazw dni tygodnia (P, W, �, ...) oraz w p�tli/p�tlach odpowiedzialnych za numery dni w miesi�cu nie mo�na u�ywa� �adnych zmiennych ca�kowitych (ani int, ani long, ani Integer itd.) � jedn� z konsekwencji tego ograniczenia jest punkt V. z poni�szych.

 (4 pkt.) Bez podania parametr�w formalnych programu wy�wietlony b�dzie aktualny miesi�c w formie:

 Dzisiaj jest: 2023-10-19.
 Do sylwestra zostalo: 73 dni.

 pa�dziernik 2023

 P   W   �   C   P   S   N
 1
 2   3   4   5   6   7   8
 9  10  11  12  13  14  15
 16  17  18  19* 20  21  22
 23  24  25  26  27  28  29
 30  31

 (2 pkt.) Z podaniem opcji -m 5 wy�wietlony b�dzie miesi�c maj aktualnego roku (itp. dla pozosta�ych miesi�cy), tj. dla tego przyk�adu:

 Dzisiaj jest: 2023-10-19.
 Do sylwestra zostalo: 73 dni.

 maj 2023

 P   W   �   C   P   S   N
 1   2   3   4   5   6   7
 8   9  10  11  12  13  14
 15  16  17  18  19  20  21
 22  23  24  25  26  27  28
 29  30  31

 (2 pkt.) Z podaniem opcji -m 5 -y 2011 wy�wietlony b�dzie miesi�c maj 2011 roku (itp. dla pozosta�ych miesi�cy i lat), tj. dla tego przyk�adu:

 Dzisiaj jest: 2023-10-19.
 Do sylwestra zostalo: 73 dni.

 maj 2011

 P   W   �   C   P   S   N
 1
 2   3   4   5   6   7   8
 9  10  11  12  13  14  15
 16  17  18  19  20  21  22
 23  24  25  26  27  28  29
 30  31
 (1 pkt.) Je�eli wy�wietlony miesi�c jest aktualnym, to po numerze aktualnego dnia niech wy�wietli si� gwiazdka (patrz: np. przyk�adowe wyj�cie dla programu bez podania parametr�w).
 (1 pkt.) Nazwa miesi�ca, skr�ty nazw dni tygodnia oraz numery dni w miesi�cu nie mog� by� wpisane r�cznie w programie (tj. nie mog� by� wypisane bezpo�rednio przy pomocy litera��w czy liczb). Powinny by� wypisane dzi�ki odpowiednim klasom � Month, DayOfWeek oraz LocalDate (patrz: wskaz�wki poni�ej).

 Ze wzgl�du na to, �e nie znamy jeszcze obs�ugi wyj�tk�w, zak�adamy, �e u�ytkownik podaje tylko prawid�owe numery miesi�ca i roku jako parametry formalne.
 Wskaz�wki:

 Etykiety miesi�ca/dnia tygodnia w j�zyku polskim uzyskamy dzi�ki metodzie o nazwie
 String getDisplayName(TextStyle style, Locale locale).
 Z typu wyliczeniowego  TextStyle korzystamy, przekazuj�c odpowiedni� sta�� (Enum Constant w dokumentacji), np. TextStyle.SHORT da�aby w efekcie skr�con� wersj� odpowiedniej nazwy miesi�ca/dnia tygodnia. W celu u�ycia polskich nazw nale�y przekaza� do metody obiekt wskazuj�cy j�zyk new Locale("pl") lub wskazuj�cy j�zyk i kraj: new Locale("pl", "PL").
 DayOfWeek to r�wnie� klasa � typ wyliczeniowy.
 W wypisywaniu z zachowaniem odpowiedniego wyr�wnania pomo�e metoda PrintStream printf(String format, Object... args) z odpowiednim specyfikatorem (identycznym jak w C).
 Prosz� pami�ta� o importowaniu u�ywanych klas, je�li s� spoza pakietu java.lang.
 */

import java.time.LocalDate;
import java.time.temporal.ChronoUnit;
import java.util.Calendar;
import java.util.Locale;


class Main {
    public static void printCalendar(int month, int year){
        Calendar calendar = Calendar.getInstance();
        System.out.println("Dzisiaj jest: " + LocalDate.now());
        System.out.println("Do sylwestra zostalo: " + LocalDate.now().until(LocalDate.of(LocalDate.now().getYear(), 12, 31), ChronoUnit.DAYS) + " dni.\n");
        System.out.println("   " + calendar.getDisplayName(Calendar.MONTH, Calendar.LONG, new Locale("pl")) + " " + LocalDate.now().getYear());
        System.out.println("  P  W  �  C  P  S  N");

        calendar.set(LocalDate.now().getYear(), LocalDate.now().getMonthValue() - 1, 1);
        var dayOfWeek = calendar.get(Calendar.DAY_OF_WEEK);
        var dayOfMonth = calendar.getActualMaximum(Calendar.DAY_OF_MONTH);
        for (int i = 1; i < dayOfWeek; i++) {
            System.out.print("    ");
        }

        for (int i = 1; i <= dayOfMonth; i++) {
            if (i == LocalDate.now().getDayOfMonth() && LocalDate.now().getMonthValue() == LocalDate.now().getMonthValue()) {
                System.out.printf("%3d*", i);
            } else {
                System.out.printf("%3d", i);
            }
            if ((i + dayOfWeek - 1) % 7 == 0) {
                System.out.println();
            }
        }

    }


    public static void main(String[] args) {
        if (args.length == 0) {
            printCalendar(-1, -1);
        } else if (args.length == 1) {
            printCalendar(Integer.parseInt(args[0]), -1);
        } else if (args.length == 2) {
            printCalendar(Integer.parseInt(args[0]), Integer.parseInt(args[1]));
        }


    }

}