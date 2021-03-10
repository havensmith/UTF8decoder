#include <stdio.h>


int pow(int base, int pow) {
   int product = 1;
   for(int i = 0; i < pow; i++) {
      product *= base;
   }
   return product;
}

//structure to hold bytes of characters encoded in UTF8
struct UTF8Char {
   unsigned char bytes[4]; //byte array
   int length; //bytelength of character
   int startIndex; //starting index of first byte in "bytes" = 3 - byteLength (unused bytes set to 00000000 = 0x00)
   int unicode; //utf8 code of character
};

//set of all characters
struct UTF8Char chars[150000]; //there are 143,859 unique characters in unicode
int frequency[150000];
int mapSize = 0;

//returns the bytelength of a character given it's lead byte
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

//computes unicode of a character encoded in UTF8
int convertUnicode(struct UTF8Char c) {
   //if the length of the character is one, then the character can be represented in ASCII directly
   if (c.length == 1){
      return (int)c.bytes[3];
   }
   else{
      int sum = 0;
      //concatenates trailing bits
      for (int i = 3; i > c.startIndex; i--) {
         sum += ((int)(c.bytes[i]) - 128) * pow(2, 6 * (3 - i));
      }
      //computes relevant leading byte value
      int sum2 = (int)c.bytes[c.startIndex];
      for (int i = 0; i < c.length; i++) {
         sum2 -= pow(2, 7 - i);
      }
      //concatonate leading byte
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

//adds character to character set -- represented in unicode
void addChar(struct UTF8Char c){
   for (int i = 0; i < mapSize; i++) {
      if (chars[i].unicode == c.unicode) {
         frequency[i] ++;
         return;
      }
   }
   //if the character exists, the corresponding frequency set will increment the respective value
   chars[mapSize] = c;
   frequency[mapSize] = 1;
   mapSize++;
   return;
}

void sortMap(){
   //standard bubble sort algorithim -- uses two swaps since the character set and the frequency set are corresponding
   int sorted = 0;
   while (sorted == 0) {
      sorted = 1; //assume list to be sorted
      for (int i = 0; i < mapSize - 1; i++) {
         if (frequency[i] < frequency[i + 1]) {
            //swap
            int temp1 = frequency[i];
            struct UTF8Char temp2 = chars[i];
            frequency[i] = frequency[i + 1];
            chars[i] = chars[i + 1];
            frequency[i + 1] = temp1;
            chars[i + 1] = temp2;
            sorted = 0; //since a swap was made, the list could possibly be unsorted, so we assume as such
         }
      }
   }
}

int main() {
   char c = getchar();
   while(c != EOF){
      unsigned char bytes[4] = {0, 0, 0, 0}; //holds bytes of scanned characters
      int length = byteLength(c);
      int startIndex = 4 - length; //starting index of first bit, since bytelength varies. (the last byte will always be in index 3)
      bytes[startIndex] = (unsigned char)c; //set first byte
      //set remaining bytes
      for(int i = startIndex + 1; i < 4; i++){
         bytes[i] = getchar();
      }
      //create a UTF8 character with useful info to help unicode function
      struct UTF8Char utf8Char = {{bytes[0], bytes[1], bytes[2], bytes[3]}, length, startIndex, 0};
      utf8Char.unicode = convertUnicode(utf8Char);
      addChar(utf8Char);
      //printf("%d", utf8Char.code);
      c = getchar(); //scan in next character
   }
   sortMap(); //sorts map of characters and frequencies from most occuring to least
   //prints characters and respective frequencies. Some characters such as ' ' and \n print in a nonstandard way, so cases are added
   //for these
   for (int i = 0; i < mapSize; i++) {
      for(int j = chars[i].startIndex; j < 4; j++) {
         char c = chars[i].bytes[j];
         putchar(c);
      }
      printf("->%d\n", frequency[i]);
      
   }
   return 0;
}