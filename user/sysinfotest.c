#include "kernel/types.h"
#include "user/user.h"

struct sysinfo {
  long uptime;
  unsigned long totalram;
  unsigned long freeram;
  unsigned short procs;
};

int main(void){
    struct sysinfo sysi;
    int ret = sysinfo(&sysi);
    printf("uptime: %d \n", sysi.uptime);
    // printf("totalram: %d \n", sysi.freeram);
    // printf("freeram: %d \n", sysi.freeram);
    // printf("procs: %d \n", sysi.procs);
    return ret;
}