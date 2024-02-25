#include <iostream>

using namespace std;

struct Gladiator
{
  string name;
  int strength;
  int ability;
  int age;
};

bool fight(Gladiator g1, Gladiator g2) // RAM: 16N + 2 & ASSINTÓTICA: O(N)
{
  int g1_life, g2_life = 100; // 2

  while (true) // 16N
  {
    g2_life -= g1.strength + (2 * g1.ability);
    if (g2_life <= 0)
    {
      return 1;
    }

    g1_life -= g2.strength + (2 * g2.ability);
    if (g1_life <= 0)
    {
      return 0;
    }
  }
}

int main() // RAM: 16N² + 23N + 50 & ASSINTÓTICA: O(N²)
{
  Gladiator gladiators[5];

  cout << "Cadastre seus gladiadores: " << endl;

  for (int i = 0; i < 5; i++) // (2 * 5) + (3 * 5) = 25 + 25 = 50
  {
    cout << "Nome: ";
    getline(cin >> ws, gladiators[i].name); // 2 * 5
    cout << "Força: ";
    cin >> gladiators[i].strength; // 1 * 5
    cout << "Habilidade: ";
    cin >> gladiators[i].ability; // 1 * 5
    cout << "Idade: ";
    cin >> gladiators[i].age; // 1 * 5
  }

  while (true) // RAM: (23 + 16N)N & ASSINTÓTICA: O(N)
  {
    int g1, g2;

    cin >> g1;    // 1
    if (g1 == -1) // 2
    {
      break;
    }

    cin >> g2;    // 1
    if (g2 == -1) // 2
    {
      break;
    }

    if (fight(gladiators[g1], gladiators[g2]) == 1) // 5 + (16N + 2)
    {
      cout << gladiators[g1].name << " ganhou a batalha contra " << gladiators[g2].name << endl; // 4
    }
    else
    {
      cout << gladiators[g2].name << " ganhou a batalha contra " << gladiators[g1].name << endl; // 4
    }
  }

  return 0;
}