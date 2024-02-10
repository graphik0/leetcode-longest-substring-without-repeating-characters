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
