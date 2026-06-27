class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ump;
        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            ump[key].push_back(s);   // Ex: ump["act"].push_back("cat")
        }

        vector<vector<string>> ans;
        for (auto& p : ump) {
            ans.push_back(p.second);
        }

        return ans;                                    
    }
};

