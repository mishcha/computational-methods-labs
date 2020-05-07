#include<iostream>
using namespace std;

int main()
{
	const int HEIGHT = 4;
	const int WIDTH = 4;
	float arr[HEIGHT][WIDTH] = { {8.3, 2.62 , 4.1, 1.9 }, 
	                           {3.92, 8.45 , 8.78, 2.46 }, 
	                           {3.77, 7.21, 8.04, 2.28}, 
	                           {2.21, 3.65, 1.69, 6.99} };

	bool flag = true;

	for (int i = 0; i < HEIGHT; ++i)
	{
		for (int j = 0; j < WIDTH; ++j)
			cout << arr[i][j];
		cout << endl;
	}

	for (int i = 1; i < HEIGHT - 1; ++i)
		for (int j = 1; j < WIDTH - 1; ++j)
			if (arr[i][j] != arr[j][i])
				flag = false;

	cout << (flag ? "Matrix is symmetric" : "Not symmetric");
	cout << endl << endl;

	system("pause");
}