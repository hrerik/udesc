/*

NOTA PARA O PROFESSOR RUI:
Apesar de nao termos visto ponteiros em sala ainda, optei por usar por deixar o
programa mais "modular", ou seja, seria possivel usar a mesma funcao em outros
programas.

Outra coisa, se for fazer testes automatizados, tem uma area comentada na funcao 'int pega_int()' na
linha 298 (se eu nao der nenhum enter kkk) onde basta comentar a area 'PARA VALIDACOES' e descomentar
a area 'PARA TESTES AUTOMATIZADOS'. As validacoes podem atrapalhar os testes de maquina. 









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
#include <stdlib.h>

#define M 10 ///< Numero de linhas (conjuntos armazenados possiveis)
#define N 10 ///< Numero de colunhas (elementos em cada conjunto)

// PROTOTIPOS DE FUNCOES

/* Funcao que aceita somente inteiros como entrada. Feito atraves dum loop ate que um
inteiro seja inserido.
@returns inteiro que representa o valor inserido pelo usuario*/
int pega_int();

/* Funcao que verifica se existe um elemento igual ao do argumento dentro de uma linha
de uma matriz
@param matriz: ponteiro para matriz de inteiros que armazena os conjuntos
@param elemento: inteiro que representa o elemento a ser buscado
@param i_conjunto: inteiro que representa o indice da linha a ser analisada
@param colunas: inteiro que representa o numero de colunas da matriz
@returns i do elemento se existir; -1 caso contrario*/
int existe_igual(int *matriz, int elemento, int i_conjunto, int colunas);

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
@param p_num_conjuntos: ponteiro para inteiro que representa o numero de conjuntos
@param i_conjunto: inteiro que representa o indice do conjunto a ser removido
@param colunas: inteiro que representa o numero de colunas da matriz
@param linhas: inteiro que representa o numero de linhas da matriz*/
void remover_conjunto(int *matriz, int *p_num_conjuntos, int i_conjunto, int linhas, int colunas);

/* Faz a uniao entre dois conjuntos armazenados na matriz.
@param matriz: ponteiro para matriz de inteiros que armazena os conjuntos
@param p_num_conjuntos: ponteiro para inteiro que representa o numero de conjuntos
@param i_conjunto1: inteiro que representa o indice do primeiro conjunto
@param i_conjunto2: inteiro que representa o indice do segundo conjunto
@param colunas: inteiro que representa o numero de colunas da matriz
@param linhas: inteiro que representa o numero de linhas da matriz*/
void unir_conjuntos(int *matriz, int *p_num_conjuntos, int i_conjunto1, int i_conjunto2, int linhas, int colunas);

