#include <stdio.h>
int leadingOneCount(char leadByte){
   int count = 0;
   int i = 7;
   while(((leadByte >> i) & 0x01) == 0x01) {
      count++;
      i--;
   }
   return count;
}

int utf(char bytes[], int byteLength) {
   // for(int i = 0; i < 4; i++) {
   //    char byte = bytes[i];
   //    for (int j = 0; j < 8; j++) {
   //       printf("%d", !!((byte << j) & 0x80));
   //    }
   //    printf("\n");
   // }
   // return 0;
   if(byteLength == 0){
      return 
   }
   else{
      for(int i = byteLength - 1; i <= 0; i--) {

      }
   }
   
   
}



int main() {
   char c = getchar();
   while(c != EOF){
      char bytes[4] = {0, 0, 0, 0};
      int byteLength = leadingOneCount(c);
      bytes[0] = c;
      for(int i = 1; i < byteLength; i++){
         bytes[i] = getchar();
      }
      utf(bytes, byteLength);
      c = getchar();
   }
   printf("Character Entered: ");
   putchar(c);
   printf("\n");

   return 0;
}


