class Solution {
public:
    string numberToWordsHelper(int num){
        string digitString[]={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
        string teenString[]={"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
        string tenString[]={"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
        string res="";
        if(num>99){
            res+=digitString[num/100]+" Hundred ";
        }
        num=num%100;
        if(num>9 && num<20){
            res+=teenString[num%10]+ " ";
        }
        else{
            if(num>=20){
                res+=tenString[num/10] + " ";
            }
            num%=10;
            if(num>0){
                res+=digitString[num]+" ";
            }
        }
        return res;
    }
    string numberToWords(int num) {
        if(num==0){
            return "Zero";
        }
        string result="";
        string bigIntString[]={"Thousand","Million","Billion"};
        result+=numberToWordsHelper(num%1000);
        num=num/1000;
        for(int i=0;i<3;i++){
            if(num>0 && num%1000>0){
                result=numberToWordsHelper(num%1000)+bigIntString[i] + " " +result;
            }
            num=num/1000;
        }
        return result.empty()?result:result.substr(0,result.size()-1);
    }
};