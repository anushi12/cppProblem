    

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code here
      //brute force
        vector<int>ans;
        for(int i=0;i<n;i++){
            bool flag = false;
            for(int j=i+1;j<n;j++){
                if(a[j]>a[i]){
                    flag = true;
                    break;
                }
            }
            if(flag == false){
                ans.push_back(a[i]);
            }
        }
      
      
      //optimise 
        vector<int>ans;
        int maxi = INT_MIN;
        for(int i = n-1;i>=0;i--){
            if(a[i]>=maxi){
              ans.push_back(a[i]);
             
            }
           maxi = max(maxi,a[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
