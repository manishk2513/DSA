#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n = 4;
	vector<string>queens(n, string(n, '.'));

	for(string q : queens){
		for(char num : q){
			cout<<num<<" ";
		}
		cout<<endl;
	}

	vector<vector<int>>nums(n, vector<int>(n, 1));
	for(vector<int> num : nums){
		for(int n : num){
			cout<<n<<" ";
		}
		cout<<endl;
	}

	return 0;
}