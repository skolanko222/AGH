/**
 * Movie
 * Rekord przechowujący informacje o filmie.
 */
public record Movie(String title, String director, int duration) {
    @Override
    public String toString() {
        return title + ',' + director + ',' + duration;
    }
}
