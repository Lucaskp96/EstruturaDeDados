#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    int* op = malloc(sizeof(int));

    printf("\t\t\tHello world!\n");
    printf("This is my Agenda! Choose an option below:\n");
    printf("\t0. Person insertion\n");
    printf("\t1. Person delete from the top\n");
    printf("\t2. Person delete by name\n");
    printf("\t3. Clear Agenda\n");
    printf("\t4. List Agenda\n");
    printf("\t5. Quit\n: ");

    scanf("%d", op);
    switch(*op){
        case 0:
                break;
        case 1:
                break;
        case 2:
                break;
        case 3:
                break;
        case 4:
                break;
        case 5:
                break;
        default:    break;
    }

    return 0;
}
