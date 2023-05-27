#include "kernel/types.h"
#include "user/user.h"



int main(void){
   
    
    changesched(ALG_FCFS);
    int p;
    struct proctime proctwait[32];
    for (int i = 0; i < 32; i++)
    {
        p = fork();
        if (p==0)
        {
            long A[100000000];
            long B[100000000];
            for (int i = 0; i < 100000000; i++)
             {
                A[i]=2;
            }
            for (int i = 0; i < 100000000; i++)
             {
                B[i]=1;
            }
            long y = 0;
            for(int i = 0 ; i < 100000000 ; i++){
               y +=A[i]+B[i]; 
            }
             sleep(50);
            break;
        }
        
    }
    if(p != 0){
        long cpuburst_time=0;
        long turnaround_time=0;
        long waiting_time=0;
        int exitp;
        for (int i = 0; i < 32; i++)
        {
            twait(&exitp,&proctwait[i]);
            cpuburst_time += proctwait[i].cpuburst_time;
            turnaround_time +=proctwait[i].turnaround_time;
            waiting_time += proctwait[i].waiting_time;
        }
    
        printf("ALG_FCFS cpuburst_time:   %d Sec\n",cpuburst_time/32);
        printf("ALG_FCFS turnaround_time: %d Sec\n", (long)turnaround_time/32);
        printf("ALG_FCFS waiting_time:  %d Sec\n",(long)waiting_time/32);

    }

    if(p==0){
        return 0;
    }
    int p1;
    changesched(ALG_RR);
    struct proctime proctwait2[32];
    for (int i = 0; i < 32; i++)
    {
        p1 = fork();
        if (p1==0)
        {
            long A[100000000];
            long B[100000000];
            for (int i = 0; i < 100000000; i++)
             {
                A[i]=2;
            }
            for (int i = 0; i < 100000000; i++)
             {
                B[i]=1;
            }
            long y = 0;
            for(int i = 0 ; i < 100000000 ; i++){
               y +=A[i]+B[i]; 
            }
             sleep(50);
            break;
        }
        
    }
    
    if(p1 != 0){
        long cpuburst_time2=0;
        long turnaround_time2=0;
        long waiting_time2=0;
        int exitp;
        for (int i = 0; i < 32; i++)
        {
        twait(&exitp,&proctwait2[i]);
        cpuburst_time2 += proctwait2[i].cpuburst_time;
        turnaround_time2 +=proctwait2[i].turnaround_time;
        waiting_time2 += proctwait2[i].waiting_time;
        }
        printf("\n");
        printf("ALG_RR cpuburst_time:   %d Sec\n",cpuburst_time2/32);
        printf("ALG_RR turnaround_time: %d Sec\n", turnaround_time2/32);
        printf("ALG_RR waiting_time:  %d Sec\n",waiting_time2/32);

    }

    return 0;
}