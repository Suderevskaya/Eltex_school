#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

void fromNumToBits (int num, char res[]) {
    for (int i = 0; i < 3; i++) {
        if (num%2 == 0) {
            res[2-i]='0';       
        } else {
            res[2-i]='1';
        }
        num = num/2;
    }
}

void fromCharToBits (char input[], char res[]) {
    for (int i = 0; i < 3; i++) {
        if (input[3*i] == 'r') {
            res[3*i]='1';       
        } else {
            res[3*i]='0';
        }
        if (input[3*i+1] == 'w') {
            res[3*i+1]='1';       
        } else {
            res[3*i+1]='0';
        }
        if (input[3*i+2] == 'x') {
            res[3*i+2]='1';       
        } else {
            res[3*i+2]='0';
        }
    }
}

void fromBitsToChar (char input[], char res[]) {
    for (int i = 0; i < 3; i++) {
        if (input[3*i]=='1') {
            res[3*i] = 'r';       
        } else {
            res[3*i] = '-';
        }
        if (input[3*i+1]=='1') {
            res[3*i+1] = 'w';       
        } else {
            res[3*i+1] = '-';
        }
        if (input[3*i+2] == '1') {
            res[3*i+2]='x';       
        } else {
            res[3*i+2]='-';
        }
    }
}

void fromCharToNum(char input[], int u, int g, int o){
    u = 0;
    g = 0;
    o = 0;
    if (input[0] == 'r') u += 4;
    if (input[1] == 'w') u += 2;
    if (input[2] == 'x') u += 1;
    if (input[3] == 'r') g += 4;
    if (input[4] == 'w') g += 2;
    if (input[5] == 'x') g += 1;
    if (input[6] == 'r') o += 4;
    if (input[7] == 'w') o += 2;
    if (input[8] == 'x') o += 1;
}

void changeInt(char input[]) {
    int u, g, o;
    char outChar[10];
    while (getchar()!='\n') continue;
    printf("Введите команду изменения (3-х значное число):\n");
    scanf("%d", &u);           
    o = u%10;
    g = (u/10)%10;
    u = u/100;
    fromNumToBits(u,&input[0]);
    fromNumToBits(g,&input[3]);
    fromNumToBits(o,&input[6]);
    printf("Цифровое представление: %d%d%d\n", u, g, o);
    printf("Битовое представление: %s\n", input);
    fromBitsToChar(input, outChar);
    printf("Буквенное представление: %s\n", outChar);
}

void changeChar(char all[], char input[]) {
    printf("Введите команду изменения (В формате [uoga][+-=][rwx]):\n");
    while (getchar()!='\n') continue;
    scanf("%s", all);
    printf("%s", all);
    char type = ' ';
    char toWho[4];
    char which[4];
    int i = 0;
    while (all[i] != 'r' | all[i] != 'w' | all[i] != 'x') {
        toWho[i] = all[i];
        i++;
    }
    toWho[i] = '\0';
    type = all[i];
    while (all[i] =! '\0') {
        which[i] = all[i];
    }
    which[i] = '\0';
    int j = 0;
    char toWhat;
    if (type == '+') toWhat = '1';
    if (type == '-') toWhat = '0';
    if (toWho[0] == 'a') {
        for (i = 0; i < 3; i++) {
            if (type == '=') for (int k = 3*i; k < (3*i+2); k++) input[k]='0';
            if (which[0] == 'r') input[3*i] = toWhat;
            if (which[1] == 'w' | which[0] == 'w' ) input[3*i+1] = toWhat;
            if (which[2] == 'x' | which[1] == 'x' | which[0] == 'x') input[3*i+2] = toWhat;
        }
    }
    i = 0;
    while (toWho != '\0') {
        if (toWho[j] == 'u') { i = 0; }
        else {
            if (toWho[j] == 'g') { i = 1; }
            else if (toWho[j] == 'o') { i = 2; }
        }
        if (type == '=') for (int k = 3*i; k < (3*i+2); k++) input[k]='0';
        if (which[0] == 'r') input[3*i] = toWhat;
        if (which[1] == 'w' | which[0] == 'w' ) input[3*i+1] = toWhat;
        if (which[2] == 'x' | which[1] == 'x' | which[0] == 'x') input[3*i+2] = toWhat;
        j++;
    }
    int u, g, o;
    char outChar[10];
    printf("Битовое представление: %s\n", input);
    fromBitsToChar(input, outChar);
    printf("Буквенное представление: %s\n", outChar);
    fromCharToNum(outChar, u, g, o);
    printf("Цифровое представление: %d%d%d\n", u, g, o);
}

int main(int argc, char *argv[]) {
    char menuCommand = '4';
    char check = '0';
    char input[10];
    char output[10];
    char pathFile[200];
    char outChar[10];       
    char all[8];
    int u, g, o;
    struct stat st;
    while (menuCommand!='0') {        
        printf("1-из буквенного в битовое представление\n2-из цифрового в битовое представление\n3-права доступа по файлу\n0-exit\nEnter command:\n");
        scanf("%c", &menuCommand);
        switch (menuCommand) {
            case '1':
                printf("Введите права доступа в буквенном виде:\n");
                scanf("%s", input);
                fromCharToBits(input, output);
                printf("Битовое представление: %s\n", output);
                while (getchar()!='\n') continue;
                printf("Хотите внести изменения? (0-нет, 1-да)\n");
                scanf("%c", &check);
                if (check == '1') {
                    while (getchar()!='\n') continue;
                    printf("В каком формате? (0-цифровом, 1-буквенном)\n");
                    scanf("%c", &check);
                    if (check == '1'){ changeChar(all, output);}
                    else changeInt(output);
                }
                break;
            case '2':
                printf("Введите 3-х значное число:\n");                
                scanf("%d", &u);
                o = u%10;
                g = (u/10)%10;
                u = u/100;
                fromNumToBits(u,&output[0]);
                fromNumToBits(g,&output[3]);
                fromNumToBits(o,&output[6]);
                printf("Битовое представление: %s\n", output);
                while (getchar()!='\n') continue;
                printf("Хотите внести изменения? (0-нет, 1-да)\n");
                scanf("%c", &check);
                if (check == '1') {
                    while (getchar()!='\n') continue;
                    printf("В каком формате? (0-цифровом, 1-буквенном)\n");
                    scanf("%c", &check);
                    if (check == '1'){ changeChar(all, output);}
                    else changeInt(output);
                }
                break;
            case '3':
                printf("Введите путь к файлу (относительно папки из которой запущена программа):\n");
                scanf("%s", pathFile);
                stat(pathFile, &st);
                printf("%d\n", st.st_mode);
                o = st.st_mode%8;
                g = (st.st_mode/8)%8;
                u = (st.st_mode/8)%8;
                printf("Цифровое представление: %d%d%d\n", u, g, o);
                fromNumToBits(u,&output[0]);
                fromNumToBits(g,&output[3]);
                fromNumToBits(o,&output[6]);
                printf("Битовое представление: %s\n", output);
                fromBitsToChar(output, outChar);
                printf("Буквенное представление: %s\n", outChar);
                while (getchar()!='\n') continue;
                printf("Хотите внести изменения? (0-нет, 1-да)\n");
                scanf("%c", &check);
                if (check == '1') {
                    while (getchar()!='\n') continue;
                    printf("В каком формате? (0-цифровом, 1-буквенном)\n");
                    scanf("%c", &check);
                    if (check == '1'){ changeChar(all, output);}
                    else changeInt(output);
                }
                break;
            default:
                break;
        }
        while (getchar()!='\n')
            continue;
    }
}