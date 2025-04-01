#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define M 7

int main(){

    srand(time(NULL));

    int i,j;
    double mt[N][M], *p = &mt[0][0];

    for(i = 0;i<N; i++)
    {
        for(j = 0;j<M; j++)
        {
            //mt[i][j]=1+rand()%100;
           *(p + i * M + j)=1+rand()%100;
            
            printf("%lf ", *(p + i * M + j)); //investigar esta formula para poder hacer matrices
        }
    printf("\n");
    }

    return 0;
}

