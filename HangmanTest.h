/**   @author Brad Arvin
      
      Unit tests for the hangman class
      */
      
#ifndef HANGMAN_TEST_H
#define HANGMAN_TEST_H

#include <Hangman.h>

#include <iostream>
#include <cxxtest/TestSuite.h>

using namespace std;

class HangmanTest : public CxxTest::TestSuite {
public:
  void testConstructor() {
    Hangman a = Hangman("apple");
    
    TS_ASSERT_EQUALS("_____", a.getShow());
    
    TS_ASSERT_EQUALS(a.getShow().length(), 5);
    
    TS_ASSERT_EQUALS(a.getMissedLetters(), "");
    
    TS_ASSERT_EQUALS(a.getMissesLeft(), 6);
    
    TS_ASSERT(!a.testWinner());
  }
  
  void testGuessLetter() {
    Hangman a = Hangman("apple");
    
    TS_ASSERT(a.guessLetter('a'));
    
    TS_ASSERT(!a.guessLetter('b')); 
    
    TS_ASSERT(a.guessLetter('p'));
    
    TS_ASSERT(!a.guessLetter('c'));
    
    TS_ASSERT(a.guessLetter('a'));
  }
  
  void testShow() {
    Hangman a = Hangman("apple"); 
    
    TS_ASSERT_EQUALS("_____", a.getShow());
    
    a.guessLetter('a');
    TS_ASSERT_EQUALS("a____", a.getShow());
    
    a.guessLetter('b');
    TS_ASSERT_EQUALS("a____", a.getShow());
    
    a.guessLetter('p');
    TS_ASSERT_EQUALS("app__", a.getShow());
    
    a.guessLetter('e');
    TS_ASSERT_EQUALS("app_e", a.getShow());
  }
  
  void testMissedLetters() {
    Hangman a = Hangman("apple");
    
    a.guessLetter('b');
    TS_ASSERT_EQUALS("b", a.getMissedLetters());
    
    a.guessLetter('c');
    TS_ASSERT_EQUALS("bc", a.getMissedLetters());
    
    a.guessLetter('d');
    TS_ASSERT_EQUALS("bcd", a.getMissedLetters());
  }
  
  void testMissesLeft() {
    Hangman a = Hangman("apple");
    TS_ASSERT_EQUALS(a.getMissesLeft(), 6);
    
    a.guessLetter('p');
    TS_ASSERT_EQUALS(a.getMissesLeft(), 6);
    
    for (int i = 0; i < 6; i++) {
      a.guessLetter('b');
      TS_ASSERT_EQUALS(a.getMissesLeft(), 6 - (i + 1));
    }
  } 
  
  void testTestWinner() {
    Hangman a = Hangman("app"); 

    TS_ASSERT(!a.testWinner()); 

    a.guessLetter('a');
    TS_ASSERT(!a.testWinner());

    a.guessLetter('p');
    TS_ASSERT(a.testWinner());
  }
};

#endif
