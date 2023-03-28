int longestSuccessiveElements(vector<int>&a) {
    // Write your code here.
    int longest = 1;
    int lastSmallest = INT_MIN;
    int cnt = 0;
    sort(a.begin(),a.end());
    for(int i=0;i<a.size();i++){
        if(a[i]-1 == lastSmallest){
            cnt = cnt+1;
            lastSmallest=a[i];
        }
        else if(a[i]!=lastSmallest){
            cnt = 1;
            lastSmallest=a[i];
        }
      longest = max(longest,cnt);
    }
    return longest;
}
