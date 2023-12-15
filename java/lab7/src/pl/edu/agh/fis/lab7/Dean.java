package pl.edu.agh.fis.lab7;

public class Dean extends Person{
    private int startYear;
    private int endYear;
    private String degree;

    public Dean(String degree, String firstName, String lastName, int startYear, int endYear) throws NullPointerException, IllegalArgumentException{
        super(firstName, lastName);
        if(degree == null)
            throw new NullPointerException("Tytuł nie może być null!");
        if(startYear < 0)
            throw new IllegalArgumentException("Rok rozpoczęcia nie może być ujemny!");
        if(endYear < 0)
            throw new IllegalArgumentException("Rok zakończenia nie może być ujemny!");
        if(startYear > endYear)
            throw new IllegalArgumentException("Rok rozpoczęcia nie może być większy niż rok zakończenia!");
        this.degree = degree;
        this.startYear = startYear;
        this.endYear = endYear;
    }
    @Override
    public Person greater(Person ob){
        if(ob instanceof Dean){
            if(this.endYear - this.startYear >= ((Dean) ob).endYear -((Dean) ob).startYear)
                return this;
            else
                return (Dean) ob;
        }
        else
            return null;
    }
    public String getDegree(){
        return degree;
    }
    public int getStartYear(){
        return startYear;
    }
    public int getEndYear(){
        return endYear;
    }
    public void setDegree(String degree){
        if(degree == null)
            throw new NullPointerException("Tytuł nie może być null!");
        this.degree = degree;
    }
    public void setStartYear(int startYear){
        if(startYear < 0)
            throw new IllegalArgumentException("Rok rozpoczęcia nie może być ujemny!");
        if(startYear > endYear)
            throw new IllegalArgumentException("Rok rozpoczęcia nie może być większy niż rok zakończenia!");
        this.startYear = startYear;
    }
    public void setEndYear(int endYear){
        if(endYear < 0)
            throw new IllegalArgumentException("Rok zakończenia nie może być ujemny!");
        if(startYear > endYear)
            throw new IllegalArgumentException("Rok rozpoczęcia nie może być większy niż rok zakończenia!");
        this.endYear = endYear;
    }
    @Override
    public String toString(){
        return degree + " " + super.toString() + ", Dean of the Faculty since " + startYear + " to " + endYear;
    }

}
