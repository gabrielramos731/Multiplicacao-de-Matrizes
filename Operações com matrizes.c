#include <stdio.h>
#include <stdlib.h>

const int MAX = 10;
int L;
int C;

void CarregaM (int m[L][C]);
void Apresenta (int m[L][C]);
void CriaOposta (int o[L][C], int m[L][C]);
void Multiplica (int p[L][C], int m[L][C], int o[L][C]);

int main() //Gabriel Ramos da Silba - 06/2021
{
    scanf ("%d %d", &L, &C);

    int m [L][C];   //matriz m
    int o [L][C];   //matriz oposta
    int p [L][C];   //matriz produto

        if(L > MAX || C > MAX)
    {
        printf("Arquivo contém matriz maior que o suportado!\n");
        return 1;
    }

    CarregaM (m);
    Apresenta (m);
    CriaOposta (o, m);
    Multiplica (p, m, o);

    return 0;
}

void
CarregaM (int m[L][C]) //função para carregar a matriz contida no arquivo
{
    int i, j;

    printf ("Carrega M\n");
    for (i = 0; i < L; i++)   //carrega a matriz m
        for (j = 0; j < C; j++)
            scanf ("%d", &m[i][j]);

}

void
Apresenta (int m[L][C]) //função que irá apresentar a matriz carregada
{
    int i, j;   //controladores da matriz m

    printf ("Matriz original \n");
    for (i = 0; i < L; i++)
    {
        for (j = 0; j < C; j++)
            printf ("%2d ", m[i][j]);

        printf ("\n");
    }

}

void
CriaOposta (int o[L][C], int m[L][C]) //função que irá gerar e apresentar a matriz oposta
{
    int i, j;   //controladores de m
    int q, r;   //controladores de o (oposta de m)

    for (i = 0, q = 0; i < L; i++, q++)
    {
        for (j = 0, r = 0; j < C; j++, r++)
            o[q][r] = -m[i][j];   //gera a matriz oposta

    }
    printf ("Matriz oposta\n");
    for (q = 0; q < L; q++)
    {
        for (r = 0; r < C; r++)
            printf ("%2d ", o[q][r]);

        printf ("\n");
    }
}

void
Multiplica (int p[L][C], int m[L][C], int o[L][C]) //função que gera e apresenta a matriz produto
{
    int i, j;   //controladores de m
    int q, r;   //controladores de o
    int t = 0, u = 0;   //controladores de p (matriz produto)
    int a;   //variável que armazena o produto

    for (i = 0; i < L; i++, t++)
    {
        for (r = 0; r < C; u++, r++)
        {
            for (a = 0, j = 0, q = 0; j < C; j++, q++)
                a = a + (m[i][j] * o[q][r]);

            p[t][u] = a;
            a = 0;
            j = 0, q = 0;
        }
        r = 0;
        j = 0;
        u = 0;
    }

    printf ("Matriz produto\n");
    for (t = 0; t < L; t++)
    {
        for (u = 0; u < C; u++)
            printf ("%2d ", p[t][u]);  //apresanta m x o

        printf ("\n");
    }
}

