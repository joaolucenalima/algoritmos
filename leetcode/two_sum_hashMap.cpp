#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  unordered_map<int, int> numbers;
  int complement;

  for (int i = 0; i < nums.size(); i++)
  {
    complement = target - nums[i];

    if (numbers.count(complement) > 0)
    {
      cout << "[" << i << "," << numbers[complement] << "]" << endl;
    }

    numbers[nums[i]] = i;
  }

  return 0;
}