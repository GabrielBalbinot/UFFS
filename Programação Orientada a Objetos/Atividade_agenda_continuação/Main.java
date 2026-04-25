public class Main {
    public static void main(String[] args) {
        
        Agenda agenda = new Agenda();

        Pessoa p = new Pessoa("Gabriel Balbinot", new Data());
        agenda.cadastraPessoa(p);
        p.imprime();

        p.getData().setDia(29);
        p.getData().setMes(8);
        p.getData().setAno(2001);

        p.cadastraContato(new Contato(false, false, ""));
        
        int indice = 0;

        Contato temp = p.getContato(indice);

        if (temp != null) {

            temp.setNumero("49 98412-7301");

        }
        
        agenda.listaPessoas();
        
    }
}
