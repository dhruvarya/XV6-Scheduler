#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
    int id = fork();
    if (id == 0) {
        set_priority(0, 0);
        double z, d = 1, x = 0;
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 10; ++j) {
                for (z = 0; z < 80000; z += d) {
                    x = x + 3.14 * 89.64; // useless calcs
                }
            }
        }
        printf(1, "foo 1 ended\n");
        exit();
    }
    int wtime, rtime;
    waitx(&wtime, &rtime);
    printf(1, "wait = %d run = %d\n", wtime, rtime);
    exit();
}