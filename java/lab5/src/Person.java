import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;

/**
 * Record reprezentujacy osobe
 * @param firstName
 * @param lastName
 * @param dateOfBirth data w formacie yyyy-MM-dd
 * @author Szymon Kolanko
 */
public record Person (String firstName, String lastName, Date dateOfBirth){
    /**
     * @return zwraca date urodzenia w formacie yyyy-MM-dd
     */
    @Override
    public String toString() {
        DateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd");
        return firstName + ',' + lastName + ','+ dateFormat.format(dateOfBirth);
    }
}