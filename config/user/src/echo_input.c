#include <stdio.h>

int main() {
    int c;
    while(1) {
        c = getchar();
        if(c == EOF) {
            break;
        }
        putchar(c);
    }
    return 0;
}
