#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>

int main() {
    pid_t pid1,pid2,pid3;
    pid1 = fork();
    if(pid1 == 0){
        printf("Child: My processID is %d,my parent processID is %d,my process groupID is %d \n",getpid(),getppid(),getpgrp());
        setpgid(0,0);
        printf("after set\n");
        printf("Child: My processID is %d,my parent processID is %d,my process groupID is %d \n",getpid(),getppid(),getpgrp());

        //child 1
    }
    else{
     printf("Parent: My processID is %d,my process groupID is %d \n",getpid(),getpgrp());


    }


    return 0;
}