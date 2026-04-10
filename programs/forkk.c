#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    // create a child process using fork()

    // processes: parent
    pid_t pid = fork();
    // processes: parent and child1
    
    /* pid_t pid2 = fork();
    // processes: parent, child2, child1, grandchild */

    // parent process
    if (pid > 0) {
        printf("parent: %d\n", pid);
        // wait for the child process to finish and get its PID after it exits/dies
        int status; // exit status of the child process
        int child_pid = wait(&status);
        printf("child %d is done with status %d\n", child_pid, WEXITSTATUS(status));
    } 
    // child process
    else if (pid == 0) {
        printf("child: exiting %d\n", getpid());
        exit(0);
    } else {
        printf("fork failed\n");
        return 1;
    }
    return 0;
}
