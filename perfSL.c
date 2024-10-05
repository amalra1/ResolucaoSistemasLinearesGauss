#include <stdio.h>
#include "utils.h"
//#include <likwid.h>

// Encontra o maior valor da coluna i na matriz A
// E retorna o índice da linha aonde está
int_t encontraMaxColuna(real_t **A, int_t i, int_t n)
{
    real_t maior = A[0][i];
    int_t indiceMaior = 0;

    for (int j = 0; j < n; j++)
    {
        if (fabs(A[j][i]) > fabs(maior))
        {
            maior = A[j][i];
            indiceMaior = j;
        }
    }

    //printf("%ld\n", indiceMaior);
    return indiceMaior;
}

// Troca a linha inteira do iPivo com a linha do i
// E deixa o número do iPivo por primeiro
void trocaLinha(real_t **A, real_t *B, int_t i, int_t iPivo, int_t n)
{
    real_t temp;

    // Troca em A
    for (int j = 0; j < n; j++)
    {
        temp = A[iPivo][j];
        A[iPivo][j] = A[i][j];
        A[i][j] = temp;
    }

    // Troca em B
    temp = B[iPivo];
    B[iPivo] = B[i];
    B[i] = temp;
}

void triangulariza_gauss(real_t **A, real_t *B, int_t n)
{
    for (int i = 0; i < n; i++)
    {
        int_t iPivo = encontraMaxColuna(A, i, n);

        if (i != iPivo)
            trocaLinha(A, B, i, iPivo, n);

        for(int k = i + 1; k < n; k++)
        {
            real_t m = A[k][i] / A[i][i];
            A[k][i] = 0.0;

            for (int j = i + 1; j < n; j++)
                A[k][j] -= A[i][j] * m;
            B[k] -= B[i] * m;
        }
    }
}

void retrosubstituicao(real_t **A, real_t *B, int_t n, real_t *X)
{
    for (int i = n - 1; i >= 0; i--)
    {
        real_t soma = 0.0;
        for (int j = i + 1; j < n; j++)
        {
            soma += A[i][j] * X[j];
        }
        X[i] = (B[i] - soma) / A[i][i];
    }
}

int main()
{
    int_t n;
    
    scanf("%ld", &n);

    real_t **A = (real_t **)malloc(n * sizeof(real_t *));
    for (int i = 0; i < n; i++)
        A[i] = (real_t *)malloc(n * sizeof(real_t));
    real_t *B = (real_t *)malloc(n * sizeof(real_t));
    real_t *X = (real_t *)malloc(n * sizeof(real_t));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%lf", &A[i][j]);
        
        scanf("%lf", &B[i]);
    }

    triangulariza_gauss(A, B, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%lf ", A[i][j]);
        
        printf("= %lf\n", B[i]);
    }

    // Retrosubstituição
    retrosubstituicao(A, B, n, X);

    for (int i = 0; i < n; i++)
    {
        printf("%lf ", X[i]);
    }
    printf("\n");

   // Imprime saída 

    // Frees
    for (int i = 0; i < n; i++)
        free(A[i]);
    free(A);
    free(B);
    free(X);

    return 0;
}