#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_LEN_WORD 20

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

char set_dificulty_level()
{
    char level;

    system("cls");
    printf("Please set your level:\n");
    printf("E-Easy M-Medium H-Hard\n");
    printf("In case of incorrect input, it will be set on easy by default!\n");
    fflush(stdin);
    scanf(" %c", &level);//verificar e fazer um do while
    return level;
}

char *difficulty(char level) //fazer tudo no mesmo ficheiro e passar tudo no mesmo
{
    char file_name[20];
    char words[MAX_WORDS][MAX_LEN_WORD];
        int num_words=0;

    switch (level) 
    {
        case 'e':
        case 'E':
            strcpy(file_name, "easy.txt");
            break;
        case 'm':
        case 'M':
            strcpy(file_name, "medium.txt");
            break;
        case 'h':
        case 'H':
            strcpy(file_name, "hard.txt");
            break;
        default:
            strcpy(file_name, "easy.txt");
            break;
    }

    FILE *file;
    file=fopen(file_name, "r"); //file_name está vazio.

    if (file == NULL) 
    {
        printf("The file wasn't found!\n");
        getch();
        return NULL;
    }

    while (fgets(words[num_words], MAX_LEN_WORD, file)) 
    {
        words[num_words][strlen(words[num_words]) - 1] = '\0';
        num_words++;
    }
  
    srand(time(NULL));
    char *secret_word = strdup(words[rand() % num_words]);

    fclose(file);
    system("cls");

    return secret_word;
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

void game(char *secret_word, int max_attempts)
{
    char file_name[20];
    int attempts = 0;
    int win = 0;
    int i;

    system("cls");

    FILE *file;
    file=fopen(file_name, "r");

    printf("Welcome to Hangman Game!\n\n");

    char retry[MAX_LEN_WORD];

    strcpy(retry, "_");

    for (i = 1; i < strlen(secret_word); i++)
    {
        strcat(retry, " _");
    }
    printf("Secret Word: %s\n", retry);
    printf("The secret word has %d letters.\n", (int)strlen(secret_word));
    printf("Left retries: %d\n", max_attempts - attempts);
    printf("Try to guess the secret word based on the information provided.\n\n");

    while (attempts < max_attempts && !win)
    {
        printf("Type a letter: ");
        for (i = 0; i < strlen(retry); i++)
        {
            printf("%c", retry[i]);
        }
        printf("\n");

        char trying;
        scanf(" %c", &trying);

        int hit = 0;

        for (i = 0; i < strlen(secret_word); i++)
        {
            if (trying == secret_word[i])
            {
                retry[i] = trying;
                hit = 1;
            }
        }
        if (!hit)
        {
            printf("The letter %c isn't in the secret word!\n", trying);
            attempts++;
        }
        if (strcmp(secret_word, retry) == 0)
        {
            win = 1;
        }
        printf("Left retries: %d\n", max_attempts - attempts);
    }

    if (win)
    {
        printf("Congratulations! You hit the secret word: %s\n", secret_word);
    }
    else
    {
        printf("You lost! The secret word is: %s\n", secret_word);
    }

    free(secret_word);
    fclose(file);

    system("cls");
}

void menu_inicial()
{
    int GameLoop = 1;
    int max_attempts = 0;
    char level='e';
    unsigned int option = 6; //inicialize "option" on a number outside of the options
    printf("**************************************************************************************************\n");
    printf("*******************************************Hangman Game*******************************************\n");
    printf("**************************************************************************************************\n");
    printf("**************************** Diana Nunes - P4 ** Ricardo Marques - P4 ****************************\n\n\n");

    while (GameLoop == 1)
    {
        option=6;
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
                if(max_attempts==0)
                {
                    printf("Please set the number of retries before playing.\n");
                }
                else
                {
                    char *secret_word = difficulty(level);
                    game(secret_word, max_attempts);
                    free(secret_word);
                }
                break;
            case 2:
                max_attempts = max_retries();
                break;
            case 3:
                set_dificulty_level();
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
}

int main() 
{
    menu_inicial();
    return 0;
}


//Código exemplo que pode ser útil para projeto
/*
void gotoxy(int x, int y)
{
    COORD pos = {x, y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);

int maint(int argc, char *argv[])
{
    gotoxy(10, 10);
    printf("------");

    gotoxy(11, 10);
    printf("A");
    gotoxy(13,10);
    printf("A");

    return;
}

}

//Isto ajuda a resolver problemas que vão puder surgir na parte gráfica do projeto
*/