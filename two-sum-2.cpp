// Given an array of integers that is already sorted in ascending order,
// find two numbers such that they add up to a specific target number.
// The function twoSum should return indices of the two numbers such
// that they add up the target, where index1 must be less than index2, 
// Please note thar you return answer (both index1 and index2) are not zero-based
// You must assume that each input would have exactly one solution and you
// may not use the same element twice.
// Input numbers = {2, 7, 11, 15}, target = 9
// index1 = 1, index2 = 2 
//
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {
            vector<int> result; 
            result.resize(2, 0);
            map<int, int> remainMap;
            for (int i = 0; i < numbers.size(); ++i) {
                int remainValue = target - numbers[i];
                if (remainMap.find(remainValue) != remainMap.end()) {
                    result[0] = remainMap[remainValue] + 1;
                    result[1] = i + 1;
                    break;
                } 
                else {
                    remainMap.insert(pair<int, int>(numbers[i], i)); 
                }
            }
            return result;
        }
};

int main()
{
    int test[] = {2, 7, 11, 15};
    int target = 18;
    vector<int> v(test, test + sizeof(test) / sizeof(test[0]));
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
    Solution s;
    vector<int> result = s.twoSum(v, target);
    cout << "index1 = " << result[0] << " index2 = " << result[1] << endl;
    return 0; 
}
