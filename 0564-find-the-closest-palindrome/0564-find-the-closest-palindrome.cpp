class Solution {
public:
    string nearestPalindromic(string n) {
      int len=n.length();
      if(len==1)
      {
        return to_string(stoi(n)-1);
      }  
      vector<long long>candidate;
      candidate.push_back(pow(10,len-1)-1);
      candidate.push_back(pow(10,len)+1); 
      long long prefix=stoll(n.substr(0,(len+1)/2));
      for(int i=-1;i<=1;i++)
      {
        string p=to_string(prefix+i);
        string candidates=p+string(p.rbegin()+len%2,p.rend());
        candidate.push_back(stoll(candidates));
      }
      long long num=stoll(n);
      long long closest=-1;
      for(long long cand:candidate)
      {
        if(num==cand)
        {
            continue;
        }
        if(closest==-1 || abs(cand-num)<abs(closest-num) || abs(cand-num)==abs(closest-num) && cand<closest)
        {
               closest=cand;  
        }
      }
      return to_string(closest);
    }
};