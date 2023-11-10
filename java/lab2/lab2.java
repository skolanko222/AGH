import java.time.LocalDate;
import java.time.DayOfWeek;
import java.time.Month;

import java.time.format.TextStyle;

import java.util.Locale;


public class lab2{
	public static void main(String[] args)
	{
		int m;
		int y;
		LocalDate today = LocalDate.now();
		if(args.length == 2)
		{
			m = Integer.parseInt(args[1]);
			today = today.withMonth(m);
		}
		if(args.length == 4)
		{
			m = Integer.parseInt(args[1]);
			y = Integer.parseInt(args[3]);
			today = today.withMonth(m);
			today = today.withYear(y);
		}
		
		System.out.println("Dzisiaj jest: " + today);
		int dzienRoku = today.getDayOfYear();
		if(dzienRoku < 256)
		{
			System.out.print("Najblizszy dzien programisty: " + today.getYear() + "-09-13");
		}
		else
		{
			System.out.print("Najblizszy dzien programisty: " + (today.getYear()+1) + "-09-13");
		}
		if(today.getMonth() == Month.SEPTEMBER )
			System.out.println("#\n");
		else
			System.out.println("\n");

		System.out.println();
		System.out.println( today.getMonth().getDisplayName(TextStyle.SHORT, new Locale("pl")) +  " " + today.getYear() + "\n    ");

		for(DayOfWeek day = DayOfWeek.MONDAY; ; day = day.plus(1))
		{
			System.out.print(day.getDisplayName(TextStyle.NARROW, new Locale("pl")) + "  ");
			if(day == DayOfWeek.SUNDAY)
			{
				break;
			}
		}
		System.out.println();

		LocalDate j = today.withDayOfMonth(1);
		for(DayOfWeek i = DayOfWeek.MONDAY; ; i = i.plus(1))
		{
			
			if(i != today.withDayOfMonth(1).getDayOfWeek())
			{
				System.out.printf("   ");
			}
			else
			{
				break;
			}
			j.plusDays(1);
		}

		for(; ; j = j.plusDays(1))
		{
			System.out.printf("%2d ", j.getDayOfMonth());
			if(j.getDayOfWeek() == DayOfWeek.SUNDAY)
			{
				System.out.println();
			}
			if(j.getDayOfMonth() == today.lengthOfMonth())
			{
				break;
			}
			
		}
		
	}
}