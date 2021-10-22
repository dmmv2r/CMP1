#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include "token.h"
#include "scanner.h"
#include "testScanner.h"

using namespace std;

int tokenIndex; //determines which token
int charIndex; //determines which character in the token
int lineIndex; //determines which line
static int isComment; //comment boolean of sorts

int testScanner(istream& in) {   
   string line;
   Token token;
  
   getKeyMap();
   getOpMap();

   lineIndex = 1;

   while(getline(in, line)) { //loops until EOF detected
      tokenIndex = 0;

      if(filter(line) == -1) { //removes all comments and whitespace
         return 1;
      }

      charIndex = 0;

      if(line.length() > 0) { //make sure line is not empty
         while(scanner(line, token) == 0) {
            showToken(token);
         }
      }
      
      lineIndex++; //next line
   }

   if(in.eof()) { //detects if EOF

      if(lineIndex > 1) { //gets proper line for EOF token
         lineIndex--;
      }

      token.ID = eofTK;
      token.keyword = "EOF";
      token.line = lineIndex;
      showToken(token);
   }

   return 0;

}

int filter(string& str) { //function to remove comments and whitespace
   if(tokenIndex >= str.length()) { //handles an error that may occur
      return 0;
   }

   string newStr;
   char ch;
   char lastCh;
   const char s = ' '; //s stands for space

   for(int i = tokenIndex; i < str.length(); i++) { //loop through characters in line
      ch = str.at(i);
      
      if(i > 0) {
         lastCh = str.at(i - 1);
      }

      if(ch == comment && lastCh == comment) { //detects if comment key
         newStr.push_back(s);

         isComment = !isComment;
      }
      else if(!isComment) {

         if(isspace(ch)) { //cleans up whitespace that may be left

            if(!isspace(lastCh)) {
               newStr.push_back(ch);
            }
         }

         else if(goodChar(ch) == -1) { //detects error if character doesn't exist
            cout << "SCANNER ERROR: Invalid character " << ch << endl;
            cout << "Line: " << lineIndex << endl;
            return -1;
         }

         else { //valid character
            newStr.push_back(ch);
         }
      }
   
   tokenIndex++;

   }

   str.assign(newStr);
   return tokenIndex;
}

int goodChar(char ch) { //detects if char is a valid character
   string s(1, ch);
   if(isOp(s) == -1 && !isdigit(ch) && !isalpha(ch)) {
      return -1;
   }
   return 0;
}

