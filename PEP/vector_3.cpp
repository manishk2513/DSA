#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<int>v(5, 0);

	v.push_back(8);
	v.push_back(7);

	for(int n : v){
		cout<<n<<" ";
	}
	cout<<endl;

	vector<vector<int>>v2;
	v2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	for(vector<int>num : v2){
		for(int n : num){
			cout<<n<<" ";
		}
		cout<<endl;
	}

	return 0;
}