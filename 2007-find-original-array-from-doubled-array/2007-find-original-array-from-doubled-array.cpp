class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();

        if(n%2!=0) return{};

        sort(changed.begin(),changed.end());
        map<int,int> mp;

        for(auto it : changed){
            mp[it]++;
        }

        vector<int> res;

        for (int num: changed){
            int twice = 2*num;
            if(mp[num]==0) continue;
            if(mp.find(twice)==mp.end() || mp[twice]==0){
                return {};
            }
            res.push_back(num);
            mp[twice]--;
            mp[num]--;
        }
        return res;
    }
};