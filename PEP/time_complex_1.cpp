#include<iostream>
using namespace std;

int main(){
	int n = 100;
	for(int i = n; i > 1; i /= 2){
		cout<<i<<" ";
	}
	cout<<endl;

	for(int i = 1; i < n; i *= 2){
		cout<<i<<" ";
	}
	cout<<endl;

	for(int i = 2; i * i <= n; i++){
		cout<<i<<" ";
	}
	cout<<endl;

	int p = 0;
	for(int i = 0; p < n; i++){
		p += i;
		cout<<p<<" ";
	}

	return 0;
}