/* Faz a interseccao entre dois conjuntos armazenados na matriz.
@param matriz: ponteiro para matriz de inteiros que armazena os conjuntos
@param p_num_conjuntos: ponteiro para inteiro que representa o numero de conjuntos
@param i_conjunto1: inteiro que representa o indice do primeiro conjunto
@param i_conjunto2: inteiro que representa o indice do segundo conjunto
@param colunas: inteiro que representa o numero de colunas da matriz 
@param linhas: inteiro que representa o numero de linhas da matriz*/
void intersecionar_conjuntos(int *matriz, int *p_num_conjuntos, int i_conjunto1, int i_conjunto2, int linhas, int colunas);

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
    int *matriz = malloc(sizeof(int) * N * M);
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            //matriz[i][j] = 0;
            *(matriz + i * M + j) = 0;
        }
        
    }
    
    // Numero de conjuntos. Maximo de M conjuntos.
    int num_conjuntos = 0;

    // Indices dos conjuntos das unioes e intersecoes
    int i_conjunto1, i_conjunto2;

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
            criar_conjunto(matriz, &num_conjuntos, M, N);
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
                    inserir_elementos(matriz, input, M, N);
                }
                else
                {
                    printf("Conjunto %d nao existe!\n", input);
                }
            }
            break;
        case 3:
            if (num_conjuntos == 0)
            {
                printf("Nenhum conjunto criado! Crie um conjunto primeiro.\n");
            }
            else
            {
                printf("Escolha um conjunto de 0 a %d:\n", num_conjuntos - 1);
                input = pega_int(); // indice do conjunto a ser removido (neste escopo)
                remover_conjunto(matriz, &num_conjuntos, input, M, N);
            }
            break;
        case 4:
            if (num_conjuntos < 2)
            {
                printf("Necessario ter pelo menos 2 conjuntos para fazer a uniao!\n");
                break;
            }
            if (num_conjuntos == M)
            {
                printf("A matriz de conjuntos esta cheia! Nao e possivel fazer mais unioes.\n");
                break;
            }
            printf("Escolha dois conjuntos de 0 a %d:\n", num_conjuntos - 1);
            printf("Conjunto 1:\n");
            i_conjunto1 = pega_int();
            if (i_conjunto1 < 0 || i_conjunto1 >= num_conjuntos)
            {
                printf("Conjunto %d nao existe!\n", i_conjunto1);
                break;
            }
            printf("Conjunto 2:\n");
            i_conjunto2 = pega_int();
            if (i_conjunto2 < 0 || i_conjunto2 >= num_conjuntos)
            {
                printf("Conjunto %d nao existe!\n", i_conjunto2);
                break;
            }
            unir_conjuntos(matriz, &num_conjuntos, i_conjunto1, i_conjunto2, M, N);
            break;
        case 5:
            
            if (num_conjuntos < 2)
            {
                printf("Necessario ter pelo menos 2 conjuntos para fazer a intersecao!\n");
                break;
            }
            if (num_conjuntos == M)
            {
                printf("A matriz de conjuntos esta cheia! Nao e possivel fazer mais intersecoes.\n");
                break;
            }
            printf("Escolha dois conjuntos de 0 a %d:\n", num_conjuntos - 1);
            printf("Conjunto 1:\n");
            i_conjunto1 = pega_int();
            if (i_conjunto1 < 0 || i_conjunto1 >= num_conjuntos)
            {
                printf("Conjunto %d nao existe!\n", i_conjunto1);
                break;
            }
            printf("Conjunto 2:\n");
            i_conjunto2 = pega_int();
            if (i_conjunto2 < 0 || i_conjunto2 >= num_conjuntos)
            {
                printf("Conjunto %d nao existe!\n", i_conjunto2);
                break;
            }
            intersecionar_conjuntos(matriz, &num_conjuntos, i_conjunto1, i_conjunto2, M, N);
            break;
        case 6:
            mostrar_conjunto(matriz, num_conjuntos, N);
            break;
        case 7:
            mostrar_conjuntos(matriz, num_conjuntos, M, N);
            break;
        case 8:
            if (num_conjuntos == 0)
            {
                printf("Nao ha conjuntos para se buscar um valor.\n");
                break;
            }
            
            printf("Insira o elemento a ser buscado:\n");
            input = pega_int();
            buscar_elemento(matriz, num_conjuntos, input, N);
            break;
        case 9:
            sair_programa(&status);
            break;
        default:
            printf("Opcao %d nao encontrada!\n", input);
            break;
        }

        if (status != 0)
        {
            // printf("Pressione ENTER para continuar...");
            // while (getchar() != '\n')
            //     ; // Limpa o buffer de entrada
            printf("-------------------------\n");
        }
    }

    free(matriz);
    return 0;
}

int pega_int()
{
    int input = 0;

    // PARA VALIDACOES:
    //---------------------------------------------------------
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
    //---------------------------------------------------------


    // PARA TESTES AUTOMATIZADOS:
    // scanf("%d", &input);
    return input;
}

