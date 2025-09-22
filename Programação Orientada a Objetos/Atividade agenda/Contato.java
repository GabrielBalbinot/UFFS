public class Contato {
    
    String numero;
    boolean whatsapp;
    boolean telegram;
    
    void imprimir() {
        
        if (whatsapp && telegram) {
            
            System.out.println("Telegram && WhatsApp: " + numero);
            
        } else if (whatsapp) {
            System.out.println("WhatsApp: " + numero);
        } else {
            System.out.println("Telegram: " + numero);
        }
        
        
    }
    
    
}