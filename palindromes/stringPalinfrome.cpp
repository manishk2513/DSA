#include <iostream>
using namespace std;

bool isPalindrome(string str){
	cout<<"String str = "<<str<<endl;

	

	return 1;
}

int main(){
	string str;
	cout<<"Enter string: ";
	getline(cin, str);

	if(isPalindrome(str)){
		cout<<"The string \""<<str<<"\" is palindrome";
	} else {
		cout<<"The string \""<<str<<"\" is not a palindrome";	
	}
}