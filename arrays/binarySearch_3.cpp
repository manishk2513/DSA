#include<iostream>
using namespace std;

int binarySearch(int *arr, int size, int target){
	int left = 0;
	int right = size - 1;

	while(left <= right){
		int mid = left + (right - left)/2;
		if(arr[mid] == target) return mid;

		if(target < arr[mid]){
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return -1;
}

int main(){

	int arr[] = {15, 18, 22, 38, 45, 59, 60, 67, 78, 91};
	int size = sizeof(arr) / sizeof(arr[0]);
	
	cout<<"array elements: "<<endl;
	for(int val : arr){
		cout<<val<<" ";
	}

	cout<<endl<<"enter target element: ";
	int target;
	cin>>target;

	cout<<endl<<"Target Element Index: ";
	cout<<binarySearch(arr, size, target)<<endl;

	return 0;
}