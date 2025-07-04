class Solution {
public:
    static char kthCharacter(long long k, vector<int>& operations, int b=63){
        return (b<0||k<=1)?'a':(
        (k>(1ULL<<b))?'a'+(operations[b]+(kthCharacter(k-(1ULL<<b), operations, b-1)-'a'))%26:kthCharacter(k, operations, b-1));
    }
};