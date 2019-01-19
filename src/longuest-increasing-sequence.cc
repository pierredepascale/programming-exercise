// longuest increasing sequence

#include <vector>
#include <iostream>

using namespace std;

// formulation:
// lis(seq) = 1+max_of_i(
int lis(const vector<int> &seq, int start)
{
  int maximum_length = 1 ;

  for (int index = start+1 ; index < seq.size() ; index++)
    {
      if (seq[index] >= seq[start])
        {
          int sequence_length = 1 + lis(seq, index) ;
          
          if (sequence_length > maximum_length)
            maximum_length = sequence_length ;
        }
    }
  return maximum_length ;
}

// { 1,2,3,4 } => 4
// { 1,3,2,4 } => 3
// { } => 0

int main(int ac, char *av[])
{
  cout << "LIS 1,2,3,4 => " << lis({1,2,3,4}, 0) << endl ;
  cout << "LIS 1,3,2,4 => " << lis({1,3,2,4}, 0) << endl ;
  cout << "LIS {} => " << lis({}, 0) << endl ;
}
