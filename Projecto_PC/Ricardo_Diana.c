#include <stdio.h>
#include <stdlib.h>

void set_dificulty_level()
{
    //codezzzzzzzzzzzzzzzzzzz
}

void help()
{
    char menu_return_flag;
    system("cls");
    printf("\nGame rules:\n\n"
    "1st rule: Choose the number of retries you want to start playing (you can choose between 3 and 15 retries)\n\n"
    "2nd rule: Choose the difficulty level:\n\n"
    "E to set easy level (for 6 letter words)\nM to define medium level (for 8 letter words)\nH to define difficult level (for 10 letter words)\n\n"
    "3rd rule: The lines corresponding to the secret word will be displayed and the user must enter letters, when a letter\nbelongs to the word it will appear in the correct place,"
    "if it does not belong to the word it will be indicated\nthat the letter is not available.\n\n"
    "4th rule: Good Luck!\n"
    "**************************************************************************************************\n\n\n");
    printf("Press x whenever your ready to return to the main menu.\n\n\n");
    do 
    {
        fflush(stdin);
        scanf("%c", &menu_return_flag);
        printf("Please input only the 'x' character whenever you are ready to go back to the main menu.\n");
    } 
    while (menu_return_flag != 'x' && menu_return_flag != 'X');

    system("cls");
    return menu_inicial();
}

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

    switch (option)
    {
        case 1:
            /* code */
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 4:
            help();
            break;
        case 5:
            exit(0);
            break;

        default:
            break;
    }

}

int main() 
{
    menu_inicial();
    return 0;
}