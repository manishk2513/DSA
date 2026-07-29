#include<iostream>
using namespace std;

int main(){
	int arr[] = {8, 7, 6, 5, 9, 2, -3};

	int max = arr[0];
	int min = arr[0];
	int secMax;
	int secMin;

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

	for(int num : arr){
		
	}

	cout<<"\n2nd max: "<<max;
	cout<<"\n2nd min: "<<min<<endl;


	return 0;
}