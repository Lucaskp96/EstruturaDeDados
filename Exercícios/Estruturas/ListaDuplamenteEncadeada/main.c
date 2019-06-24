#include <stdio.h>
#include <stdlib.h>
int main(){
    char* name = malloc(15*sizeof(char));
    scanf("%s", name);
    printf("%s", name);

    return 0;
}
