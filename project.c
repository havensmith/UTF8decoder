#include <stdio.h>
#include <math.h>

int chars[150000]; //there are 143,859 characters in unicode
int frequency[150000];
int mapSize = 0;

struct UTF8Char {
   unsigned char bytes[4];
   int length;
   int startIndex;
   int code;

};

int byteLength(char leadByte){
   int count = 0;
   int i = 7;
   while(((leadByte >> i) & 0x01) == 0x01) {
      count++;
      i--;
   }
   if(count == 0) {
      return 1;
   }
   return count;
}

int UTFCode(struct UTF8Char c) {
   if (c.length == 1){
      return (int)c.bytes[3];
   }
   else{
      int sum = 0;
      for (int i = 3; i > c.startIndex; i--) {
         sum += ((int)(c.bytes[i]) - 128) * pow(2, 6 * (3 - i));
      }
      int sum2 = (int)c.bytes[c.startIndex];
      for (int i = 0; i < c.length; i++) {
         sum2 -= pow(2, 7 - i);
      }
      sum2 *= pow(2, 6 * (c.length - 1));
      sum += sum2;
      return sum;
   }
   



   // for(int i = 0; i < 4; i++) {
   //    char byte = bytes[i];
   //    for (int j = 0; j < 8; j++) {
   //       printf("%d", !!((byte << j) & 0x80));
   //    }
   //    printf("\n");
   // }
   return 0;
   
}

void addChar(int UTFCode){
   for (int i = 0; i < mapSize; i++) {
      if (chars[i] == UTFCode) {
         frequency[i] ++;
         return;
      }
   }
   chars[mapSize] = UTFCode;
   frequency[mapSize] = 1;
   mapSize++;
   return;
}

int main() {
   FILE *file = fopen("test1.txt", "r");
   char c = getc(file);
   while(c != EOF){
      unsigned char bytes[4] = {0, 0, 0, 0};
      int length = byteLength(c);
      int startIndex = 4 - length;
      bytes[startIndex] = (unsigned char)c;
      for(int i = startIndex + 1; i < 4; i++){
         bytes[i] = getc(file);
      }
      struct UTF8Char utf8Char = {{bytes[0], bytes[1], bytes[2], bytes[3]}, length, startIndex, 0};
      utf8Char.code = UTFCode(utf8Char);
      addChar(utf8Char.code);
      //printf("%d", utf8Char.code);
      c = getc(file);
   }
   for (int i = 0; i < mapSize; i++) {
      if(chars[i] < 128){
         putchar((char)chars[i]);
         printf(" -> %d\n", frequency[i]);
      }
      else {
         printf("%x -> %d\n", chars[i], frequency[i]);
      }
      
   }
   return 0;
}


