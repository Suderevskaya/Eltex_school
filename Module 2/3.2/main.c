#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertIPFromStringToInt(char input[], unsigned int out[]) {
   //oooooh what's too many
   int i = 0; int j = 1; int k = 0; int f = 0; int g = 0;
   for (f = 0; f < 4; f++) out[f] = 0;
   for (f = 0; f < 3; f++) {
      g = 0; j = 1;
      while (input[i] != '.') {
         i++;
         g++;
         j = j * 10;
      }
      for (k = 0; k < g; k++) {
         j = j / 10;
         out[f] += (input[i - g + k] - '0') * j;
      }
      i++;
   }
   g = 0; j = 1;
   while (input[i] != '\0') {
      i++;
      g++;
      j = j * 10;
   }
   for (k = 0; k < g; k++) {
      j = j / 10;
      out[f] += (input[i - g + k] - '0') * j;
   }
}

char checkIP(char check, char rand_IP[], char my_IP[], char mask[], char network_IP[], char dest_IP[]) {
   int i = 0;
   check = '1';
   for (i = 0; i < 32; i++) {
      network_IP[i] = my_IP[i] & mask[i];
      dest_IP[i] = rand_IP[i] & mask[i];
      if ((network_IP[i] ^ dest_IP[i]) == '1') { check = '0'; i = 32; }
   }
   return check;
}
char checkIP_notBit(char check, int rand_IP[], int my_IP[], int mask[], int network_IP[], int dest_IP[]) {
   int i = 0;
   check = '1';
   for (i = 0; i < 4; i++) {
      network_IP[i] = my_IP[i] & mask[i];
      dest_IP[i] = rand_IP[i] & mask[i];
      if ((network_IP[i] ^ dest_IP[i]) != 0) { check = '0'; i = 4; }
   }
   return check;
}

int main(int argc, char* argv[]) {
   char my_IP_string[15], mask_string[15], N_string[15];
   unsigned int  my_IP[4], mask[4], rand_IP[4], net_Src[4], net_Dst[4];
   unsigned long int N = 0;
   unsigned long int i = 0; unsigned long int j = 1; int k = 0; int f = 0;
   char check = '1';
   unsigned long int my_N = 0;
   printf("%d\n", argc);
   strcpy(my_IP_string, argv[1]);
   convertIPFromStringToInt(my_IP_string, my_IP);
   strcpy(mask_string, argv[2]);
   convertIPFromStringToInt(mask_string, mask);
   strcpy(N_string, argv[3]);
   while (N_string[i] != '\0') {
      i++;
      j = j * 10;
   }
   for (k = 0; k < i; k++) {
      j = j / 10;
      N += (N_string[k] - '0') * j;
   }
   printf("Input:\n");
   printf("N = %ld\n", N);
   printf("Gateway: %d.%d.%d.%d\n", my_IP[0], my_IP[1], my_IP[2], my_IP[3]);
   printf("Mask: %d.%d.%d.%d\n", mask[0], mask[1], mask[2], mask[3]);
   for (i = 0; i < N; i++) {
      rand_IP[0] = 0; rand_IP[0] = 192 + rand() % 31;
      for (f = 1; f < 4; f++) { rand_IP[f] = 0; rand_IP[f] = rand() % 256; }
      check = checkIP_notBit(check, rand_IP, my_IP, mask, net_Src, net_Dst);
      if (check == '1') my_N++;
   }
   printf("Mine count: %ld - %ld%%\n", my_N, (my_N * 100 / N));
   printf("Other count: %ld - %ld%%\n", (N - my_N), (100 - (my_N * 100 / N)));
}