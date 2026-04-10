#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/* Now it should be clear why it is helpful that fork and exec are separate calls:
between the two, the shell has a chance to redirect the child’s I/O without 
disturbing the I/O setup of the main shell. */
int main(void) {
    int pid = fork();
    if (pid == 0) {
        // Child process
        int fd = open("out.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        // Redirect stdout to file
        dup2(fd, 1);
        close(fd);
        // Replace process with "ls"
        execlp("ls", "ls", NULL);
    } else {
        // Parent process
        wait(NULL);
        printf("Done\n");
    }
    return 0;
}
