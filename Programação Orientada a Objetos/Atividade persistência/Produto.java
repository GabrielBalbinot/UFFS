public class Produto {
    
    private String nome;
    private int quantidade;
    private double preco;

    Produto(String nome, double preco, int quantidade) {
        this.nome = nome;
        this.quantidade = quantidade;
        this.preco = preco;
    }

    public String getNome() {
        return this.nome;
    }

    public double getPreco() {
        return this.preco;
    }

    public int getQuantidade() {
        return this.quantidade;
    }

}
