#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "pstat.h"

int
main(int argc, char *argv[])
{
    struct proc_stat ps;
    int id = fork();
    if (id == 0) {
        set_priority(10, 0);
        double z, d = 1, x = 0;
        for (int i = 0; i < 5; ++i) {
            getpinfo(&ps);
            printf(1, "\nPID == %d\nRun_time = %d\nNum_run = %d\ncurrent_queue=%d\n", ps.pid, ps.runtime, ps.num_run, ps.current_queue);
            for(int i=0;i<5;i++) {
                printf(1, "%d ", ps.ticks[i]);
            }
            for (int j = 0; j < 10; ++j) {
                for (z = 0; z < 8000000; z += d) {
                    x = x + 3.14 * 89.64; // useless calcs
                }
            }
        }
        printf(1, "foo 2 ended\n");
        exit();
    }
    int wtime, rtime;
    waitx(&wtime, &rtime);
    printf(1, "wait = %d run = %d\n", wtime, rtime);
    exit();
}
