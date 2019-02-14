// reverse a string inplace

#include <string>
#include <iostream>

using namespace std;

string reverse(string str) {
  string result = "" ;

  for(int index = str.size()-1 ; index >= 0 ; index--)
    result += str[index] ;

  return result ;
}

int main(int ac, char *av[]) {
  cout << "The reverse of 'hello' is " << reverse("hello") << endl ;
  cout << "The reverse of 'hellow' is " << reverse("hellow") << endl ;
  cout << "The reverse of '' is " << reverse("") << endl ;
  cout << "The reverse of '1' is " << reverse("1") << endl ;
}
