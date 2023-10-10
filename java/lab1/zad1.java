import java.util.Random;


public class zad1 {
    public static void main(String[] args) {

		int n = Integer.parseInt(args[0]);
		double rMax = Double.parseDouble(args[1]);
		Random rand = new Random();

		double alpha = rand.nextDouble() * 2 * Math.PI;

		for(int i = 0; i < n; i++)
		{
			alpha = rand.nextDouble() * 2 * Math.PI;
			double r = rand.nextDouble()*rMax;
			System.out.println(Math.cos(alpha) * r + " " + Math.sin(alpha)*r);
		}

    }

}