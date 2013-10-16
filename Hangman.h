/**   @author Brad Arvin
      
      Interface for the hangman class, this class represents a single
      game of hangman, based on the word passed in.
      */

#ifndef HANGMAN_H
#define HANGMAN_H

#include <string>
#include <vector>
using namespace std;

class Hangman {

public:
  Hangman(string playWord);
  bool guessLetter(char letter);
  string getPlayWord();
  string getShow();
  string getMissedLetters();
  int getMissesLeft();
  bool testWinner();
  
private:
  string playWord;
  string showWord;
  string missedLetters;
  int missesLeft;
  
};

#endif
