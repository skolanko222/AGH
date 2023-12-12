import java.time.LocalDate;

public class Graduate extends Student{
    private LocalDate graduationDate;

    public Graduate(String firstName, String lastName, int idNumber, double average, LocalDate graduationDate) throws NullPointerException, IllegalArgumentException{
        super(firstName, lastName, idNumber, average);
        if(graduationDate == null)
            throw new NullPointerException("Data ukończenia studiów nie może być null!");
        this.graduationDate = graduationDate;
    }
    public LocalDate getGraduationDate(){
        return graduationDate;
    }
    public void setGraduationDate(LocalDate graduationDate){
        if(graduationDate == null)
            throw new NullPointerException("Data ukończenia studiów nie może być null!");
        this.graduationDate = graduationDate;
    }
    @Override
    public String toString(){
        if(graduationDate.equals( LocalDate.now()))
            return super.toString() + "0 " + graduationDate;
        else
        return super.toString() + ", graduation date: " + graduationDate;
    }

}
