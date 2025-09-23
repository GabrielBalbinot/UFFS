public class Main
{
	public static void main(String[] args) {

        Agenda agenda = new Agenda();
	    
		Data d1 = new Data(29,8,2001);	    
	    Contato c1 = new Contato("49 98412-7301", true, true);				
		Pessoa p1 = new Pessoa("Gabriel Francisco Dall Rosa Balbinot", d1);
		p1.cadastrarContato(c1);
			
		agenda.cadastrarPessoa(p1);
		
		System.out.println(agenda.buscarPessoaPeloNome("Gabriel Francisco Dall Rosa Balbinot"));
        
        Data d2 = new Data();	    
	    Contato c2 = new Contato("49 99908-7700", true, false);			
		Pessoa p2 = new Pessoa("Ciclano Beltrano", d2);
		p2.cadastrarContato(c2);      		
		agenda.cadastrarPessoa(p2); 

        Contato.imprimeQtdTotalContatos();

	}
}
