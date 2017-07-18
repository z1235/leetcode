#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unsigned length = 0;
		for (unsigned i = 0; i < s.size(); ++i) {
			unsigned j = i;
			unordered_map<char, unsigned> myMap;
			myMap.clear();
			while (j < s.size() && myMap.find(s[j]) == myMap.end()) { // not find in the past subString
				myMap.insert(pair<char, unsigned>(s[j], j));
				j++;
			}
			if (length < j - i)
				length = j - i;
		}
		return length;
	}
};
int main()
{
	string str;
	cin >> str;
	Solution s;
	cout << s.lengthOfLongestSubstring(str) << endl;
	return 0;
}
