// Given an index k, return the kth row of the pascal's triangle
// For example, given k = 3, return [1, 3, 3, 1]

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        result.resize(rowIndex + 1, 1);
        for (int i = 0; i < (rowIndex + 1); ++i) {
            for (int j = i - 1; j >= 1; --j) {
                result[j] = result[j] + result[j - 1];
            }
        }
        return result;
    }
};


int main()
{
    cout << "Please input the index of the pascal's row: ";
    int rowIndex;
    cin >> rowIndex;
    Solution s;
    vector<int> result = s.getRow(rowIndex);
    for (int i = 0; i < result.size(); ++i)
        cout << result[i] << " ";
    cout << endl;
    return 0;
}
