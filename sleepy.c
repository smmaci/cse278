/*Samuel Mallamaci
*CSE278 Dr. Alomari
*Homework 1
*February 11, 2016
*/

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(int argc, char *argv[]){
  int i;
  if (argc == 1){
	for(i = 1; i <= 20; i++){
		printf("default pid: %d, tick %d\n", getpid(), i);
		sleep(1);
	}
  } else {
  	for(i = 1; i <= atoi(argv[1]); i++){
    		printf("passed pid: %d, tick %d\n", getpid(), i);
    		sleep(1);
  	}
  }
  return 0;
}
