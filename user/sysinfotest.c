#include "kernel/types.h"
#include "user/user.h"


int main(void){
    struct sysinfo sysi;
    int ret = sysinfo(&sysi);

    printf("uptime:   %d Sec\n", sysi.uptime);
    printf("totalram: %d KB\n", sysi.totalram / 1000);
    printf("freeram:  %d KB\n", sysi.freeram / 1000);
    printf("procs:    %d \n", sysi.procs);

    return ret;
}
