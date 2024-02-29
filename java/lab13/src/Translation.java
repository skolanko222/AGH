import lombok.NonNull;
import lombok.Value;

@Value
public class Translation {
    int grammaticalNumber;
    @NonNull
    String word1;
    String word2;
    String word3;
}