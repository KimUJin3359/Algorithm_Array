#include <iostream>

using namespace std;

int main()
{
	int num;
	int test_c;
	int max_v;
	int max_i;
	int score;
	int arr[101];

	cin >> num;
	//file input

	for (int i = 0; i < num; i++)
	{
		//initialize
		for (int i = 0; i < 101; i++)
			arr[i] = 0;
		//test case num
		cin >> test_c;
		//get frequency
		for (int j = 0; j < 1000; j++)
		{
			cin >> score;
			arr[score]++;
		}
		max_v = -1;
		//get frequency index
		for (int j = 0; j < 101; j++)
		{
			if (max_v <= arr[j])
			{
				max_v = arr[j];
				max_i = j;
			}
		}
		cout << "#" << test_c << " " << max_i << endl;
	}
}