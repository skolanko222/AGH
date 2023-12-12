abstract public class Person {
    private String firstName;
    private String lastName;

    abstract public Person greater(Person ob);

    public Person(String firstName, String lastName) throws NullPointerException {
        if (firstName == null || lastName == null) {
            throw new NullPointerException("Imię ani nazwisko nie może byc null!");
        }
        this.firstName = firstName;
        this.lastName = lastName;
    }

    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public void setFirstName(String firstName) {
        if(firstName == null)
            throw new NullPointerException("Imię nie może być null!");
        this.firstName = firstName;
    }

    public void setLastName(String lastName) {
        if(lastName == null)
            throw new NullPointerException("Nazwisko nie może być null!");
        this.lastName = lastName;
    }

    @Override
    public String toString() {
        return firstName + " " + lastName;
    }
}
