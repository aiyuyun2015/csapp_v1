#include<unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

printf("Child: My processID is %d,my parent processID is %d,my process groupID is %d \n",getpid(),getppid(),getpgrp());

}