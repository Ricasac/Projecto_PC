#include <stdio.h>
#include <stdlib.h>

void menu_inicial()
{
    unsigned int option;
    printf("**************************************************************************************************\n");
    printf("*******************************************Hangman Game*******************************************\n");
    printf("**************************************************************************************************\n");
    printf("**************************** Diana Nunes - P4 ** Ricardo Marques - P4 ****************************\n\n\n\n");
    
    printf("***********************************************Menu***********************************************\n");
    printf("1 - Play\n");
    printf("2 - Set Number of retries\n");
    printf("3 - Set difficulty level\n");
    printf("4 - Help\n");
    printf("5 - Exit\n");

    printf("Please input the appropriate number to advance\n");
    scanf("%u", &option);
    printf("The number you selected is %u!\n", option);
}

int main() 
{
    menu_inicial();
    //aplly switch cases
    return 0;
}