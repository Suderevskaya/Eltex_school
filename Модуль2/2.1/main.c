#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Data {
    int num;
    char lastName[20], firstName[20];
    char middleName[20], job[20], position[20];
    char phoneNumbers[5][12], mails[5][20], sociaMedias[5][20], messengers[5][20];
} Data;
int main(int argc, char *argv[]) {
    char varLastName[5][20]={"Petrova","Sidorova","Ruka","Lipova","Chrahmalova"};
    char varFirstName[5][20]={"Antonina","Albina","Argentina","Karina","Marina"};
    struct Data contacts[20];
    for (int i=0;i<5;i++){
        contacts[i].num=i;
        strcpy(contacts[i].lastName, varLastName[rand()%4]);
        strcpy(contacts[i].firstName, varFirstName[rand()%4]);
        strcpy(contacts[i].middleName, "");
        strcpy(contacts[i].job, "");
        strcpy(contacts[i].position, "");
        for (int k = 0; k < 5; k++) {
            strcpy(contacts[i].phoneNumbers[k], "");
            strcpy(contacts[i].mails[k], "");
            strcpy(contacts[i].sociaMedias[k], "");
            strcpy(contacts[i].messengers[k], "");
        }
    }
    char menuCommand = '4';
    char newLastName[20], newFirstName[20];
    char newMiddleName[20], newJob[20], newPosition[20];
    char newPhoneNumbers[5][12], newMails[5][20], newSociaMedias[5][20], newMessengers[5][20];
    int howMuch;
    char yesNo;
    int i = 5;
    int numOfContact;
    while (menuCommand!='0') {
        printf("1-add\n2-edit\n3-delete\n4-print\n0-exit\nEnter command:\n");
        scanf("%c", &menuCommand);
        switch (menuCommand) {
            case '1':
                printf("Enter last name:\n");
                scanf("%s", newLastName);
                printf("Enter first name:\n");
                scanf("%s", newFirstName);
                printf("Wanna enter middle name?\n0-no\n1-yes\n");
                while (getchar()!='\n') continue;
                scanf("%c",&yesNo);
                if (yesNo=='1') {
                    printf("Enter middle name:\n");
                    scanf("%s", newMiddleName);
                }
                printf("Wanna enter job?\n0-no\n1-yes\n");
                while (getchar()!='\n') continue;
                scanf("%c",&yesNo);
                if (yesNo=='1') {
                    printf("Enter job\n");
                    scanf("%s", newJob);
                }
                printf("Wanna enter position?\n0-no\n1-yes\n");
                while (getchar()!='\n') continue;
                scanf("%c",&yesNo);
                if (yesNo=='1') {
                    printf("Enter position:\n");
                    scanf("%s", newPosition);
                }
                printf("Wanna enter phone numbers?\n0-no\n1-yes\n");
                while (getchar()!='\n') continue;
                scanf("%c",&yesNo);
                if (yesNo=='1') {
                    printf("How much phone numbers you want to enter? (max 5)\n");
                    while (getchar()!='\n') continue;
                    scanf("%d", &howMuch);
                    for (int j = 0; j < howMuch; j++){ 
                        printf("Enter phone number:\n");
                        scanf("%s", newPhoneNumbers[j]);
                    }
                }
                contacts[i].num=i;
                strcpy(contacts[i].lastName, newLastName);
                strcpy(contacts[i].firstName, newFirstName);
                strcpy(contacts[i].middleName, newMiddleName);
                strcpy(contacts[i].job, newJob);
                strcpy(contacts[i].position, newPosition);
                for (int j = 0; j < 5; j++)
                    strcpy(contacts[i].phoneNumbers[j], newPhoneNumbers[j]);
                i++;
                break;
            case '2':
                printf("Enter num of contact:\n");
                scanf("%d", &numOfContact);
                break;
            case '3':
                printf("Enter num of contact:\n");
                scanf("%d", &numOfContact);                
                contacts[numOfContact].num=numOfContact;
                strcpy(contacts[numOfContact].lastName, "");
                strcpy(contacts[numOfContact].firstName, "");
                strcpy(contacts[numOfContact].middleName, "");
                strcpy(contacts[numOfContact].job, "");
                strcpy(contacts[numOfContact].position, "");
                for(int k = 0; k < 5; k++) {
                    strcpy(contacts[numOfContact].phoneNumbers[k], "");
                    strcpy(contacts[numOfContact].mails[k], "");
                    strcpy(contacts[numOfContact].sociaMedias[k], "");
                    strcpy(contacts[numOfContact].messengers[k], "");
                }
                break;
            case '4':
                for(int j = 0; j < i; j++) {
                    printf("%s\n", contacts[j].lastName);
                    printf("%s\n", contacts[j].firstName);
                    printf("%s\n", contacts[j].middleName);
                    printf("%s\n", contacts[j].job);
                    printf("%s\n", contacts[j].position);
                    for(int k = 0; k < 5; k++)
                        printf("%s\n", contacts[j].phoneNumbers[k]);
                }
                printf ("\n");
                break;
            default:
                break;
        }
        while (getchar()!='\n')
            continue;
    }
}