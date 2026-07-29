#include<iostream>
using namespace std;

class Solution{
public:
	bool armstrong(int n){
		int temp = n;
		int sum = 0;
		while(temp > 0){
			int digit = temp % 10;
			sum = sum + (digit * digit * digit);
			temp /= 10;
		}

		return sum == n;
	}
};

int main(){
	int n = 371; //or 153
	Solution s;

	bool res = s.armstrong(n);
	if(res){
		cout<<n<<" is an armstrong number.";
	} else {
		cout<<n<<" is not an armstrong number.";
	}

	return 0;
}

