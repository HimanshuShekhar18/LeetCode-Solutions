class RandomizedSet {
public:

    unordered_map<int,int> mp;
    vector<int> key;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp[val]==0) {
            key.push_back(val);
            mp[val]=key.size();
            return 1;
        } 
        else return 0;
    }
    
    bool remove(int val) {

        if(mp[val]==0) {
            mp.erase(val);
            return 0;
        }
        else{
            int index = mp[val]-1;
            int lastindex = key.size()-1;
            mp[key[lastindex]] = mp[val];
            swap(key[index],key[lastindex]);
            key.pop_back();
            mp.erase(val);
            return 1;
        }      
    }
    
    int getRandom() {
        int size = key.size();
        int index = rand()%size;
        return key[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
