/***********************************************************************
name: 	
	Spencer Ross
	Sarah Mathes
	Jakob Miner
	
Project 2 -- Egg Shell -- esh

description:	
	CS 460 ////Description HERE////

Objectives:	
	•	Your EggShell executable should be called esh.

	•	esh should run an infinite loop that provides the user with a 
		prompt. At this prompt, the user should be able to enter a 
		command which your shell should endeavor to execute.

	•	The first task will be reading in the command, and since some 
		commands may contain arguments you will have to read in the 
		entire line. For this, I would recommend looking into [GNU Read-
		line library]. 

	•	After the input is read in, the shell will need to verify that 
		the command entered is indeed a legal command. All commands must 
		be found on the path specified by the environment variable, PATH. 

	•	The PATH consists of a series of paths delimited by the ‘:’ 
		character. To show the value of PATH, type echo $PATH on the linux 
		command line.

	•	To access the directories included on the PATH, you might want to 
		investigate the functions getenv() and strtok(). If esh cannot find 
		the command on the PATH, then it should check the current directory 
		‘.’. If the command is still not found, then it should print an error 
		message and present a new prompt, i.e., esh should not crash.

	•	If the command is found, esh should execute it using fork() and 
		execv(). Commands may have up to five optional arguments which are 
		delimited by white space. 

	•	If the last argument in a command is an & character, it indicates 
		that the command is to be run in the background. In other words, when 
		the shell spawns a child process, it should not wait for the child to 
		terminate before prompting the user for the next command.

	•	If the user types exit then esh should terminate.

	•	You can omit handling the cd command.

***********************************************************************/

/* Includes and definitions */
#include <unistd.h>
// #include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
/**********************************************************************
./esh <arg1> &

    maybe put some usage here??
**********************************************************************/

int main(int argc, char const *argv[]) {
	char* pathEnviron = getenv("PATH");
	char** paths = (char **)malloc(128*sizeof(char*));
	char* input;
	int numArgs = 0;
	char *token;
	char** args = NULL;
	int numPaths = 0; // number of directories on PATH

	// Seperate each directory on PATH by ":"
	token = strtok(pathEnviron,":");
	while ( token != NULL ){ 
		printf("%s\n",token);
		paths[numPaths] = (char *)malloc(strlen(token)*sizeof(char *));
		strcpy(paths[numPaths],token);
		numPaths++;
		token = strtok(NULL,":");
	}
	numPaths--;	
	
	// Print statement to confirm paths in path[]
	int j=0;
	while ( j <= numPaths){
		printf("FILE PATH:\n %s\n", paths[j]);
		j++;
	}

	while (1){
		numArgs = 0;
		input = readline("esh>");
		token = strtok(input, " ");
		while ( token != NULL ){
			args = (char **)realloc(args, sizeof(char **)*(numArgs+1));
			args[numArgs] = (char *)malloc(sizeof(char *)*strlen(token));
			strcpy(args[numArgs],token);
			numArgs = numArgs + 1;
			token = strtok(NULL, " ");
		}

		// Demonstrating the argument number and each token. args[0] should be the command.
		printf("number of arguments: %i\n", numArgs);
		int i =0;
		while (i < numArgs ){
			printf("LINE: %s\n", args[i]);
			i++;
		}	
	}
	
	
	return 0;
}


