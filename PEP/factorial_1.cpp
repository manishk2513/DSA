#include<iostream>
using namespace std;

long long factorial(int n){
	if(n < 0) return -1;
	if(n == 0) return 1;
	return n * factorial(n - 1);
}

int main(){
	cout<<factorial(9)<<endl;
	return 0;
}