//
//  main.cpp
//  Longest-Palindromic-Subsequence DP
//
//  Created by Zijian Xie on 2016/11/7.
//  Copyright © 2016年 Jason Xie. All rights reserved.
//
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

// not substring, it does not request consective.
class LongestPaliSub{
private:
    string s;
public:
    LongestPaliSub(string& ss){
        s = ss;
    }
    
    int DP(){
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));
        for(int len = 1; len <= (int)s.size(); ++len){
            for(int i = 0; i + len < (int)s.size(); ++i){
                int j = i + len;
                if(s[i] == s[j]){
                    dp[i][j] += 2 + dp[i+1][j-1];
                }else{
                    dp[i][j] = max(dp[i+1][j],dp[i][j-1]);//往前缩一位或者i往后走一位，这两段的subsequence取最大
                }
            }
        }
        cout<< "The longest length of subsequence is "<< dp[0][s.size()-1]<<endl;
        return dp[0][s.size()-1];
    }
    
};

int main(int argc, const char * argv[]) {
    string s = "agbdba";
    LongestPaliSub* test = new LongestPaliSub(s);
    test->DP();
    return 0;
}
