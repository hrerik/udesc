#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct
{
    int hora;
    int minuto;
} Horario;

typedef struct
{
    Data data;
    Horario horario_inicio;
    Horario horario_fim;
    char descricao[100];
    char local[100];
} Evento;

/* Valida se uma data e valida.
@param dia: inteiro que representa o dia
@param mes: inteiro que representa o mes
@param ano: inteiro que representa o ano
@return: inteiro 1 se valida, 0 caso contrario */
int validarData(int dia, int mes, int ano);

/* Valida se um horario e valido.
@param hora: inteiro que representa a hora
@param minuto: inteiro que representa o minuto
@return: inteiro 1 se valido, 0 caso contrario */
int validarHorario(int hora, int minuto);

/* Compara dois eventos por data e horario de inicio.
@param a: estrutura Evento para comparacao
@param b: estrutura Evento para comparacao
@return: inteiro positivo se a vem depois de b, 
negativo se a antes de b e 0 se ao mesmo tempo
(tecnicamente impossivel) */
int compararDataHorario(Evento a, Evento b);

/* Verifica se um novo evento sobrepoe algum evento existente.
@param novo: estrutura Evento a ser verificada
@param eventos: ponteiro para array de estruturas Evento
@param total: inteiro que representa o numero total de eventos
@return: inteiro 1 se ha sobreposicao, 0 caso contrario */
int verificarSobreposicao(Evento novo, Evento *eventos, int total);

/* Carrega eventos do arquivo de texto para a memoria.
@param eventos: ponteiro para ponteiro de array de estruturas Evento
@return: inteiro que representa o numero de eventos carregados */
int carregarEventos(Evento **eventos);

/* Salva eventos da memoria para o arquivo de texto.
@param eventos: ponteiro para array de estruturas Evento
@param total: inteiro que representa o numero total de eventos */
void salvarEventos(Evento *eventos, int total);

/* Cadastra um novo evento na agenda.
@param eventos: ponteiro para ponteiro de array de estruturas Evento
@param total: ponteiro para inteiro que representa o numero total de eventos */
void cadastrarEvento(Evento **eventos, int *total);

/* Mostra todos os eventos cadastrados na agenda.
@param eventos: ponteiro para array de estruturas Evento
@param total: inteiro que representa o numero total de eventos */
void mostrarTodosEventos(Evento *eventos, int total);

/* Mostra todos os eventos de uma data especifica.
@param eventos: ponteiro para array de estruturas Evento
@param total: inteiro que representa o numero total de eventos */
void mostrarEventosPorData(Evento *eventos, int total);

/* Mostra todos os eventos com uma descricao especifica.
@param eventos: ponteiro para array de estruturas Evento
@param total: inteiro que representa o numero total de eventos */
void mostrarEventosPorDescricao(Evento *eventos, int total);

/* Remove um evento da agenda baseado na data e horario de inicio.
@param eventos: ponteiro para ponteiro de array de estruturas Evento
@param total: ponteiro para inteiro que representa o numero total de eventos */
void removerEvento(Evento **eventos, int *total);

int main()
{
    Evento *eventos = NULL; // Vetor de structs de Eventos
    int total = carregarEventos(&eventos); //
    int opcao;

    do
    {
        printf("\n--- AGENDA DE EVENTOS ---\n");
        printf("1. Cadastrar novo evento\n");
        printf("2. Mostrar todos os eventos\n");
        printf("3. Mostrar eventos por data\n");
        printf("4. Mostrar eventos por descricao\n");
        printf("5. Remover evento\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastrarEvento(&eventos, &total);
            break;
        case 2:
            mostrarTodosEventos(eventos, total);
            break;
        case 3:
            mostrarEventosPorData(eventos, total);
            break;
        case 4:
            mostrarEventosPorDescricao(eventos, total);
            break;
        case 5:
            removerEvento(&eventos, &total);
            break;
        case 6:
            salvarEventos(eventos, total);
            // nao necessario eventos = NULL pois o programa esta encerrando
            if (eventos)
            {
                free(eventos);
            }
            printf("Programa encerrado!\n");
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while (opcao != 6);

    return 0;
}

int validarData(int dia, int mes, int ano)
{
    if (ano < 1900 || ano > 2100)
        return 0;
    if (mes < 1 || mes > 12)
        return 0;

    int diasMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (mes == 2 && ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)))
    {
        diasMes[1] = 29;
    }

    if (dia < 1 || dia > diasMes[mes - 1])
        return 0;

    return 1;
}

