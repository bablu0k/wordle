#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main () {
    int x = 1;
    char* c = (char*) &x;
    if (*c) printf("Little endian");
    else printf("Big endian");
    return 0;
}
