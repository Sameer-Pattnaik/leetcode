class RandomizedSet {
    unordered_set<int>s;
public:
    RandomizedSet() {
       
    }
    
    bool insert(int val) {
        if(s.find(val)!=s.end())return 0;
        else {
          
           s.insert(val);
            return 1;
        }
    }
    
    bool remove(int val) {
        if(s.find(val)==s.end())return 0;
        else {
           
            s.erase(val);
            return 1;
        }
    }
    
    int getRandom() {
        return *next(s.begin(),rand()%s.size()); //hehe kaisa laga mera mazak
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */