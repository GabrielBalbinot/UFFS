public class Livro {
    
    public String titulo;
    public String autor;
    public int anoPublicacao;
    
    public Livro() {
        
        this.titulo = "Sem título";
        this.autor = "Desconhecido";
        this.anoPublicacao = 0;
        
    }
    
    public Livro(String titulo, String autor, int anoPublicacao) {
        
        this.titulo = titulo;
        this.autor = autor;
        this.anoPublicacao = anoPublicacao;
        
    }
    
    public void imprime() {
        
        System.out.println("Título: " + titulo);
        System.out.println("Autor: " + autor);
        System.out.println("Ano de publicação: " + anoPublicacao);
        
    }
    
}