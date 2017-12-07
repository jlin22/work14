#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>
#define KEY 99999
int main(int argc, char ** argv){
  if (strcmp(argv[1],"-c")==0){
    int sid = semget(KEY,1,IPC_CREAT | IPC_EXCL | 0660);
    if (sid == -1){
      printf("semaphore already exists\n");
    }
    else{
      int x;
      sscanf(argv[2],"%d",&x);
      semctl(sid,0,SETVAL,x);
      printf("semaphore created : %d\n", KEY);
      printf("value set : %d\n",x);
    }  
  }
  if (strcmp(argv[1],"-v")==0){
    int sid = semget(KEY,0,0);
    int x = semctl(sid,0, GETVAL);
    printf("semaphore value : %d\n",x);
  }
  if (strcmp(argv[1],"-r")==0){
    int sid = semget(KEY,0,0);
    int x = semctl(sid,0,IPC_RMID);
    printf("semaphore removed : %d\n", x);
  }
  return 0;
}
  
