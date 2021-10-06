#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

long int cadastra_telefone (){

    long int tel;
    
    printf ("Digite o telefone do contato: ");
    scanf ("%li", &tel);

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

void listar_cadastros (char** nome,char** telefone,char** email, int c){

    system ("cls");

    for (int i=0; i<c; i++){
        printf ("Cadastro %d\nNome: %s\nTelefone: %li\nE-mail: %s\n\n", i+1, nome[i], telefone[i], email[i]); //imprimir o cadastro na posicao i
    }

    system ("Pause");
}

void free_col (char** m, int tam){ //função para limpar memoria das matrizes

    for (int i=0; i<tam; i++){
        free (m[i]);
    }

}

int main (){

    char** nome,** email;//matriz
    long int* telefone; //vetor
    int op, tam=100, i=0, j; //variaveis de controle

    //alocação inicial
    nome=malloc(sizeof(char*)*tam);
    telefone=malloc(sizeof(long int*)*tam);
    email=malloc(sizeof(char*)*tam);

    do{ //menu
        system ("cls");
        printf ("(Espacos livre na agenda: %d, Espacos usado na agenda: %d)\n\nMENU\n1) Cadastra Contato\n2) Listar Contatos\n3) Editar Contatos\n4) Dobrar espaco da agenda\n0) Sair\nOpcao: ",tam, i);
        scanf ("%d", &op);

        switch (op){
            case 1:
            if (i<tam){
                nome[i]=cadastra_nome();
                telefone[i]=cadastra_telefone();
                email[i]=cadastra_email();
                i++;
            }else{
                printf ("Limite de agenda atingido!\n");
                system ("pause");
            }
            break;

            case 2:
                listar_cadastros(nome, telefone, email, i);
                break;

            case 3:
                printf ("Digite o numero do cadastro: ");
                scanf ("%d", &j);
                j--;

                if (j<i){
                    system ("cls");
                    
                    free(nome[j]);
                    nome[j]=cadastra_nome();

                    telefone[j]=cadastra_telefone();

                    free(email[j]);
                    email[j]=cadastra_email();
                }else{
                    printf ("Numero do cadastro invalido!\n");
                    system ("pause");
                }

                break;
            
            case 4:
                tam*=2;

                nome=realloc(nome, sizeof(char*)*tam);
                telefone=realloc(telefone, sizeof(long int*)*tam);
                email=realloc(email, sizeof(char*)*tam);
                break;

        }

    }while (op!=0);

    //limpar memoria
    free_col(nome, tam);
    free(nome);
    free(telefone);
    free_col(email, tam);
    free(email);

    return 0;
}