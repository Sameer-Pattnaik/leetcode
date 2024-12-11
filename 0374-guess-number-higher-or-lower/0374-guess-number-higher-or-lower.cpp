/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        if(guess(n)==0)
        {
            return n;
        }
        int s=1;
        int e=n;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(guess(mid)==0)
            {
                return mid;
            }
            else if(guess(mid)==1)
            {
                e=n;
                s=mid+1;
            }
            else
            {
                s=s;
                e=mid-1;
            }
        }
        return -1;
    }
};