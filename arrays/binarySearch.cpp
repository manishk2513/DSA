#include<iostream>
using namespace std;

int main(){

	int n = 10;
	// cout<<"enter size of array: ";
	// cin>>n;
	// cout<<"enter only sorted array: "<<endl;
	// int arr[n];

	// for(int i = 0; i < n; i++){
	// 	cin>>arr[i];
	// }

	int arr[n] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	cout<<"array elements: "<<endl;
	for(int i = 0; i < n; i++){
		cout<<arr[i]<<" ";
	}



	return 0;
}