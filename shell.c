/**
 * Ferdinand Imeka & Charles Homsuk
 */
/**
 * main - Entry point, Simple command line interpreter
 * How to use: To run commands the user needs to type any command with or without
 * arguments into the prompt and press 'enter'
 * info: This program use execvp() function to execute a command, 
 * The user does not need to include any path in the command line, it print out
 * errors, checks for input 'q' and if input is empty.
 *
 * Return: Always success
 */
#include "shell.h"

/* declare getline() */
char *input = NULL;
size_t capacity;

/* Declaring strtok() */
char *arr[512];
char *tok;
int b;

/* Display an info for the user at the start */
void startDisplay(){
    printf(" __________________________________________");
    printf("|                                          |");
    printf("|  WELCOME TO F&C COMMAND LINE INTERPRETER |");
    printf("|  SIMPLY WRITE A COMMAND AND TAP 'ENTER'  |");
    printf("|  EXAMPLE : ls -a                         |");
    printf("|  TYPE 'q' TO EXIT                        |");
    printf("|__________________________________________|");
}

/* print out "F&C_shell" */
void displayPrompt(){
    printf("F&C_SHELL : ");
}

/* Divide input line into tokens */
void makeToken(char *input){
    b = 0;
    tok = strtok(input, "\n ");
    while (tok != NULL) {
    arr[b++] = tok; /* adds token into array*/
    tok = strtok(NULL, "\n");
    }
    arr[b] = NULL;
}

/* Execute commands */
void execute(){
    int pid, i, wtw;
    
    wtw = waitpid(-1, &i, arr);
    pid = fork();  /*create a process*/
    if (pid != 0)/* if not successfully completed */
    fputchar(wtw);/* wait for process termination */

    if (execvp(arr[0], arr) == -1) /* command successfully completed or return -1 when something went wrong */
    perror("Command Error"); /* error message */
    exit(errno);
}

int main(){
    capacity = 0;
    startDisplay();
    while(1)
    {
    displayPrompt(); /* Display user prompt */
    _getline(&input, &capacity, stdin); /* Read the user input */
    /* checks if the input is empty */
    if (strcmp(input, "\n") == 0)
    perror("Please input your command");
    continue;
    }
    makeToken(input); /* divide line into tokens */
    /* checks for 'q', if yes exit shell */
    if (strcmp(arr[0], "q"))
    {
    printf("System: shell has been exited");
    return (0);
    }
    execute(); /* call execvp() */
}
