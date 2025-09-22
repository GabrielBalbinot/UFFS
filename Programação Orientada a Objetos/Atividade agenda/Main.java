public class Main
{
	public static void main(String[] args) {
	    
		Data data = new Data();
	    data.dia = 29;
	    data.mes = 8;
	    data.ano = 2001;
	    
	    Contato c = new Contato();
		c.whatsapp = true;
		c.telegram = true;
		c.numero = "49 98412-7301";
		
		Pessoa p = new Pessoa();
		p.nome = "Gabriel Francisco Dall Rosa Balbinot";
		p.dataNascimento = data;
		p.cadastrarContato(c);
		
		Agenda agenda = new Agenda();
		
		agenda.cadastrarPessoa(p);
		agenda.listarPessoas();
		System.out.println(agenda.buscarPessoaPeloNome("Gabriel Francisco Dall Rosa Balbinot"));
	}
}
