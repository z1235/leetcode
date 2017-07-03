// Given an array of interger, return indices of the two numbers such that
// they add up to a specific target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// Example nums = [2, 7, 11, 15], target = 9
// return [0, 1]
//
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>&nums, int target) {
        vector<int> result;
        result.resize(2, 0);
        map<int, int> myMap;
        for (int i = 0; i < nums.size(); ++i) {
            int leaveValue = target - nums[i];
            if (myMap.find(leaveValue) != myMap.end()) {
                result[0] = myMap[leaveValue];
                result[1] = i; 
                break;
            } 
            else {
                myMap.insert(pair<int, int>(nums[i], i)); 
            }
        }
        return result;
    }
};

int main()
{
    int test[] = {2, 7, 11, 15};
    int target = 9;
    vector<int> v(test, test + sizeof(test) / sizeof(test[0]));
    cout << "Array is : ";
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }   
    cout << endl;
    Solution s;
    vector<int> result = s.twoSum(v, target);
    cout << "index1 = " << result[0] << "index2 = " << result[1] << endl;
    return 0;
}
