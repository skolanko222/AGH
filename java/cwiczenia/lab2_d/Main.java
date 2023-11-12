/**
 * Napisz program, który m.in. przy u¿yciu klas LocalDate, Month i DayOfWeek wyœwietli
 * aktualn¹ datê, liczbê dni pozosta³ych do sylwestra aktualnego roku oraz kalendarz dla odpowiedniego miesi¹ca roku, którego wyjœcie bêdzie dok³adnie identyczne z poni¿szym. Dodatkowe ograniczenie: w pêtli wypisuj¹cej etykiety nazw dni tygodnia (P, W, Œ, ...) oraz w pêtli/pêtlach odpowiedzialnych za numery dni w miesi¹cu nie mo¿na u¿ywaæ ¿adnych zmiennych ca³kowitych (ani int, ani long, ani Integer itd.) – jedn¹ z konsekwencji tego ograniczenia jest punkt V. z poni¿szych.

 (4 pkt.) Bez podania parametrów formalnych programu wyœwietlony bêdzie aktualny miesi¹c w formie:

 Dzisiaj jest: 2023-10-19.
 Do sylwestra zostalo: 73 dni.

 paŸdziernik 2023

 P   W   Œ   C   P   S   N
 1
 2   3   4   5   6   7   8
 9  10  11  12  13  14  15
 16  17  18  19* 20  21  22
 23  24  25  26  27  28  29
 30  31

 (2 pkt.) Z podaniem opcji -m 5 wyœwietlony bêdzie miesi¹c maj aktualnego roku (itp. dla pozosta³ych miesiêcy), tj. dla tego przyk³adu:

 Dzisiaj jest: 2023-10-19.
 Do sylwestra zostalo: 73 dni.

 maj 2023

 P   W   Œ   C   P   S   N
 1   2   3   4   5   6   7
 8   9  10  11  12  13  14
 15  16  17  18  19  20  21
 22  23  24  25  26  27  28
 29  30  31

 (2 pkt.) Z podaniem opcji -m 5 -y 2011 wyœwietlony bêdzie miesi¹c maj 2011 roku (itp. dla pozosta³ych miesiêcy i lat), tj. dla tego przyk³adu:

 Dzisiaj jest: 2023-10-19.
 Do sylwestra zostalo: 73 dni.

 maj 2011

 P   W   Œ   C   P   S   N
 1
 2   3   4   5   6   7   8
 9  10  11  12  13  14  15
 16  17  18  19  20  21  22
 23  24  25  26  27  28  29
 30  31
 (1 pkt.) Je¿eli wyœwietlony miesi¹c jest aktualnym, to po numerze aktualnego dnia niech wyœwietli siê gwiazdka (patrz: np. przyk³adowe wyjœcie dla programu bez podania parametrów).
 (1 pkt.) Nazwa miesi¹ca, skróty nazw dni tygodnia oraz numery dni w miesi¹cu nie mog¹ byæ wpisane rêcznie w programie (tj. nie mog¹ byæ wypisane bezpoœrednio przy pomocy litera³ów czy liczb). Powinny byæ wypisane dziêki odpowiednim klasom – Month, DayOfWeek oraz LocalDate (patrz: wskazówki poni¿ej).

 Ze wzglêdu na to, ¿e nie znamy jeszcze obs³ugi wyj¹tków, zak³adamy, ¿e u¿ytkownik podaje tylko prawid³owe numery miesi¹ca i roku jako parametry formalne.
 Wskazówki:

 Etykiety miesi¹ca/dnia tygodnia w jêzyku polskim uzyskamy dziêki metodzie o nazwie
 String getDisplayName(TextStyle style, Locale locale).
 Z typu wyliczeniowego  TextStyle korzystamy, przekazuj¹c odpowiedni¹ sta³¹ (Enum Constant w dokumentacji), np. TextStyle.SHORT da³aby w efekcie skrócon¹ wersjê odpowiedniej nazwy miesi¹ca/dnia tygodnia. W celu u¿ycia polskich nazw nale¿y przekazaæ do metody obiekt wskazuj¹cy jêzyk new Locale("pl") lub wskazuj¹cy jêzyk i kraj: new Locale("pl", "PL").
 DayOfWeek to równie¿ klasa – typ wyliczeniowy.
 W wypisywaniu z zachowaniem odpowiedniego wyrównania pomo¿e metoda PrintStream printf(String format, Object... args) z odpowiednim specyfikatorem (identycznym jak w C).
 Proszê pamiêtaæ o importowaniu u¿ywanych klas, jeœli s¹ spoza pakietu java.lang.
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
        System.out.println("  P  W  Œ  C  P  S  N");

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