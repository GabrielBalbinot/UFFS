public class Agenda {
    private Pessoa[] pessoas = new Pessoa[15];
    private int qtdPessoas = 0;

    public Agenda() {

    }

    Pessoa getPessoa(int indice) {

        if (pessoas[indice] == null) {
            System.out.println("Pessoa inexistente");
            return null;
        }

        return pessoas[indice];

    }

    void cadastraPessoa(Pessoa p) {
        if (qtdPessoas >= pessoas.length) {
            System.out.println("Número máximo de pessoas cadastradas já " +
                "atingido!");
            return;
        }

        pessoas[qtdPessoas] = p;
        qtdPessoas++;
    }

    void listaPessoas() {
        System.out.println("A agenda tem " + qtdPessoas + " pessoa(s):");
        for (int i = 0; i < qtdPessoas; i++){
            System.out.println("Pessoa " + (i + 1) + ":");
            System.out.println("--------------------");
            pessoas[i].imprime();
            System.out.println("--------------------");
        }
    }

    boolean buscaPessoa(String nome){
        for (int i = 0; i < qtdPessoas; i++) {
            if (pessoas[i].getNome().equals(nome)) {
                System.out.println(nome + " encontrado(a)!");
                System.out.println("--------------------");
                pessoas[i].imprime();
                System.out.println("--------------------");
                return true;
            }
        }
        System.out.println(nome + " não encontrado(a)!");
        return false;
    }
}
