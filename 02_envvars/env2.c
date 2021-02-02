// Print environment variables using environ.
//
// Compile:
//  $ gcc env2.c -o env2

#include <stdio.h>

extern char **environ;

int main(int argc, char *argv[], char* envp[]) {
    int i = 0;
    while (environ[i] != NULL) {
        printf("%s\n", environ[i]);
        i++;
    }
    return 0;
}
