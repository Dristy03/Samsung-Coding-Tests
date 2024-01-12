/*
Given an integer ‘K’ and a binary tree in string format. Every node of a tree has a value in the range of 0 to 9. We need to find the sum of elements at the K-th level from the root. The root is at level 0. 
Tree is given in the form: (node value(left subtree)(right subtree)) 

Examples: 

Input : tree = "(0(5(6()())(4()(9()())))(7(1()())(3()())))" 
        k = 2
Output : 14
*/


#include<iostream>
#include<string>
using namespace std;
 
int sumAtKthLevel(string s, int k){
    
    int lvl = -1;
    int ans = 0;
    
    for(int i=0;i<s.size();i++)
     {
        if(s[i] == '(')
        {
            lvl++;
        }
        else if(s[i] == ')')
        {
            lvl--;
        }
        else if(lvl == k)
        {
            int x=s[i]-'0';
			i++;			
			while(s[i]>=48 && s[i]<=57)
			{
				int d=s[i]-'0';
				x=x*10+d;
				i++;
			}
			i--;			
			ans+=x;
        }
      
    }
    
    return ans;
    
}
 
int main(){
    
    
    int t; 
    cin>>t;
    while(t--){
    string s;
    int k;
    cin>>s>>k;

    cout<<sumAtKthLevel(s,k)<<endl;
    }
    return 0;
}