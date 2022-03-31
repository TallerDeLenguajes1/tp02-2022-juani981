#include<time.h>
#include<stdint.h>
#define N 20
int i;
int vt[N];
int main(int argc, char const *argv[])
{
        for(i = 0;i<N; i++)
    {
    *(vt+i)=1+(rand()%100);
    printf("%d\n", *(vt+i));
    }
    return 0;
}