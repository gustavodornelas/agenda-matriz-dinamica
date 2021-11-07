typedef struct contato CONTATO;

CONTATO* criarAgenda ();
CONTATO* cadastraContato (CONTATO* a);
void editarContato (CONTATO* a);
CONTATO* buscaCadastro(CONTATO* a);
CONTATO* removerContato (CONTATO* a);
void imprimirCadastros (CONTATO* a, int op);
void freeContatos(CONTATO* a);



