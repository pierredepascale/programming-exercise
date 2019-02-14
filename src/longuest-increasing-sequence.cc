// finds the longuest increasing sequence in a vector
// formulation
// lis(n) = max(seq_at(n), lis(seq_after(n)))

#include <vector>
#include <iostream>

using namespace std;

// Testscase
// lis([1,2,3,1,1,2,1,2,3,4]) = 4
// list([]) = 0
// list([1]) = 1

int seq_at(const vector<int>& sequence, int start) {
  int last = sequence[start] ;
  int index = start+1 ;
  
  while(index < sequence.size() && sequence[index] >= last) {
    last = sequence[index] ;
    index++ ;
  }

  return index-start ;
}

int lis(const vector<int>& sequence, int start) {
  if (start < sequence.size()) {
    int len = seq_at(sequence, start) ;
    return max(len, lis(sequence, start+len)) ;
  } else {
    return 0 ;
  }
}

int main(int ac, char *av[]) {
  cout << "lis([1,2,3,1,1,2,1,2,3,4]) is "
       << lis({1,2,3,1,1,2,1,2,3,4}, 0) << endl ;
  cout << "lis([1]) is "
       << lis({1}, 0) << endl ;
  cout << "lis([]) is "
       << lis({}, 0) << endl ;
}
