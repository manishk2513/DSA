#include<iostream>
using namespace std;

int main(){
	int arr[] = {91, 32, 63, 24, 75, 59};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	cout<<"original array: ";
	for(int i = 0; i < size; i++){
		cout<<arr[i]<<" ";
	}

	for(int i = 0; i < size/2; i++){
		int temp = arr[i];
		arr[i] = arr[size - i - 1];
		arr[size - i - 1] = temp;
	}

	cout<<"\nreversed array: ";
	for(int i = 0; i < size; i++){
		cout<<arr[i]<<" ";
	}

	return 0;
}