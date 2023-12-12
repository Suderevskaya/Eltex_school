#include <stdio.h>
#include <math.h>
float sum (float a, float b) {
    return a+b;
}
float sub (float a, float b) {
    return a-b;
}
float mul (float a, float b) {
    return a*b;
}
float div (float a, float b) {
    return a/b;
}
float my_cos (float a) {
    return cosf(a);
}
float my_sin (float a) {
    return sinf(a);
}
float my_tg (float a) {
    return tanf(a);
}
float my_ctg (float a) {
    return tanf(1.570796-a);
}
float my_pow (float a, float b) {
    return powf(a,b);
}
float my_sqrt (float a) {
    return sqrtf(a);
}
float my_log (float a, float b) {
    return logf(a)/logf(b);
}
int main(int argc, char *argv[]) {
    int menuCommand = 1;
    float a, b, res = 0.;
    char check;
    while (menuCommand != 0) {
        check = 1;
        printf("1: +\n2: -\n3: *\n4: /\n5: cos\n6: sin\n7: tg\n8: ctg\n9: pow\n10: sqrt\n11: log\n0: exit\nEnter num of command:\n");
        scanf("%d", &menuCommand);
        switch (menuCommand) {
            case 0:
                check = 0;
                break;
            case 1:
                printf("Enter two numbers:\n");
                scanf("%f %f", &a, &b);
                res = sum(a,b);
                break;
            case 2:
                printf("Enter two numbers (first - second):\n");
                scanf("%f %f", &a, &b);
                res = sub(a,b);
                break;
            case 3:
                printf("Enter two numbers:\n");
                scanf("%f %f", &a, &b);
                res = mul(a,b);
                break;
            case 4:
                printf("Enter two numbers (first / second):\n");
                scanf("%f %f", &a, &b);
                res = div(a,b);
                break;
            case 5:
                printf("Enter number:\n");
                scanf("%f", &a);
                res = my_cos(a);
                break;
            case 6:
                printf("Enter number:\n");
                scanf("%f", &a);
                res = my_sin(a);
                break;
            case 7:
                printf("Enter number:\n");
                scanf("%f", &a);
                res = my_tg(a);
                break;
            case 8:
                printf("Enter number:\n");
                scanf("%f", &a);
                res = my_ctg(a);
                break;            
            case 9:
                printf("Enter two numbers (first^second):\n");
                scanf("%f %f", &a, &b);
                res = my_pow(a,b);
                break;
            case 10:
                printf("Enter number:\n");
                scanf("%f", &a);
                res = my_sqrt(a);
                break;
            case 11:
                printf("Enter two numbers (second - log base):\n");
                scanf("%f %f", &a, &b);
                res = my_log(a,b);
                break;
            default:
                printf("Wrong command\n");
                check = 0;
                break;
        }
        if (check == 1) printf("%f\n", res);
        while (getchar()!='\n')
            continue;
    }
}