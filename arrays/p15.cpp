#include <iostream>

using namespace std;

int main() 
{
  int n, numbers[201 * 10] = {0}, result, last_value = 0;

  cin >> n;

  for (int i = 0; i < n; i++)
  {

    // sub_operation
    result = last_value - i - 1;
    if (result > 0 && !numbers[result])
    {
      last_value = result;
      numbers[last_value] = 1;
      continue;
    }

    // addition operation
    last_value = last_value + i + 1;
    numbers[last_value] = 1;

  }
  cout << last_value << endl;
  return 0;
}
