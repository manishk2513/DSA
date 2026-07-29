#include<iostream>
using namespace std;

int binarySearch(int *arr, int left, int right, int target){
	
	if(left > right) return -1;

	int mid = left + (right - left)/2;
	if(arr[mid] == target) return mid;

	if(target < arr[mid])
		return binarySearch(arr, left, mid - 1, target);
		
	return binarySearch(arr, mid + 1, right, target);
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
	cout<<binarySearch(arr, 0, size - 1, target)<<endl;

	return 0;
}