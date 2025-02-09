#include <iostream>
#include <vector>
#include <string>
using namespace std;


string longestCommonSubstring(const string& s1, const string& s2) {
    int n = s1.length();
    int m = s2.length();

   
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int maxLength = 0; 
    int endInx = 0;  
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endInx = i - 1; 
                }
            } else {
                dp[i][j] = 0; 
            }
        }
    }

    
    cout << "Dynamic Programming Table:" << endl;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    
    if (maxLength == 0) {
        return ""; 
    }
    return s1.substr(endInx - maxLength + 1, maxLength);
}

int main() {
    string s1, s2;

    
    cout << "Enter the first string: ";
    cin >> s1;
    cout << "Enter the second string: ";
    cin >> s2;

    
    if (s1.length() != s2.length()) {
        cout << "Error: Strings must be of equal length." << endl;
        return 1;
    }

    
    string lcs = longestCommonSubstring(s1, s2);

    
    cout << "Longest Common Substring: " << lcs << endl;

    return 0;
}