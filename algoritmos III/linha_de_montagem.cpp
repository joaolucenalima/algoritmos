#include <iostream>

using namespace std;

int chassis_exit_time[2] = {3, 2};

int stations_time[2][6] = {{7, 9, 3, 4, 8, 4}, {8, 5, 6, 4, 5, 7}};
int transitions_time[2][5] = {{2, 3, 1, 3, 4}, {2, 1, 2, 2, 1}};

int solutions[2][6];

int best_time = __INT_MAX__;

int fastest_way(int time, int i, int j) // Algoritmo base: recursão com backtracing
{
  if (j == 6)
  {
    if (time + chassis_exit_time[i] < best_time)
      best_time = time + chassis_exit_time[i];
    return time + chassis_exit_time[i];
  }

  int time1 = fastest_way(time + stations_time[i][j], i, j + 1);
  int time2 = fastest_way(time + transitions_time[i][j] + stations_time[i][j], 1 - i, j + 1);

  return min(time1, time2);
}

int main()
{
  fastest_way(2, 0, 0);
  fastest_way(4, 1, 0);

  cout << best_time << endl;
  return 0;
}