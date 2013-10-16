/**   @author Brad Arvin
      
      Implementation of the dictionary class.
      */


#include <Dictionary.h>

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
// Needed for random
#include <time.h>
#include <cstdlib>
#include <stdlib.h>  

using namespace std;

Dictionary::Dictionary(string fileName, unsigned int minLength) {
  ifstream wordsFile;
  wordsFile.open(fileName.c_str());
  
  string curWord;
  while(wordsFile >> curWord) {
    if(curWord.length() >= minLength) {
      words.push_back(curWord);
    }
  }
  
  wordsFile.close();
}

string Dictionary::randomWord() {
  return words[rand() % words.size()]; 
}

int Dictionary::size() {
  return words.size();
}
