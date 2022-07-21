// 乘法器
// Created by weipeng2k on 2022/7/21.
//

#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int score = 0;

void end_game(int sig) {
    printf("\nFinal Score is %i\n", score);
    exit(0);
}

int catch_signal(int sig, void (*handler)(int)) {
    struct sigaction action;
    // 这是一个宏
    action.sa_handler = handler;
    // 也是一个宏
    sigemptyset(&(action.sa_mask));
    action.sa_flags = 0;
    return sigaction(sig, &action, NULL);
}

void times_up(int sig) {
    puts("TIME'S UP!");
    raise(SIGINT);
}

void error(char *msg) {
    fprintf(stderr, "%s, %s\n", msg, strerror(errno));
}

int main(void) {
    catch_signal(SIGALRM, times_up);
    catch_signal(SIGINT, end_game);
    srandom(time(0));

    while (1) {
        int a = random() % 11;
        int b = random() % 11;
        char txt[4];
        alarm(5);

        printf("\nwhat is %i times %i?", a, b);
        fgets(txt, 4, stdin);
        int answer = atoi(txt);
        if (answer == a * b) {
            score++;
        } else {
            printf("\nwrong!score is %i\n", score);
        }
    }

    return 0;
}