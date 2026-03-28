#include<iostream>
using namespace std;

void QuickSort(int arr[], int low, int high){
	if(low >= high){
		return;
	}

	int s = low;
	int e = high;
	int m = s + (e - s) / 2;	// 0, 6
								// {3, -2, 4, [0], 1, 4, 5}
	int pivot = arr[m];
	
	while(s <= e){
		while(arr[s] < pivot){
			s++;
		}

		while(arr[e] > pivot){
			e--;
		}

		if(s <= e){
			swap(arr[s], arr[e]);
			s++;
			e--;
		}
	}
	QuickSort(arr, low, e);
	QuickSort(arr, s, high);

}

int main(){

	int arr[] = {3, -2, 4, 0, 1, 4, 5};

	for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	QuickSort(arr, 0, 6);

	for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
		cout<<arr[i]<<" ";
	}

	return 0;
}