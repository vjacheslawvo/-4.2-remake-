#include <stdio.h>
#include <stdlib.h>


void print_received_arrays( int **A, int **B, int M, int N);
int max(int **A,int M,int N);
int transpon (int **B,int **T,int M,int N);
int product(int **A,int **B,int **Prod,int M,int N);
int sort(int **A,int M,int N);
int matrix_sum(int **A,int **B,int sum,int M,int N);


int main()
{
    int input_var;
    int action;
    int sum;
    int M=3;
    int N=4;

    printf("\n Enter the size of the matrices:");
    printf("\n\n !! Only the first value will be used to construct the square matrix !!\n");
    printf("\nNumber of lines >");
    scanf("%d", &M);
    printf("\nNumber of columns >");
    scanf("%d", &N);


    int **A = NULL;
    A=(int**) malloc(M * sizeof(int));
    for(int i=0; i<M; i++)
    {
        A[i]=(int*) malloc(M * sizeof(int));
    }

    int **B=NULL;
    B=(int**) malloc(N * sizeof(int));

    int **Prod=NULL;
    Prod=(int**) malloc(N * sizeof(int));

    int **T=NULL;
    T=(int**) malloc(M * sizeof(int));

    for(int i=0; i<N; i++)
    {
        B[i]=(int*) malloc(M * sizeof(int));
        Prod[i]=(int*) malloc(M * sizeof(int));
        T[i]=(int*) malloc(M * sizeof(int));
    }

    do
    {
        system("cls");
        printf(" Fill in the matrix: 1. Automatically 2. Personally\n>");
        scanf("%d",&input_var);
    }
    while(input_var != 1 && input_var != 2);

    if(input_var==2)
    {
        printf("Square matrix A:\n");
        for (int i=0; i<M; i++)
        {
            for (int j=0; j<M; j++)
            {
                printf("A[%d][%d]=",i,j);
                scanf("%d",&A[i][j]);
            }
        }

        printf("Rectangular matrix B:\n");
        for (int i=0; i<M; i++)
        {
            for (int j=0; j<N; j++)
            {
                printf("B[%d][%d]=",i,j);
                scanf("%d",&B[i][j]);
            }
        }
    }


    else
    {
        for (int i=0; i<M; i++)
        {
            for (int j=0; j<M; j++)
            {
                A[i][j]= rand()%101;
            }
        }
        for (int i=0; i<M; i++)
        {
            for (int j=0; j<N; j++)
            {
                B[i][j]= rand()%101;
            }
        }
    }

    print_received_arrays(A, B, M, N);


    do
    {
        printf("\nOperations on matrices:\n1. Maximum value matrix A \n2. Transpose the matrix B\n3. Multiply AxB\n4. Sort A\n5. Sum\n >");
        scanf("%d",&action);
    }
    while(action != 1 && action != 2 && action != 3 && action != 4 && action != 5);

    switch (action)
    {
    case 1:
        max(A,M,N);
        break;

    case 2:
        transpon(B,T,M,N);
        break;

    case 3:
        printf("AxB = \n");
        product(A,B,Prod,M,N);
        break;

    case 4:

        sort(A,M,N);
        break;

    case 5:
        matrix_sum(A,B,sum,M,N);
        break;
    }

    for(int i=0; i<1; i++)
    {
        free(A[i]);
    }
    free(A);
    for(int i=0; i<N; i++)
    {
        free(B[i]);
        free(Prod[i]);
        free(T[i]);
    }
    free(B);
    free(Prod);
    free(T);

    return 0;
}


//------------------------------------------------------------------------------------------


void print_received_arrays( int **A, int **B, int M, int N)
{

    for (int i=0; i<M; i++)
    {
        for (int j=0; j<M; j++)
        {
            printf("%3d ", A[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (int i=0; i<M; i++)
    {
        for (int j=0; j<N; j++)
        {
            printf("%3d ", B[i][j]);
        }
        printf("\n");
    }

}


//------------------------------------------------------------------------------------------


int max(int **A,int M,int N)
{

    int maximal= 0;
    for(int i=0; i<M; i++)
    {
        for(int j=0; j<M; j++)
        {
            if (A[i][j] > maximal)
            {
                maximal = A[i][j];
            }
        }
    }
    printf("\nMax value A: %d\n",maximal);
}


//-------------------------------------------------------------------------------------------


int transpon (int **B,int **T,int M,int N)
{
    for (int i=0; i<M; i++)
    {
        for (int j=0; j<N; j++)
        {
            T[j][i] = B[i][j];
        }
    }
    printf("\n Transpon matrix B :  \n");
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<M; j++)
        {
            printf("%3d ", T[i][j]);
        }
        printf("\n");
    }
}


//-----------------------------------------------------------------------------------------


int product(int **A,int **B,int **Prod,int M,int N)
{
    for(int i=0; i<M; i++)
    {
        for(int j=0; j<N; j++)
        {
            Prod[i][j]=0;
            for(int p=0; p<M; p++)
            {
                Prod[i][j] += A[i][p] * B[p][j];
            }
        }
    }

    for (int i=0; i<M; i++)
    {
        for (int j=0; j<N; j++)
        {
            printf("%3d ", Prod[i][j]);
        }
        printf("\n");
    }
}


//---------------------------------------------------------------------------------------


int sort(int **A,int M,int N)
{
    int sort_var;
    do
    {
        printf("\n Sort: 1. matrix 2. line of matrix\n >");
        scanf("%d", &sort_var);
    }
    while(sort_var !=1 && sort_var !=2);
    if (sort_var == 1)
    {
        int temp;
        for(int k = 0; k < M * N; ++k)
        {
            for(int i = 0; i < M; ++i)
            {
                for(int j = 0; j < N; ++j)
                {
                    if(j != N - 1)
                    {
                        if(A[i][j+1] < A[i][j])
                        {
                            int temp = A[i][j+1];
                            A[i][j+1] = A[i][j];
                            A[i][j] = temp;
                        }
                    }

                }
            }
        }

        for (int i=0; i<M; i++)
        {
            for (int j=0; j<M; j++)
            {
                printf("%3d ", A[i][j]);
            }
            printf("\n");
        }
    }
    if(sort_var == 2)
    {
        int sort = 0;
        int temp;

        printf("\nEnter the line to sort: ");
        scanf("%d",&sort);
        for(int k=1; k<M; k++)
        {
            for(int j=0; j<M-k; j++)
            {
                if(A[sort][j]>A[sort][j+1])
                {
                    temp = A[sort][j];
                    A[sort][j] = A[sort][j+1];
                    A[sort][j+1] = temp;
                }
            }
        }

        for(int j=0; j<M; j++)
        {
            printf("%3d ",A[sort][j]);
        }
    }
}


//----------------------------------------------------------------------------------------


int matrix_sum(int **A,int **B,int sum,int M,int N)
{
    for(int i=0; i<M; i++)
    {
        int sum=0;
        for(int j=0; j<N; j++)
        {
            sum = sum + A[i][j];
        }
        printf("\n Sum line:%d  A =%d",i,sum);
    }

    for(int j=0; j<N; j++)
    {
        int sum=0;
        for(int i=0; i<M; i++)
        {
            sum = sum + B[i][j];
        }
        printf("\n Sum colum:%d  B =%d",j,sum);
    }
}
