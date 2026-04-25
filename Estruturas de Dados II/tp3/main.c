#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

// Função de comparação para inteiros (necessária para a biblioteca)
int compare_ints(const void *a, const void *b, void *udata)
{
    int va = *(const int *)a;
    int vb = *(const int *)b;
    if (va < vb)
        return -1;
    if (va > vb)
        return 1;
    return 0;
}

// Função auxiliar para imprimir a árvore (percurso em ordem)
bool print_item(const void *item, void *udata)
{
    printf("%d ", *(const int *)item);
    return true; // continue iteration
}

void print_tree(struct btree *bt)
{
    printf("Arvore atual: [ ");
    btree_ascend(bt, NULL, print_item, NULL);
    printf("]\n");
}

int main()
{
    
    struct btree *bt = btree_new(sizeof(int), 3, compare_ints, NULL);

    printf("--- INSERCAO ---\n");
    int valores_insercao[] = {10, 20, 5, 6, 12, 30, 7, 17, 29, 23, 12, 111, 10, 23};
    int qtd_insercao = sizeof(valores_insercao) / sizeof(valores_insercao[0]);

    for (int i = 0; i < qtd_insercao; i++)
    {
        int val = valores_insercao[i];

        // btree_set insere ou substitui o valor.
        // Retorna o ponteiro anterior se já existia (duplicata), ou NULL se é novo.
        const void *prev = btree_set(bt, &val);
        /*
        if (prev)
        {
            printf("Inserindo %d... (Duplicado, valor atualizado)\n", val);
        }
        else
        {
            printf("Inserindo %d...\n", val);
        }
        */
    }
    print_tree(bt);
    printf("\n");

    // 2. Busca
    printf("--- BUSCA ---\n");
    int valores_busca[] = {6, 15};
    int qtd_busca = sizeof(valores_busca) / sizeof(valores_busca[0]);

    for (int i = 0; i < qtd_busca; i++)
    {
        int key = valores_busca[i];
        const int *found = btree_get(bt, &key);

        if (found)
        {
            printf("Busca por %d: ENCONTRADO\n", key);
        }
        else
        {
            printf("Busca por %d: NAO ENCONTRADO\n", key);
        }
    }
    printf("\n");

    // 3. Remoção
    printf("--- REMOCAO ---\n");
    int valores_remocao[] = {6, 5, 7};
    int qtd_remocao = sizeof(valores_remocao) / sizeof(valores_remocao[0]);

    for (int i = 0; i < qtd_remocao; i++)
    {
        int key = valores_remocao[i];
        printf("Removendo %d... ", key);

        // btree_delete retorna o item removido ou NULL se não encontrado
        const void *removed = btree_delete(bt, &key);

        if (removed)
        {
            printf("Sucesso.\n");
        }
        else
        {
            printf("Falha (não encontrado).\n");
        }
    }

    



    printf("\n\n\n");

    return 0;
}