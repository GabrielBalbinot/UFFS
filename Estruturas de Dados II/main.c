#include <stdio.h>
#include <string.h>
#include <windows.h>

typedef struct {
    int id;
    char nome[40];
    float media;
    int ativo;
} Aluno;

int passarID();
long buscarRegistro(int);
void criarRegistro();
void lerRegistros();
void alterarNome(long, char *);
void alterarMedia(long, float);
void alterarRegistro();
void exclusao();
void clear();

int main()
{

    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    int acao = 0;
    
    while (acao != 5) {
        
        printf("Digite o número da ação que deseja realizar\n\n");
        printf("1- Create\n2- Read\n3- Update\n4- Delete\n5- Sair\n");
    
        scanf("%d", &acao);
        
        if (acao == 1) {
            criarRegistro();
        } else if (acao == 2) {
            lerRegistros();
        } else if (acao == 3) {
            alterarRegistro();
        } else if (acao == 4) {
            exclusao();
        } else if (acao == 5) {
            break;
        } else {
            printf("Opção inválida!\n");
        }
        
        printf("Pressione ENTER para voltar ao menu principal.");
        getchar();
        getchar();
        
        clear();
                
    }
    

    return 0;
}

void clear() {
    
    for (int i=0; i < 50; i++)
        printf("\n");
    
}

int passarID() {
    int id;
    printf("Digite o id do registro: ");
    scanf("%d", &id);
    return id;
}

long buscarRegistro(int id) {
    
    FILE *fp = fopen("registros.dat", "r");
    
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);
    
    int x = -1, i = 0;
    
    while (ftell(fp) < size) {
        
        fread(&x, sizeof(int), 1, fp);
        if (x == id) {
            
            long i = sizeof(int);

            fseek(fp, -i, SEEK_CUR);
            long pos = ftell(fp);
            fclose(fp);
            
            return pos;
            
        }
            
        
        fseek(fp, sizeof(Aluno) - sizeof(int), 1);
        
    }
    
    return -1;
    
    fclose(fp);
    
}

void criarRegistro() {

    int id = passarID();
    
    if (buscarRegistro(id) != -1) {
        
        printf("Id %d já está sendo utilizado!\n", id);
        return;
        
    }
    
    Aluno a;
    a.id = id;
    getchar();
    printf("Nome: ");
    scanf("%[^\n]", a.nome);
    
    printf("Média: ");
    scanf("%f", &a.media);
    
    a.ativo = 1;
    
    FILE *fp = fopen("registros.dat", "a");
    int total = fwrite(&a, sizeof(Aluno), 1, fp);
    
    if (total != 1) {
        printf("Erro na gravação do registro!\n");
    } else {
        printf("Registro Realizado com sucesso!\n");
    }
    printf("\n");
    fclose(fp);
    
}

void lerRegistros() {
    
    printf("1- Ler registros ativos\n2- Ler registros inativos\n3- Ler todos\n");
    int acao;
    scanf("%d", &acao);
    
    FILE *fp = fopen("registros.dat", "r");
    Aluno a;
    
    if (acao == 1) {
        
        while (fread(&a, sizeof(Aluno), 1, fp) != 0) {
            
            if (a.ativo) {
                printf("ID: %d\nNome: %s\nMédia: %.2f\nAtivo: %d\n\n", a.id, a.nome, a.media, a.ativo);
            }
        
        }
    } else if (acao == 2) {
        
        while (fread(&a, sizeof(Aluno), 1, fp) != 0) {
            
            if (!a.ativo) {
                printf("ID: %d\nNome: %s\nMédia: %.2f\nAtivo: %d\n\n", a.id, a.nome, a.media, a.ativo);
            }
        
        }
    } else {
        while (fread(&a, sizeof(Aluno), 1, fp) != 0) {
            
            printf("ID: %d\nNome: %s\nMédia: %.2f\nAtivo: %d\n\n", a.id, a.nome, a.media, a.ativo);
        
        }
    }
    
    
    
    fclose(fp);
    
}

void alterarNome(long pos, char *nome) {
    
    FILE *fd = fopen("registros.dat", "r+");
    fseek(fd, pos+sizeof(int), SEEK_SET);
    
    long bts = fwrite(nome, sizeof(char), 40, fd);
    
    fclose(fd);
    
}

void alterarMedia(long pos, float media) {
   
   FILE *fd = fopen("registros.dat", "r+");
   
   fseek(fd, pos+sizeof(int)+sizeof(char)*40, SEEK_SET);
   long bts = fwrite(&media, sizeof(float), 1, fd);
   
   fclose(fd);
   
}

void alterarRegistro() {
    
    int id = passarID();
    
    long pos = buscarRegistro(id);
    
    if (pos == -1) {
        printf("Registro inválido!\n");
        return;
    }
    
    int acao;
    
    printf("Qual campo deseja atualizar?\n1- Nome\n2- Média\n");
    
    scanf("%d", &acao);
    getchar();
    
    if (acao == 1) {
        
        char nome[40];
        printf("Digite o nome do aluno: ");
        scanf("%[^\n]", nome);
        alterarNome(pos, nome);
        
    } else if (acao == 2) {
        
        float media;
        printf("Digite a média do aluno: ");
        scanf("%f", &media);
        alterarMedia(pos, media);
        
    } else {
        printf("Opção inválida! Retornando ao menu principal\n");
        return;
    }

    printf("Registro alterado com sucesso.\n");

    
}

void exclusao() {
    
    int id = passarID();
    
    long pos = buscarRegistro(id);
    
    if (pos == -1) {
        printf("Registro inválido!\n");
        return;
    }
    
    FILE *fd = fopen("registros.dat", "r+");
    
    fseek(fd, pos+sizeof(int)+sizeof(char)*40+sizeof(float), SEEK_SET);
    int inativar = 0;
    fwrite(&inativar, sizeof(int), 1, fd);
    
    fclose(fd);

    printf("Registro excluído (alterado para inativo).\n");
    
}