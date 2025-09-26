public class Pessoa {
   String nome;
   Data dataNascimento;
   Contato[] contatos = new Contato[4];
   int qtdContatos = 0;

   Pessoa(String var1, Data var2) {
      this.nome = var1;
      this.dataNascimento = var2;
   }

   void cadastrarContato(Contato var1) {
      if (this.qtdContatos == this.contatos.length) {
         System.out.println("Lista de contatos cheia!");
      } else {
         this.contatos[this.qtdContatos] = var1;
         ++this.qtdContatos;
      }
   }

   void listarContatos() {
      Contato[] var1 = this.contatos;
      int var2 = var1.length;

      for(int var3 = 0; var3 < var2; ++var3) {
         Contato var4 = var1[var3];
         if (var4 != null) {
            var4.imprimir();
         }
      }

   }

   void imprimir() {
      System.out.println("Nome: " + this.nome);
      System.out.print("Data de nascimento: ");
      this.dataNascimento.imprimir();
      this.listarContatos();
   }
}
