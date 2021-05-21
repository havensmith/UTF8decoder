# Unicode-UTF8 Byte Decoding in C
Haven Smith<br/>
## How it Works
 This project is a program to read input bytes from a file, use these bits to decode the Unicode character via UTF8, and count and record the occurrence of each character in the file. At the end of the file or when the file is closed, then it is writen to stdout the list of characters sorted by the number of times the characters appear in the input in order of greatest to least. note: some characters may be invisible but they shuold still be printed.
 ![ExampleOut](/images/UTF-8.png)
### Translating Between UTF8 and Unicode
- The high-order but in binary is always important.
- If the high-order bit is zero, then only one byte is needed and the representation of the current character is ASCII.
- If the high order bits are [110], then the Unicode character will be two bytes long. Also this means that the next byte must have a 1 in the high order bit and the second bit 0.
- If the high order bits are [1110…], then Unicode will be three bytes long. Also, the next two bytes should have a one in the high order bit and the second bit 0.
- This pattern will follow with 4 byte encoding and larger.
## Usage
1. have a C compiler installed.
2. insert your text into the file "sample.txt"
3. run the command "make all" on the terminal
4. run the command "make run"
5. if you wish to switch the sample text, change the text, resave sample.txt, and run the command "make run" from the project directory
5. to clear the exectuable file, run "make clean"




