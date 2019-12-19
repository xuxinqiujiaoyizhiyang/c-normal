#include<iostream>
#include<stdlib.h>
#include<iomanip>

using namespace std;

void fun(int arr[], int n) {
	int c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i] <= arr[j]) {
				c = arr[i];
				arr[i] = arr[j];
				arr[j] = c;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}
void fun(double arr[], int n) {
	double c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i] <= arr[j]) {
				c = arr[i];
				arr[i] = arr[j];
				arr[j] = c;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << setiosflags(ios::fixed) << setprecision(2) << arr[i] << " ";
	}
}

	int    main()
	{
		char l;
		int N;


		cin >> l;

		cin >> N;
		if (l == 'i')
		{
			int *arr;
			arr = new int(N);

			for (int i = 0; i < N; i++)
			{
				cin >> arr[i];
			}
			fun(arr, N);
		}
		else if (l == 'd') {
			double *arr;
			arr = new double(N);

			for (int i = 0; i < N; i++)
			{
				cin >> arr[i];
			}
			fun(arr, N);
		}

	system("pause");
	return 0;
}