#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "pstat.h"

int
main(int argc, char *argv[])
{
    int id = fork();
    if (id == 0) {
        set_priority(20, 0);
        double z, d = 1, x = 0, ll = 1;
        for (int i = 0; i < 50; ++i) {
            sleep(10);
            for (z = 0; z < 8000000; z += d) {
                x = x + 1.14 * 69.420;
                for(int k = 0; k < 5; k++) {
                    ll = ll * (i+1) + z;
                    ll *= 5; // useless calc
                }
                ll = ll - (z+1);
            }
        }
        #ifdef MLFQ
        struct proc_stat ps;
        getpinfo(&ps);
        printf(1, "\nPID == %d\nRun_time = %d\nNum_run = %d\ncurrent_queue=%d\n", ps.pid, ps.runtime, ps.num_run, ps.current_queue);
        printf(1, "ticks : ");
        for(int i=0;i<5;i++) {
            printf(1, "%d ", ps.ticks[i]);
        }
        printf(1, "\n");
        #endif
        printf(1, "test 2 ended\n");
        exit();
    }
    int wtime, rtime;
    waitx(&wtime, &rtime);
    printf(1, "wait = %d run = %d\n", wtime, rtime);
    exit();
}
