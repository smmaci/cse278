/*
About this program:
- This program counts words.
- The specific words that will be counted are passed in as command-line arguments.
- The program reads words (one word per line) from standard input until EOF or
  an input line starting with a dot '.'
- The program prints out a summary of the number of times each word has appeared.
- Various command-line options alter the behavior of the program.

E.g., count the number of times 'cat', 'nap' or 'dog' appears.
> ./main cat nap dog
Given input:
 cat
 .
Expected output:
 Looking for 3 words
 Result:
 cat:1
 nap:0
 dog:0
 
 Note: this code was automatically formatted (styled) using 'indent main.c -kr'.
 
 This assignment was adapted from operating system programming problems by
 Lawrence Angrave at the University of Illinois at Champaign-Urbana (UIUC).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "smp0_tests.h"

#define LENGTH(s) (sizeof(s) / sizeof(*s))

/* Structures */
typedef struct {
  char *word;
  int counter;
} WordCountEntry;

/*The optional user specified output file*/
char *user_file_name  = (char*)malloc(20);
FILE *user_file;



int process_stream(WordCountEntry entries[], int entry_count)
{
  short line_count = 0;
  char buffer[30];

  while (fgets(buffer, 30, stdin)) {
    if (*buffer == '.')
      break;
    /* Compare against each entry */
    int i = 0;
    while (i < entry_count) {
      if (!strcmp(entries[i].word, buffer))
        entries[i].counter++;
      i++;
    }
    line_count++;
  }
  return line_count;
}


void print_result(WordCountEntry entries[], int entry_count)
{
  int i = 1;
  printf("Result:\n");
  while (i < entry_count) {
    if(*user_file_name == NULL){
      printf("%s:%d\n", entries[i].word, entries[i].counter);
    }else {
      user_file = fopen(user_file_name, "w");
      fprintf(user_file, "%s:%d\n", entries[i].word, entries[i].counter);
    }
    i++;
  }
  fclose(user_file);
}


void printHelp(const char *name)
{
  fprintf(stderr, "usage: %s [-h] <word1> ... <wordN>\n", name);
}


int main(int argc, char **argv)
{
  const char *prog_name = *argv;
  char *user_file = (char*)malloc(20);
  WordCountEntry *entries = malloc(20*sizeof(WordCountEntry));
  int entryCount = 0;
  int flagCount = 0;
  /* Entry point for the testrunner program */
  if (argc > 1 && !strcmp(argv[1], "-test")) {
    run_smp0_tests(argc - 1, argv + 1);
    return EXIT_SUCCESS;
  }

  while (*argv != NULL) {
    if (**argv == '-') {

      switch ((*argv)[1]) {
        case 'h':
          printHelp(prog_name);
	  break;
        case 'f':
          strcpy(user_file_name, (*argv + 2));
          printf("Setting output file name to %s.\n", user_file_name);
          
          break;
        default:
          fprintf(stderr, "%s: Invalid option %s. Use -h for help.\n",
                 prog_name, *argv);
		 break;
      }
      flagCount++;/*this keeps track of how many flags have been called in the commandline*/
    } else {
      if (entryCount < LENGTH(entries)) {
        entries[entryCount].word = *argv;
        entries[entryCount++].counter = 0;
      }
    }
    argv++;   
  }
  if ((argc - flagCount) == 1) {
    fprintf(stderr, "%s: Please supply at least one word. Use -h for help.\n",
           prog_name);
    return EXIT_FAILURE;
  }
  if ((argc - flagCount) == 2) {
    printf("Looking for a single word\n");
  } else {
    printf("Looking for %d words\n", ((argc - 1) - flagCount));
  }

  process_stream(entries, entryCount);
  print_result(entries, entryCount);

  return EXIT_SUCCESS;
}
