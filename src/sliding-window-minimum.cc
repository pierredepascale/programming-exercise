// sliding window minimum

#include <vector>
#include <iostream>

using namespace std ;

int minimum_of_k(const vector<int> list, int start, int len) {
  int minimum_value = list[start];
  
  for (int i = start+1 ; i < start+len ; i++) {
    if (list[i] < minimum_value)
      minimum_value = list[i] ;
  }

  return minimum_value ;
}

void sliding_window_minimum(const vector<int> &list, int k) {
  vector<int> result ;
  
  for (int i = 0 ; i < list.size() - k+1 ; i++) {
    cout << " " << minimum_of_k(list, i, k) ;
  }
}

int main(int ac, char *av[]) {
  cout << "swm { 4,3,2,1,5,7,6,8,9 } =" ;
  sliding_window_minimum({4,3,2,1,5,7,6,8,9}, 3) ;
}