int validarHorario(int hora, int minuto)
{
    return (hora >= 0 && hora <= 23 && minuto >= 0 && minuto <= 59);
}

int compararDataHorario(Evento a, Evento b)
{
    if (a.data.ano != b.data.ano)
        return a.data.ano - b.data.ano;
    if (a.data.mes != b.data.mes)
        return a.data.mes - b.data.mes;
    if (a.data.dia != b.data.dia)
        return a.data.dia - b.data.dia;
    if (a.horario_inicio.hora != b.horario_inicio.hora)
        return a.horario_inicio.hora - b.horario_inicio.hora;
    return a.horario_inicio.minuto - b.horario_inicio.minuto;
}

int verificarSobreposicao(Evento novo, Evento *eventos, int total)
{
    for (int i = 0; i < total; i++)
    {
        if (novo.data.ano == eventos[i].data.ano &&
            novo.data.mes == eventos[i].data.mes &&
            novo.data.dia == eventos[i].data.dia)
        {

            // convertendo horario em minutos a partir da meia noite
            int inicio_novo = novo.horario_inicio.hora * 60 + novo.horario_inicio.minuto;
            int fim_novo = novo.horario_fim.hora * 60 + novo.horario_fim.minuto;
            int inicio_existente = eventos[i].horario_inicio.hora * 60 + eventos[i].horario_inicio.minuto;
            int fim_existente = eventos[i].horario_fim.hora * 60 + eventos[i].horario_fim.minuto;

            if (!(fim_novo <= inicio_existente || inicio_novo >= fim_existente))
            {
                return 1;
            }
        }
    }
    return 0;
}

int carregarEventos(Evento **eventos)
{
    // foi usado **eventos e nao *evento por que o primeiro asteristico pegava
    // o endereco de eventos o segundo eh pelo fato de eventos ser um vetor

    FILE *arquivo = fopen("agenda.txt", "r");
    if (!arquivo) // arquivo nao existe, nao ha registros
    {
        return 0;
    }

    int total = 0;
    fscanf(arquivo, "Registros: %d\n", &total);

    if (total == 0)
    {
        fclose(arquivo);
        return 0;
    }

    // casting pro compilador saber que dados estao sendo lidados
    *eventos = (Evento *)malloc(total * sizeof(Evento));

    for (int i = 0; i < total; i++)
    {
        fscanf(arquivo, "---\n"); // ignora
        // interpretacao
        // eventos eh um ponteiro pra "eventos_main", logo fscanf recebendo &eventos altera no vetor da main
        // assim, &(*eventos)[i] eh o endereco de um evento do vetor da main
        // dava pra fazer com *(evento + i), mas buguei na hora :(
        fscanf(arquivo, "Data: %d/%d/%d\n", &(*eventos)[i].data.dia, &(*eventos)[i].data.mes, &(*eventos)[i].data.ano);
        fscanf(arquivo, "Inicio: %d:%d\n", &(*eventos)[i].horario_inicio.hora, &(*eventos)[i].horario_inicio.minuto);
        fscanf(arquivo, "Fim: %d:%d\n", &(*eventos)[i].horario_fim.hora, &(*eventos)[i].horario_fim.minuto);
        fscanf(arquivo, "Descricao: %99[^\n]\n", (*eventos)[i].descricao);
        fscanf(arquivo, "Local: %99[^\n]\n", (*eventos)[i].local);
    }

    fclose(arquivo);
    return total;
}

void salvarEventos(Evento *eventos, int total)
{
    FILE *arquivo = fopen("agenda.txt", "w");
    if (!arquivo)
    {
        // por algum motivo o arquivo não pode ser editado/criado
        printf("Erro ao salvar arquivo!\n");
        return;
    }

    fprintf(arquivo, "Registros: %d\n", total);

    for (int i = 0; i < total; i++)
    {
        fprintf(arquivo, "---\n");
        fprintf(arquivo, "Data: %02d/%02d/%04d\n", eventos[i].data.dia, eventos[i].data.mes, eventos[i].data.ano);
        fprintf(arquivo, "Inicio: %02d:%02d\n", eventos[i].horario_inicio.hora, eventos[i].horario_inicio.minuto);
        fprintf(arquivo, "Fim: %02d:%02d\n", eventos[i].horario_fim.hora, eventos[i].horario_fim.minuto);
        fprintf(arquivo, "Descricao: %s\n", eventos[i].descricao);
        fprintf(arquivo, "Local: %s\n", eventos[i].local);
    }

    fclose(arquivo);
}

