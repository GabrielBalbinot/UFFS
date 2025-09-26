import java.time.LocalDate;

public class Data {
    
    int dia;
    int mes;
    int ano;

    public Data() {

        this.dia = LocalDate.now().getDayOfMonth();
        this.mes = LocalDate.now().getMonthValue();
        this.ano = LocalDate.now().getYear();

    }

    public Data(int dia, int mes, int ano) {

        this.dia = dia;
        this.mes = mes;
        this.ano = ano;

    }
    
    void imprimir() {
        
        System.out.printf("%02d/%02d/%04d\n", dia, mes, ano);
        
    }
    
    
}