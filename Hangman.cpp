/**   @author Brad Arvin
      
      Implementation of the hangman class.
  */

#include <Hangman.h>

#include <string>
#include <iostream>

using namespace std;

Hangman::Hangman(string playWord) {
  this->playWord = playWord;
  this->showWord.append<int>(playWord.length(), 0x5f); 
  this->missedLetters = "";
  this->missesLeft = 6;
}

bool Hangman::guessLetter(char letter) {
  bool found = false;
  
  for (unsigned int i = 0; i < playWord.length(); i++) {
    if (playWord[i] == letter) {
      found = true;
      showWord[i] = letter;
    }
  }
  
  if (!found) {
    missedLetters += letter;
    missesLeft--;
  }

  return found;
}

string Hangman::getPlayWord() {
  return playWord;
}

string Hangman::getShow() {
  return showWord;
}

string Hangman::getMissedLetters() {
  return missedLetters;
}

int Hangman::getMissesLeft() {
  return missesLeft;
}

bool Hangman::testWinner() {
  for (unsigned int i = 0; i < playWord.length(); i++) {
    if (showWord[i] == 0x5f) return false;
  }
  
  if (missesLeft == 0) return false;
  
  return true;
}
