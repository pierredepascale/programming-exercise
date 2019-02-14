//#include <unordered_map>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> neighbours(int position) {
  switch (position) {
  case 0: return { 4, 6 } ;
  case 1: return { 6, 8 } ;
  case 2: return { 7, 9 } ;
  case 3: return { 8, 4 } ;
  case 4: return { 3, 9, 0 } ;
  case 5: return { } ;
  case 6: return { 7, 1, 0 } ;
  case 7: return { 2, 6 } ;
  case 8: return { 1, 3 } ;
  case 9: return { 2, 4 } ;
  }
  throw "expected value position in neibours" ;
}

map<pair<int,int>, int> cache ;

int count_phone_numbers(int n, int position) {
  cout << "count_phone_numbesr(" << n << "," << position << ")" << endl ;
  auto entry = cache.find(pair<int,int>(n, position)) ;
  if (entry != cache.end())
    return entry->second ;

  cout << "entry not found in cache. Computing..." << endl ;
  if (n == 1)
    return 1 ;
  else {
    int count = 1 ;
    
    for (auto next_position : neighbours(position))
      count += count_phone_numbers(n-1, next_position) ;

    cache[pair<int,int>(n, position)] = count ;
    return count ;
  }
}

int main(int ac, char *av[]) {
  cout << "phone position 1: " << count_phone_numbers(1, 5) << endl ;
  cout << "phone count 2: " << count_phone_numbers(2, 1) << endl ;
  cout << "phone count 2: " << count_phone_numbers(2, 7) << endl ;
}
