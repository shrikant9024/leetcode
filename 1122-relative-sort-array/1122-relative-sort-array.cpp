class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mp;
        for(auto it : arr1){
            mp[it]++;
        }
        int i=0;
        for(auto it : arr2){
            while(mp[it]-- >0){
                arr1[i++] = it;
            }
        }
        
        for(auto it : mp){
            int freq = it.second;
            while(freq>0){
                arr1[i++] = it.first;
                freq--;
            }
        }
        return arr1;
    }
};