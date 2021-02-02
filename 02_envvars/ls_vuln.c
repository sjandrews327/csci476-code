// Compile:
//  $ gcc ls_vuln.c -o ls_vuln

#include <stdlib.h>

int main()
{
    system("ls");
}
