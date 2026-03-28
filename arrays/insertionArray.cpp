#include<iostream>
using namespace std;

int main(){

	int n = 10;
	int index, num;
	int arr[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	cout<<"array elements: "<<endl;
	for(int i = 0; i < n; i++){
		cout<<arr[i]<<" ";
	}

	cout<<"enter element to insert: ";
	cin>>num;
	cout<<"enter index to insert at: ";
	cin>>index;

	for(int i = n; i > index; i++){
		arr[i] = arr[i-1];
	}

	arr[index] = num;
	cout<<"array elements: "<<endl;
	for(int i = 0; i < n; i++){
		cout<<arr[i]<<" ";
	}

	return 0;
}