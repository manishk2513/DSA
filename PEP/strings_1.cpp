#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){

	// string str = "hello this   is a cpp program";
	// vector<char>s;
	// for(int i = 0; i < str.size() - 1; i++){
	// 	s.push_back(c);
	// }

	// for(char c : s){
	// 	cout<<c<<" ";
	// }

	string str = "hello this   is a cpp program";
	for (char c : str) {
        if (string("aeiouAEIOU").find(c) != string::npos)
            cout << c << ' ';
    }

	return 0;
}