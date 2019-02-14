// Computes all pairs in an array that sum to K

#include <vector>
#include <set>
#include <iostream>

using namespace std;

const int K = 10 ;

vector<pair<int,int>>
sum_to_k(const vector<int> &elements, int expected_sum) {
  set<int> cache ;
  vector<pair<int,int>> result ;
  
  for (auto number : elements) {
    if (cache.find(expected_sum-number) != cache.end()) {
      result.push_back(pair<int,int>(number, expected_sum-number)) ;
    }
    cache.insert(number) ;
  }
  return result ;
}

// Example
// [1,3,6,4,2,1,7] sum to 10 -> (3,7), (6,4)
int main(int ac, char *av[]) {
  vector<pair<int,int>> pairs = sum_to_k({1,3,6,4,2,1,7}, K) ;
  
  cout << "[1,3,6,4,2,1,7] sum to 10: " << endl ;
  for (auto p : pairs) {
    cout << p.first << "," << p.second << endl ;
  }
}

