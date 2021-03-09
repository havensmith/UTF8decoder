#include <stdio.h>

int byteLength(char leadByte){
   int count = 0;
   int i = 7;
   //counts leading ones by masking off bits starting at the most significant bit 2^7
   while(((leadByte >> i) & 0x01) == 0x01) {
      count++;
      i--;
   }
   //if no leading 1's, then the character is 1 byte long
   if(count == 0) {
      return 1;
   }
   return count;
}

int main() {
    FILE *file = fopen("test2.txt", "r");
    char c = getc(file);
    unsigned char bytes[4] = {0, 0, 0, 0}; //holds bytes of scanned characters
    int length = byteLength(c);
    int startIndex = 4 - length; //starting index of first bit, since bytelength varies. (the last byte will always be in index 3)
    bytes[startIndex] = (unsigned char)c; //set first byte
    //set remaining bytes
    for(int i = startIndex + 1; i < 4; i++){
        c = getc(file);
        bytes[i] = c;
    }
    for(int i = startIndex; i < 4; i++) {
        putchar(bytes[i]);
    }
}
