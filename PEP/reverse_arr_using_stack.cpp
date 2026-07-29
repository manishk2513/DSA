#include<iostream>
#include<stack>
using namespace std;

int main(){
	int arr[] = {91, 32, 63, 24, 75, 59};
	int size = sizeof(arr)/sizeof(arr[0]);
	stack<int> st;
	for(int i : arr){
		st.push(i);
	}

	int revArr[size];
	for(int i = 0; !st.empty(); i++){
		revArr[i] = st.top();
		st.pop();
	}

	cout<<"original array: ";
	for(int i = 0; i < size; i++){
		cout<<arr[i]<<" ";
	}

	cout<<"\nreversed array: ";
	for(int i = 0; i < size; i++){
		cout<<revArr[i]<<" ";
	}


	return 0;
}