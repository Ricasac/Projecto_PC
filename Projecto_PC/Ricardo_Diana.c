#include <stdio.h>
#include <stdlib.h>

void menu_inicial()
{
    unsigned int option = 6; //inicialize "option" on a number outside of the options
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
    while(option < 1 || option > 5)
    {
        fflush(stdin); //clears buffer. Makes sure that if you input something outside of a number, it does not cause havoc
        scanf("%u", &option);
        if(option < 1 || option > 5)
        {
            printf("Your input is invalid, please try again\n");
        }
    }
    printf("The number you selected is %u!\n", option);
}



int main() 
{
    menu_inicial();
    //aplly switch cases
    return 0;
}