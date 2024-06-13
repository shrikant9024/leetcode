class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(),seats.end());
        
         sort(students.begin(),students.end());
        
        //seat = [1,3,5]
        // students = [2,4,7]
        int move = 0;
        int n = seats.size();
        for(int i =0;i<n;i++){
            move += abs(seats[i]-students[i]);
        }
        return move;
    }
};