#include<iostream>

using namespace std;

int main()
{
  int const N = 201;
  int n, numbers[N], value, values[771] = {0};

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> value;
    value += 500;
    values[value]++;


    // another solution using if statment to check sign
    // if (value < 0)
    // {
    //   value = (value * -1) + 270;
    //   values[value]++;
    // }
    // else
    // {
    //   values[value]++;
    // }
  }

  int max_repeat = 0;
  for (int i = 0; i < 771; i++)
  {
    if (values[i] > values[max_repeat])
    {
      max_repeat = i;
    }
  }
  
  // if (max_number > 270)
  // {
  //   max_number = (max_number - 270) * -1;
  // }

  cout << max_repeat - 500 << " repeated " << values[max_repeat] << " times: the largest" << endl;
  return 0;
}
