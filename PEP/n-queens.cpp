#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<string>>ans;

	bool isSafe(int row, int col, vector<string>& board, int n){
		for(int i = 0; i < row; i++){
			if(board[i][col] == 'Q'){
				return false;
			}
		}
		for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
			if(board[i][j] == 'Q'){
				return false;
			}
		}
		for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++){
			if(board[i][j] == 'Q'){
				if(board[i][j] == 'Q'){
					return false;
				}
			}
		}
		return true;
	}

	void sol(int row, vector<string>& board, int n){
		if(row == n){
			ans.push_back(board);
			return;
		}

		for(int col = 0; col < n; col++){
			if(isSafe(row, col, board, n)){
				board[row][col] = 'Q';
				sol(row + 1, board, n);
				board[row][col] = '_';
			}
		}
	}

    vector<vector<string>> solveNQueens(int n) {
    	vector<string>board(n, string(n, '_'));
    	sol(0, board, n);
        return ans;
    }
};


int main(){
	int n = 4;
	Solution s;
	vector<vector<string>>ans = s.solveNQueens(n);
	for(vector<string> str : ans){
		for(string c : str){
			cout<<c<<endl;
		}
		cout<<endl;
	}

}