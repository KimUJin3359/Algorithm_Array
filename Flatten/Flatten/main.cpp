#include <iostream>

using namespace std;

int solve_problem(int num, int sum, int arr[100]);
int judge_flat(int sum, int arr[100]);

int main()
{
	int num;
	int sum;
	int arr[100];

	//file input
	for (int i = 0; i < 10; i++)
	{
		sum = 0;
		cin >> num;
		for (int j = 0; j < 100; j++)
		{
			cin >> arr[j];
			sum += arr[j];
		}
		//solve the problem
		cout << "#" << (i + 1) << " " << solve_problem(num, sum, arr) << endl;
	}
}

int solve_problem(int num, int sum, int arr[100])
{
	int min_v, min_i;	//min_value, min_index
	int max_v, max_i;	//max_value, max_index
	while (num)
	{
		if (judge_flat(sum, arr))
			break;
		min_v = 987654321;
		max_v = -1;
		for (int i = 0; i < 100; i++)
		{
			if (min_v > arr[i])
			{
				min_v = arr[i];
				min_i = i;
			}
			if (max_v < arr[i])
			{
				max_v = arr[i];
				max_i = i;
			}
		}
		arr[min_i]++;
		arr[max_i]--;
		num--;
	}
	min_v = 987654321;
	max_v = -1;
	for (int i = 0; i < 100; i++)
	{
		if (min_v > arr[i])
		{
			min_v = arr[i];
			min_i = i;
		}
		if (max_v < arr[i])
		{
			max_v = arr[i];
			max_i = i;
		}
	}
	return(arr[max_i] - arr[min_i]);
}

int judge_flat(int sum, int arr[100]) {
	int div;
	int mod;
	int i;

	div = sum / 100;
	mod = sum % 100;

	if (mod == 0)
	{
		for (i = 0; i < 100; i++)
		{
			if (arr[i] != div)
				break;
		}
	}
	else {
		for (i = 0; i < 100; i++)
		{
			if (arr[i] != div && arr[i] != (div + 1))
				break;
		}
	}
	if (i == 100)
		return (1);
	else
		return (0);
}
