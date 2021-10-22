//main.cpp

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

#include "token.h"
#include "scanner.h"
#include "testScanner.h"

using namespace std;

int main(int argc, char* argv[]) {
   string fileName = argv[1];
   string fileExt = ".fs"; //for appending if file doesn't already have it

   if(argc > 2) {
      cout << "Too many arguments given" << endl;
      cout << "Ending" << endl;
      return -1;
   } 
   else if(argc == 1) {
      cout << "1 ARGUMENT" << endl;
      testScanner(cin);
   }
   else if(argc == 2) {
      cout << "Input file given" << endl;
      cout << endl;

      size_t index = fileName.find(".fs"); //searcher for proper extension

      if(index == string::npos) { //extension not found
         fileName += fileExt;
      }

      ifstream file(fileName.c_str());
      
      if(file) {
         testScanner(file);
      }  
   }

   return 0;
}
