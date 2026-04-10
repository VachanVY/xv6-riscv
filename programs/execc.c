#include <stdio.h>
#include <unistd.h>

int main(void) {
    printf("Hello before exec\n");

    char *args[] = {"/bin/echo", "echo", "Hello World", NULL};
    execv("/bin/echo", args);

    printf("This will not print\n");
}
