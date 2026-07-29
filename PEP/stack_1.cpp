#include<iostream>
#include<stack>
using namespace std;

int main(){
	stack<int> st;

	st.push(45);
	st.push(89);
	st.push(62);
	st.push(33);

	stack<int> temp(st);

	while(!temp.empty()){
		cout<<temp.top()<<" ";
		temp.pop();
	}

	return 0;
}