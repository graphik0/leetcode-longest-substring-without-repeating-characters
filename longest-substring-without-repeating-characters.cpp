#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int start = 0;
        int longestLength = 0;
        
        for (int end = 0; end < s.size(); ++end) {
            while (charSet.count(s[end])) {
                charSet.erase(s[start]);
                start++;
            }
            charSet.insert(s[end]);
            longestLength = max(longestLength, end - start + 1);
        }
        
        return longestLength;
    }
};

int main() {
    Solution solution;
    string input = "abcabcbb"; // Example input string
    int result = solution.lengthOfLongestSubstring(input);
    cout << "Length of the longest substring without repeating characters: " << result << endl;
    return 0;
}

