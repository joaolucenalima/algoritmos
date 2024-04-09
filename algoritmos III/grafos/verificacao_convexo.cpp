#include <iostream>
#include <list>

using namespace std;

int main()
{
    int vertices;
    cin >> vertices;

    int vertice_inicial;
    cin >> vertice_inicial;

    int matriz[vertices][vertices];

    int i, j;

    // inicializando elementos da matriz com 0
    for (i = 0; i < vertices; i++)
        for (j = 0; j < vertices; j++)
            matriz[i][j] = 0;

    // preenchendo as arestas
    while (i != -1 && j != -1)
    {
        cin >> i >> j;
        matriz[i][j] = 1;
        matriz[j][i] = 1;
    }

    // bfs
    list<int> fila;
    bool visitados[vertices];

    fila.push_back(0);
    visitados[vertice_inicial] = true;

    while (!fila.empty())
    {
        int cidade_a_verificar = fila.front();
        fila.pop_front();

        for (j = 0; j < vertices; j++)
            if (matriz[cidade_a_verificar][j] == 1 && !visitados[j])
            {
                visitados[j] = true;
                fila.push_back(j);
            }
    }

    bool conexo = true;
    for (i = 0; i < vertices; i++)
        if (!visitados[i])
        {
            conexo = false;
            break;
        }

    if (conexo)
        cout << "Conexo" << endl;
    else
        cout << "Desconexo" << endl;

    return 0;
}