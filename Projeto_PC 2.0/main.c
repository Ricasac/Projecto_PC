#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void header()
{
    printf("**************************************************************************************************\n");
    printf("*******************************************Hangman Game*******************************************\n");
    printf("**************************************************************************************************\n");
    printf("**************************** Diana Nunes - P4 ** Ricardo Marques - P4 ****************************\n\n\n");
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
    "4th rule: Have Fun!\n\n\n");
    printf("Press x whenever your ready to return to the main menu.\n\n\n");
    do 
    {
        fflush(stdin);
        scanf("%c", &menu_return_flag);
        printf("Please input only the 'x' character whenever you are ready to go back to the main menu.\n");
    } 
    while (menu_return_flag != 'x' && menu_return_flag != 'X');

    system("cls");

}

int max_retries()
{
    system("cls");
    int retries;
    do
    {
        printf("Enter the number of retries (between 3 and 15):\n");
        scanf("%d", &retries);
    }while (retries < 3 || retries > 15);
    system("cls");

    return retries;
}

int main() 
{
    int GameLoop = 1;
    int max_attempts = 0;
    char level='e';
    unsigned int option = 6; //inicialize "option" on a number outside of the options
    header();
    
    do
    {
        printf("***********************************************Menu***********************************************\n");
        printf("1 - Play\n");
        printf("2 - Set Number of retries\n");
        printf("3 - Set difficulty level\n");
        printf("4 - Help\n");
        printf("5 - Exit\n");
        printf("Please input the appropriate number to advance\n");
        while(1)
        {
            fflush(stdin); //clears buffer. Makes sure that if you input something outside of a number, it does not cause havoc
            scanf("%u", &option);
            if(option < 1 || option > 5)
            {
                printf("Your input is invalid, please try again\n");
            }
            break;
        }
        
        switch (option)
        {
            case 1:
                if(max_attempts==0)
                {
                    printf("Please set the number of retries before playing.\n");
                }
                else
                {
                    /*
                    char *secret_word = difficulty(level);
                    game(secret_word, max_attempts);
                    free(secret_word);
                    */
                }
                break;
            case 2:
                max_attempts = max_retries();
                break;
            case 3:
                //set_dificulty_level();
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
    } while (GameLoop = 1);
    
}