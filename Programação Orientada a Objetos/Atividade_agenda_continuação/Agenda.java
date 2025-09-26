public class Agenda {
   Pessoa[] pessoas = new Pessoa[15];
   int qtdPessoas = 0;

   Agenda() {
   }

   void cadastrarPessoa(Pessoa var1) {
      if (this.qtdPessoas == this.pessoas.length) {
         System.out.println("A agenda está cheia!");
      } else {
         this.pessoas[this.qtdPessoas] = var1;
         ++this.qtdPessoas;
      }
   }

   void listarPessoas() {
      Pessoa[] var1 = this.pessoas;
      int var2 = var1.length;

      for(int var3 = 0; var3 < var2; ++var3) {
         Pessoa var4 = var1[var3];
         if (var4 != null) {
            var4.imprimir();
         }
      }

   }

   boolean buscarPessoaPeloNome(String var1) {
      Pessoa[] var2 = this.pessoas;
      int var3 = var2.length;

      for(int var4 = 0; var4 < var3; ++var4) {
         Pessoa var5 = var2[var4];
         if (var5 != null && var5.nome.equals(var1)) {
            return true;
         }
      }

      return false;
   }
}
