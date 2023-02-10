#include<iostream>

using namespace std;

// i got the half of the solution 
// i skatched on paper

int main()
{
  int n;
  cin >> n;
  int numbers[n], freqs[151] = {0};

  for (int i = 0; i < n; i++)
  {
    cin >> numbers[i];
    freqs[numbers[i]]++;
  }

  int max_repeat = 0, max_pos;
  for (int i = 0; i < n; i++)
  {
    if (freqs[numbers[i]] > max_repeat)
    {
      max_repeat = freqs[numbers[i]];
      max_pos = numbers[i];
    }
  }
  cout << max_pos << " repeated " << max_repeat << " times" << endl;
}
