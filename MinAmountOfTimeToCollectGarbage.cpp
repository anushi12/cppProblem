class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int cnt = 0;
        int lastg =0, lastp = 0, lastm = 0;
        for(int i =0; i<garbage. size(); i++){
            for(auto it: garbage[i]){
                if(it == 'M') lastm = i;
                else if(it == 'G') lastg = i;
                else lastp = i;
                cnt ++;
            }
        }
        int total = cnt; int sum = 0;
        for(int  i = 0; i<travel.size();i++){
            sum += travel[i];

            if(lastm == i+1) total += sum;
            if(lastp == i+1) total += sum;
            if(lastg == i+1) total += sum;
        }
        return total;
    }
};
