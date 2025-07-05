#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.h"

int main()
{
    int acao = 0;
    ListaSimples lista;
    initList(&lista);
    
    while (acao != 6) {
        
        printf("1. Incluir Produção\n2. Consultar\n3. Alterar\n4. Excluir\n5. Listar todos\n6. Sair\n\n");
            
        scanf("%d", &acao);
        
        if (acao == 1) {
            inclusao(&lista);
        } else if (acao == 2) {
            consulta(&lista);
            
        }else if (acao == 3) {
            alterarProducao(&lista);
            
        }else if (acao == 4) {
            exclusao(&lista);
            
        } else if (acao == 5) {
            printAll(lista);
        }
    }

    return 0;
}

char cultivares[4][20] = {"Coastcross", "Florakirk", "Jiggs", "Tifton 85"};

int hash(char *cultivar) {

    if (strcmp(cultivar, "Coastcross")) {

        return 0;

    } else if (strcmp(cultivar, "Florakirk")) {

        return 1;

    } else if (strcmp(cultivar, "Jiggs")) {

        return 2;

    } else if (strcmp(cultivar, "Tifton 85")) {

        return 3;

    }

    return -1;

}

void initList(ListaSimples *lista) {
    
    lista->first = NULL;
    lista->last = NULL;
    
    for (int i = 0; i < 4; i++) {
        
        for (int j=0; j < 3; j++) {

            lista->sumario[i].tipos[j].fardos80 = 0;
            lista->sumario[i].tipos[j].fardos160 = 0;
            lista->sumario[i].tipos[j].armazenagem = 0;

        }

    }
    
}

Node *allocNode() {
    
    Node *node = (Node *) malloc(sizeof(Node));
    node->next = NULL;
    
    int cultivarId;
    
    printf("Digite o código da produção: ");
    scanf("%d", &node->producao.codigo);
    
    printf("Digite a data da produção (DD/MM/AAAA): ");
    scanf("%d/%d/%d", &node->producao.dataProducao.dia, &node->producao.dataProducao.mes, &node->producao.dataProducao.ano);
    
    printf("Selecione a cultivar:\n\t1. Coastcross\n\t2. Florakirk\n\t3. Jiggs\n\t4. Tifton 85\n\t");
    scanf("%d", &cultivarId);
    strcpy(node->producao.tipoDeFardo.cultivar, cultivares[cultivarId-1]);
    getchar();
    printf("Selecione o tipo de feno (Digite apenas A, B ou C): ");
    scanf("%c", &node->producao.tipoDeFardo.tipoDeFeno);
    getchar();
    printf("Digite o diâmetro do feno em centímetros: ");
    scanf("%d", &node->producao.tipoDeFardo.diametro);
    
    printf("Digite a quantidade de fardos: ");
    scanf("%d", &node->producao.qtDeFardos);
    
    printf("Digite o tempo da produção em minutos: ");
    scanf("%d", &node->producao.tempoEmMin);
    
    return node;
    
}

void inclusao(ListaSimples *lista) {
    
    Node *node = allocNode(), *aux, *prev;
    
    if (lista->first == NULL) {
        
        lista->first = node;
        lista->last = node;

        // atualizarSumario(lista, );

        printf("Produção incluída com sucesso.\n\n");
        
        return;
        
    }
    
    for (aux = lista->first; aux != NULL; aux = aux->next) {
        
        if (node->producao.codigo == aux->producao.codigo) {
            
            printf("Já existe uma produção com o código %d\n", node->producao.codigo);
            printf("Produção não incluída.\n\n");
            return;
            
        }
        
        if (node->producao.codigo < aux->producao.codigo) {
            
            if (aux == lista->first) {
                node->next = aux;
                lista->first = node;
                
                printf("Produção incluída com sucesso.\n\n");
                return;
                
            }
            
            
            node->next = aux;
            prev->next = node;
            
            printf("Produção incluída com sucesso.\n\n");
            return;
            
        }
        
        prev = aux;
        
    }
    
    lista->last->next = node;
    lista->last = node;
    printf("Produção incluída com sucesso.\n\n");
    
}

