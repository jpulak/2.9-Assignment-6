# morseCodeConverter
Write a modular program (with functions) that creates a file containing the Morse code equivalent of the input file. The input file will contain only uppercase letters, spaces, periods, and newlines. The code for each letter in the output file will be followed by a space. Spaces, newlines, and periods in the input file will be written to the output file as-is.

The user must be allowed to enter the name of the input file and the name of the output file. Be sure you include a prompt asking the user to enter the name of the input file and another prompt asking the user to enter the name of the output file.

When your program is unable to open the specified file, display an error message like the one shown below. Note, |filename| should be replaced by the actual filename entered by the user. Please note there is a period and then a newline at the end.

`Error, unable to open file |filename|`.
Example:

If the following is a line of the input file:

`HAVE A NICE DAY.`
The corresponding line of the output file should be:

`.... .- ...- .   .-   -. .. -.-. .   -.. .- -.-- . `
To solve a portion of the problem:

(1)

Write a function named loadMorseArray that takes the following two arguments in order: 1) An array of strings that will hold the codes for the twenty-six letters of the alphabet, after this function puts them there, 2) A reference to an ifstream object that has been linked to the file morseLetters.txt, which contains the Morse code for each of the letters in the alphabet. This function will fill the array with the Morse codes for the letters, such that, the element with subscript 0 has the code for A, the element with subscript 1 has the code for B,… . The function returns true if the array was successfully filled and false otherwise. The fill should be deemed successful when 26 codes are read and stored in the array.

The following is a valid prototype for the function specified:

`bool loadMorseArray(string[], ifstream&);`

Each line of the file morseLetters.txt contains a letter followed by a tab and then the Morse code for the letter (a sequence of dots and/or dashes). The first line is for A, the second for B,… .

```
A    .-
B    -...
C    -.-.
D    -..
E    .
F    ..-.
G    --.
H    ....
I    ..
J    .---
K    -.-
L    .-..
M    --
N    -.
O    ---
P    .--.
Q    --.-
R    .-.
S    ...
T    -
U    ..-
V    ...-
W    .--
X    -..-
Y    -.--
Z    --..
```

Note: there are two files available for you to download, Mac_morseLetters.txt and Windows_morseLetters.txt. The difference is in the newline representation used. These can be used for testing your code in your IDE. When submitting, zylabs will use a file called morseLetters.txt, so make sure to use "morseLetters.txt" as your filename when opening in your code.

(2)

Write a function named genMorse that takes the following three arguments in order: 1) A reference to a string that will be filled with the Morse code conversion of one line from the file, 2) A string containing one line of text from the input file, 3) The string array containing the Morse codes for each letter. This function converts each character of the string from the input file, adding the Morse code for each letter to the output string followed by a space character and copying spaces and periods found in the input string to the string containing the Morse code conversion.

Please note, the only characters in the string will be uppercase letters, spaces, and periods.

The following is a valid prototype for the function specified:

`void genMorse(string&, const string , const string[]);`

(3)

Read a line of text from the input file using getline. The getline function does not put the trailing newline in the string. When you write a translated line to the file, write one newline at the end.

(4)

The Morse code for a particular letter is in the array at subscript [letter % ‘A’]. A is at 0, B is at 1, … .

(5)

When at least one line was written to the file, display the following message at the end of the program replacing |num lines| with the actual number of lines translated. Note, there is a period followed by a newline at the end.

`Translation complete. |num lines| lines translated.`
Do not use a return in the middle of a function, multiple returns, or the exit function to end the function/program when invalid data is received. Design your decision structure so that other processing is skipped when an invalid input is received. Do not forget that a preceding comment is required above the definition (not the prototype) of all called functions. Do not use global variables.

