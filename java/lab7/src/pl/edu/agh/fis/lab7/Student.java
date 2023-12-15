package pl.edu.agh.fis.lab7;

public class Student extends Person{
    private int idNumber;
    private double average;

    public Student(String firstName, String lastName, int idNumber, double average) throws NullPointerException, IllegalArgumentException{
        super(firstName, lastName);
        if(idNumber < 0)
            throw new IllegalArgumentException("Numer indeksu nie może być ujemny!");
        if(average < 2.0 || average > 5.0)
            throw new IllegalArgumentException("Średnia nie może być mniejsza niż 2.0 i większa niż 5.0!");
        this.idNumber = idNumber;
        this.average = average;
    }
    public Student greater(Person ob){
        if(ob instanceof Student){
            if(this.average >= ((Student) ob).average)
                return this;
            else
                return (Student) ob;
        }
        else
            return null;
    }
    public int getIdNumber(){
        return idNumber;
    }
    public double getAverage(){
        return average;
    }
    public void setAverage(double average){
        this.average = average;
    }
    @Override
    public String toString(){
        return super.toString() + ", id number: " + idNumber + ", average: " + average;
    }

}
