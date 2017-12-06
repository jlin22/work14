#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>
void create(int key,int value);

  
int main(int arg, char *argv[]){
  int key = 100;
  if (strcmp(argv[1], "-c")==0){
    create(key,5);
  }
  if (strcmp(argv[1], "-v")==0){
  }
  if (strcmp(argv[1], "-r")==0){
  }
  return 0;
}
void create(int key, int value){
  if (0){//semaphore exists
    printf("semaphore already exists\n");
  }
  else{
    int x = semget(key, 1, IPC_CREAT | 0660);
    printf("semaphore created : %d\n", x);
  }
}
