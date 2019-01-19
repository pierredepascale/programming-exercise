// string permutation

#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

typedef map<char,int> count_table ;

// returns a mapping table counting how many time the characters of str occurs
count_table compute_character_counts(string str) {
  count_table table ;

  for(int index = 0 ; index < str.size() ; index++) {
    auto entry = table.find(str[index]) ;
    if (entry == table.end()) {
      table.insert(pair<char,int>(str[index], 1)) ;
    } else {
      table[str[index]] = entry->second+1 ;
    }
  }

  return table ;
}

// Verify if str1 is a permutation of str2
bool check_permutation(string str1, string str2) {
  if (str1.size() != str2.size())
    return false ;
  
  count_table table = compute_character_counts(str2) ;

  for (int index = 0; index < str1.size() ; index++) {
    auto count = table.find(str1[index]) ;
    if (count == table.end()) {
      return false ;
    } else if (count->second > 0) {
      table[str1[index]] = count->second-1 ;
    } else {
      return false ;
    }
  }

  return true ;
}

int main(int ac, char *av[]) {
  cout << "test 1 ABC et CBA:" << check_permutation("ABC", "CBA") << endl ;
  cout << "test 2 AAA et AAB:" << check_permutation("AAA", "AAB") << endl ;
  cout << "test 3 AAA et A:" << check_permutation("AAA", "A") << endl ;
  cout << "test 4 ''  et '':" << check_permutation("", "") << endl ;
  cout << "test 5 ''  et ABC:" << check_permutation("", "ABC") << endl ;
  cout << "test 6 ABC et '':" << check_permutation("ABC", "") << endl ;
}




// "abc", "cba" => vrai
// "abc", "def" => faux
// "", "" => vrai

