// Given a sorted array, remove the duplicated in place such that each
// element appear only once and return the new length. Do not allocate
// extra space for another array, you must do this in place with constant 
// memory
// For example,
// Given input array nums = [1, 1, 4]
// You function should return length = 2, with the first two elements of 
// nums being 1 and 2 respectively. It donen't matter what you leave beyond
// the new length
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int j = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                j++;
                nums[j] = nums[i];
            }
        }
        return j + 1;
    }
};


int main()
{
    int test[] = {1, 2, 2, 3, 3, 4, 5};
    int n = sizeof(test) / sizeof(test[0]);
    cout << "Before remove the vector is ";
    for (int i = 0; i < n; ++i)
        cout << test[i] << " ";
    cout << endl;
    cout << "After remove the vector is ";
    vector<int> v(test, test+n);
    Solution s;
    n = s.removeDuplicates(v);
    for (int i = 0; i < n; ++i) {
        cout << v[i] << " ";
    } 
    cout << endl;
    return 0;
}
