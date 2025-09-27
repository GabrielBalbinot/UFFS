public class Main
{
	public static void main(String[] args) {
	    
	    Livro semTitulo = new Livro();
	    Livro comTitulo = new Livro("Hamlet", "William Shakespeare", 1623);
	    
	    semTitulo.imprime();
	    System.out.println();
	    comTitulo.imprime();
	    
	}
}