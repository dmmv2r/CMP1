#include <iostream>
#include <string>
#include "token.h"
#include "scanner.h"

using namespace std;

const char SPACE = ' ';

int scanner(string& str, Token& token) {
   int row = 0;
   int nextRow;
   int nextCol;
   string tokenKey;
   char nextChar;

   token.line = lineIndex; //gets current token line number

   while(charIndex <= str.length()) { //loops while there are still characters to read
      
      if(charIndex < str.length()) { //sets up use for FSA table for next char
         nextChar = str.at(charIndex);
      }
      else {
         nextChar = SPACE;
      }

      nextCol = getCol(nextChar);
      nextRow = FSA_TABLE[row][nextCol];

      if(nextRow < 0) { //detects if error
         row = 0;

         errorM(nextRow, str);

         charIndex++;
         return -1;
      }
      else if(nextRow > FINAL) { //detects if a final state
         token.keyword = tokenKey;

         switch(nextRow) { //find the proper state
            case FINAL_ID:
               if(isKey(token) == -1) {
                  token.ID = idTK;
                  token.keyword.assign("idTK " + tokenKey);
               }
               else {
                  token.ID = keywordTK;
                  token.keyword.append(" " + tokenKey);
               }
               break;
            case FINAL_INT:
               token.ID = idTK;
               token.keyword.assign("intTK " + tokenKey);
               break;
            case FINAL_OP:
               token.ID = opTK;
               getOp(token);
               token.keyword.append(" " + tokenKey);
               break;
         }
   
         return 0;

      }

      row = nextRow;
      charIndex++;

      if(!isspace(nextChar)) { //detects if next char is space, if not then add
         tokenKey.push_back(nextChar);
      }
   }

   //if this point is reached, and error has occurred.
   return -1;
}

int getCol(char x) {
   string s(1,x); //turns char into string for checking operator
   if(isalpha(x)) {

      if(islower(x)) {
         return 0; //column 0
      }
      else {
         return 1;
      }
   }
   else if(isdigit(x)) {
      return 2;
   }
   else if(isspace(x)) {
      return 3;
   }
   else if(isOp(s)) {
      return 5;
   }
   else {
      return -1; //character not found
   }
}

void errorM(int errNum, string str) { //outputs token error information
   cout << "SCANNER ERROR: Line " << lineIndex << endl;
   if(errNum == ERROR_LET) {
      cout << "Invalid letter entry" << endl;
   }
   else if(errNum == ERROR_NUM) {
      cout << "Invalid digit entry" << endl;
   }
}

