#include<iostream>
using namespace std;

// This program calculates the maximum number of working days
// that can be scheduled in a given number of days, while
// also allowing for at least one day of rest after every
// three working days.
int main(){
int t;
// t is the number of test cases
cin >>t;
while(t--){
int n;
// n is the number of days available for scheduling
cin >>n;
// We need to allow for at least one day of rest after every three working days,
// so we need to subtract 3 from the total number of days.
n = n-3;
// The maximum number of working days that can be scheduled is then calculated by
// dividing the number of remaining days by 3 and subtracting 1.
cout <<(n/3)-1<<endl;
}
}



