#ifndef HEADER_H
#define HEADER_H

typedef struct data{
   int dia;
   int mes;
   int ano;
} Data;

typedef struct fardo{
   char cultivar[20];
   char tipoDeFeno;
   int diametro;
} Fardo;

typedef struct producao{
   int codigo;
   Data dataProducao;
   Fardo tipoDeFardo;  
   int qtDeFardos;
   int tempoEmMin;
} Producao;

typedef struct nodeSimples {
    
   Producao producao;
   struct nodeSimples *next;
    
} Node;

typedef struct tipoFeno
{ 
  
   int fardos80;
   int fardos160;
   int armazenagem;
   
} Tipo;


typedef struct sumario {

   Tipo tipos[3];

} Sumario;

typedef struct sentinelaLista {
    
   Node *first;
   Node *last;

   Sumario sumario[4];   
    
} ListaSimples;

extern char *cultivarares[4];

void initList(ListaSimples *);
int hash(char *cultivar);
Node *allocNode();
void inclusao(ListaSimples *);
void consulta(ListaSimples *);
void consultaPorData(ListaSimples *, int, int, int);
void consultaPorCultivar(ListaSimples *, char *st);
void exclusao(ListaSimples *);
void alterarProducao(ListaSimples *);
void printProducao(Producao);
void printAll(ListaSimples);
int armazenagem(int, int);

#endif