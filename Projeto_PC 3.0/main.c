#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_LEN_WORD 20
#define INPUT_FILE "palavras_secretas.txt"
#define EASY_WORD_NUM_CHARS 6
#define MEDIUM_WORD_NUM_CHARS 8
#define HARD_WORD_NUM_CHARS 10

void help();
int read_int_from_stdin(int lower_bound, int upper_bound, char *input_msg);
int max_retries();
char set_dificulty_level();
void read_words_from_file(char words[MAX_WORDS][MAX_LEN_WORD], char difficulty_level);
void header();
void menu();

int main() 
{
    header();   
    menu();
}

int read_int_from_stdin(int lower_bound, int upper_bound, char *input_msg)
{
    int option;

    do
    {
        puts(input_msg);
        fflush(stdin); //clears buffer. Makes sure that if you input something outside of a number, it does not cause havoc
        scanf("%d", &option);
    } while (option < lower_bound || option > upper_bound);

    return option;
}

int max_retries()
{
    int retries;

    system("cls");
    retries = read_int_from_stdin(3, 15, "Enter the number of retries (between 3 and 15)");
    system("cls");

    return retries;
}

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
    "4th rule: Have Fun!\n");

    do 
    {
        printf("Please input only the 'x' character whenever you are ready to go back to the main menu.\n");
        fflush(stdin);
        scanf("%c", &menu_return_flag);
    } 
    while (menu_return_flag != 'x' && menu_return_flag != 'X');

    system("cls");
}

char set_dificulty_level()
{
    char level;

    system("cls");
    printf("Please set your level:\n");
    printf("E-Easy M-Medium H-Hard\n");
    printf("In case of incorrect input, it will be set on easy by default!\n");
    
    fflush(stdin);
    scanf(" %c", &level);

    level = toupper(level);

    if (level != 'E' && level != 'M' && level != 'H')
    {
        return 'E';
    }

    return level;
}

void read_words_from_file(char words[MAX_WORDS][MAX_LEN_WORD], char difficulty_level)
{
    char word[MAX_LEN_WORD];
    int num_words = 0;
    int word_len;

    switch (difficulty_level) 
    {
        case 'E':
            word_len = EASY_WORD_NUM_CHARS;
            break;
        case 'M':
            word_len = MEDIUM_WORD_NUM_CHARS;
            break;
        case 'H':
            word_len = HARD_WORD_NUM_CHARS;
            break;
        default:
            word_len = EASY_WORD_NUM_CHARS;
            break;
    }

    FILE *file;
    file=fopen(INPUT_FILE, "r");

    if (file == NULL) 
    {
        printf("The file wasn't found!\n");
        // getc();
        return;
        // exit();
    }

    while (fgets(word, MAX_LEN_WORD, file)) 
    {
        word[strcspn(word, "\r\n")] = 0;
        
        if (strlen(word) != word_len)
        {
            continue;
        }

        strcpy(words[num_words], word);
        num_words++;
    }
}

void menu()
{
    int option;
    int max_attempts = 0;
    char difficulty_level;
    char words[MAX_WORDS][MAX_LEN_WORD];

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
                // chose_word(words);
                if(max_attempts == 0)
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
                // play();
                break;
            case 2:
                max_attempts = max_retries();
                break;
            case 3:
                difficulty_level = set_dificulty_level();
                printf(">> %c\n", difficulty_level);
                read_words_from_file(words, difficulty_level);
                break;
            case 4:
                help();
                break;
        }
    } while (option != 5);
}