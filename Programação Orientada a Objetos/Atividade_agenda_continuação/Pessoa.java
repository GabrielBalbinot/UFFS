public class Pessoa {
   private String nome;
   private Data dataNasc;
   private Contato[] contatos = new Contato[4];
   private int qtdContatos = 0;

   public Pessoa(String nome, Data dataNasc) {
      this.nome = nome;
      this.dataNasc = dataNasc;
   }

   String getNome() {
      return this.nome;
   }

   void setNome(String nome) {
      this.nome = nome;
   }

   Data getData() {
      return this.dataNasc;
   }

   void setData(Data data) {
      this.dataNasc = data;
   }

   Contato getContato(int indice) {

      if (contatos[indice] == null) {
         System.out.println("Contato inexistente!");
         return null;
      }

      return contatos[indice];
   }

   void cadastraContato(Contato c) {
      if (qtdContatos >= contatos.length) {
         System.out.println("Número máximo de contatos cadastrados já " +
               "atingido!");
         return;
      }

      contatos[qtdContatos] = c;
      qtdContatos++;
   }

   void listaContatos() {
      System.out.println(qtdContatos + " contato(s):");
      for (int i = 0; i < qtdContatos; i++) {
         System.out.println("Contato " + (i + 1) + ":");
         contatos[i].imprime();
      }
   }

   void imprime() {
      System.out.println("Nome: " + this.nome);
      System.out.println("Data de Nascimento:");
      this.dataNasc.imprime();
      this.listaContatos();
   }
}
