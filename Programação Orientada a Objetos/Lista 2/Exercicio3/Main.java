public class Main
{
	public static void main(String[] args) {
	    
	    double c = 25.0;
	    double f = 100.0;
	    
	    double temperaturaEmFahrenheit = Conversor.celsiusParaFahrenheit(c);
	    double temperaturaEmCelsius = Conversor.fahrenheitParaCelsius(f);
	    
	    System.out.printf("%.1f°C em F: %.1f°\n", c, temperaturaEmFahrenheit);
	    System.out.printf("%.1f°F em C: %.1f°\n", f, temperaturaEmCelsius);
	    
	}
}