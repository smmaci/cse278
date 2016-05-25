#include <sys/types.h>
#include <stdio.h>
int a = 6;
int main(void){
  int b;
  pid_t pid;
  b = 88;
  printf("before fork\n");
  
  pid = fork();
  if(pid == 0){
    a++;b++;
  }else
    wait(pid);
  printf("pid = %d\n", pid);
  printf("after fork, a = %d, b = %d\n", a, b);
}
