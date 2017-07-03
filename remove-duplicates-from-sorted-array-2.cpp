// Follow up for "Remove Duplicates"
// What if duplicates are allowed at most twice
// For example,
// Given sorted array nums = [1, 1, 1, 2, 2, 3]
// You function should return length = 5, with the first five elements of 
// nums being 1, 1, 2, 2, and 3. 
// It doesn't matter what you leave beyond the new length
#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            if (nums.size() == 0)
                return 0;
            int j = 0;
            int i = 1; // i 指向 j 后面一个数
            int cnt = 0;
            for (; i < nums.size(); ++i) {
                if (nums[i] == nums[j]) 
                    cnt++;
                else 
                    cnt = 0;
                if (cnt > 1)
                    continue;
                j++;
                nums[j] = nums[i];
            }
            return j + 1;
        }
};

int main()
{
    int test[] = {1, 1, 1, 1, 1, 1};
    vector<int> v(test, test + sizeof(test) / sizeof(test[0]));
    cout << "Before remove vector : ";
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;
    Solution s;
    int n = s.removeDuplicates(v);
    cout << "After remove vector: ";
    for (int i = 0; i < n; ++i) 
        cout << v[i] << " ";
    cout << endl;
   return 0; 
}
