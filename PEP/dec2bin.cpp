#include<iostream>
using namespace std;

class Solution{
public:
	int bin2dec(string &b){
		int dec = 0;
		for(char bit : b){
			dec = dec * 2 + (bit - '0');
		}
		return dec;
	}
};

int main(){
	string bin = "1010"; // this value must be a binary number
	Solution s;

	cout<<"decimal representation of the binary num ("<<bin<<") is: "<<s.bin2dec(bin);

	return 0;
}