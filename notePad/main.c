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
#define Up 72
#define Down 80
#define sz 50
#define lin 10

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
    char *pstartbuffer[lin];

    for (int i = 0; i < lin; i++) {
        pstartbuffer[i] = (char *)malloc(sz * sizeof(char));
        if (pstartbuffer[i] == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }
    }

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < sz; j++) {
            pstartbuffer[i][j] = ' ';
        }
    }

    int currstep = 0, currline = 0;
    int countChar[lin] = {0};
    char ch;

    do {
        system("cls");

        for (int i = 0; i < lin; i++) {
            for (int j = 0; j < sz; j++) {
                textattr(0x25);
                printf("%c", pstartbuffer[i][j]);
                textattr(0x07);
            }
            printf("\n");
        }

        gotoxy(currstep, currline);

        ch = getch();
        if (ch == -32) {
            ch = getch();
        }

        switch (ch) {
            case Right: {
                if (currstep < countChar[currline] && currstep < sz - 1) {
                    currstep++;
                }
                break;
            }
            case Left: {
                if (currstep > 0) {
                    currstep--;
                }
                break;
            }
            case Up: {
                if (currline > 0) {
                    currline--;
                    if (currstep > countChar[currline]) {
                        currstep = countChar[currline];
                    }
                    // else hya hya msh h7rko
                }
                break;
            }
            case Down: {
                if (currline < lin - 1) {
                    currline++;
                    if (currstep > countChar[currline]) {
                        currstep = countChar[currline];
                    }
                }
                break;
            }
            case Home: {
                currstep = 0;
                currline = 0;
                break;
            }
            case End: {
                while (currline < lin - 1 && countChar[currline + 1] > 0) {
                    currline++;
                }
                currstep = countChar[currline];
                break;
            }
            case Backspace: {
                if (currstep > 0) {
                    for (int i = currstep - 1; i < countChar[currline] - 1; i++) {
                        pstartbuffer[currline][i] = pstartbuffer[currline][i + 1];
                    }
                    pstartbuffer[currline][countChar[currline] - 1] = ' ';
                    countChar[currline]--;
                    currstep--;
                }
                break;
            }
            case Delete: {
                if (currstep < countChar[currline]) {
                    for (int i = currstep; i < countChar[currline] - 1; i++) {
                        pstartbuffer[currline][i] = pstartbuffer[currline][i + 1];
                    }
                    pstartbuffer[currline][countChar[currline] - 1] = ' ';
                    countChar[currline]--;
                }
                break;
            }
            case Enter: {
                if (currline < lin - 1) {
                    currline++;
                    currstep = 0;
                }
                break;
            }
            case Esc: {
                printf("Goodbye!\n");
                for (int i = 0; i < lin; i++) {
                    free(pstartbuffer[i]);
                }
                return 0;
            }
            default: {
                if (currstep < sz ) {
                    if (countChar[currline] < sz ) {
                        for (int i = countChar[currline]; i > currstep; i--) {
                            pstartbuffer[currline][i] = pstartbuffer[currline][i - 1];
                        }
                        pstartbuffer[currline][currstep] = ch;
                        countChar[currline]++;
                        currstep++;
                    }
                }

                break;
            }
        }

    } while (1);
    for (int i = 0; i < lin; i++) {
        free(pstartbuffer[i]);
    }
    return 0;
}
