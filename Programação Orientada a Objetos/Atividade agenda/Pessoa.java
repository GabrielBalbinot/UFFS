public class Pessoa {
    
    String nome;
    Data dataNascimento;
    Contato[] contatos = new Contato[4];
    int qtdContatos = 0;
    
    void cadastrarContato(Contato c) {
        
        if (qtdContatos == 4) {
            System.out.println("Lista de contatos cheia!");
            return;
        }
        
        contatos[qtdContatos] = c;
        qtdContatos++;
        
    }
    
    void listarContatos() {
        
        for (Contato c : contatos) {
            if (c != null) {
                c.imprimir();
            }
        }
        
    }
    
    void imprimir() {
        
        System.out.println("Nome: " + nome);
        System.out.print("Data de nascimento: ");
        dataNascimento.imprimir();
        
        listarContatos();
        
    }
    
}