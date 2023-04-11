#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(void)
{
    int pid = getpid();
    int a = -100000;

    // take a time 
    for(int i = 0 ; i<200000000 ; i++)
    {
        for(int j = 0 ; j<10; j++){
            a++;
        }   
        a = -100000;
    }

    int ticks = getProcTick(pid);
    printf("ticks: %d\n",ticks);
    exit(0);
}