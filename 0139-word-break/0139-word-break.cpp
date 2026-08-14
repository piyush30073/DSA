class Solution {
public:

    bool solve(string& s, int i, unordered_map<char, vector<string>>& mp, vector<int>& dp) {
        if(i == s.size()) return true;
        if(dp[i] != -1) return dp[i];

        bool ans = false;

        for(string x : mp[s[i]]) {
            string temp = s.substr(i, x.size());

            if(temp == x) ans |= solve(s, i+x.size(), mp, dp);
        }

        return dp[i] = ans;
    }

    bool wordBreak(string ss, vector<string>& wordDict) {
        unordered_map<char, vector<string>> mp;
        vector<int> dp(ss.size(), -1);

        for(string s : wordDict) {
            char f = s[0];
            mp[f].push_back(s);
        }

        return solve(ss, 0, mp, dp);
    }
};