/*

TODOs:
1. Conjuntos precisam ser armazenados numa matriz (vetor de vetores)
1.1. Conjuntos sao vetores de inteiros
1.2. O numero de linhas e colunas serao constantes
2. Vetores serao inicializados em 0
2.1. Valores iguais a zero (0) nao serao considerados no vetor, ou seja, um vetor [1,2,3,0,0,0] nao tem 6 elementos no ponto de vista de vetores, somente no de conjuntos
3. Um contador ira monitorar o numero de conjuntos existentes
3.1 Sera zerado ao iniciar o programa
4. O programa devera ter um painel inicial que tera as seguintes funcionalidades:
---
Gerenciamento de Conjuntos

Menu

1-Criar um novo conjunto vazio
2-Inserir dados em um conjunto
3-Remover um conjunto
4-Fazer a uniao entre dois conjuntos
5-Fazer a interseccao entre dois conjuntos
6-Mostrar um conjunto
7-Mostrar todos os conjuntos
8-Fazer busca por um valor
9-Sair do programa

Escolha uma opção:
---
4.1. O programa estara um loop infinito ate que o usuario escolha a opcao 9 do painel (Sair do programa)
4.2. Devera ser feito modularmente, ou seja, com funcoes (eh ate mais facil)
4.3. O programa devera ter um forte tratamento de erro e devera dar feedback ao usuario, indicando o que houve de errado

-------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#define M 10 ///< Numero de linhas (conjuntos armazenados possiveis)
#define N 10 ///< Numero de colunhas (elementos em cada conjunto)

void criar_conjunto();
void inserir_elementos();
void remover_conjunto();
void unir_conjuntos();
void intersecionar_conjuntos();
void mostrar_conjunto();
void mostrar_conjuntos();
void buscar_elemento();
void sair_programa();

int main() {
    

    return 0;
}
