/*
  Created By : Sonu Sharma
  3-11-19      19:28
*/

#include <bits/stdc++.h>
using namespace std;
int isGreater(int x,int y,int z){
    int big=x>y?(x>z?x:z):(y>z?y:z);
    return big;
}
int main(){
    int n1,n2,n3,sum1=0,sum2=0,sum3=0;
    cin>>n1>>n2>>n3;
    int a1[n1],a2[n2],a3[n3];
    stack<int> s1,s2,s3;
    for(int i=0;i<n1;i++){
        cin>>a1[i];
        sum1+=a1[i];
    }
    for(int i=0;i<n2;i++){
        cin>>a2[i];
        sum2+=a2[i];
    }
    for(int i=0;i<n3;i++){
        cin>>a3[i];
        sum3+=a3[i];
    }
    for(int i=n1-1;i>=0;i--){
        s1.push(a1[i]);
    }
    for(int i=n2-1;i>=0;i--){
        s2.push(a2[i]);
    }
    for(int i=n3-1;i>=0;i--){
        s3.push(a3[i]);
    }
    while(sum1!=sum2 || sum2!=sum3){
        int z=isGreater(sum1,sum2,sum3);
        if(sum1==z){
            sum1=sum1-s1.top();
            s1.pop();
        }
        if(sum2==z){
            sum2=sum2-s2.top();
            s2.pop();
        }
        if(sum3==z){
            sum3=sum3-s3.top();
            s3.pop();
        }
    }
    cout<<sum1;
}
