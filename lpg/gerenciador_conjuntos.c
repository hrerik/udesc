/*

NOTA PARA O PROFESSOR RUI:
Apesar de nao termos visto ponteiros em sala ainda, optei por usar por deixar o
programa mais "modular", ou seja, seria possivel usar a mesma funcao em outros
programas.




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

// PROTOTIPOS DE FUNCOES

/* Funcao que aceita somente inteiros como entrada. Feito atraves dum loop ate que um
inteiro seja inserido.
@return: inteiro que representa o valor inserido pelo usuario*/
int pega_int();

/* Cria um novo conjunto vazio e o adiciona a matriz de conjuntos.
@param matriz: ponteiro para matriz de inteiros que armazena os conjuntos
@param p_num_conjuntos: ponteiro para inteiro que representa o numero de conjuntos
@param linhas: inteiro que representa o numero de linhas da matriz
@param colunas: inteiro que representa o numero de colunas da matriz */
void criar_conjunto(int *matriz, int *p_num_conjunto, int linhas, int colunas);

/* Insere elementos num conjunto previamente selecionado.
@param matriz: ponteiro para matriz de inteiros que armazena os conjuntos
@param i_conjunto: inteiro que representa o indice do conjunto a ser modificado
@param linhas: inteiro que representa o numero de linhas da matriz
@param colunas: inteiro que representa o numero de colunas da matriz*/
void inserir_elementos(int *matriz, int i_conjunto, int linhas, int colunas);

/* Remove um conjunto da matriz de conjuntos.
@param matriz: ponteiro para matriz de inteiros que armazena os conjuntos
@param num_conjuntos: ponteiro para inteiro que representa o numero de conjuntos
@param i_conjunto: inteiro que representa o indice do conjunto a ser removido*/
void remover_conjunto();

/* Faz a uniao entre dois conjuntos armazenados na matriz.
@param matriz: ponteiro para matriz de inteiros que armazena os conjuntos
@param num_conjuntos: ponteiro para inteiro que representa o numero de conjuntos
@param i_conjunto1: inteiro que representa o indice do primeiro conjunto
@param i_conjunto2: inteiro que representa o indice do segundo conjunto
@param colunas: inteiro que representa o numero de colunas da matriz */
void unir_conjuntos(int *matriz, int *num_conjuntos, int i_conjunto1, int i_conjunto2, int colunas);

/* Faz a interseccao entre dois conjuntos armazenados na matriz.
@param matriz: ponteiro para matriz de inteiros que armazena os conjuntos
@param num_conjuntos: ponteiro para inteiro que representa o numero de conjuntos
@param i_conjunto1: inteiro que representa o indice do primeiro conjunto
@param i_conjunto2: inteiro que representa o indice do segundo conjunto
@param colunas: inteiro que representa o numero de colunas da matriz */
void intersecionar_conjuntos(int *matriz, int *num_conjuntos, int i_conjunto1, int i_conjunto2, int colunas);

/* Mostra um conjunto armazenado na matriz.
@param matriz: ponteiro para matriz de inteiros que armazena os conjuntos
@param num_conjuntos: inteiro que representa o numero de conjuntos armazenados
@param colunas: inteiro que representa o numero de colunas da matriz */
void mostrar_conjunto(int *matriz, int num_conjuntos, int colunas);

/* Mostra todos os conjuntos armazenados na matriz.
@param matriz: ponteiro para matriz de inteiros que armazena os conjuntos
@param num_conjuntos: inteiro que representa o numero de conjuntos armazenados
@param linhas: inteiro que representa o numero de linhas da matriz
@param colunas: inteiro que representa o numero de colunas da matriz*/
void mostrar_conjuntos(int *matriz, int num_conjuntos, int linhas, int colunas);

/* Faz uma busca por um elemento em todos os conjuntos armazenados na matriz.
Printa os indices dos conjuntos que contiverem o elemento.
@param matriz: ponteiro para matriz de inteiros que armazena os conjuntos
@param num_conjuntos: inteiro que representa o numero de conjuntos armazenados
@param elemento: inteiro que representa o elemento a ser buscado
@param colunas: inteiro que representa o numero de colunas da matriz*/
void buscar_elemento(int *matriz, int num_conjuntos, int elemento, int colunas);

