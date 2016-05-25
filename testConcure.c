#include <stdio.h>
#include <sys/types.h>
int main(){
  pid_t pid;
  int i;
  pid = fork();
  for(i = 0; i < 2; i++){
  //  pid = fork(); 
    printf("i: %d pid: %d\n", i,  pid);
  }
}
