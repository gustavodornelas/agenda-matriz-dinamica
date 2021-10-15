#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contato{
    char* nome;
    char* telefone;
    char* email;
}CONTATO;

typedef struct agenda{
    CONTATO* contatos;
    int tam, cad; //tamanho e cadastros
}AGENDA;

char bufferNome[100], bufferTelefone[100], bufferEmail[100]; //buffer

int cadastraContato (AGENDA* a, int j){

    int i;

    if (j==-1){ //verifica se é um novo cadastro ou um cadastro a ser editado
        i = a->cad; 
        a->cad++; 
    }else{
        i=j;

        //limpar contato para cadastrar um novo contato no local
        free (a->contatos[i].nome);
        free (a->contatos[i].telefone);
        free (a->contatos[i].telefone);
    }
    system ("cls");

    //Recebe Nome
    printf ("Digite o nome do contato: ");
    scanf (" %[^\n]", bufferNome);  //lê buffer de nome
    
    //Recebe Telefone
    printf ("Digite o telefone do contato: ");
    scanf (" %[^\n]", bufferTelefone); //lê buffer de telefone

    //Recebe E-mail
    printf ("Digite o email do contato: ");
    scanf (" %[^\n]", bufferEmail); //ler buffer de email
    
    //Alocando memoria para armazenar os valores
    a->contatos[i].nome = malloc(sizeof(char) * strlen(bufferNome)+1);
    a->contatos[i].telefone = malloc(sizeof(char) * strlen(bufferTelefone)+1);
    a->contatos[i].email = malloc(sizeof(char) * strlen(bufferEmail)+1);

    if (a->contatos[i].nome==NULL || a->contatos[i].telefone==NULL || a->contatos[i].email==NULL){
        printf ("Erro ao alocar memoria!\n");
        return -1;
    }

    //copiando valores para a struct
    strcpy(a->contatos[i].nome, bufferNome);
    strcpy(a->contatos[i].telefone, bufferTelefone);
    strcpy(a->contatos[i].email, bufferEmail);

    return 0;
}

int busca_cadastros(AGENDA* a){

    char busca[100];

    system ("cls");
    printf ("Digite o nome ou telefone do contato desejado: ");
    scanf (" %s", busca);

    for (int i=0; i<a->cad; i++){

        if (strcmp(busca, a->contatos[i].nome)==0 || strcmp(busca, a->contatos[i].telefone)==0){
            return i;
        }
    }

    return -1;
}

void listar_cadastros (AGENDA* a,int t, int c){

    system ("cls");

    for (int i=t; i<c; i++){
        printf ("Cadastro %d\nNome: %s\nTelefone: %s\nE-mail: %s\n\n", i+1, a->contatos[i].nome, a->contatos[i].telefone, a->contatos[i].email); //imprimir o cadastro na posicao i
    }

    system ("Pause");
}

void free_contatos(AGENDA* a, int tam){ //função para limpar memoria da Struct

    for (int i=0; i<tam; i++){
        free (a->contatos[i].nome);
        free (a->contatos[i].telefone);
        free (a->contatos[i].telefone);
    }
}

int main (){

    AGENDA a; //Struct
    int op, j; //variaveis de controle

    a.tam=100;

    //alocação inicial
    a.contatos=malloc(sizeof(CONTATO*)*a.tam);

    if (a.contatos==NULL){
        printf ("Erro ao alocar memoria!\n");
        return -1;
    }

    do{ //menu
        system ("cls");
        printf ("(Espacos livre na agenda: %d, Espacos usado na agenda: %d)\n\nMENU\n1) Cadastra Contato\n2) Listar Contatos\n3) Buscar Contato\n4) Editar Contatos\n5) Dobrar espaco da agenda\n0) Sair\nOpcao: ",a.tam, a.cad);
        scanf ("%d", &op);

        switch (op){
            case 1: //Cadastra Contato
            if (a.cad<a.tam){  

                if (cadastraContato(&a, -1)==-1){
                    return -1;
                };

            }else{
                printf ("Limite de agenda atingido!\n");
                system ("pause");
            }
            break;

            case 2: //Listar Contatos
                listar_cadastros(&a, 0, a.cad);
                break;

            case 3: //Buscar Contato

                j=busca_cadastros(&a);
                if (j != -1){
                    listar_cadastros(&a, j, j+1);
                }else{
                    printf ("Nome ou telefone invalido!\n");
                    system ("pause");
                }
                break;

            case 4: //Editar Contatos
                j=busca_cadastros(&a);

                if (j!=-1){
                    if (cadastraContato(&a, j)==-1){
                        return -1;
                    }

                }else{
                    printf ("Nome ou telefone invalido!\n");
                    system ("pause");
                }
                break;
            
            case 5: //Dobrar espaco da agenda
                a.tam*=2;
                a.contatos=realloc(a.contatos, sizeof(char*)*a.tam);
                
                if (a.contatos==NULL){
                    printf ("Erro ao alocar memoria!\n");
                    return -1;
                }
                break;
        }

    }while (op!=0);

    //limpar memoria
    free_contatos(&a, a.tam);
    free(a.contatos);
    return 0;
}