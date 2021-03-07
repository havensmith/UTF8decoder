#include <stdio.h>
int byteLength(char leadByte){
   int count = 0;
   int i = 7;
   while(((leadByte >> i) & 0x01) == 0x01) {
      count++;
      i--;
   }
   return count;
}



int main() {
   char c;
   c = getchar();
   printf("Character Entered: ");
   putchar(c);

   printf("\n%d", byteLength(c));
   // for(int i = 7; i >= 0; i--) {
   //    printf("%d\n", (c >> i) & 0x01);
   // }
   

   return 0;
}


