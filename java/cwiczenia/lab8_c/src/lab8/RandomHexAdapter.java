package lab8;

import java.io.IOException;
import java.nio.CharBuffer;
import java.nio.ReadOnlyBufferException;

final public class RandomHexAdapter extends RandomHex implements Readable{

    private final int amount;

    public RandomHexAdapter(int length, int amount) {
        super(length);
        this.amount = amount;
    }
    @Override
    public int read(CharBuffer cb) throws IOException {
        try {
            for(int i = 0; i < amount; i++){
                cb.append(rand());
                cb.append("\n");
            }

            return -1;
        } catch (NullPointerException e) {
            return -1;
        }
        catch (ReadOnlyBufferException e){
            System.out.println("Buffer is read only");
            return -1;
        }
    }
}
