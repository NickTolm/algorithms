#include <iostream>

using namespace std;
//Сортировка слиянием
void merge_sort(int *array, int l, int r){ 
	
		if (l == r) return; 
	
		int mid = (l + r) / 2; 
	
		merge_sort(array, l, mid); 
		merge_sort(array, mid + 1, r);
	
		int i = l; 
		int j = mid + 1; 
		int *tmp = new int[r*sizeof(int)];
		for (int step = 0; step < r - l + 1; step++){ 
			if ((j>r) || ((i <= mid) && (array[i] < array[j]))){
				tmp[step] = array[i];
				i++;
			}
			else{
				tmp[step] = array[j];
				j++;
			}
		}
		for (int step = 0; step < r - l + 1; step++) 
			array[l + step] = tmp[step];
	}
//Сортировка вставками
void InsertionSort(int *array, int len){ 
	
		int temp,  
			item; 
	
		for (int counter = 1; counter < len; counter++){
			temp = array[counter]; 
			item = counter - 1; 
			while (item >= 0 && array[item]>temp){ 
				array[item + 1] = array[item]; 
				array[item] = temp;
				item--;
			}
		}
	}
//Сортировка выбором
void Selection_Sort(int *array, int len){ 
		
	for (int repeat_counter = 0; repeat_counter < len; repeat_counter++){ 
				int temp = array[0]; 
		for (int element_counter = repeat_counter + 1; element_counter < len; element_counter++){ 
			if (array[repeat_counter]>array[element_counter]){  
						temp = array[repeat_counter];
						array[repeat_counter] = array[element_counter];
						array[element_counter] = temp;
			}
		}
	}
}
//Пузырьковая сортировка
void bubble_sort(int *array, int len){

	for (int i = 0; i < len; i++){
		for (int k = 0; k <len - i-1; k++){
			if (Arr[k]>Arr[k + 1]){
				int buf = Arr[k];
				Arr[k] = Arr[k + 1];
				Arr[k + 1] = buf;
			}
		}
	}
}
//Быстрая сортировка
void quicksort(int *arr, int start, int end){

	int comp, i, j, k;
	comp = arr[(start + end)] / 2; 
	i = start;
	j = end;


	do{
		while ((arr[i]<comp) && (i<end)) i++;  
		while ((comp<arr[j]) && (j>start)) j--; 

		if (i <= j){
			k = arr[i];
			arr[i] = arr[j];
			arr[j] = k;
			i++;
			j--;
		}
	} while (i <= j); 

	if (start<j) quicksort(arr, start, j);
	if (i<end) quicksort(arr, i, end);


}

int main(){

	int N;
	cin >> N;

	int *a = new int[N];

	for (int i = 0; i<N; i++){
		cin >> a[i];
	}


	cout << endl;

	InsertionSort(a, 0, N-1);
	quicksort(a,0,N-1);

	for (int i = 0; i<N; i++){
		cout << a[i];
	}


	system("pause");
	return 0;
}