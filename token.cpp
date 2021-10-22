#include <iostream>
#include <string>
#include <map>
#include "token.h"
#include "scanner.h"

using namespace std;

map<string, string> keyMap;
map<string, string> opMap;

void getKeyMap() { //creates linkage map for keywords
   keyMap.insert(make_pair("start", "startTK"));
   keyMap.insert(make_pair("stop", "stopTK"));
   keyMap.insert(make_pair("loop", "loopTK"));
   keyMap.insert(make_pair("while", "whileTK"));
   keyMap.insert(make_pair("for", "forTK"));
   keyMap.insert(make_pair("label", "labelTK"));
   keyMap.insert(make_pair("exit", "exitTK"));
   keyMap.insert(make_pair("listen", "listenTK"));
   keyMap.insert(make_pair("talk", "listenTK"));
   keyMap.insert(make_pair("program", "programTK"));
   keyMap.insert(make_pair("if", "ifTK"));
   keyMap.insert(make_pair("then", "thenTK"));
   keyMap.insert(make_pair("assign", "assignTK"));
   keyMap.insert(make_pair("declare", "declareTK"));
   keyMap.insert(make_pair("jump", "jumpTK"));
}

void getOpMap() { //creates linkage map for operators
   opMap.insert(make_pair("=", "equalTK"));
   opMap.insert(make_pair(">", "greatTK"));
   opMap.insert(make_pair("<", "lessTK"));
   opMap.insert(make_pair("==", "eqEqTK"));
   opMap.insert(make_pair(":", "colonTK"));
   opMap.insert(make_pair(":=", "coEqTK"));
   opMap.insert(make_pair("+", "plusTK"));
   opMap.insert(make_pair("-", "minusTK"));
   opMap.insert(make_pair("*", "timesTK"));
   opMap.insert(make_pair("/", "divideTK"));
   opMap.insert(make_pair("%", "percentTK"));
   opMap.insert(make_pair(".", "periodTK"));
   opMap.insert(make_pair("(", "leftParenTK"));
   opMap.insert(make_pair(")", "rightParenTK"));
   opMap.insert(make_pair(",", "commaTK"));
   opMap.insert(make_pair("{", "leftBraceTK"));
   opMap.insert(make_pair("}", "rightBraceTK"));
   opMap.insert(make_pair(";", "semiCoTK"));
   opMap.insert(make_pair("[", "leftBrackTK"));
   opMap.insert(make_pair("]", "rightBrackTK"));
}

void showToken(Token token) { //outputs token information
   cout << "ID: " << tokenNames[token.ID] << endl;
   cout << "Keyword: " << token.keyword << endl;
   cout << "Line: " << token.line << endl;
   cout << endl;
}

void getOp(Token& token) { //finds proper token keyword
   token.keyword.assign(opMap[token.keyword]);
}

int isKey(Token& token) { //determines if token is a keyword
   for(int i = 0; i < 14; i++) { //loops through keyword list
      if(token.keyword == keywords[i]) {
         token.keyword = keyMap[token.keyword];
         return i;
      } else {
         return -1;
      }   
   }
}

int isOp(string x) { //determines if token is an operator
   for(int i = 0; i < 20; i++) { //loops through operator list
      if(x == operators[i]) {
         return 1;
      } else {
         return 0;
      }
   }
}

