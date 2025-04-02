class MedianFinder {
public:
    multiset<int>left,right;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.empty() || left.size()<=right.size()){
            left.insert(num);
        }else{
            right.insert(num);
        }

        if(!right.empty() && *left.rbegin()>*right.begin()){
            int temp1=*left.rbegin();
            int temp2=*right.begin();
            left.erase(left.find(temp1));
            right.erase(right.find(temp2));

            right.insert(temp1);
            left.insert(temp2);
        }
    }
    
    double findMedian() {
        if(left.size()==right.size()){
            int x = *left.rbegin() + *right.begin();
            return (double)x/(2*1.0);
        }
        else{
            return double(*left.rbegin());
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */