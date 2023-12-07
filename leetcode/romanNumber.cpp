#include <iostream>
#include <map>

using namespace std;

int main()
{
  map<char, int> roman_nums;
  string s = "XVII";

  int intNumber = 0;

  roman_nums['I'] = 1;
  roman_nums['V'] = 5;
  roman_nums['X'] = 10;
  roman_nums['L'] = 50;
  roman_nums['C'] = 100;
  roman_nums['D'] = 500;
  roman_nums['M'] = 1000;

  cout << roman_nums[s[0]] << endl;

  for (int i = s.length() - 1; i >= 0; i--)
  {
    if (roman_nums[s[i]] < roman_nums[s[i - 1]])
    {
      intNumber -= (roman_nums[s[i]] + roman_nums[s[i - 1]]);
    }
    else
    {
      intNumber += roman_nums[s[i]] + roman_nums[s[i - 1]];
    }
  }

  cout << intNumber << endl;

  return 0;
}
