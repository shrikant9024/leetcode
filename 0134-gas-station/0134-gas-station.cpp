class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalfuel = 0;
        int totalcost = 0;
        
        for(auto it: gas){
            totalfuel +=it;
        }
        
        for(auto it : cost){
            totalcost += it;
        }
        
        if(totalfuel<totalcost) return -1;
        
        int start = 0;
        int curfuel =0;
        
        for(int i =0;i<gas.size();i++){
            curfuel +=(gas[i]-cost[i]);
            if(curfuel<0){
                start = i+1;
                curfuel = 0;
            }
            
        }
        return start;
    }
};