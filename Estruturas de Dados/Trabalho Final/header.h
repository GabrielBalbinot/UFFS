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

typedef struct sentinelaLista {
    
    Node *first;
    Node *last;
    
} ListaSimples;

extern char *cultivarares[4];

void initList(ListaSimples *);
Node *allocNode();
void inclusao(ListaSimples *);
void consulta(ListaSimples *);
void consultaPorData(ListaSimples *, int, int, int);
void consultaPorCultivar(ListaSimples *, char *st);
void exclusao(ListaSimples *);
void alterarProducao(ListaSimples *);
void printProducao(Producao);
void printAll(ListaSimples);

#endif