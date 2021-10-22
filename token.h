#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <map>

using namespace std;

extern int tokenIndex; //which token
extern int charIndex; //the character in a token
extern int lineIndex; //line

extern map<string, string> keyMap;
extern map<string, string> opMap;

enum tokenID {errTK, idTK, keywordTK, opTK, itTK, eofTK};
const string tokenNames[6] = {"Error", "Identifier", "Keyword", "Operator", "Integer", "EOF"};
const string keywords[16] = {"start", "stop", "loop", "while", "for", "label", "exit", "listen", "talk", "program", "if", "then", "assign", "declare", "jump", "else"};
const string operators[20] = {"=", ">", "<", "==", ":", ":=", "+", "-", "*", "/", "%", ".", "(", ")", ",", "{", "}", ";", "[", "]"};
const char comment = '$';

struct Token {
   tokenID ID;
   string keyword;
   int line;
}; //token struct

void getKeyMap();
void getOpMap();
void showToken(Token token);
void getOp(Token& token);
int isKey(Token& token);
int isOp(string x);

#endif

