#include <iostream>
#include <windows.h>
#include <iomanip>
#include <ctime>

using namespace std;

void Array2D(int a[10][10])
{
	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			a[i][j] = rand() % 21 - 10;
		}
	}
}

void Print2D(int a[10][10])
{
	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int MaxElem(int a[10][10], int max[10], int method = 1)
{
	int s = 0;
	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			s += a[i][j];
		}
		max[i] = s;
		s = 0;
	}
	if (method == 1)
	{
		for (size_t i = 0; i < 10; i++)
			if (s < max[i])
				s = max[i];
		return s;
	}
	else if (method == 0)
	{
		for (size_t i = 0; i < 10; i++)
			if (s > max[i])
				s = max[i];
		return s;
	}
	else
		return 10101010;
}

int main()
{
	srand(time(NULL));
    int arr[10][10];
	int max[10];
	Array2D(arr);
	Print2D(arr);
	int s;
	cout << "Enter 1 for max elem or 0 for minimum" << endl;
	cin >> s;
	if (s == 0 || s == 1)
		cout << "Max or min: " << MaxElem(arr, max, s) << endl;
	else
		cout << "Invalid number." << endl;
}