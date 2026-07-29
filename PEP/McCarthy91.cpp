#include<iostream>
using namespace std;

int print(int n){
	if(n > 100) return (n - 10);

	return print(print(n + 11));
}

int main(){
	cout<<print(10)<<endl;
	return 0;
}