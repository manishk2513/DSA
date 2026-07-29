#include<iostream>
using namespace std;

int main(){
	int arr[] = {8, 7, 6, 5, 9, 2, -3};

	int max = arr[0];
	int min = arr[0];

	cout<<"arr: ";
	for(int num : arr){
		cout<<num<<" ";

		if(num > max){
			max = num;
		}
		if(num < min){
			min = num;
		}
	}

	cout<<"\nmax: "<<max;
	cout<<"\nmin: "<<min<<endl;


	return 0;
}