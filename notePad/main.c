#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define Enter 13
#define Esc 27
#define Home 115
#define End 116
#define Right 77
#define Left 75
#define Up 72
#define Down 80
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

        switch (ch) {
            case Right: {
                if (steps < sz) {
                    steps++;
                    pcurr++;
                }
                break;
            }
            case Left: {
                if (steps > 0) {
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
                steps=sz;
                pcurr = pstart + steps;
                break;
            }
            case Enter:{
                gotoxy(0,1);
                printf("You Entered the program!!! good buy");
                return 0;
            }
            case Esc:
                return 0;
            default: {
                if(steps >= 0 && steps < sz){
                    if(*pcurr!=' '){
                        for (int i = sz - 1; i > steps; i--) {
                            *(pstart + i) = *(pstart + i - 1);
                        }
                    }
                    *pcurr = ch;
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
