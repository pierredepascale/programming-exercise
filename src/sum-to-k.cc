// find two numbers in the list that sum to K
#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;

const int K=10 ;

void sum_to_k(const vector<int> &seq, int k)
{
  unordered_set<int> seen ;

  for (auto number : seq) {
    int complement = k - number ;
    
    if (seen.find(complement) != seen.end()) {
      cout << "found with " << number << endl ;
    }
    seen.insert(number) ; 
  }
}

int main(int ac, char *av[]) {
  sum_to_k({ 1,2,3,4,5,6,7,8,9 }, K) ;
}
