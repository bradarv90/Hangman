/**   @author Brad Arvin
      
      Unit tests for the Dictionary class.
      */

#ifndef DICTIONARY_TEST_H
#define DICTIONARY_TEST_H

#include <Dictionary.h>

#include <iostream>
#include <cxxtest/TestSuite.h>

using namespace std;

class DictionaryTest : public CxxTest::TestSuite {
public:
  void testConstructor() {
    Dictionary a = Dictionary("wordswithfriends.txt", 0);
    int old = a.size();
    TS_ASSERT_LESS_THAN(0, old);
    
    for (int i = 0; i < 4; i++) {
      a = Dictionary("wordswithfriends.txt", 2 * i + 2);
      TS_ASSERT_LESS_THAN_EQUALS(a.size(), old);
      old = a.size();
    }
  }
  
  void testRandomWord() {  
  //p.s. yes I know this won't test every word in the Dictionary
  //but it will test a lot
  
    Dictionary a = Dictionary("wordswithfriends.txt", 4);
    string tester;
    for (int i = 0; i < a.size(); i++) {
      tester = a.randomWord();
      TS_ASSERT_LESS_THAN(3, tester.length());
    }
  }
  
  void testSize() {
    Dictionary a = Dictionary("wordswithfriends.txt", 0);
    int old = a.size();
    TS_ASSERT_LESS_THAN(0, old); 
    
    for (int i = 0; i < 20; i++) {
      a = Dictionary("wordswithfriends.txt", i);
      TS_ASSERT_LESS_THAN_EQUALS(a.size(), old);
      old = a.size();
    }
  }
};
  
#endif
