import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.UUID;
import java.text.DateFormat;
/**
 * Klasa reprezentujaca uzytkownika sklepu
 * @author Szymon Kolanko
 */
public class User {
    /**
     * Record reprezentujacy osobe
     */
    final private Person person;
    /**
     * UUID uzytkownika
     */
    final private UUID id;
    /**
     * Haslo użytownika
     */
    private String password;
    /**
     * email uzytkownika
     */
    private String email;

    /**
     * Konstruktor klasy User
     * @param person
     * @param password
     * @param email
     * @param id
     */
    public User(Person person, String password, String email, UUID id) {
        this.person = person;
        this.id = id;
        this.password = password;
        this.email = email;
    }

    /**
     * Metoda statyczna tworzaca obiekt klasy User z podanych parametrow w formacie String
     * @param idString UUID w formacie String
     * @param email email
     * @param password haslo
     * @param firstName imie
     * @param lastName nazwisko
     * @param dateOfBirth data urodzenia w formacie yyyy-MM-dd
     * @return obiekt klasy User
     */
    static public User valueOf(String idString, String email, String password, String firstName, String lastName, String dateOfBirth) {
        UUID id = UUID.fromString(idString);
        DateFormat myDateFormat = new SimpleDateFormat("yyyy-MM-dd");
        Date date = null;
        try{
            date = myDateFormat.parse(dateOfBirth);
        }
        catch (Exception e){
            System.out.println("Blad konwersji str->Date");
        }
        return new User(new Person(firstName,lastName, date), password, email, id);

    }

    /**
     * Metoda zwracajaca reprezentacje obiektu klasy User w formacie String
     * @return
     */
    @Override
    public String toString() {
        return id.toString() + ',' + email + ',' + password + ',' + person;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public Person getPerson() {
        return person;
    }

    public UUID getId() {
        return id;
    }

    public String getPassword() {
        return password;
    }

    public String getEmail() {
        return email;
    }
}
