#include<iostream>
using namespace std;

bool isPalindrome(int number){
		int temp = number;
	int reverse = 0;

	while(temp > 0){
		reverse *= 10;
		reverse += temp % 10;
		temp /= 10;
	}
	
	if(reverse == number){
		return true;
	} else {
		return false;
	}
}

int main(){
	int number;
	cout<<"Enter a number: ";
	cin>>number;
	cout<<"inside main: "<<number<<endl;

	if(isPalindrome(number)){
		cout<<"The number "<<number<<" is palindrome.";
	} else {
		cout<<"The number "<<number<<" is not a palindrome.";
	}

	return 0;
}