#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "TAD-agenda.h"

char bufferNome[100], bufferTelefone[100], bufferEmail[100]; //buffer

typedef struct contato{
    char* nome;
    char* telefone;
    char* email;
    CONTATO* prox;
}CONTATO;

CONTATO* criarAgenda (){

    CONTATO* inicio = NULL;

    return inicio;
}

void freeContatos(CONTATO* a){
    CONTATO* aux = a;
    CONTATO* ref;

    while ( aux != NULL ){
        ref = aux->prox;
        free(aux->nome);
        free (aux->telefone);
        free (aux->email);

        free ( aux );

        aux = ref;
    }
}

CONTATO* cadastraContato (CONTATO* a){

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

    CONTATO* novo = malloc (sizeof(CONTATO));

    novo->nome = malloc (sizeof(char) * strlen(bufferNome));
    strcpy (novo->nome,bufferNome);

    novo->telefone = malloc (sizeof(char) * strlen(bufferTelefone));
    strcpy(novo->telefone,bufferTelefone);

    novo->email = malloc (sizeof(char) * strlen(bufferEmail));
    strcpy(novo->email,bufferEmail);

    novo->prox = a;
    return novo;
}

void editarContato (CONTATO* a){

    CONTATO* aux;
    aux = buscaCadastro(a);

    if (aux!=NULL){
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

    aux->nome=bufferNome;
    aux->telefone=bufferTelefone;
    aux->email=bufferEmail;
    }
}

void imprimirCadastros (CONTATO* a, int op){

    CONTATO* aux = a;

    system ("cls");

    while(aux!=NULL){
        printf ("Cadastro: %d\nNome: %s\nTelefone: %s\nE-mail: %s\n\n", aux, aux->nome, aux->telefone, aux->email); //imprimir o cadastro no ponteiro aux

        if (op==1){
            break;
        }

        aux = aux->prox;
    }
    system ("Pause");
}

CONTATO* buscaCadastro(CONTATO* a){
    CONTATO* aux = a;
    char busca[100];

    system ("cls");
    printf ("Digite o nome ou telefone do contato desejado: ");
    scanf (" %s", busca);

    while (aux != NULL){
        if (strcmp(busca, aux->nome)==0 || strcmp(busca, aux->telefone)==0){
            return aux;
        }
        aux = aux->prox;
    }

    printf ("Nome ou telefone invalido!\n");
    system ("pause");

    return NULL;
}

CONTATO* removerContato (CONTATO* a){

    CONTATO* aux = a;
    CONTATO* ant = NULL;
    char busca[100];

    system ("cls");
    printf ("Digite o nome ou telefone do contato desejado: ");
    scanf (" %s", busca);

    while (aux != NULL){
        if (strcmp(busca, aux->nome)==0 || strcmp(busca, aux->telefone)==0){
            break;
        }
        ant = aux;
        aux = aux->prox;
    }

    if (aux== NULL){
        printf ("Nome ou telefone invalido!\n");
        system ("pause");
        return a;
    }

    if (ant==NULL){
        a = aux->prox;
    }else{
        ant->prox = aux->prox;
    }

    printf ("Contato Removido!\n");
    system ("pause");
    free (aux);
    return a;
}