void consulta(ListaSimples *lista) {
    
    int tipoDeConsulta;
    printf("Qual o formato da consulta:\n\t1. Por data\n\t2. Por cultivar\n\t");
    scanf("%d", &tipoDeConsulta);
    
    if (tipoDeConsulta == 1) {
        
        int dia, mes, ano;
        printf("Digite a data a ser consultada (DD/MM/AAAA): ");
        scanf("%d/%d/%d", &dia, &mes, &ano);
        
        consultaPorData(lista, dia, mes, ano);
        
    } else if (tipoDeConsulta == 2) {
        
        int cultivarId;
        printf("Selecione a cultivar:\n\t1. Coastcross\n\t2. Florakirk\n\t3. Jiggs\n\t4. Tifton 85\n\t");
        scanf("%d", &cultivarId);
        
        consultaPorCultivar(lista, cultivares[cultivarId]);
        
    } else {
        printf("Tipo de consulta inválido.\n\n");
    }
    
}

void consultaPorData(ListaSimples *lista, int dia, int mes, int ano) {
    
    Node *aux;
    int resultados = 0;
    
    for (aux=lista->first; aux != NULL; aux=aux->next) {
        
        if (aux->producao.dataProducao.dia == dia && aux->producao.dataProducao.mes == mes && aux->producao.dataProducao.ano == ano) {
            
            printf("%02d/%02d/%04d: %s - %c - %d fardos\n", dia, mes, ano, aux->producao.tipoDeFardo.cultivar, aux->producao.tipoDeFardo.tipoDeFeno, aux->producao.qtDeFardos);
            resultados++;
        }
        
    }
    
    printf("Foram retornado(s) %d resultado(s).\n\n", resultados);
    
}

void consultaPorCultivar(ListaSimples *lista, char *st) {
    
    printf("Aqui será implementado a consulta por cultivar.\n\n");
    
}

void exclusao(ListaSimples *lista) {
    
    int codigo;
    Node *aux, *prev;
    
    printf("Digite o código da produção a ser excluída: ");
    scanf("%d", &codigo);
    
    for (aux = lista->first; aux != NULL; aux = aux->next) {
        
        if (aux->producao.codigo == codigo) {
            
            // caso só tenha uma produção listada
            if (lista->first == lista->last) {
                
                free(aux);
                initList(lista);
                printf("A produção de código %d foi excluída com sucesso!\n\n", codigo);
                return;
                
            }
            
            // caso a produção a ser excluída seja a primeira da lista
            if (aux == lista->first) {
                
                lista->first = aux->next;
                aux->next = NULL;
                free(aux);
                
                printf("A produção de código %d foi excluída com sucesso!\n\n", codigo);
                return;
                
            }
            
            // comportamento normal da exclusão
            prev->next = aux->next;
            aux->next = NULL;
            free(aux);
            
            // caso a produção a ser excluída seja a última da lista encadeada
            if (prev->next == NULL) {
                lista->last = prev;
            }
            
            printf("A produção de código %d foi excluída com sucesso!\n\n", codigo);
            return;
            
        }
        
        prev = aux;
        
    }
    
    printf("Não existe produção com o código %d\n\n", codigo);
    
}

