#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contato{
    char* nome;
    char* telefone;
    char* email;
}Contato;

typedef struct agenda{
    Contato* contatos;
    int tam;
}Agenda;

char* cadastra_nome (){ //cadastrar nome na agenda

    char tmp_nome[100]; //buffer
    char* nome;

    system ("cls");

    printf ("Digite o nome do contato: ");
    scanf (" %[^\n]", tmp_nome);

    nome=malloc(sizeof(char) * strlen(tmp_nome)+1); //alocar espaço de acordo com o tamanho do nome lido

    strcpy(nome, tmp_nome); //copiar buffer para o espaço na memoria

    return nome; //retornar a posição na memoria
}

char* cadastra_telefone (){

    char tmp_tel[15]; //buffer
    char *tel;
    
    printf ("Digite o telefone do contato: ");
    scanf ("  %s", tmp_tel); //lê um telefone

    tel=malloc(sizeof(char) * strlen(tmp_tel)+1); //aloca memoria de acordo com o telefone

    strcpy(tel, tmp_tel); //copia valor para ponteiro

    return tel;
}

char* cadastra_email (){

    char tmp_email[100]; //buffer
    char* email;

    printf ("Digite o email do contato: ");
    scanf (" %s", tmp_email); //ler buffer de email
        
    if (strlen(tmp_email)==0){ //caso o buffer fique em branco
        email=malloc(sizeof(char));
        strcpy(email,'\0');
    }else{ //caso o usuario cadastre um email
        email=malloc(sizeof(char) * strlen(tmp_email)+1);
        strcpy(email, tmp_email);
    }

    return email;
}

int busca_cadastros(Agenda* a, int c){

    char busca[100];

    system ("cls");

    printf ("Digite o nome ou telefone do contato desejado: ");
    scanf (" %s", busca);

    for (int i=0; i<c; i++){

        if (strcmp(busca, a->contatos[i].nome)==0 || strcmp(busca, a->contatos[i].telefone)==0){
            return i;
        }
    }

    return -1;
}

void listar_cadastros (Agenda* a,int t, int c){

    system ("cls");

    for (int i=t; i<c; i++){
        printf ("Cadastro %d\nNome: %s\nTelefone: %s\nE-mail: %s\n\n", i+1, a->contatos[i].nome, a->contatos[i].telefone, a->contatos[i].email); //imprimir o cadastro na posicao i
    }

    system ("Pause");
}

void free_contatos(Agenda* a, int tam){ //função para limpar memoria das matrizes

    for (int i=0; i<tam; i++){
        free (a->contatos[i].nome);
        free (a->contatos[i].telefone);
        free (a->contatos[i].telefone);
    }

}

int main (){

    Agenda a; //Struct
    int op, i=0, j; //variaveis de controle

    a.tam=100;

    //alocação inicial
    a.contatos=malloc(sizeof(Contato*)*a.tam);

    if (a.contatos==NULL){
        printf ("Erro ao alocar memoria!\n");
        return -1;
    }

    do{ //menu
        system ("cls");
        printf ("(Espacos livre na agenda: %d, Espacos usado na agenda: %d)\n\nMENU\n1) Cadastra Contato\n2) Listar Contatos\n3) Buscar Contato\n4) Editar Contatos\n5) Dobrar espaco da agenda\n0) Sair\nOpcao: ",a.tam, i);
        scanf ("%d", &op);

        switch (op){
            case 1:
            if (i<a.tam){  //cadastra valores na struct

                a.contatos[i].nome=cadastra_nome();
                a.contatos[i].telefone=cadastra_telefone();
                a.contatos[i].email=cadastra_email();  
                i++;

            }else{
                printf ("Limite de agenda atingido!\n");
                system ("pause");
            }
            break;

            case 2:
                listar_cadastros(&a, 0, i);
                break;

            case 3:

                j=busca_cadastros(&a, i);
                if (j!=-1){
                    listar_cadastros(&a, j, j+1);
                }else{
                    printf ("Nome ou telefone invalido!\n");
                    system ("pause");
                }

                break;

            case 4:
                j=busca_cadastros(&a, i);

                if (j!=-1){
                    system ("cls");
                    
                    free(a.contatos[j].nome);
                    a.contatos[j].nome=cadastra_nome();

                    free(a.contatos[j].telefone);
                    a.contatos[j].telefone=cadastra_telefone();

                    free(a.contatos[j].email);
                    a.contatos[j].email=cadastra_email();
                }else{
                    printf ("Nome ou telefone invalido!\n");
                    system ("pause");
                }

                break;
            
            case 5:
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