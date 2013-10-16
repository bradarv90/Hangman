/**   @author Brad Arvin
      
      Interaface for the Dictionary class that can load a text file
      and store the words in a vector for generation of a random word.
      */

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
using namespace std;

class Dictionary {
public:
  Dictionary(string fileName, unsigned int minLength);
  string randomWord();
  int size();
private:
  vector<string> words;
};

#endif
