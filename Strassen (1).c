#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int** sum(int **A, int **B, int n)
{
    int** C = (int**)malloc(n*sizeof(int *));
    for(int i = 0; i < n; i++) C[i] = (int*)malloc(n*sizeof(int));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}
int** mul(int **A, int **B, int k)
{
    int n = (int)pow(2, (double)k);
    int m = (int)pow(2, (double)(k-1));
    int** C = (int**)malloc(n*sizeof(int*));
    for(int i = 0; i < n; i++) C[i] = (int*)malloc(n*sizeof(int));
    if(k == 1)
    {
        C[0][0] = A[0][0]*B[0][0] + A[0][1]*B[1][0];
        C[0][1] = A[0][0]*B[0][1] + A[0][1]*B[1][1];
        C[1][0] = A[1][0]*B[0][0] + A[1][1]*B[1][0];
        C[1][1] = A[1][0]*B[0][1] + A[1][1]*B[1][1];
        return C;
    }
    int** A1 = (int**)malloc(m*sizeof(int*));
    for(int i = 0; i < m; i++) A1[i] = (int*)malloc(m*sizeof(int));
    int** A2 = (int**)malloc(m*sizeof(int*));
    for(int i = 0; i < m; i++) A2[i] = (int*)malloc(m*sizeof(int));
    int** A3 = (int**)malloc(m*sizeof(int*));
    for(int i = 0; i < m; i++) A3[i] = (int*)malloc(m*sizeof(int));
    int** A4 = (int**)malloc(m*sizeof(int*));
    for(int i = 0; i < m; i++) A4[i] = (int*)malloc(m*sizeof(int));
    int** B1 = (int**)malloc(m*sizeof(int*));
    for(int i = 0; i < m; i++) B1[i] = (int*)malloc(m*sizeof(int));
    int** B2 = (int**)malloc(m*sizeof(int*));
    for(int i = 0; i < m; i++) B2[i] = (int*)malloc(m*sizeof(int));
    int** B3 = (int**)malloc(m*sizeof(int*));
    for(int i = 0; i < m; i++) B3[i] = (int*)malloc(m*sizeof(int));
    int** B4 = (int**)malloc(m*sizeof(int*));
    for(int i = 0; i < m; i++) B4[i] = (int*)malloc(m*sizeof(int));
    int **C1; int **C2; int **C3; int **C4;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)
        {
            A1[i][j] = A[i][j];
            B1[i][j] = B[i][j];
        }
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = m; j < n; j++)
        {
            A2[i][j-m] = A[i][j];
            B2[i][j-m] = B[i][j];
        }
    }
    for(int i = m; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            A3[i-m][j] = A[i][j];
            B3[i-m][j] = B[i][j];
        }
    }
    for(int i = m; i < n; i++)
    {
        for(int j = m; j < n; j++)
        {
            A4[i-m][j-m] = A[i][j];
            B4[i-m][j-m] = B[i][j];
        }
    }
    C1 = sum(mul(A2,B3,k-1), mul(A1,B1,k-1), m);
    C2 = sum(mul(A4,B4,k-1), mul(A3,B2,k-1), m);
    C3 = sum(mul(A3,B1,k-1), mul(A4,B3,k-1), m);
    C4 = sum(mul(A1,B2,k-1), mul(A2,B4,k-1), m);
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)
        {
            C[i][j] = C1[i][j];
        }
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = m; j < n; j++)
        {
            C[i][j] = C2[i][j-m];
        }
    }
    for(int i = m; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            C[i][j] = C3[i-m][j];
        }
    }
    for(int i = m; i < n; i++)
    {
        for(int j = m; j < n; j++)
        {
            C[i][j] = C4[i-m][j-m];
        }
    }
    return C;
}

int main()
{
    int k = 4;
    srand(time(0));
    int n = (int)pow(2, (double)k);
    int** A = (int**)malloc(n*sizeof(int *));
    for(int i = 0; i < n; i++) A[i] = (int*)malloc(n*sizeof(int));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++) 
        A[i][j] = rand()%10 + 1;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++) 
        printf("%d ", A[i][j]);
        printf("\n");
    }
    printf("\n");

    int** B = (int**)malloc(n*sizeof(int *));
    for(int i = 0; i < n; i++) B[i] = (int*)malloc(n*sizeof(int));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++) 
        B[i][j] = rand()%10 + 1;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++) 
        printf("%d ", B[i][j]);
        printf("\n");
    }
    printf("\n");

    int** C;
    C = mul(A, B, k);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++) 
        printf("%d ", C[i][j]);
        printf("\n");
    }
}