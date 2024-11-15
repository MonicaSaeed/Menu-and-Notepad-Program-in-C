#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define sz 20

#define Enter 13
#define Esc 27
#define Home 115
#define End 116
#define Up 72
#define Down 80
#define Tab 9

void textattr(int i){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),i);
}

void gotoxy(int x, int y){
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

struct Employee{
    int code;
    char name[20];
    int age;
    float salary, bonus, tax;
};

char printMenu(int);
void addNewEmployee(struct Employee [],int);
void displayEployee(struct Employee [],int,int[]);
void displayAllEployee(struct Employee [], int[]);

int main()
{
    int highlight = 0;
    struct Employee emp[sz];
    int flag[sz]={0};

    do{
        system("cls");
        char ch = printMenu(highlight);

        switch(ch) {
            case Up:{
                if(highlight>0){
                    highlight-- ;
                }
                break;
            }
            case Down:{
                if(highlight<3){
                    highlight++ ;
                }
                break;
            }
            case Home:{
                highlight = 0;
                break;
            }
            case End:{
                highlight = 3;
                break;
            }
            case Enter:{
                if(highlight==0){
                    system("cls");
                    int indx;
                    printf("Eter employee index from 1-20 For Add New\n\n");
                    scanf("%d",&indx);
                    system("cls");
                    addNewEmployee(emp,indx);
                    flag[indx-1]=1;
                    printf("Click Enter to Back Menu");
                    char ch;
                    ch = getch();
                    if(ch == Enter){
                        highlight = 0;
                    }
                }
                else if (highlight==1){
                    system("cls");
                    int indx;
                    printf("Eter Employee index from 1-20 For Search\n\n");
                    scanf("%d",&indx);
                    displayEployee(emp,indx,flag);
                    printf("Click Enter to Back Menu");
                    char ch;
                    ch = getch();
                    if(ch == Enter){
                        highlight = 0;
                    }
                }
                else if (highlight==2){
                    system("cls");
                    displayAllEployee(emp,flag);
                    printf("Click Enter to Back Menu");
                    char ch;
                    ch = getch();
                    if(ch == Enter){
                        highlight = 0;
                    }
                }
                else{
                    system("cls");
                    printf("Good bye :)");
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

char printMenu(int highlight){
    char menu[4][20] = {"New", "Display", "Display All", "Exit"};
    printf("    Menu \n");
    printf("----------- \n");
    for(int i = 0; i < 4; i++) {
        if(i==highlight){
            textattr(0x25);
            printf("%s \n", menu[i]);
            textattr(0x07);
        }else{
            printf("%s \n", menu[i]);
        }
    }
    // to read keyboard
    char ch = getch();
    // special char
    if(ch == -32){
        ch = getch();
    }
    return ch;
}

void addNewEmployee(struct Employee emp[], int indx){
    printf("             Employee Form\n");
    printf("       ----------------------------\n");
    gotoxy(5, 3);
    printf("Code: ");
    gotoxy(5, 5);
    printf("Name: ");
    gotoxy(5, 7);
    printf("Age: ");
    gotoxy(30, 3);
    printf("Salary: ");
    gotoxy(30, 5);
    printf("Bonus: ");
    gotoxy(30, 7);
    printf("Tax: ");
    gotoxy(12, 3);
    scanf("%d", &emp[indx-1].code);
    getchar();
    gotoxy(12, 5);
    gets(emp[indx-1].name);
    gotoxy(12, 7);
    scanf("%d", &emp[indx-1].age);
    gotoxy(38, 3);
    scanf("%f", &emp[indx-1].salary);
    gotoxy(38, 5);
    scanf("%f", &emp[indx-1].bonus);
    gotoxy(38, 7);
    scanf("%f", &emp[indx-1].tax);
}

void displayEployee(struct Employee emp[],int indx, int flag[]){
    if(flag[indx-1] == 1){
        printf("Employee %d Details\n",indx);
        printf("----------------\n");
        printf("Code: %d\n", emp[indx-1].code);
        printf("Name: %s\n", emp[indx-1].name);
        printf("Age: %d\n", emp[indx-1].age);
        printf("Net Salary: %.2f\n\n\n", emp[indx-1].salary + emp[indx-1].bonus - emp[indx-1].tax);
    }else{
        printf("Not found\n");
    }
}
void displayAllEployee(struct Employee emp[], int flag[]){
    int count=0;
    for(int i=0;i<sz;i++){
        if(flag[i] == 1){
            count++;
            printf("Employee %d Details\n",i+1);
            printf("----------------\n");
            printf("Code: %d\n", emp[i].code);
            printf("Name: %s\n", emp[i].name);
            printf("Age: %d\n", emp[i].age);
            printf("Net Salary: %.2f\n\n\n", emp[i].salary + emp[i].bonus - emp[i].tax);
        }
    }
    if(count==0){
        printf("There are no employees\n");
    }
}


