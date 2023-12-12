#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
float sum () {
    float a, b;
    printf("Enter two numbers:\n");
    scanf("%f %f", &a, &b);
    return a+b;
}
float sub () {
    float a, b;
    printf("Enter two numbers (first - second):\n");
    scanf("%f %f", &a, &b);
    return a-b;
}
float mul () {
    float a, b;
    printf("Enter two numbers:\n");
    scanf("%f %f", &a, &b);
    return a*b;
}
float my_div () {
    float a, b;
    printf("Enter two numbers (first / second):\n");
    scanf("%f %f", &a, &b);
    return a/b;
}
float my_cos () {
    float a;
    printf("Enter number:\n");
    scanf("%f", &a);
    return cosf(a);
}
float my_sin () {
    float a;
    printf("Enter number:\n");
    scanf("%f", &a);
    return sinf(a);
}
float my_tg () {
    float a;
    printf("Enter number:\n");
    scanf("%f", &a);
    return tanf(a);
}
float my_ctg () {
    float a;
    printf("Enter number:\n");
    scanf("%f", &a);
    return tanf(1.570796-a);
}
float my_pow () {
    float a, b;
    printf("Enter two numbers (first^second):\n");
    scanf("%f %f", &a, &b);
    return powf(a,b);
}
float my_sqrt () {
    float a;
    printf("Enter number:\n");
    scanf("%f", &a);
    return sqrtf(a);
}
float my_log () {
    float a, b;
    printf("Enter two numbers (second - log base):\n");
    scanf("%f %f", &a, &b);
    return logf(a)/logf(b);
}
int main(int argc, char *argv[]) {
    int accessLevel = 1;
    while (accessLevel != 0) {
        printf("for all: +-*/\n2: plus cos sin tg ctg\n3: all\n0: exit\nEnter access level:\n");
        scanf("%d", &accessLevel);
        //float *operations = (void*)malloc(4*sizeof(void));
        //for (int i =0; i<4;i++){
            //operations[i]=(float*)malloc(4*sizeof(float));
        //}
        float **operations;
        operations = (float**)malloc(4*sizeof(float*));
        //????????????????????????????
        for (int i =0; i<4;i++){
            operations[i]=(float*)malloc(sizeof(float));
        }
        //void(*operations[4])(void);
        operations[0]=sum;
        operations[1]=sub;
        operations[2]=mul;
        operations[3]=my_div;
        int n = sizeof("1: +\n2: -\n3: *\n4: /\n");
        char menuEnd[] = "0: exit\nEnter num of command:\n";
        char *menu = (char*)malloc(n);
        strcpy(menu, "1: +\n2: -\n3: *\n4: /\n");
        switch (accessLevel) {
            case 2:
                //*operations = (float*)malloc(8*sizeof(float));
                menu = (char*)realloc(menu,n+sizeof("5: cos\n6: sin\n7: tg\n8: ctg\n"));
                strcpy(menu+n-1, "5: cos\n6: sin\n7: tg\n8: ctg\n");
                //void (*operations[8])={sum,sub,mul,my_div,my_cos,my_sin,my_tg,my_ctg};
                //char menu [] = "1: +\n2: -\n3: *\n4: /\n5: cos\n6: sin\n7: tg\n8: ctg\n0: exit\nEnter num of command:\n";
                break;
            case 3:
                menu = (char*)realloc(menu,n+sizeof("5: cos\n6: sin\n7: tg\n8: ctg\n9: pow\n10: sqrt\n11: log\n"));
                strcpy(menu+n-1, "5: cos\n6: sin\n7: tg\n8: ctg\n9: pow\n10: sqrt\n11: log\n");
                //void (*operations[11])={sum,sub,mul,my_div,my_cos,my_sin,my_tg,my_ctg,my_pow,my_sqrt,my_log};
                //char menu [] = "1: +\n2: -\n3: *\n4: /\n5: cos\n6: sin\n7: tg\n8: ctg\n9: pow\n10: sqrt\n11: log\n0: exit\nEnter num of command:\n";
                break;
            default:
                break;
        }        
        int menuCommand = 1;
        float res = 0.;
        while (menuCommand != 0) {
            printf("%s", menu);
            printf("%s", menuEnd);
            scanf("%d", &menuCommand);
            int length = sizeof(operations) / sizeof(operations[0]);
            for (int i = 0; i < (sizeof(operations) / sizeof(operations[0])); i++) {
                if (menuCommand == i) {
                    operations[i];
                    printf("%f\n", res);
                }
            }
            while (getchar()!='\n')
                continue;
        }
        while (getchar()!='\n')
            continue;
    }
}