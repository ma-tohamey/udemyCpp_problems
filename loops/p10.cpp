#include<iostream>

using namespace std;

int main()
{
  int words_num;
  string word;
  cin >> words_num;

  while (words_num > 0)
  {
    cin >> word;
    if (word == "no" || word == "No" || word == "NO" || word == "nO}"
        || word == "on" || word == "ON" || word == "On" || word == "oN")
    {
      cout << word << " ";
    }
    words_num--;
  }
  cout << endl;
}
