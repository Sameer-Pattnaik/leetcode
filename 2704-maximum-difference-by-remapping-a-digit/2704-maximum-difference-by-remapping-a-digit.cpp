class Solution {
public:
    static consteval array<int, 10> pow10(){
        array<int, 10> ans={1};
        for (int i=1; i<10; i++)
            ans[i]=ans[i-1]*10;
        return ans;
    }
    
    static int minMaxDifference(int num) {
        constexpr array<int, 10> tens=pow10();
        int T=*upper_bound(tens.begin(), tens.end(), num)/10;
        bool seeA=0, seeB=0;
        int a=-1, b=-1, x=0, y=0;
        for( int t=T; t>=1; num%=t, t/=10){
            const int d=num/t;
        //    cout<<"d="<<d<<endl;
            if (!seeA && d!=9){
                a=d;
                seeA=1;
                x+=9*t;
            }
            else if (seeA && d==a) x+=9*t;
            else x+=d*t;
            if (!seeB && d!=0){
                b=d;
                seeB=1;
            }
            else if (d!=b) y+=d*t;
        }
    
        return x-y;
    }
};