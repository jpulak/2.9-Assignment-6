// program for converting to morse code
// using files data

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// func prototypes

bool loadMorseArray(string morse[], ifstream& inFile);
void genMorse(string& morseLine, const string textLine, const string morse[]);

//main func

int main() {
    const int SIZE = 26;
    string morse[SIZE];

    // gather inputs
    
    string inputFileName, outputFileName;
    cout << "Enter the name of the input file: ";
    cin >> inputFileName;
    cout << "Enter the name of the output file: ";
    cin >> outputFileName;

    // open file w/ morse code
    
    ifstream morseFile("morseLetters.txt");
    bool morseFileOpen = morseFile.is_open();
    
    //follor through conditions
    
    if (morseFileOpen) 
    {
        if (!loadMorseArray(morse, morseFile)) 
        {
            cout << "Error, unable to load Morse codes." << endl;
            morseFileOpen = false; 
        }
        morseFile.close();
    }
    if (!morseFileOpen) 
    {
        cout << "Error, unable to open file morseLetters.txt." << endl;
    } 
    else 
    {
        ifstream inFile(inputFileName);
        ofstream outFile(outputFileName); 
        bool filesOpen = inFile.is_open() && outFile.is_open();
        if (!filesOpen) 
        {
            if (!inFile.is_open()) 
            {
                cout << "Error, unable to open file " << inputFileName << "." << endl;
            } 
            else if (!outFile.is_open()) 
            {
                cout << "Error, unable to open file " << outputFileName << "." << endl;
            }
        } 
        else 
        {
            
            //if all files successfully open
            
            string textLine;
            int lineCount = 0;
            while (getline(inFile, textLine)) 
            {
                string morseLine;
                genMorse(morseLine, textLine, morse);
                outFile << morseLine << endl;
                lineCount++;
            }
            cout << "Translation complete. " << lineCount << " lines translated." << endl;
            inFile.close();
            outFile.close();
        }
    }
    return 0;
}

// func to load Morse codes into the array

bool loadMorseArray(string morse[], ifstream& inFile) {
    string letter, code;
    int count = 0;
    bool success = true;

    while (count < 26 && inFile >> letter >> code) 
    {
        morse[count] = code;
        count++;
    }
    if (count != 26) 
    {
        success = false;
    }
    return success;
}

// func to convert a line of text to Morse code

void genMorse(string& morseLine, const string textLine, const string morse[]) {
    for (size_t i = 0; i < textLine.length(); i++) 
    {
        char ch = textLine[i];
        if (ch >= 'A' && ch <= 'Z') 
        {
            morseLine += morse[ch - 'A'] + " ";
        } 
        else if (ch == ' ' || ch == '.') 
        {
            morseLine += ch;
        }
    }
}
