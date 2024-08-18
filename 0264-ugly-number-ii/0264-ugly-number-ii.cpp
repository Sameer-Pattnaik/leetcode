class Solution {
public:
    int nthUglyNumber(int n) {
        set<long>st;
        st.insert(1);
        for(int i=2;i<=n;i++)
        {
            long num=*st.begin();
            st.erase(num);
            st.insert(num*2);
            st.insert(num*3);
            st.insert(num*5);

        }
        return *st.begin();
    }
};