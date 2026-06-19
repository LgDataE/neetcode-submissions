class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        
        // Consider each element in the string
        for (int i = 0; i < strs[0].size(); i++) {
            char c = strs[0][i];
            // strs[0].size -> length of 1st string

            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size() || strs[j][i] != c) {
                    return ans;
                }
            }

            ans += c;
        }

        return ans;
    }
};