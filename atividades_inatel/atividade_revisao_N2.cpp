/*
	Esses sitema tem o objetivo de registar dados de alunos em uma tabela hash.
	O processo de cadastro de alunos e o seguinte:
		1 - Primeiro os dados do aluno sao informados pelo usuario;
		2 - Em seguida, o aluno entra na fila de matriculas;
		3 - Assim que a fila e processada, os alunos sao registrados na tabela.
		Obs.: A tabela tem um limite de matriculas e os demais alunos que nao puderem ser registrados devem permanecer na fila.
	O processo de exclusao de alunos e o seguinte:
		1 - O aluno e buscado na tabela e inserido em uma pilha de analises;
		2 - Quando o conselho analisa a pilha, os alunos sao excluidos da tabela.
		Obs.: O conselho so processa 5 alunos da pilha por vez.
	Os usuarios podem ainda gerar listas de alunos ativos por curso e buscar os dados de um aluno pela matricula.
*/

#include <iostream>
#include <list>
#include <locale.h>

#define MAX_CURSOS 7
#define MAX_PROCESSOS_CONSELHO 5

using namespace std;

const string SIGLAS_CURSOS[MAX_CURSOS] = {"GEC", "GES", "GEB", "GET", "GEE", "GEP", "GEA"};

struct Aluno
{
	int matricula;
	string nome;
	int curso;
	int status;
};

int hash_aux(int k, int m)
{
	return k % m;
}

int hash_aux2(int k, int m)
{
	return 1 + (k % (m - 1));
}

int hash_duplo(int k, int m, int i)
{
	return (hash_aux(k, m) + i * hash_aux2(k, m)) % m;
}

int insere_aluno(Aluno tabela_hash[], int m, Aluno aluno)
{
	int pos, i = 0;
	while (i < m)
	{
		pos = hash_duplo(aluno.matricula, m, i);
		if (tabela_hash[pos].status != 1)
		{
			tabela_hash[pos] = aluno;
			tabela_hash[pos].status = 1;
			return pos;
		}
		i++;
	}
	return -1;
}

void lista_cursos()
{
	cout << "Cursos disponiveis: " << 0 << ": " << SIGLAS_CURSOS[0];
	for (int i = 1; i < MAX_CURSOS; i++)
	{
		cout << ", " << i << ": " << SIGLAS_CURSOS[i];
	}
	cout << endl;
}

int solicita_curso()
{
	int curso;
	lista_cursos();
	while (true)
	{
		cout << "Digite o curso (0 a " << MAX_CURSOS - 1 << "): ";
		cin >> curso;
		if (curso < 0 || curso >= MAX_CURSOS)
			cout << "Curso invalido." << endl;
		else
			return curso;
	}
	return -1;
}

Aluno novo_aluno()
{
	Aluno novo;
	cout << "Digite a matricula do aluno: ";
	cin >> novo.matricula;
	cin.ignore();
	cout << "Digite o nome do aluno: ";
	getline(cin, novo.nome);

	novo.curso = solicita_curso();
	return novo;
}

void exibe_aluno(Aluno a)
{
	cout << endl
			 << "Informacoes do aluno:" << endl;
	cout << "Nome: " << a.nome << endl;
	cout << "Matricula: " << a.matricula << endl;
	cout << "Curso: " << SIGLAS_CURSOS[a.curso] << endl;
}

void lista_alunos_curso(Aluno tabela_hash[], int m, int curso)
{
	for (int i = 0; i < m; i++)
	{
		cout << "Posicao " << i << ": ";
		if (tabela_hash[i].status == 1 && tabela_hash[i].curso == curso)
		{
			exibe_aluno(tabela_hash[i]);
		}
		else if (tabela_hash[i].status == 2)
			cout << "Aluno removido.";
		else
			cout << "Matricula disponivel.";
		cout << endl;
	}
}

void remover_aluno(Aluno tabela_hash[], int m, int matricula)
{
	int colisoes = 0;

	do
	{
		int pos = hash_duplo(matricula, m, colisoes);

		if (tabela_hash[pos].matricula == matricula)
		{
			tabela_hash[pos].status = 2;
			break;
		}
		else
		{
			colisoes++;
		}
	} while (colisoes < m);
}

