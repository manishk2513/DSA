#include<iostream>
using namespace std;

int linearSearch(int *arr, int size, int target){
	for(int i = 0; i < size; i++){
		if(arr[i] == target){
			return i;
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

	cout<<endl<<"target element index: "<<linearSearch(arr, size, target)<<endl;

	return 0;
}