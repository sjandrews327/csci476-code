// Compile:
//  $ gcc myenv2.c -o myenv2

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("/usr/bin/env");
    return 0;
}
