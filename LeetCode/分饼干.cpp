/* 一道easy，
 * 利用了贪心算法的策略 */
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count = 0;
        sort(g.begin(), g.end()); sort(s.begin(), s.end());
        for(int i = 0, j=0; i < s.size(); i++){
            if(j == g.size()) break;
            if(s[i] >= g[j]){
                j++;
                count++;
            }
        }
        return count;
    }
};
