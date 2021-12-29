
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
/*
struct sigaction {
    void (*sa_handler)(int);
    void (*sa_sigaction)(int, siginfo_t *, void *);
    sigset_t sa_mask;
    int sa_flags;
    void (*sa_restorer)(void);
}
*/


void handler(int sig)    //信号处理函数的实现
{
   printf("SIGINT sig");
}
int main()
{
    sigset_t new,old;
    struct sigaction act;
    act.sa_handler = handler;  //信号处理函数handler
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    sigaction(SIGINT, &act, 0);  //准备捕捉SIGINT信号
    sigemptyset(&new);
    sigaddset(&new, SIGINT);
    sigprocmask(SIG_BLOCK, &new, &old);  //将SIGINT信号阻塞，同时保存当前信号集
    printf("Blocked");
    sigprocmask(SIG_SETMASK, &old, NULL);  //取消阻塞
    pause();
    return 0;
}