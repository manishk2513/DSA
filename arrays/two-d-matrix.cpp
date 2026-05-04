#include<iostream>
#include<vector>
using namespace std;

int main(){
	int r = 4;
	int c = 2;
	vector<vector<int>> mat(r, vector<int>(c, 0));

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++){
			cin >> mat[i][j];
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++){
			cout << mat[i][j]<<" ";
		}
		cout<<endl;
	}

	cout<<"==================="<<endl;

	for (int i = 0; i < r; i++) {
		for(int j = i + 1; j < c; j++){
			cout << (mat[][0] - mat[--i][0])<<" "<<endl;
		}  
	}

	return 0;
}