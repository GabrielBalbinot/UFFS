public class Contato {
    private boolean ehTelegram;
    private boolean ehWhatsapp;
    private String numero;

    public Contato(boolean t, boolean w, String numero) {
        this.ehTelegram = t;
        this.ehWhatsapp = w;
        this.numero = numero;
    }

    boolean getTelegram() {
        return ehTelegram;
    }

    void setTelegram(boolean b) {
        ehTelegram = b;
    }

    boolean getWhatsapp() {
        return ehWhatsapp;
    }

    void setWhastapp(boolean b) {
        ehWhatsapp = b;
    }

    String getNumero() {
        return numero;
    }

    void setNumero(String numero) {
        this.numero = numero;
    }

    void imprime() {
        System.out.println("Número: " + this.numero);
        if (this.ehTelegram){
            System.out.println("É telegram!");
        }
        if (this.ehWhatsapp){
            System.out.println("É whatsapp!");
        }
    }
}
