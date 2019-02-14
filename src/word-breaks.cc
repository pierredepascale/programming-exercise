// word breaks
#include <string>
#include <set>
#include <iostream>

using namespace std;

set<string> dict = { "pie", "apple" } ;

string word_breaks(const string &input) {
  int start = 0 ;
  int index = 0 ;
  string result = "" ;
  
  while (index <= input.length()) {
    string word = input.substr(start, index-start) ;
    if (dict.find(word) != dict.end()) {
      if (start == 0)
        result += word ;
      else
        result += " " + word ;
      start = index ;
    }
    index++ ;
  }

  if (start == 0)
    return "<not found>" ;
  else {
    if (dict.find(input.substr(start, index-start)) != dict.end()) {
      result += " " + input.substr(start, index-start) ;
    }
    return result ;
  }
}

int main(int ac, char *av[]) {
  cout << "word breaks 'applepie' => " << word_breaks("applepie") << endl ;
  cout << "word breaks 'apple' => " << word_breaks("apple") << endl ;
  cout << "word breaks 'appleapplepiepie' => " <<
    word_breaks("appleapplepiepie") << endl ;
  cout << "word breaks '' => " << word_breaks("") << endl ;
}
