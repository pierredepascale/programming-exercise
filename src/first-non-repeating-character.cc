// first non-repeating character

#include <vector>
#include <map>
#include <string>
#include <iostream>

using namespace std;

struct stat {
  char ch ;
  int count ;
} ;

void first_non_repeating_char(const string &input) {
  vector<stat> char_seen ;
  int index ;
  
  for (int i = 0 ; i < input.length() ; i++) {
    char ch = input[i] ;

    // find char in table
    for (index = 0 ; index < char_seen.size() ; index++) {
      if (char_seen[index].ch == ch) {
        char_seen[index].count++ ;
        break ;
      }
    }
    if (index == char_seen.size()) {
      char_seen.push_back({ ch, 1 }) ;
    }
  }
  
  for (index = 0 ; index < char_seen.size() ; index++) {
    if (char_seen[index].count == 1) {
      cout << "character is '" << char_seen[index].ch << "'" << endl ;
      break ;
    }
  }
  
  if (index == char_seen.size())
    cout << "unexpected: all characters repeat at least once" << endl ;
}

int main(int ac, char *av[]) {
  cout << "test aabcbcdeef => " ;
  first_non_repeating_char("aabcbcdeef") ;
}
