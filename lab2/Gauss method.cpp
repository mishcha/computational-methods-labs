#include<iostream>
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<math.h>

using namespace std;

void Show(int, double*);
void PryamojHod(int, double**, double*);
void ObratnyHod(int, double**, double*, double*);

int main()
{
	int n;
	cout << "\nEnter number of variables: ";

	while (!(cin >> n) || (cin.peek() != '\n') || (n <= 0))
	{
		cin.clear();
		while (cin.get() != '\n');

		cout << "\n\a Error! press any key...";
		_getch();
		system("cls");
		cout << "\n Enter number of variables: ";
	}

	double** a = new double* [n];
	for (int i = 0; i < n; i++)
		a[i] = new double[n];
	double* b = new double[n];
	double* x = new double[n];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "Enter " << (j + 1) << " confficient of " << (i + 1) << " equation: ";

			while (!(cin >> a[i][j]) || (cin.peek() != '\n'))
			{
				cin.clear();

				while (cin.get() != '\n');
				cout << "\n Error!\n press any key...";
				_getch();
				system("cls");
				cout << "Enter " << (j + 1) << " coefficient of " << (i + 1) << " equation: ";
			}
		}

		cout << "Enter " << (i + 1) << " constant of " << (i + 1) << " equation: ";

		while (!(cin >> b[i]) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "\n Error!\n press any key...";
			_getch();
			system("cls");
			cout << "Enter " << (i + 1) << " constant of " << (i + 1) << " equation: ";
		}
	}

	cout << "\n Matrix A: " << endl;

	for (int i = 0; i < n; i++)
		Show(n, a[i]);

	cout << "\n Vector B: " << endl;
	Show(n, b);

	PryamojHod(n, a, b);
	ObratnyHod(n, a, b, x);

	cout << "\n Result: " << endl;
	Show(n, x);

	for (int i = 0; i < n; i++)
		delete[] a[i];

	delete[] a;
	delete[] b;
	delete[] x;

	system("pause");
	return 0;
}

void Show(int n, double* vec)
{
	for (int i = 0; i < n; i++)
		cout << "\t" << vec[i];

	cout << endl;
}

void PryamojHod(int n, double** a, double* b)
{
	double v = 0;

	for (int k(0), im; k < n; k++)
	{
		im = k;

		for (int i = k + 1; i < n; i++)
		{
			if (fabs(a[im][k]) < fabs(a[i][k]))
				im = i;
		}
		if (im != k)
		{
			for (int j(0); j < n; j++)
			{
				v = a[im][j];
				a[im][j] = a[k][j];
				a[k][j] = v;
			}
			v = b[im];
			b[im] = b[k];
			b[k] = v;
		}
		for (int i = k + 1; i < n; i++)
		{
			v = 1.0 * a[i][k] / a[k][k];
			a[i][k] = 0;
			b[i] = b[i] - v * b[k];

			if (v != 0)
			{
				for (int j = k + 1; j < n; j++)
					a[i][j] = a[i][j] - v * a[k][j];
			}
		}

	}
}

void ObratnyHod(int n, double** a, double* b, double* x)
{
	double s = 0;
	x[n - 1] = 1.0 * b[n - 1] / a[n - 1][n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		s = 0;
		for (int j = i + 1; j < n; j++)
			s = s + a[i][j] * x[j];

		x[i] = 1.0 * (b[i] - s) / a[i][i];
	}
}

