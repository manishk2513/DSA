#include <iostream>
#include<stack>
using namespace std;

int main(){

	string str = "Hello World!";

	stack<char> st;

	for(char ch : str){
		st.push(ch);
	}

	string rev = "";

	while(!st.empty()){
		rev += st.top();
		st.pop();
	}

	cout<<"original string: "<<str<<endl;
	cout<<"reversed string: "<<rev<<endl;




	return 0;
}