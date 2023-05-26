#include "kernel/types.h"
#include "user/user.h"

int main(void){
    struct proctime proctwait;
    int p = fork();
    if(p != 0){
        int exitp;
        twait(&exitp,&proctwait);
        printf("cpuburst_time:   %d Sec\n",proctwait.cpuburst_time);
        printf("turnaround_time: %d Sec\n", proctwait.turnaround_time);
        printf("waiting_time:  %d Sec\n",proctwait.waiting_time);

    }
    else {
        int y = 0;
        for(int i = 0 ; i < 10000000 ; i++){
            for(int j = 0 ; j < 500 ; j++){
                y++;
            }
        }
        sleep(50);
    }

    return 0;
}