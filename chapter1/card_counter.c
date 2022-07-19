//
// Created by weipeng2k on 2022/6/19.
//

#include <stdio.h>
#include <stdlib.h>

int card_value(char card_name[]) {
    int ret = 0;
    switch (card_name[0]) {
        case 'J':
        case 'Q':
        case 'K':
            ret = 10;
            break;
        case 'A':
            ret = 11;
            break;
        case 'X':
            ret = 0;
            break;
        default:
            ret = atoi(card_name);
            if (ret <= 1 || ret > 10) {
                puts("无法理解这个值");
                ret = -1;
            }
    }

    return ret;
}

int main() {
    char card_name[3];
    puts("输入牌名：");
    scanf("%2s", card_name);
    int val;;

    while ((val = card_value(card_name)) != 0) {
        printf("输入的牌点数为：%i\n", val);
        puts("输入牌名：");
        scanf("%2s", card_name);
    }

    return 0;
}
