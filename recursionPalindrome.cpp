//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
public:	
	bool rev(int i, string S){
	    int n =S.size();
	    if(i==n/2) return true;
	    if(S[i]!=S[n-i-1]) return false;
	    return rev(i+1,S);
	}
	
	int isPalindrome(string S)
	{
	    int i=0;
     return rev(i,S);
	}
};


int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}
