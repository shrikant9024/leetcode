class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
            vector<int> temp;
            int n = arr.size();
    temp.push_back(arr[0]);		//push first element of array into vector
    int len = 1;				//take Len =1
    for(int i =1;i<n;i++){			//iterate in array
        if(arr[i]>temp.back()){		//check if element is greater than the last element pushed in vector
            temp.push_back(arr[i]);	//if yes push in vector
            len++;					//increment l
        } else{
            int ind = lower_bound(temp.begin(),temp.end(),arr[i]) - temp.begin();	//imply lower bound func
//{	when u apply lower bound func. U point to the next greater element and it index which is to found. Suppose array is [1,2.4,6] so if element to found is 4 at index 2. . Lower bound will point to 6  so u do -temp.begin so it points to 4 again.
//}
            temp[ind] = arr[i];		//u have gotten the index now update in vector

        }
    }
    return len;

    }
};