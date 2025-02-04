#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
    int c1 = fork();
    char *file[] = {"test1", 0};
    if(c1 == 0) {
    	printf(1, "starting test1\n");
    	exec(file[0], file);
    	exit();
    }
    // sleep(100);
    char *file1[] = {"test2", 0};
    int c2 = fork();
    if(c2 == 0) {
    	printf(1, "starting test2\n");
    	exec(file1[0], file1);
    	exit();
    }
    // sleep(100);
    char *file2[] = {"test3", 0};
    int c3 = fork();
    if(c3 == 0) {
    	printf(1, "starting test3\n");
    	exec(file2[0], file2);
    	exit();
    }
    wait();
    wait();
    wait();
    exit();
}
