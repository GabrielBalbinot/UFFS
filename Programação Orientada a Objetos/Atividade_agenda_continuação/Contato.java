public class Contato {
   String numero;
   boolean whatsapp;
   boolean telegram;
   static int qtdTotalContatos = 0;

   static void imprimeQtdTotalContatos() {
      System.out.println("Quantidade total de contatos: " + qtdTotalContatos);
   }

   Contato(String var1, boolean var2, boolean var3) {
      this.numero = var1;
      this.whatsapp = var2;
      this.telegram = var3;
      ++qtdTotalContatos;
   }

   void imprimir() {
      if (this.whatsapp && this.telegram) {
         System.out.println("Telegram && WhatsApp: " + this.numero);
      } else if (this.whatsapp) {
         System.out.println("WhatsApp: " + this.numero);
      } else if (this.telegram) {
         System.out.println("Telegram: " + this.numero);
      } else {
         System.out.println("Número:" + this.numero);
      }

   }
}
