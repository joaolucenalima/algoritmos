#include <iostream>
#include <cmath>

using namespace std;

int convertStringResult(string stringResult)
{
  int length = stringResult.length() - 1;

  int result = stringResult[length] - '0';

  for (int i = length - 1; i >= 0; i--)
  {
    int x = length - i;
    result += (stringResult[i] - '0') * (pow(10, x));
  }

  return result;
}

int myAtoi(string s)
{
  string::size_type cont = 0;
  bool isNegative = false;

  // removing first whitespaces
  s.erase(0, s.find_first_not_of(" "));

  if (s[0] == '-')
  {
    isNegative = true;
    cont = 1;
  }
  if (s[0] == '+')
  {
    cont = 1;
  }

  string stringResult;
  int result = 0;

  for (cont; cont < s.length(); cont++)
  {
    // is a number
    if (s[cont] + 0 > 47 && s[cont] + 0 < 58)
    {
      stringResult += s[cont];
    }
    else
    {
      break;
    }
  }

  if (stringResult.length() > 0)
  {
    result = convertStringResult(stringResult);
  }

  if (isNegative)
  {
    result *= (-1);
  }

  return result;
}

int main()
{
  string s = "4193";

  int result = myAtoi(s);
  cout << result << endl;

  return 0;
}