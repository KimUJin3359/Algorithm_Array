#include <iostream>

using namespace std;

int solve_problem(int size, int *arr);
int get_max(int a, int b, int c, int d);

int main()
{
	int size = 1000;
	int arr[1000];

	//file input
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < size; j++)
			arr[j] = 0;
		cin >> size;
		for (int j = 0; j < size; j++)
			cin >> arr[j];
		//solve the problem
		cout << "#" << (i + 1) << " " << solve_problem(size, arr) << endl;
	}
}

int solve_problem(int size, int *arr)
{
	int res = 0;
	unsigned char max;

	for (int i = 2; i < size - 2; i++)
	{
		max = get_max(arr[i - 2], arr[i - 1], arr[i + 1], arr[i + 2]);
		if (arr[i] - max > 0)
			res += arr[i] - max;
	}
	return (res);
}

int get_max(int a, int b, int c, int d)
{
	if (a > b)
	{
		if (a > c)
		{
			if (a > d)
				return (a);
			else
				return (d);
		}
		else
		{
			if (c > d)
				return (c);
			else
				return (d);
		}
	}
	else
	{
		if (b > c)
		{
			if (b > d)
				return (b);
			else
				return (d);
		}
		else
		{
			if (c > d)
				return (c);
			else
				return (d);
		}
	}
}