int buscar_aluno(Aluno tabela_hash[], int m, int matricula)
{
	int colisoes = 0;

	do
	{
		int pos = hash_duplo(matricula, m, colisoes);

		if (tabela_hash[pos].matricula == matricula)
		{
			return pos;
		}
		else
		{
			colisoes++;
		}

	} while (colisoes != m);

	return -1;
}

int menu()
{
	int op;
	cout << "\t\t\tMenu\n";
	cout << "\t1:\tInserir aluno na fila de matricula.\n";
	cout << "\t2:\tBuscar aluno\n";
	cout << "\t3:\tListar alunos ativos do curso.\n";
	cout << "\t4:\tInserir aluno na pilha de remocao.\n";
	cout << "\t5:\tProcessar fila de matriculas.\n";
	cout << "\t6:\tEnviar alunos excluidos para analise do conselho.\n";
	cout << "\t-1:\tSair\n";
	cin >> op;
	return op;
}

int main()
{
	setlocale(LC_ALL, "");
	cout << "Bem-vindo(a) ao sistema de cadastro de alunos!\n\n";

	list<Aluno> fila;
	list<Aluno> pilha;

	int m = 10;
	Aluno tabela_hash[m];

	for (int i = 0; i < m; i++)
	{
		tabela_hash[i].matricula = -1;
		tabela_hash[i].status = 0;
	}
	int op = 0;
	while (op != -1)
	{
		op = menu();
		switch (op)
		{
		case 1:
		{
			// Inserir aluno na fila - OK
			Aluno novo = novo_aluno();

			fila.push_back(novo);

			break;
		}
		case 2:
		{
			// Buscar aluno pela matricula - OK
			int matricula;
			cout << "Informe a matricula para buscar: ";
			cin >> matricula;
			int pos = buscar_aluno(tabela_hash, m, matricula);
			if (pos != -1)
			{
				Aluno buscado = tabela_hash[pos];
				exibe_aluno(buscado);
			}
			else
			{
				cout << "Aluno nao encontrado" << endl;
			}
			break;
		}
		case 3:
		{
			// Listar alunos de um determinado curso - OK
			int curso = solicita_curso();
			lista_alunos_curso(tabela_hash, m, curso);
			break;
		}
		case 4:
		{
			// Remover aluno pela matricula - OK
			int matricula;
			cout << "Informa a matricula para remover: ";
			cin >> matricula;

			// Buscar aluno a ser removido - OK
			int pos = buscar_aluno(tabela_hash, m, matricula);
			if (pos != -1)
			{
				Aluno removido = tabela_hash[pos];
				// Adicionar aluno na pilha - OK
				pilha.push_back(removido);

				cout << "Aluno adicionado na pilha de remocao." << endl;
			}
			else
			{
				cout << "Aluno nao encontrado" << endl;
			}
			break;
		}
		case 5:
		{
			// Processar fila de matriculas - OK
			while (!fila.empty())
			{
				Aluno novo;

				// Seleciona um dos alunos a ser removido da fila - OK
				novo = fila.front();

				int pos = insere_aluno(tabela_hash, m, novo);
				if (pos != -1)
				{
					cout << tabela_hash[pos].nome << " inserido na posicao " << pos << endl;
					// Remove da fila - OK
					fila.pop_front();
				}
				else
				{
					cout << "Tabela cheia!";
					break;
				}
			}
			break;
		}
		case 6:
		{
			// Processa pilha de remocoes - OK
			int processos = 0;
			while (processos < MAX_PROCESSOS_CONSELHO && !pilha.empty())
			{
				Aluno removido = pilha.back();

				exibe_aluno(removido);

				char confirma = 'n';
				cout << "Tem certeza que quer remover o aluno acima? (s/n) ";
				cin >> confirma;
				if (confirma == 's')
				{
					// Remover da tabela - OK
					remover_aluno(tabela_hash, m, removido.matricula);
					cout << "Aluno removido." << endl;
				}
				else if (confirma == 'n')
				{
					cout << "Aluno desconsiderado na remocao." << endl;
				}
				else
				{
					cout << "Opcao invalida...";
					break;
				}
				// Remover da pilha - OK
				pilha.pop_back();
				processos++;
			}
			break;
		}
		case -1:
			break;
		default:
			cout << "Opcao invalida!" << endl
					 << endl;
			break;
		}
	}

	cout << "\n\nObrigado por utilizar o sistema de cadastro de alunos!\n";

	return 0;
}