int existe_igual(int *matriz, int elemento, int i_conjunto, int colunas)
{
    for (int i = 0; i < colunas; i++) // iterador sobre [indices do] conjunto
    {
        int m_elemento = *(matriz + i_conjunto * colunas + i);
        if (m_elemento == 0)
        {
            // fim do conjunto ou conjunto vazio (nao ha mais elementos)
            break;
        }
        if (m_elemento == elemento)
        {
            return i;
        }
    }
    return -1;
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

void inserir_elementos(int *matriz, int i_conjunto, int linhas, int colunas)
{
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

void remover_conjunto(int *matriz, int *p_num_conjuntos, int i_conjunto, int linhas, int colunas)
{
    if (*p_num_conjuntos == 0)
    {
        // como voce chegou aqui? ksksk
        printf("Nao ha conjuntos armazenados!\n");
        return;
    }
    if (i_conjunto < 0 || i_conjunto >= *p_num_conjuntos)
    {
        printf("Conjunto %d nao existe!\n", i_conjunto);
        return;
    }
    for (int i = 0; i < colunas; i++)
    {
        // zera o conjunto antes de remove-lo (para nao aparecer elementos "lixos")
        *(matriz + i_conjunto * colunas + i) = 0;
    }
    (*p_num_conjuntos)--;
    printf("Conjunto %d removido! (%d/%d)\n", i_conjunto, *p_num_conjuntos, linhas);

    // se o conjunto a ser removido nao for o ultimo
    // (nota: necessariamente i_conjunto < num_conjuntos)
    if (i_conjunto != *p_num_conjuntos)
    {
        for (int i = i_conjunto; i < *p_num_conjuntos; i++)
        {
            for (int j = 0; j < colunas; j++)
            {
                // move uma linha para "cima"
                *(matriz + i * colunas + j) = *(matriz + (i + 1) * colunas + j);
            }
        }
        for (int i = 0; i < colunas; i++)
        {
            // zera ultima linha para nao ter um conjunto "lixo"
            *(matriz + *p_num_conjuntos * colunas + i) = 0;
        }
    }
}

void unir_conjuntos(int *matriz, int *p_num_conjuntos, int i_conjunto1, int i_conjunto2, int linhas, int colunas)
{
    // aqui assumindo que pode-se fazer a uniao

    // zera conjunto (pode ter lixo)
    for (int i = 0; i < colunas; i++)
    {
        *(matriz + (*p_num_conjuntos) * colunas + i) = 0;
    }
    

    int num_elementos = 0;
    for (int i = 0; i < colunas; i++)
    {
        // copia o primeiro conjunto na ultima linha vaga
        int cp_elem = *(matriz + i_conjunto1 * colunas + i); // elemento copiado
        if (cp_elem == 0) // chegou no fim
        {
            break;
        }
        *(matriz + (*p_num_conjuntos) * colunas + i) = cp_elem;
        num_elementos++;
    }

    // iterador para o segundo conjunto
    // verifica se o elemento ja existe no primeiro
    // caso contrario, adiciona na ultima linha
    for (int i = 0; i < colunas; i++)
    {
        int elem2 = *(matriz + i_conjunto2 * colunas + i); // elemento do segundo conjunto
        if (elem2 == 0)                                    // chegou no fim
        {
            break;
        }
        if (existe_igual(matriz, elem2, *p_num_conjuntos, colunas) == -1) // -1 se nao existe
        {
            if (num_elementos == colunas) // se o conjunto estiver cheio
            {
                printf("Uniao cria um conjunto com mais de %d elementos.\n", colunas);
                printf("Impossivel salvar dentro da matriz!\n");
                printf("Uniao nao realizada.\n");
                for (int j = 0; j < colunas; j++)
                {
                    *(matriz + (*p_num_conjuntos) * colunas + j) = 0; // zera o conjunto para nao ter lixo
                }
                return; // sai do void
            }
            *(matriz + *p_num_conjuntos * colunas + num_elementos) = elem2; // adiciona o elemento na ultima linha
            num_elementos++;
        }
    }
    (*p_num_conjuntos)++; // so chega nesta linha se a operacao foi bem sucedida
    printf("Uniao entre conjuntos %d e %d criada! (%d/%d)\n", i_conjunto1, i_conjunto2, *p_num_conjuntos, linhas);
}

void intersecionar_conjuntos(int *matriz, int *p_num_conjuntos, int i_conjunto1, int i_conjunto2, int linhas, int colunas) {
    
    // aqui assumindo que pode-se fazer a intersecao

    // zera conjunto (pode ter lixo)
    for (int i = 0; i < colunas; i++)
    {
        *(matriz + (*p_num_conjuntos) * colunas + i) = 0;
    }
    

    int i_intersecao = 0;
    for (int i = 0; *(matriz + i_conjunto1*colunas + i) != 0 && i < colunas; i++)
    {
        int elem = *(matriz + i_conjunto1*colunas + i);
        if (existe_igual(matriz, elem, i_conjunto2, colunas) != -1)
        {
            *(matriz + (*p_num_conjuntos) * colunas + i_intersecao) = elem;
            i_intersecao++;
        }
    }
    
    (*p_num_conjuntos)++;
    printf("Intersecao entre conjuntos %d e %d criada! (%d/%d)\n", i_conjunto1, i_conjunto2, (*p_num_conjuntos), linhas);
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

void buscar_elemento(int *matriz, int num_conjuntos, int elemento, int colunas)
{

    int flag_encontrado = 0;
    printf("Encontrado em...\n");

    for (int i = 0; i < num_conjuntos; i++) // iterador sobre [indices de] conjuntos
    {
        if (existe_igual(matriz, elemento, i, colunas) != -1)
        {
            printf("Conjunto %d\n", i);
            flag_encontrado = 1;
        }
    }
    if (flag_encontrado == 0)
    {
        printf("Nenhum conjunto.\n");
    }
}

void sair_programa(int *status)
{
    printf("Saindo do programa...\n");
    *status = 0;
}

