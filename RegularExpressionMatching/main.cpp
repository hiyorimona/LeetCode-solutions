#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    static bool isMatch(string s, string p) {
        int s_len = s.length();
        int p_len = p.length();

        // DP table to handle substings in strings
        vector<vector<bool>> dp(s_len + 1, vector<bool>(p_len + 1, false));

        dp[0][0] = true;

        //  iterate over each character in the pattern p
        for (int j = 1; j <= p_len; ++j) {
            if (p[j - 1] == '*') { // can match an empty string
                dp[0][j] = dp[0][j - 2];
            }
        }

        for (int i = 1; i <= s_len; ++i) { // iterate over each character in s
            for (int j = 1; j <= p_len;
                 ++j) { //  iterate over each character in the pattern p
                if (p[j - 1] == s[i - 1] ||
                    p[j - 1] == '.') { // . should match any character
                    dp[i][j] =
                            dp[i - 1]
                            [j - 1]; // if true the previous characters matched

                } else if (p[j - 1] == '*') { // * is the current character in the pattern
                    dp[i][j] = dp[i][j - 2];

                    // * is the current character in s, or the character is .
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }

        return dp[s_len][p_len];
    }
};

int main() {
    Solution sol;
    string s1 = "aa", p1 = "a";
    string s2 = "aa", p2 = "a*";

    cout << boolalpha;
    cout << "Case 1: " << sol.isMatch(s1, p1) << std::endl;
    cout << "Case 2: " << sol.isMatch(s2, p2) << std::endl;

    return 0;

}

