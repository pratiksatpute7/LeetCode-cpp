class Solution {
public:
    int climbStairs(int n) {
        unordered_map<int, int> mp;
        return count(n, mp);
    }

    int count(int index, unordered_map<int, int>& mp) {
        if(index < 0) {
            return 0;
        }
        if(mp.find(index) != mp.end()) {
           return mp[index];
        }

        if(index == 0) {
            return 1;
        }

        int left = count(index - 1, mp);

        int right = count(index - 2, mp);

        if(mp.find(index) == mp.end()) {
            mp[index] = left + right;
        }

        return (right + left);
    }
};