#ifndef SCANNER_H
#define SCANNER_H

#include "token.h"

using namespace std;

//possible states and their numbers
const int ERROR_NUM = -2;
const int ERROR_LET = -1;
const int ZERO = 0;
const int ONE = 1;
const int TWO = 2;
const int THREE = 3;
const int FINAL = 1000;
const int FINAL_ID = 1001;
const int FINAL_INT = 1002;
const int FINAL_OP = 1003;
const int FINAL_EOF = 1004;

const int FSA_TABLE[4][6] = {
      {TWO, ERROR_LET, THREE, ZERO, FINAL_EOF, ONE}, //row 1
      {FINAL_OP, FINAL_OP, FINAL_OP, FINAL_OP, FINAL_OP, FINAL_OP}, //row 2
      {TWO, TWO, TWO, FINAL_ID, FINAL_ID, FINAL_ID}, //row 3
      {ERROR_NUM, ERROR_NUM, THREE, FINAL_INT, FINAL_INT, FINAL_INT} //row 4
   };

int scanner(string& str, Token& token);
int getCol(char x);
void errorM(int errNum, string str);


#endif
