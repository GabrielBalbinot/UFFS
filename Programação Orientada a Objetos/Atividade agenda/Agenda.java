public class Agenda {
    
    Pessoa[] pessoas = new Pessoa[15];
    int qtdPessoas = 0;
    
    void cadastrarPessoa(Pessoa p) {
        
        if (qtdPessoas == 15) {
            System.out.println("A agenda está cheia!");
            return;
        }
        
        pessoas[qtdPessoas] = p;
        qtdPessoas++;
        
    }
    
    void listarPessoas() {
        
        for (Pessoa p : pessoas) {
            
            if (p != null) {
                p.imprimir();
            }
            
        }
        
    }
    
    boolean buscarPessoaPeloNome(String nome) {
        
        for (Pessoa p : pessoas) {
            
            if (p != null && p.nome.equals(nome)) {
                return true;
            }
            
        }
        
        return false;
        
    }
    
}