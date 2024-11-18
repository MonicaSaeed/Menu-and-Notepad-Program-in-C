#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define Enter 13
#define Esc 27
#define Home 115
#define End 116
#define Right 77
#define Left 75
#define Backspace 8
#define Delete 83
#define sz 50

void textattr(int i) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}

void gotoxy(int x, int y) {
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int main() {
    /*char ch = getch();
    if (ch == -32) {
        ch = getch();
    }
    printf("%d",ch);*/

    char *pstart, *pcurr;
    int steps = 0;

    pstart = (char *)malloc(sz * sizeof(char));
    if (pstart == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    pcurr = pstart;
    for (int i = 0; i < sz; i++) {
        *(pcurr + i) = ' ';
    }

    char ch;
    int countChar=0;
    do {
        system("cls");
        pcurr = pstart;
        for (int i = 0; i < sz; i++) {
            textattr(0x25);
            printf("%c", *(pcurr + i));
            textattr(0x07);
        }

        pcurr = pstart + steps;
        gotoxy(steps, 0);

        ch = getch();
        if (ch == -32) {
            ch = getch();
        }

        switch(ch) {
            case Right: {
                if (steps < countChar) {
                    steps++;
                    pcurr++;
                }
                break;
            }
            case Left: {
                if (steps > 0 ) {
                    steps--;
                    pcurr--;
                }
                break;
            }
            case Home:{
                steps=0;
                pcurr = pstart;
                break;
            }
            case End:{
                steps=countChar;
                pcurr = pstart + steps;
                break;
            }
            case Enter:{
                gotoxy(0,1);
                printf("You Entered the program!!! good buy");
                return 0;
            }
            case Backspace:{
                if (steps > 0) {
                    steps--;
                    pcurr--;
                    for (int i = steps; i < countChar - 1; i++) {
                        *(pstart + i) = *(pstart + i + 1);
                    }

                    *(pstart + countChar - 1) = ' ';
                    countChar--;
                }
                break;
            }
            case Delete:{
                if (steps<countChar){
                    for (int i = steps; i < countChar - 1; i++) {
                        *(pstart + i) = *(pstart + i + 1);
                    }

                    *(pstart + countChar - 1) = ' ';
                    countChar--;
                }
                break;
            }
            case Esc:
                return 0;
            default:{
                if(steps >= 0 && steps < sz){
                    if(*pcurr!=' ' ){
                        if(countChar>=sz){
                            continue;
                        }
                        for (int i = countChar; i > steps ; i--) {
                            *(pstart + i) = *(pstart + i - 1);
                        }
                        countChar++;
                    }
                    *pcurr = ch;
                    if(steps==countChar)
                        countChar++;
                    steps++;
                    pcurr++;
                }
                break;
            }
        }
    } while (1);
    free(pstart);
    return 0;
}
