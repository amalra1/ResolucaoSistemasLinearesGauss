#include <stdio.h>
#include "utils.h"
#include <likwid.h>

// Encontra o maior valor na matriz A a partir da linha i
// E retorna seu índice
int_t encontraMax(real_t **A, int_t i, int_t n)
{
    real_t maior = A[i][0];

    for (int j = i; j < n; j++)
        for (int k = 0; k < n; k++)
            if (A[j][k] > maior)   // Comparação entre floats ---- MUDAR
                maior = A[j][k];
    
    printf("%lf\n", maior);
    return maior;
}

// Troca a linha inteira do iPivo com a linha do i
// E deixa o número do iPivo por primeiro
void trocaLinha(real_t **A, real_t *B, int_t i, int_t iPivo)
{

}

void triangulariza_gauss(real_t **A, real_t *B, int_t n)
{
    for (int i = 0; i < n; i++)
    {
        int_t iPivo = encontraMax(A, i, n);

        if (i != iPivo)
            trocaLinha(A, B, i, iPivo);

        for(int k = i + 1; k < n; k++)
        {
            real_t m = A[k][i] = 0.0;

            for (int j = i + 1; j < n; j++)
                A[k][j] -= A[i][j] * m;
            B[k] -= B[i] * m;
        }
    }
}

int main()
{
    int_t n;
    
    scanf("%ld", &n);

    real_t A[n][n];
    real_t B[n];

    // real_t **A;
    // real_t *B;

    // B = malloc(sizeof(real_t) * n);
    // A = malloc(sizeof(real_t*) * n);
    // for (int i = 0; i < n; i++)
    //     A = malloc(sizeof(real_t) * n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%lf", &A[i][j]);
        
        scanf("%lf", &B[i]);
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //         printf("%lf ", A[i][j]);
        
    //     printf("= %lf\n", B[i]);
    // }

    return 0;
}