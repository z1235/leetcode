// Given an array nums, write a function to move all 0's to the end of it
// while maintaining the relative order of the non-zero elements.
// For example, given nums = [0, 1, 0, 3, 12] after calling you function,
// nums shoule be [1, 3, 12, 0, 0]
// Note:
// 1. You must do this in-place without making a copy of the array
// 2. Minimize the total number of operations

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        for (i = 0; i < nums.size(); ++i) {
           if (nums[i] != 0) {
                nums[j] = nums[i];
                j++;
           }
        }
        for (i = j; i < nums.size(); ++i) {
            nums[i] = 0; 
        }
    }
};

int main()
{
    int mm[] = {1, 2, 3, 0, 3, 0, 4};
    vector<int> v(mm, mm + sizeof(mm) / sizeof(mm[0]));
    for (int i = 0; i < sizeof(mm) / sizeof(mm[0]); ++i)
        cout << mm[i] << " ";
    cout << endl;
    Solution s;
    s.moveZeroes(v);
    for (int i = 0; i < sizeof(mm) / sizeof(mm[0]); ++i)
        cout << v[i] << " ";
    cout << endl;
    return 0;
}
