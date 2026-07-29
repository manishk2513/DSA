#include<iostream>
#include<vector>
using namespace std;

int main(){

	// vector<int>v;

	// v.push_back(31);
	// v.push_back(83);
	// v.push_back(13);
	// v.push_back(38);
	// v.push_back(63);

	// vector<vector<int>>v2;

	// v2.push_back(v);
	// v2.push_back(v);
	
	// v2.push_back({12, 13, 7});
	// v2.push_back({98, 10, 56});

	// for(vector<int> v : v2){
	// 	for(int n : v){
	// 		cout<<n<<" ";
	// 	}
	// 	cout<<endl;
	// }

	// ////////////
	vector<int>v1 = {};
	vector<int>v2 = {0, 0, 0};
	cout<<v2.front()<<endl;
	bool res = v1 == v2;
	cout<<res;

	return 0;
}