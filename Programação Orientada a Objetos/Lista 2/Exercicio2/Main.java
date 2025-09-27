public class Main
{
	public static void main(String[] args) {
	    
	    System.out.println(Calculadora.soma(1, 2));
	    System.out.println(Calculadora.soma(1.0, 2.0));
	    System.out.println(Calculadora.soma(1, 2.0));
	    System.out.println(Calculadora.soma(1, 3.33));
	    System.out.println(Calculadora.soma(0.5, 99));
	    System.out.println(Calculadora.soma(.66, -3.66));
	    System.out.println(Calculadora.soma(100.0, -4));
	    System.out.println(Calculadora.soma(-1, -2));
	    System.out.println(Calculadora.soma(-20, 20));
	    System.out.println(Calculadora.soma(3.14159265359, 3.14159265359));
	    System.out.println(Calculadora.soma(0, 0.0));
	    
	}
}