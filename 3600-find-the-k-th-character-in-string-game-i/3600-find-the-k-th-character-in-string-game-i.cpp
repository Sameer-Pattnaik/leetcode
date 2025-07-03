class Solution {
public:
    static char kthCharacter(int k) {
        return 'a'+popcount((unsigned)(k-1));
    }
};