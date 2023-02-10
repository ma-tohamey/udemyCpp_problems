#include<iostream>

using namespace std;

int main()
{
  int const N = 200;
  int n, q, numbers[N], queries[501] = {0}, querie;

  for (int i = 0; i < 501; i++)
  {
    queries[i] = -1;
  }

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> numbers[i];
    queries[numbers[i]] = i;
  }

  cin >> q;
  for (int i = 0; i < q; i++)
  {
    cin >> querie;
    cout << queries[querie] << " ";
  }
  cout << endl;
}
