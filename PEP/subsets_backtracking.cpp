#include<iostream>
#include<string>
using namespace std;

void sol(string s, int idx, string curr){
	if(idx == s.length()){
		cout<<curr<<" ";
		return;
	}

	sol(s, idx + 1, curr + s[idx]);
	sol(s, idx + 1, curr);
}
// the above solution will print all the subsets formed using  the string
int main(){
	string s = "abc";
	sol(s, 0, "");
	return 0;
}