#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
    int c1 = fork();
    char *loli[] = {"test", 0};
    if(c1 == 0) {
    	exec(loli[0], loli);
    	exit();
    }
    // sleep(100);
    char *loli1[] = {"test1", 0};
    int c2 = fork();
    if(c2 == 0) {
    	exec(loli1[0], loli1);
    	exit();
    }
    // sleep(100);
    char *loli2[] = {"test2", 0};
    int c3 = fork();
    if(c3 == 0) {
    	exec(loli2[0], loli2);
    	exit();
    }
    wait();
    wait();
    wait();
    exit();
}