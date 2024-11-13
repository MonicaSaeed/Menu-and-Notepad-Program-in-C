#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define Enter 13
#define Esc 27
#define Home 115
#define End 116
#define Up 72
#define Down 80
#define Tab 9

void textattr(int i)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),i);
}
int main()
{
    char menu[3][10] = {"New", "Display", "Exit"};
    int highlight = 0;
    char ch;


    do{
        system("cls");
        printf("    Menu \n");
        printf("----------- \n");
        for(int i = 0; i < 3; i++) {
            if(i==highlight){
                textattr(0x25);
                printf("%s \n", menu[i]);
                textattr(0x07);
            }else{
                printf("%s \n", menu[i]);
            }
        }
        ch = getch();
        if(ch == -32){
            ch = getch();
        }
        switch(ch) {
            case Up:{

                if(highlight==2){
                    highlight = 1 ;
                }else if(highlight==1){
                    highlight = 0 ;
                }
                break;
            }
            case Down:{
                if(highlight==0){
                    highlight = 1 ;
                }else if(highlight==1){
                    highlight = 2;
                }
                break;
            }
            case Home:{
                highlight = 0;
                break;
            }
            case End:{
                highlight = 2;
                break;
            }
            case Enter:{
                if(highlight==0){
                    system("cls");
                    printf("welcome to new home :)\n");
                    printf("click enter to back menu");
                    char ch;
                    ch = getch();
                    if(ch == Enter){
                        highlight = 0;
                    }
                }else if (highlight==1){
                    system("cls");
                    printf("welcome to display :)\n");
                    printf("click enter to back menu");
                    char ch;
                    ch = getch();
                    if(ch == Enter){
                        highlight = 0;
                    }
                }else{
                    system("cls");
                    printf("good bye :)");
                    return 0;
                }
                break;
            }
            case Esc:
                return 0;
        }
    }while(1);


    return 0;
}
