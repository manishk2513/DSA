#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;


        while(left <= right){
            int mid = left + (right - left) / 2;

                if(nums[mid] == target){
                    return mid;
                } else if(nums[mid] < target){
                    left = mid + 1;
                } else{
                    right = mid - 1;
                }
        }
        return -1;
    }
};

int main(){
    Solution s;
    // the array must be sorted and in ascending order and elements must be unique
    // otherwise it will return the first index of that element only
    vector<int>nums = {-1, 0, 3, 3, 3, 12};
    int target = 3;

    cout<<s.search(nums, target);

    return 0;
}