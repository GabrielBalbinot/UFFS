public class Data {
    private int dia;
    private int mes;
    private int ano;

    public Data(int dia, int mes, int ano) {
        this.dia = dia;
        this.mes = mes;
        this.ano = ano;
    }   

    public Data() {
        this(0, 0, 0);
    }

    int getDia() {
        return this.dia;
    }

    void setDia(int dia) {
        this.dia = dia;
    }

    int getMes() {
        return this.mes;
    }

    void setMes(int mes) {
        this.mes = mes;
    }

    int getAno() {
        return this.ano;
    }

    void setAno(int ano) {
        this.ano = ano;
    }

    void imprime() {
        System.out.printf("%02d/%02d/%04d\n", dia, mes, ano);
    }
}
