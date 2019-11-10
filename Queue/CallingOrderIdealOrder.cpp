/*
  Created By : Sonu Sharma
  10-11-19     12:27
*/
/*


There are N processes to be completed. All the processes have a unique number assigned to them from 1 to N.

Now, we are given two things:

1)The calling order in which all the processes are called.
2)The ideal order in which all the processes should have been executed.

Executing a process takes 1 unit of time. Changing the position takes 1 unit of time.

We have to find out the unit of time required to complete all the process such that a process is executed from the
ideal order only when it exists at the same index in the calling order. We can push the first term from the calling
order to the last thus rotating the order.

*/
#include<bits/stdc++.h>
using namespace std;
void restaurant(){
    int n;cin>>n;
    queue<int>Q;
    vector<int>V(n);
    for(int i=0;i<n;i++){
        int a;cin>>a;
        Q.push(a);
    }
    for(int i=0;i<n;i++){
        cin>>V[i];
    }
    int i=0,ttime=0;
    while(!Q.empty()){
        if(Q.front()==V[i]){
            ttime++;i++;
            Q.pop();
        }
        else{
            ttime++;
            int t=Q.front();
            Q.pop();
            Q.push(t);
        }
    }
    cout<<ttime;
}
int main(){
    restaurant();
}
