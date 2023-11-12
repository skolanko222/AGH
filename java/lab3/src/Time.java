import java.util.Objects;
public class Time {
    private int dzien=0;
    private int godzina=0;
    private int minuta=0;
    private int sekunda=0;

    final static public int SECONDS_PER_MINUTE = 60;
    final static public int MINUTES_PER_HOUR = 60;
    final static public int HOURS_PER_DAY = 24;

    final static Time ZERO;
    static{ZERO = new Time();}


    final static public Time ONE_SECOND = new Time(0,0,0,1);

    final static public Time ONE_MINUTE = new Time(0,0,1,0);

    final static public Time ONE_HOUR = new Time(0,1,0,0);

    final static public Time ONE_DAY = new Time(1,0,0,0);

    final static public Time ONE_YEAR = new Time(365,0,0,0);

    Time(){

    }
    Time(Time copy){
        this.dzien = copy.dzien;
        this.godzina = copy.godzina;
        this.minuta = copy.minuta;
        this.sekunda = copy.sekunda;

    }
    Time(int d, int h, int m, int s){
        setDays(d);
        setHours(h);
        setMinutes(m);
        setSeconds(s);
    }
    @Override
    public String toString(){
        return String.format("%d:%02d:%02d:%02d",dzien,godzina,minuta,sekunda);
    }
    public static Time timeOf(String napis)
    {
        String[] splitted = napis.split(":");
        return new Time(Integer.parseInt(splitted[0]),Integer.parseInt(splitted[1]),Integer.parseInt(splitted[2]),Integer.parseInt(splitted[3]) );

    }
    private static boolean checkBoundaries(int a, int b, int t )
    {
        if(t < b && t >= a){
            return true;
        }
        else{
            return false;
        }
    }
    public void setDays(int x) {if(checkBoundaries(0,2147483647, x)) {dzien = x;} else{System.out.println("Liczba dni: " +x+" spoza przedzialu [0, 2147483647)!");}}
    public void setHours(int x) {        if(checkBoundaries(0,24, x)) {godzina = x;} else{System.out.println("Liczba godzin: " +x+" spoza przedzialu [0, 24)!");}
    }
    public void setMinutes(int x) {        if(checkBoundaries(0,60, x)) {minuta = x;} else{System.out.println("Liczba minut: " +x+" spoza przedzialu [0, 60)!");}
    }
    public void setSeconds(int x) {        if(checkBoundaries(0,60, x)) {sekunda = x;} else{System.out.println("Liczba sekund: " +x+" spoza przedzialu [0, 60)!");};}
    public int getDays() {return dzien;}

    public int getHours() {return godzina;}

    public int getMinutes() {return minuta;}

    public int getSeconds() {return sekunda;}

    public void addDays(int d){
        dzien= d+dzien;
    }
    public void addMinutes(int d){
        int temp = minuta + d;
        setMinutes(temp%MINUTES_PER_HOUR);
        addHours(temp/MINUTES_PER_HOUR);
    }
    public void addHours(int d){
        int temp = godzina + d;
        setHours(temp%HOURS_PER_DAY);
        addDays(temp/HOURS_PER_DAY);
    }
    public void addSeconds(int d){
        int temp = sekunda + d;
        setSeconds(temp%SECONDS_PER_MINUTE);
        addMinutes(temp/SECONDS_PER_MINUTE);
    }
    public static Time plusTime(Time t1, Time t2){
        Time temp = new Time(t1);
        temp.addSeconds(t2.getSeconds());
        temp.addMinutes(t2.getMinutes());
        temp.addHours(t2.getHours());
        temp.addDays(t2.getDays());
        return temp;

    }
    public static Time copyOf(Time toBeCopied){
        return new Time(toBeCopied);
    }

    public boolean equals(Object t){
        if(this == t ) return true;
        if(t == null) return false;
        if(getClass() != t.getClass())
            return false;
        Time newT = (Time)t;
        return sekunda == newT.getSeconds() && minuta == newT.getMinutes() && godzina == newT.getHours() && dzien == newT.getDays();
    }

    public static Time times(Time t, int x){
        Time temp = new Time(t);
        for(int i = 0; i < x-1; i++){
            temp = Time.plusTime(temp,t);
        }
        return temp;
    }

    @Override
    public int hashCode() {
        return Objects.hash(dzien, godzina, minuta, sekunda);
    }

}
