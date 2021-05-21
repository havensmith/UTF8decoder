# cs3113sp21-project0
Haven Smith<br/>
student ID: 113516246<br/>
class: CS3113 (spring 21)
## Usage
1. have a C compiler installed.
2. insert your text into the file "sample.txt"
3. run the command "make all" on the terminal
4. run the command "make run"
5. if you wish to switch the sample text, change the text, resave sample.txt, and run the command "make run" from the project directory
5. to clear the exectuable file, run "make clean"
## How it Works
### Translating Between UTF8 and Unicode
    *The high-order but in binary is always important.
    *If the high-order bit is zero, then only one byte is needed and the representation of the current character is ASCII.
    *If the high order bits are [110], then the Unicode character will be two bytes long. Also this means that the next byte must have a 1 in the high order bit and the second bit 0.
    *If the high order bits are [1110…], then Unicode will be three bytes long. Also, the next two bytes should have a one in the high order bit and the second bit 0.
    *This pattern will follow with 4 byte encoding and larger.
### ASCII
ASCII was first a seven-bit code that points to all usable characters. Because seven bits are used, ASCII can only include 2^7 or 128 different characters. This limits the number of characters to a subset of English Roman-based alphabets. Because many programming languages and applications have assumed everyone is using ASCII, serious file recognition issues have emerged.
### Unicode and UTF8
The Unicode standard was developed as a way to encode all of the characters in every language. Unicode is a collection of agreed upon mapping characters (⌛️,⏰️) to a numerical representation called and code points (U+231B, U+23F0). Currently, there is room for 1.1 million characters in the Unicode standard but only ~137K are currently being used.



