#include<iostream>
using namespace std;

class Solution{
public:
	nthFibonacci(int n){
		if(n == 0) return 0;
		if(n == 1) return 1;

		int left = 0, right = 1;
		int sum = 0;
		for(int i = 1; i < n; i++){
			sum = left + right;
			left = right;
			right = sum;
		}
		return sum;
	}
};

int main(){
	Solution s;
	int n = 6;

	cout<<n<<"-th fibonacci number: "<<s.nthFibonacci(n);

	return 0;
}