void cadastrarEvento(Evento **eventos, int *total)
{
    Evento novo;

    printf("Digite a data (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &novo.data.dia, &novo.data.mes, &novo.data.ano);

    if (!validarData(novo.data.dia, novo.data.mes, novo.data.ano))
    {
        printf("Data invalida!\n");
        return;
    }

    printf("Digite o horario de inicio (hh:mm): ");
    scanf("%d:%d", &novo.horario_inicio.hora, &novo.horario_inicio.minuto);

    if (!validarHorario(novo.horario_inicio.hora, novo.horario_inicio.minuto))
    {
        printf("Horario de inicio invalido!\n");
        return;
    }

    printf("Digite o horario de fim (hh:mm): ");
    scanf("%d:%d", &novo.horario_fim.hora, &novo.horario_fim.minuto);

    if (!validarHorario(novo.horario_fim.hora, novo.horario_fim.minuto))
    {
        printf("Horario de fim invalido!\n");
        return;
    }

    // validacao unica pra horarios dum mesmo evento
    int inicio_min = novo.horario_inicio.hora * 60 + novo.horario_inicio.minuto;
    int fim_min = novo.horario_fim.hora * 60 + novo.horario_fim.minuto;

    if (inicio_min >= fim_min)
    {
        printf("Horario de fim deve ser posterior ao de inicio!\n");
        return;
    }

    if (verificarSobreposicao(novo, *eventos, *total))
    {
        printf("Evento sobrepoe outro evento ja cadastrado!\n");
        return;
    }

    printf("Digite a descricao: ");
    getchar();
    fgets(novo.descricao, 100, stdin);
    novo.descricao[strcspn(novo.descricao, "\n")] = '\0';

    printf("Digite o local: ");
    fgets(novo.local, 100, stdin);
    novo.local[strcspn(novo.local, "\n")] = '\0';

    *eventos = (Evento *)realloc(*eventos, (*total + 1) * sizeof(Evento));
    (*eventos)[*total] = novo;
    (*total)++;


    // algoritmo de reordenacao de eventos por data e hora
    for (int i = 0; i < *total - 1; i++)
    {
        for (int j = i + 1; j < *total; j++)
        {
            if (compararDataHorario((*eventos)[i], (*eventos)[j]) > 0)
            {
                Evento temp = (*eventos)[i];
                (*eventos)[i] = (*eventos)[j];
                (*eventos)[j] = temp;
            }
        }
    }

    printf("Evento cadastrado com sucesso!\n");
}

void mostrarTodosEventos(Evento *eventos, int total)
{
    if (total == 0)
    {
        printf("Nenhum evento cadastrado!\n");
        return;
    }

    printf("\n--- TODOS OS EVENTOS ---\n");
    for (int i = 0; i < total; i++)
    {
        printf("Data: %02d/%02d/%04d\n", eventos[i].data.dia, eventos[i].data.mes, eventos[i].data.ano);
        printf("Inicio: %02d:%02d\n", eventos[i].horario_inicio.hora, eventos[i].horario_inicio.minuto);
        printf("Fim: %02d:%02d\n", eventos[i].horario_fim.hora, eventos[i].horario_fim.minuto);
        printf("Descricao: %s\n", eventos[i].descricao);
        printf("Local: %s\n", eventos[i].local);
        printf("-----------------------\n");
    }
}

void mostrarEventosPorData(Evento *eventos, int total)
{
    if (total == 0)
    {
        printf("Nenhum evento cadastrado!\n");
        return;
    }

    Data data_busca;
    printf("Digite a data (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &data_busca.dia, &data_busca.mes, &data_busca.ano);

    if (!validarData(data_busca.dia, data_busca.mes, data_busca.ano))
    {
        printf("Data invalida!\n");
        return;
    }

    int encontrados = 0;
    printf("\n--- EVENTOS EM %02d/%02d/%04d ---\n", data_busca.dia, data_busca.mes, data_busca.ano);

    for (int i = 0; i < total; i++)
    {
        if (eventos[i].data.dia == data_busca.dia &&
            eventos[i].data.mes == data_busca.mes &&
            eventos[i].data.ano == data_busca.ano)
        {

            printf("Inicio: %02d:%02d\n", eventos[i].horario_inicio.hora, eventos[i].horario_inicio.minuto);
            printf("Fim: %02d:%02d\n", eventos[i].horario_fim.hora, eventos[i].horario_fim.minuto);
            printf("Descricao: %s\n", eventos[i].descricao);
            printf("Local: %s\n", eventos[i].local);
            printf("-----------------------\n");
            encontrados++;
        }
    }

    if (encontrados == 0)
    {
        printf("Nenhum evento encontrado para esta data!\n");
    }
}

void mostrarEventosPorDescricao(Evento *eventos, int total)
{
    if (total == 0)
    {
        printf("Nenhum evento cadastrado!\n");
        return;
    }

    char descricao_busca[100];
    printf("Digite a descricao: ");
    getchar(); // consome o '\n' desgracado
    fgets(descricao_busca, 100, stdin);
    // strcspn eh funcao que pega o num de chars antes de uma string
    // especificada, que no caso eh o proprio indice de '\n'
    descricao_busca[strcspn(descricao_busca, "\n")] = '\0';

    int encontrados = 0;
    printf("\n--- EVENTOS COM DESCRICAO: %s ---\n", descricao_busca);

    for (int i = 0; i < total; i++)
    {
        if (strcmp(eventos[i].descricao, descricao_busca) == 0)
        {
            printf("Data: %02d/%02d/%04d\n", eventos[i].data.dia, eventos[i].data.mes, eventos[i].data.ano);
            printf("Inicio: %02d:%02d\n", eventos[i].horario_inicio.hora, eventos[i].horario_inicio.minuto);
            printf("Fim: %02d:%02d\n", eventos[i].horario_fim.hora, eventos[i].horario_fim.minuto);
            printf("Local: %s\n", eventos[i].local);
            printf("-----------------------\n");
            encontrados++;
        }
    }

    if (encontrados == 0)
    {
        printf("Nenhum evento encontrado com essa descricao!\n");
    }
}

void removerEvento(Evento **eventos, int *total)
{
    if (*total == 0)
    {
        printf("Nenhum evento cadastrado!\n");
        return;
    }

    Data data_busca;
    Horario horario_busca;

    printf("Digite a data (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &data_busca.dia, &data_busca.mes, &data_busca.ano);

    if (!validarData(data_busca.dia, data_busca.mes, data_busca.ano))
    {
        printf("Data invalida!\n");
        return;
    }

    printf("Digite o horario de inicio (hh:mm): ");
    scanf("%d:%d", &horario_busca.hora, &horario_busca.minuto);

    if (!validarHorario(horario_busca.hora, horario_busca.minuto))
    {
        printf("Horario invalido!\n");
        return;
    }

    int indice = -1;
    for (int i = 0; i < *total; i++)
    {
        if ((*eventos)[i].data.dia == data_busca.dia &&
            (*eventos)[i].data.mes == data_busca.mes &&
            (*eventos)[i].data.ano == data_busca.ano &&
            (*eventos)[i].horario_inicio.hora == horario_busca.hora &&
            (*eventos)[i].horario_inicio.minuto == horario_busca.minuto)
        {
            indice = i;
            break;
        }
    }

    if (indice == -1)
    {
        printf("Evento nao encontrado!\n");
        return;
    }

    for (int i = indice; i < *total - 1; i++)
    {
        (*eventos)[i] = (*eventos)[i + 1];
    }

    (*total)--;

    if (*total == 0)
    {
        // mais seguro que o mero realloc(), pois so o free() cria um
        // "ponteiro pendente" (dangling pointer) que aponta para um
        // espaco de memoria liberada
        free(*eventos);
        *eventos = NULL;
    }
    else
    {
        *eventos = (Evento *)realloc(*eventos, (*total) * sizeof(Evento));
    }

    printf("Evento removido com sucesso!\n");
}