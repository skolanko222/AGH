import java.util.EmptyStackException;

/**
 * The interface represents a LIFO functionality (last-in-first-out).
 *
 * @param <T> type of the values that are stored in the stack.
 */
public interface StackInterface<T> {
    /**
     * Tests if {@code this} stack is empty.
     *
     * @return {@code true} if {@code this} stack is empty, {@code false} otherwise.
     */
    boolean isEmpty();

    /**
     * Pushes a new value onto the top of {@code this} stack.
     *
     * @param x new value to push onto the top of {@code this} stack.
     * @throws NullPointerException if {@code x} is null.
     */
    void push(T x) throws NullPointerException;

    /**
     * Removes and returns the top value of {@code this} stack.
     *
     * @return the top value of {@code this} stack (which is removed by the function).
     * @throws EmptyStackException if {@code this} stack is empty.
     */
    T pop() throws EmptyStackException;

    /**
     * Returns the top value of {@code this} stack.
     *
     * @return the top value of {@code this} stack.
     * @throws EmptyStackException if {@code this} stack is empty.
     */
    T peek() throws EmptyStackException;

    /**
     * Returns the position of the element with value {@code el} if it occurs as an item on {@code this} stack.
     * The position is equal to the distance from the top of {@code this} stack to the nearest occurance of the item with value {@code el},
     * eg. {@code 0} if the top of {@code this} stack equals to {@code el}, {@code 1} if the previous item equals to {@code el}, etc.
     * The method returns -1 if {@code this} stack does not contain an item with the value {@code el}.
     *
     * @param el value to find
     * @return non-negative position of the item with value {@code el} if it occurs on {@code this stack}; -1 otherwise.
     * @throws NullPointerException if {@code el} is null.
     */
    int find(T el) throws NullPointerException;
}