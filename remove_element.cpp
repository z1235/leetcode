// Given an array and a value, remove all instances of that value in place 
// and return the new length
// DO not allocate extra space for another array, you must do this in place
// with constant memory
// The order of elements can be changed. It doesn't matter what you leave beyond the length
//
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            int i = 0, j = 0;
            for (i = 0; i < nums.size(); ++i) {
                if (nums[i] == val) 
                    continue;
                else {
                    nums[j] = nums[i];
                    j++; 
                }
            }
            return j;
        }
};

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(3);
    v.push_back(5);
    v.push_back(5);
    cout << "Before remove :";
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " "; 
    }
    cout << endl;
    Solution s;
    int n = s.removeElement(v, 3);
    cout << "after remove 3: \n";
    cout << "elems: size = " << n << endl;
    for (int i = 0; i < n; ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