/* Sai do programa.
@param status: ponteiro para inteiro que representa o status do programa (1 ou 0) */
void sair_programa(int *status);

// Simplesmente mostra o menu com as opcoes
void mostrar_menu();

int main()
{
    if (N <= 0 || M <= 0)
    {
        printf("Erro: N e M devem ser maiores que 0.\n");
        return -1; // Erro de inicializacao
    }

    // DEFINICAO DE VARIAVEIS

    // "Base de dados" do programa. Linhas sao vetores, colunas sao elementos de cada vetor. Tamanhos no #define.
    int matriz[M][N];
    // Numero de conjuntos. Maximo de M conjuntos.
    int num_conjuntos = 0;

    // Variavel de input do usuario no menu e ao usar funcoes
    int input;

    // 1 => Continuar rodando programa; 0 => Parar programa.
    int status = 1;

    // PROGRAMA PRINCIPAL
    while (status)
    {
        mostrar_menu();
        // break;

        input = pega_int();
        printf("\n");

        switch (input)
        {
        case 1:
            criar_conjunto((int *)matriz, &num_conjuntos, M, N);
            break;
        case 2:
            if (num_conjuntos == 0)
            {
                printf("Nenhum conjunto criado! Crie um conjunto primeiro.\n");
            }
            else
            {
                printf("Escolha um conjunto de 0 a %d:\n", num_conjuntos - 1);
                input = pega_int(); // indice do conjunto a ser modificado (neste escopo)
                if (input >= 0 && input < num_conjuntos)
                {
                    inserir_elementos((int *)matriz, input, M, N);
                }
                else
                {
                    printf("Conjunto %d nao existe!\n", input);
                }
            }
            break;
        case 6:
            mostrar_conjunto((int *)matriz, num_conjuntos, N);
            break;
        case 7:
            mostrar_conjuntos((int *)matriz, num_conjuntos, M, N);
            break;
        case 9:
            sair_programa(&status);
            break;
        default:
            printf("Opcao %d nao encontrada! Tente novamente.\n", input);
            break;
        }

        if (status != 0)
        {
            printf("-------------------------\n");
        }
    }

    return 0;
}

int pega_int()
{
    int input;
    printf("> ");
    while (1)
    {
        if (scanf("%d", &input) == 1)
        {
            // Limpa o buffer de entrada, escaneando caracter por caracter ate encontrar o '\n',
            // que indica o fim da entrada (enter apertado)
            while (getchar() != '\n')
                ;
            return input;
        }
        else
        {
            printf("Entrada invalida. Insira um inteiro.\n> ");
            while (getchar() != '\n')
                ;
        }
    }
}

void mostrar_menu()
{
    printf("\nGerenciamento de Conjuntos\n\n");
    printf("Menu\n\n");
    printf("1-Criar um novo conjunto vazio\n");
    printf("2-Inserir dados em um conjunto\n");
    printf("3-Remover um conjunto\n");
    printf("4-Fazer a uniao entre dois conjuntos\n");
    printf("5-Fazer a interseccao entre dois conjuntos\n");
    printf("6-Mostrar um conjunto\n");
    printf("7-Mostrar todos os conjuntos\n");
    printf("8-Fazer busca por um valor\n");
    printf("9-Sair do programa\n\n");
    printf("Escolha uma opcao:\n");
}

