#include <climits>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 1<<31 && divisor == -1) return INT_MAX;
        if (dividend == 1<<31 && divisor == 1) return INT_MIN;

        bool sign =true;
        if(( (dividend < 0)&&(divisor > 0)) ||  ((dividend > 0)&&(divisor < 0)))
        {
            sign=false;
        }

        long long absDividend = abs((long long)dividend);
        long long absDivisor = abs((long long)divisor);

        int quotient = 0;

        while (absDividend >= absDivisor) {
            long long tempDivisor = absDivisor, multiple = 1;
            while (absDividend >= (tempDivisor << 1)) {
                tempDivisor <<= 1;
                multiple <<= 1;
            }
            absDividend -= tempDivisor;
            quotient += multiple;
        }

        return sign ? quotient : -quotient;
    }
};