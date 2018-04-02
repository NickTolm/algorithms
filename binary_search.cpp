#include <iostream>

using namespace std;

//Бинарный поиск
int binary_search(int *array, int l, int r, int srch){


	while (1){
		int mid = (l + r) / 2;
		if (srch < array[mid])
			r = mid - 1;
		else if (srch>array[mid])
			l = mid + 1;
		else
			return mid;

		if (l > r) return -1;

	}
}

int main(){

	int N, fnd;
	cin >> N >> fnd;
	int *a = new int[N];

	for (int i = 0; i < N; i++){
		cin >> a[i];
	}

	cout << binary_search(a, 0, N, fnd);

	delete[] a;
	system("pause");
	return 0;
}