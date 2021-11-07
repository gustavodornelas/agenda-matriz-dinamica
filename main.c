#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "TAD-agenda.h"

int main (){

    CONTATO* lista = criarAgenda();
    CONTATO* aux;
    int op;

    do{ //menu
        system ("cls");
        printf ("MENU\n1) Cadastra Contato\n2) Listar Contatos\n3) Buscar Contato\n4) Editar Contatos\n5) Remover Contato\n0) Sair\nOpcao: ");
        scanf ("%d", &op);

        switch (op){
        case 1: //Cadastra Contato
            lista = cadastraContato(lista);
            break;

        case 2: //Listar Contatos
            imprimirCadastros(lista, 0);
            break;

        case 3: //Buscar Contato

            aux=buscaCadastro(lista);
            if (aux != NULL){
                imprimirCadastros(aux, 1);
            }
            break;

        case 4: //Editar Contatos

            editarContato(lista);
            break;

        case 5: //remover Contatos
            removerContato(lista);
            break;
        }

    }while (op!=0);

    freeContatos(lista);

    return 0;
}
