#include<iostream>
using namespace std;

class Solution{
public:
	// a = 45, b = 60
	// a = 36, b = 9
	int gcd(int a, int b){
		while(b != 0){
						  // a = 45, b= 60		// a = 36, b = 9
			int temp = b; // 60 -> 45 -> 15		// 9
			b = a % b;	  // 45 -> 15 -> 0 		// 0
			a = temp;	  // 60 -> 45 -> 15		// 9
		}
		return a;
	}
};

int main(){
	int a = 36, b = 9;
	Solution s;

	cout<<"gcd of "<<a<<" and "<<b<<" is: "<<s.gcd(a, b);

	return 0;
}