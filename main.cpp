/**   @author Brad Arvin
      
      Main function for hangman, plays as many games of hangman as the user wants, using the wordswithfriends.txt
      file as the dictionary of available words.
      */

#include <Hangman.h>
#include <Dictionary.h>

#include <iostream>

int main() {
  Dictionary myDic = Dictionary("wordswithfriends.txt", 4);
  
  cout << "Welcome to Hangman (beta). I've loaded " << myDic.size() << "words.\n";
  
  string choice = "y";
  
  while (choice == "y") {
    
    Hangman current = Hangman(myDic.randomWord());
    
    while (!current.testWinner() || current.getMissesLeft() != 0) {
      
      cout << "\nGuess: " << current.getShow() << " misses remaining: " << current.getMissesLeft() << " missed letters: " << current.getMissedLetters() << endl; 

      char inChar;
      cin >> inChar;

      current.guessLetter(inChar); //not sure if this will work
    }
    
    if(current.testWinner()) {
      cout << "You win! You guessed the word: " << current.getShow() << " with " << current.getMissesLeft() << " misses remaining.";
    } else {
      cout << "Sorry, you lose. The words was: " << current.getPlayWord();
    }
    
    cout << "\nPlay again? (Y/n)?";
    cin >> choice;
  }
  
  return 0;  
}
