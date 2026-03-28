#include<iostream>
using namespace std;

// reverse the digits of an integer using recursion and there must be only one parameter to the function
int reverse(int n){ 
		//356 -> 653
	
	// if(n < 10){
	// 	return (n * 10);
	// }

	// while(n > 0){
	// 	reverse(n % 10);
	// }

// this is conventional way to solve this problem

	int reverse = 0;
	while(n > 0){
		reverse *= 10;
		reverse += n % 10; 
		n /= 10;
	}
	return reverse;

}

int main(){

	int N = 3021;

	cout<<"original: "<<N<<endl;
	cout<<"reverse: "<<reverse(N)<<endl;

	return 0;
}


