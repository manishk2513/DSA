// q3. check if an array is a subset of another array
// q3. arr1 = {7, 2, 5, 6, 4}
// q3. arr2 = {4, 2, 5, 7, 8, 1, 3, 9, 6, 12}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
	bool binarySearch(vector<int>&nums, int target){
		int left = 0;
		int right = nums.size() - 1;

		while(left <= right){
			int mid = left + (right - left) / 2;
			if(nums[mid] == target){
				return true;
			} else if(nums[mid] < target){
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}
		return false;
	}

	bool checkSubset(vector<int>&nums, vector<int>&sub){
		sort(nums.begin(), nums.end());
		sort(sub.begin(), sub.end());

		for(int s : sub){
			if(!binarySearch(nums, s)){
				return false;
			}
		}
	return true;
	}
};

int main(){
	vector<int>nums = {4, 2, 5, 8, 1, 3, 9, 6, 12};
	vector<int>sub = {7, 2, 5, 6, 4};

	Solution s;
	if(s.checkSubset(nums, sub)){
		cout<<"it is a subset";
	} else {
		cout<<"it is not a subset";
	}


	cout<<endl;
	for(int n : nums) cout<<n<<" ";
	cout<<endl;
	for(int s : sub) cout<<s<<" ";
	cout<<endl;
	return 0;
}
