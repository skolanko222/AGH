import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.UUID;

/**
 * VHS class
 *
 * @author Szymon Kolanko
 *
 */
public class VHS {
    /**
     * Movie object, represents movie
     */
    final private Movie movie;
    /**
     * UUID object, represents VHS ID
     */
    final private UUID id;
    /**
     * Date object, represents rental date
     */
    private Date rentalDate;
    /**
     * Date object, represents return date
     */
    private Date returnDate;

    /**
     * VHS constructor
     * @param movie Movie object
     * @param id UUID object
     * @param rentalDate Date object
     * @param returnDate Date object
     */
    public VHS(Movie movie, UUID id, Date rentalDate, Date returnDate) {
        this.movie = movie;
        this.id = id;
        this.rentalDate = rentalDate;
        this.returnDate = returnDate;
    }

    /**
     *
     * @param id string representation of UUID
     * @param title movie title
     * @param duration string representation of movie duration
     * @param director movie director
     * @param rentalDateStr string representation of rental date
     * @param returnDateStr string representation of return date
     * @return VHS object
     */
    public static VHS valueOf(String id, String title, String duration, String director, String rentalDateStr, String returnDateStr) {
        int durationInt = 0;
        DateFormat myDateFormat = new SimpleDateFormat("yyyy-MM-dd");
        UUID uuid ;
        Date rentalDate = new Date();
        Date returnDate = new Date();
        try{
            durationInt = Integer.parseInt(duration);
        } catch (Exception e) {
            System.out.println("Error parsing duration to int!");
        }
        Movie movie = new Movie(title, director, durationInt);
        try {
            uuid = UUID.fromString(id);
        } catch (Exception e) {
            uuid = UUID.randomUUID(); // if id is not valid, generate random UUID
            System.out.println("Error parsing ID to UUID object!");
        }
        try{
            rentalDate = myDateFormat.parse(rentalDateStr);
            returnDate = myDateFormat.parse(returnDateStr);

        } catch (Exception e) {
            System.out.println("Error parsing data to Date object!");

        }
        return new VHS(movie, uuid, rentalDate, returnDate);
    }

    @Override
    public String toString() {
        DateFormat myDateFormat = new SimpleDateFormat("yyyy-MM-dd");
        return movie.title() + "," + movie.director() + "," + movie.duration() + "," + id.toString() + "," + myDateFormat.format(rentalDate) + "," + myDateFormat.format(returnDate);
    }

    public void setRentalDate(Date rentalDate) {
        this.rentalDate = rentalDate;
    }

    public void setReturnDate(Date returnDate) {
        this.returnDate = returnDate;
    }
}
