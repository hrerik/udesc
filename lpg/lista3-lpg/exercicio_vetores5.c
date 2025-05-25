// Eu tenho nojo desse codigo

#include <stdio.h>
// 10 3 6 7 -1 3 12 9 8 3 17 3

/* 
Sempre do fim ao inicio do vetor

Retorna:
-1 -> Quando nao encontra a chave
n - 1 -> Quando encontra a chave, sendo n o enesimo elemento da iteracao
*/
int busca_seq_rec(int v[], int n, int chave);

int main()
{

    int n = 0, chave = 0;

    printf("Qual o tamanho do vetor de busca?\n> ");
    scanf("%d", &n);

    int v[n];
    int indices[n];
    int v_aux[n];

    printf("Digite cada elemento:\n> ");
    int elem = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &elem);
        v[i] = elem;
    }

    for (int i = 0; i < n; i++)
    {
        v_aux[i] = v[i];
    }
    

    printf("Qual a chave de busca?\n> ");
    scanf("%d", &chave);


    int sub_v_n = 0;
    for (int i = 0; i < n; i++)
    {   
        int termo = busca_seq_rec(v_aux, n, chave);
        indices[i] = termo;
        if (v_aux[termo] == chave) {
            v_aux[termo]++;
            sub_v_n++;
        }
        // printf("i: %d / Termo: %d / v_aux[termo]: %d\n", i, termo, v_aux[termo]);
    }

    if (sub_v_n > 0) {
        int sub_v[sub_v_n];
        for (int i = 0; i < sub_v_n; i++)
        {
            int t = (sub_v_n - i) - 1;
            sub_v[i] = indices[t];
            // printf("%d ",t);
            // printf("%d ",indices[t]);
            // printf("%d\n", sub_v[i]);
        }
        for (int i = 0; i < sub_v_n; i++)
        {  
            indices[i] = sub_v[i];
        }
        
    }
    
    

    printf("Vetor de indices:\n> [");
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d, ", indices[i]);
    }
    printf("%d]", indices[n - 1]);

    return 0;
}


int busca_seq_rec(int v[], int n, int chave)
{
    if (n <= 0)
    {
        return -1;
    }
    if (v[n - 1] == chave)
    {
        return n - 1;
    }
    return busca_seq_rec(v, n - 1, chave);
}
