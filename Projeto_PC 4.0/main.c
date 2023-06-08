#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h> // its necessary to use the sleep function (causes a delay of x seconds)
#include "palavras_secretas.h" //library with all the words needed for the game

#define MAX_WORDS 100
#define MAX_LEN_WORD 20

char palavra[MAX_LEN_WORD]; //variavel global??? xD

//Base functions
void header();
void menu();
void play( int max_attempts);
int max_retries();
char set_dificulty_level();
void help();

//Aux Functions
int read_int_from_stdin(int lower_bound, int upper_bound, char *input_msg);
void pick_word(char difficulty_level);

int main() 
{
    header();   
    menu();
}

void play(int max_attempts)
{
    fflush(stdin);
    int attempts = 0;
    int win = 0;
    int i;
    
    system("cls");
    printf("Welcome to Hangman Game!\n\n");
    printf("Guess the word by entering one letter at a time.\n");

    char retry[MAX_LEN_WORD];

    strcpy(retry, "_");

    for (i = 1; i < strlen(palavra); i++)
    {
        strcat(retry, "_");
    }

    printf("The secret word has %d letters.\n", (int)strlen(palavra));
    printf("Left retries: %d\n", max_attempts - attempts);
    printf("Only the first letter will be considered!\n");
    printf("Try to guess the secret word based on the information provided.\n\n");


    while (attempts < max_attempts && !win)
    {
        printf("WORD: ");
        for (i = 0; i < strlen(retry); i++)
        {
            printf("%c", retry[i]);
        }
        printf("\n\nType a letter: ");

        sleep(1);

        char trying;
        scanf("%c", &trying);
        trying = toupper(trying);
        fflush(stdin);

        int hit = 0;

        for (i = 0; i < strlen(palavra); i++)
        {
            if (trying == palavra[i])
            {
                retry[i] = trying;
                hit = 1;
            }

        }
        
        if (!hit)
        {
            printf("\nThe letter %c isn't in the secret word!\n", trying);
            attempts++;
        }
        else  printf("\nThe letter %c is in the secret word!\n", trying);

        if (strcmp(palavra, retry) == 0)
        {
            win = 1;
        }
        printf("Left retries: %d\n\n", max_attempts - attempts);
    }

    if (win)
    {
        printf("Congratulations! You hit the secret word: %s\n", palavra);
        
        FILE *scoreboard;
        scoreboard = fopen("jogoAdivinha.txt" , "a"); //Opens the file, creates one if not existent
        
        if(scoreboard == NULL)
        {
            printf("Error oppening the file");   //Error message in case of the incapability of opening file
            return;            
        }

        fprintf(scoreboard,"Congratulations, you won! The word was %s\n", palavra); //Prints information inside file
        fclose(scoreboard);
    
    }
    
    else
    {
        printf("You lost! The secret word is: %s\n", palavra);
    }

    sleep(3);
    system("cls");

}

int read_int_from_stdin(int lower_bound, int upper_bound, char *input_msg) //general funtion to read an integer from standard input
{
    int option;

    do
    {
        puts(input_msg);
        fflush(stdin); //clears buffer. Makes sure that if you input something outside of a number, it does not cause havoc
        printf("Option: ");
        scanf("%d", &option);
    } while (option < lower_bound || option > upper_bound);

    return option;
}

int max_retries() //sets number of retries
{
    int retries;
    system("cls");
    retries = read_int_from_stdin(3, 15, "Enter a number of retries between 3 and 15 (the default is 5).");
    system("cls");

    return retries;
}

void header() //prints the header of the hangman game
{
    printf("**************************************************************************************************\n");
    printf("*******************************************Hangman Game*******************************************\n");
    printf("**************************************************************************************************\n");
    printf("**************************** Diana Nunes - P4 ** Ricardo Marques - P4 ****************************\n\n\n");
}

void help() //prints the help option in the menu
{
    char menu_return_flag;
    system("cls");

    printf("\nGame rules:\n\n"
    "1st rule: Choose the number of retries you want to start playing (you can choose between 3 and 15 retries).\nThe default number is 5.\n\n"
    "2nd rule: Choose the difficulty level:\n\n"
    "E to set easy level (for 6 letter words)\nM to define medium level (for 8 letter words)\nH to define difficult level (for 10 letter words)\nThe default dificulty level is easy.\n\n"
    "3rd rule: The lines corresponding to the secret word will be displayed and the user must enter letters, when a letter\nbelongs to the word it will appear in the correct place,"
    "if it does not belong to the word it will be indicated\nthat the letter is not available.\n\n"
    "4th rule: Have Fun!\n");

    printf("Please input any character whenever you are ready to go back to the main menu.\n");
    fflush(stdin);
    getchar();

    system("cls");
}

char set_dificulty_level() //returns the dificulty level of the game
{
    char level;

    system("cls");
    printf("Please set your level:\n");
    printf("E-Easy\nM-Medium\nH-Hard\n");
    printf("In case of incorrect input, it will be set on easy by default!\n");
    
    fflush(stdin);
    scanf(" %c", &level);

    level = toupper(level);

    if (level != 'E' && level != 'M' && level != 'H')
    {
        system("cls");
        return 'E';
    }

    system("cls");
    return level;
}

void pick_word (char difficulty_level)
{
    srand(time(NULL));
    char word[MAX_LEN_WORD];
    int word_len;
    int num_word;
    int random;

    switch (difficulty_level) 
    {
        case 'E':
            num_word = sizeof(simple_words)/sizeof(simple_words[0]);
            random = rand() % num_word; 
            strcpy(palavra,simple_words[random]);
            break;
        case 'M':
            num_word = sizeof(medium_words)/sizeof(medium_words[0]);
            random = rand() % num_word; 
            strcpy(palavra,medium_words[random]);
            break;
        case 'H':
            num_word = sizeof(hard_words)/sizeof(hard_words[0]);
            random = rand() % num_word; 
            strcpy(palavra,hard_words[random]);
            break;
    }

    printf("%s", palavra); 
}

void menu()
{
    int option;
    int max_attempts = 5;
    char difficulty_level = 'E';


    do
    {
        printf("***********************************************Menu***********************************************\n");
        printf("1 - Play\n");
        printf("2 - Set Number of retries\n");
        printf("3 - Set difficulty level\n");
        printf("4 - Help\n");
        printf("5 - Exit\n");

        option = read_int_from_stdin(1, 5, "Please input the appropriate number to advance");
        
        switch (option)
        {
            case 1:
                pick_word(difficulty_level);
                play(max_attempts);
                break;
            case 2:
                max_attempts = max_retries();
                break;
            case 3:
                difficulty_level = set_dificulty_level();
                break;
            case 4:
                help();
                break;
        }
    } while (option != 5);
}