void inserir_elementos(int *matriz, int i_conjunto, int linhas, int colunas)
{
    // verifica se o conjunto existe
    if (i_conjunto < 0 || i_conjunto >= linhas)
    {
        printf("Como voce chegou aqui? kkkk\n");
        printf("Conjunto %d nao existe dentro da matriz!\n", i_conjunto);
        return;
    }

    // confere se o ultimo elemento do conjunto foi inserido
    if (*(matriz + i_conjunto * colunas + colunas - 1) != 0)
    {
        printf("Conjunto %d cheio! Nao e possivel adicionar mais elementos.\n", i_conjunto);
        return;
    }
    else
    {
        int elemento;
        printf("Insira os elementos do conjunto %d (0 para parar):\n", i_conjunto);

        int i_inicial = 0; // indice do primeiro elemento vazio
        for (int i = 0; i < colunas; i++)
        {
            if (*(matriz + i_conjunto * colunas + i) != 0) // verifica o primeiro elemento vazio
            {
                i_inicial++; // incrementa caso for elemento valido
                // nota: por ter passado do primeiro 'if', sabemos que existe
                // pelo menos uma posicao valida
            }
        }

        printf("Voce pode inserir %d elementos.\n", colunas - i_inicial);

        for (int i = i_inicial; i < colunas; i++) // iterador para inserir elementos
        {
            elemento = pega_int();
            if (elemento == 0)
            {
                break; // Usuario parou de inserir elementos
            }
            else
            {
                int insert = 1; // flag de insercao
                for (int i_similar = 0; i_similar < colunas; i_similar++)
                {
                    if (elemento == *(matriz + i_conjunto * colunas + i_similar)) // verifica se o elemento ja existe no conjunto
                    {
                        printf("Elemento %d ja existe no conjunto %d! Tente novamente.\n", elemento, i_conjunto);
                        insert = 0;
                        i--;   // decrementa para desconsiderar insercao
                        break; // elemento ja existe, nao adiciona
                    }
                }
                if (insert == 1)
                {
                    *(matriz + i_conjunto * colunas + i) = elemento; // adiciona o elemento ao conjunto
                }
            }
        }
    }
}

void criar_conjunto(int *matriz, int *p_num_conjunto, int linhas, int colunas)
{
    if ((*p_num_conjunto) < linhas) // ha espaco para mais conjuntos
    {
        printf("Conjunto %d criado! ", (*p_num_conjunto));
        for (int i = 0; i < colunas; i++)
        {
            *(matriz + (*p_num_conjunto) * colunas + i) = 0; // inicializa o conjunto com 0
        }
        (*p_num_conjunto)++;
        printf("(%d/%d)\n", (*p_num_conjunto), linhas);
    }
    else // limite atingido
    {
        printf("Capacidade maxima de conjuntos atingida! (%d/%d)\n", (*p_num_conjunto), linhas);
    }
}

void mostrar_conjunto(int *matriz, int num_conjuntos, int colunas)
{
    if (num_conjuntos == 0)
    {
        printf("Nao ha conjuntos armazenados!\n");
        return;
    }
    else
    {
        printf("Escolha um conjunto de 0 a %d:\n", num_conjuntos - 1);
        int i_conjunto = pega_int();
        if (i_conjunto < 0 || i_conjunto >= num_conjuntos) // verifica se o conjunto existe
        {
            printf("Conjunto %d nao existe!\n", i_conjunto);
            return;
        }
        printf("Conjunto %d: ", i_conjunto);
        if (*(matriz + i_conjunto * colunas) == 0) // mostra "vazio" se o 1o elemento for 0
        {
            printf("vazio\n");
            return;
        }
        // mostra elementos do conjunto formatadamente
        printf("[%d", *(matriz + i_conjunto * colunas));
        for (int i = 1; i < colunas; i++) // se ha mais de um, imprime formatadamente
        {
            if (*(matriz + i_conjunto * colunas + i) != 0)
            {
                printf(", %d", *(matriz + i_conjunto * colunas + i));
            }
        }
        printf("]\n");
    }
}

void mostrar_conjuntos(int *matriz, int num_conjuntos, int linhas, int colunas)
{
    if (num_conjuntos == 0)
    {
        printf("Nao ha conjuntos armazenados!\n");
        return;
    }
    else
    {
        printf("Temos %d conjuntos:\n", num_conjuntos);

        for (int i = 0; i < num_conjuntos; i++) // iterador dos conjuntos
        {
            printf("Conjunto %d: ", i);

            if (*(matriz + i * colunas) == 0) // mostra "vazio" se o 1o elemento for 0
            {
                printf("vazio\n");
            }
            else // exibe elementos formatadamente
            {
                printf("[%d", *(matriz + i * colunas));
                for (int j = 1; j < colunas; j++) // se ha mais de um, imprime formatadamente
                {
                    if (*(matriz + i * colunas + j) != 0)
                    {
                        printf(", %d", *(matriz + i * colunas + j));
                    }
                }
                printf("]\n");
            }
        }
    }
}

void sair_programa(int *status)
{
    printf("Saindo do programa...\n");
    *status = 0;
}
