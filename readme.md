# Exercício

## Escreva um programa que implementa uma Agenda Telefônica de 100 contatos. A agenda deve armazenar um nome e telefone para cada contato.

### a) Para utilizar a memória eficientemente, modifique o programa para alocar o espaço exato para o nome de cada contato.
(Sugestão: Utilize um vetor (100+ posições) declarado estaticamente como BUFFER para receber o nome do contato)
### b) Adicione à agenda a funcionalidade de armazenar um e-mail para o contato. 
### c) Adicione a agenda a funcionalidade de dobrar o espaço de tamanho disponível. Caso não haja mais espaços para armazenar contatos, o programa deverá alocar uma nova área de memória 2 vezes maior que a original.
(Obs.: utilize um tamanho inicial pequeno para testar a funcionalidade)

### d) Criar função que pesquise pelo nome ou pelo telefone do usuário.

### e) Alterar todas as matrizes para uma única Struct

### f) Implementar o TAD da Agenda telefônica oferecendo as seguintes operações:

- criar: criar uma agenda vazia (sem contatos)
- liberar: liberar o espaço ocupado pela agenda e seus contatos
- adicionar: insere um novo contato na agenda
- imprimir: imprime todos os contatos armazenados
- buscar: Tenta encontrar o contato com um determinado nome ou telefone
- remover: remove um determinado contato com base no nome ou telefone
- alterar: edita as informações como nome e telefone de um determinado contato encontrado pelo nome ou telefone.

Obs.: A nova lista não terá limite de contatos.