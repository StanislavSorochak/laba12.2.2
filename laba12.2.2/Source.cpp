#include <iostream>
#include <Windows.h>

using namespace std;

typedef int inform;

struct Spusok
{
	Spusok* link1;
	inform inf;
};

int Creata(Spusok*& first, Spusok*& last, int index, int N);
int COUT(Spusok*& T, inform inf, int N, int index);
int Process(Spusok*& T, int x, inform inf);

int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Spusok* first = NULL;
	Spusok* last = NULL;
	Spusok* T;

	int index = 0, N = 4;
	Creata(first, last, index, N);

	T = first;
	cout << "���� ���������� ��� ����� ����������� �������: " << endl << endl;
	COUT(T, 0, N, index);
	cout << endl << endl;

	int x;
	cout << "������ ����� ��������, ��� ��������� �������� �������������� ���� ������� ��������: ";
	cin >> x;

	T = first;
	cout << endl;
	cout << "���� ���������� ��� ����� ������������� ������� " << endl << endl;
	Process(T, x, 0);
	cout << endl;

	return 0;
}

int Creata(Spusok*& first, Spusok*& last, int index, int N)
{
	Spusok* tmp = new Spusok;

	tmp->inf = index;
	tmp->link1 = NULL;
	if (first == NULL)
		first = tmp;
	else
		last->link1 = tmp;
	last = tmp;

	if (index < N - 1)
		return Creata(first, last, index + 1, N);
	else
		return 0;
}

int COUT(Spusok*& T, inform inf, int N, int index)
{
	if (T != NULL)
	{
		inf = T->inf;
		cout << inf << "   ";
	}

	if (T != NULL)
		return COUT(T->link1, inf, N, index + 1);
	else
		return 0;
}

int Process(Spusok*& T, int x, inform inf)
{
	if (T != NULL)
	{
		inf = T->inf;                         // 1(���������� ��������� �������� �������� � ������ � ����� 'inf')
		T->inf = inf + x;                     // 2(����� ������������� ��������(�������� �� 'x') � ������� ������)
		cout << T->inf << "   ";
	}
	if (T != NULL)
		return Process(T->link1, x, inf);      // 3(������� ��������� �� �������� ������� ��� ��������� �������� � ��������� ��������)
	else
		return 0;
}