void alterarProducao(ListaSimples *lista) {
    
    int codigo;
    printf("Digite o código da produção a ser alterada: ");
    scanf("%d", &codigo);
    
    Node *aux;
    
    for (aux=lista->first;aux != NULL; aux = aux->next) {
        
        if (aux->producao.codigo == codigo) {
            
            int tipoDeAlteracao;
            
            printf("Qual campo deseja alterar?\n\t1. Data\n\t2. Cultivar\n\t3. Tipo de feno\n\t4. Diâmetro do feno\n\t5. Quantidade de fardos\n\t6. Tempo de produção\n\t7. Cancelar alteração\n\t");
            scanf("%d", &tipoDeAlteracao);
            getchar();
            
            if (tipoDeAlteracao == 1) {
                
                printf("\tDigite a data da produção (DD/MM/AAAA): ");
                scanf("%d/%d/%d", &aux->producao.dataProducao.dia, &aux->producao.dataProducao.mes, &aux->producao.dataProducao.ano);
                printf("\tData alterada com sucesso.\n\n");
                
            } else if (tipoDeAlteracao == 2) {
                
                printf("\tSelecione a cultivar:\n\t\t1. Coastcross\n\t\t2. Florakirk\n\t\t3. Jiggs\n\t\t4. Tifton 85\n\t\t");
                int cultivarId;
                scanf("%d", &cultivarId);
                strcpy(aux->producao.tipoDeFardo.cultivar, cultivares[cultivarId-1]);
                printf("\tCultivar alterada com sucesso.\n\n");
                
            } else if (tipoDeAlteracao == 3) {
                printf("\tSelecione o tipo de feno (Digite apenas A, B ou C): ");
                scanf("%c", &aux->producao.tipoDeFardo.tipoDeFeno);
                printf("\tTipo de feno alterado com sucesso.\n\n");
            } else if (tipoDeAlteracao == 4) {
                printf("\tDigite o diâmetro do feno em centímetros: ");
                scanf("%d", &aux->producao.tipoDeFardo.diametro);
                printf("\tDiâmetro do feno alterado com sucesso.\n\n");
            } else if (tipoDeAlteracao == 5) {
                printf("\tDigite a quantidade de fardos: ");
                scanf("%d", &aux->producao.qtDeFardos);
                printf("\tQuantidade de fardos alterado com sucesso.\n\n");
            } else if (tipoDeAlteracao == 6) {
                printf("\tDigite o tempo da produção em minutos: ");
                scanf("%d", &aux->producao.tempoEmMin);
                printf("\tTempo de produção alterado com sucesso.\n\n");
            } else {
                printf("Alteração cancelada.\n");
            }
            
            return;
        }
        
        
    }
    
    printf("Não existe produção com o código %d.\n\n", codigo);
    
}

void printProducao(Producao prod) {
    
    printf("Código: %d\n", prod.codigo);
    printf("Data: %02d/%02d/%d\n", prod.dataProducao.dia, prod.dataProducao.mes, prod.dataProducao.ano);
    printf("Cultivar: %s\n", prod.tipoDeFardo.cultivar);
    printf("Tipo de feno: %c\n", prod.tipoDeFardo.tipoDeFeno);
    printf("Diâmetro: %dcm\n", prod.tipoDeFardo.diametro);
    printf("Quantidade de fardos: %d\n", prod.qtDeFardos);
    printf("Tempo de produção: %d minutos\n\n", prod.tempoEmMin);
    
}

void printAll(ListaSimples lista) {
    
    Node *aux;
    
    for (aux=lista.first; aux != NULL; aux=aux->next) {
        
        printProducao(aux->producao);
        
    }
    
}

int armazenagemTotal(int qtDeFardos80, int qtDeFardos160) {

    // retorna a área total em cm², que será tratado na hora de apresentar
    // o dado ao cliente
    return  80*80*(qtDeFardos80 / 3 + qtDeFardos80 % 3 > 0) + 160*160*(qtDeFardos160 / 3 + qtDeFardos160 % 3 > 0);

}

void atualizarSumario(ListaSimples *lista, Node *node, int acao) {


    int cultivarIndex = hash(node->producao.tipoDeFardo.cultivar);
    int tipoIndex = node->producao.tipoDeFardo.tipoDeFeno - 'A';
    Tipo *sumarioPorTipo = &lista->sumario[cultivarIndex].tipos[tipoIndex];

    if (node->producao.tipoDeFardo.diametro == 80) {

        sumarioPorTipo->fardos80 += node->producao.qtDeFardos;

    } else {
        sumarioPorTipo->fardos160 += node->producao.qtDeFardos;
    }

    sumarioPorTipo->armazenagem = armazenagemTotal(sumarioPorTipo->fardos80, sumarioPorTipo->fardos160);


}