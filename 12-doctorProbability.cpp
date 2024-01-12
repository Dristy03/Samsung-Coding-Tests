/*
https://www.geeksforgeeks.org/samsung-interview-experience-set-39-campus-r-d-noida/
https://www.careercup.com/page?pid=samsung-interview-questions

A Doctor travels from a division to other division where divisions are connected like a graph(directed graph) and 
the edge weights are the probabilities of the doctor going from that division to other connected division but the 
doctor stays 10mins at each division now there will be given time and had to find the division in which he will be 
staying by that time and is determined by finding division which has high probability.

Input is number of test cases followed by the number of nodes, edges, time after which we need to find the division 
in which he will be there, the edges starting point, end point, probability.

Note: If he reaches a point where there are no further nodes then he leaves the lab after 10 mins and the traveling 
time is not considered and during that 10min at 10th min he will be in next division, so be careful

2
6 10 40 
1 2 0.3 1 3 0.7 3 3 0.2 3 4 0.8 2 4 1 4 5 0.9 4 4 0.1 5 6 1.0 6 3 0.5 6 6 0.5
6 10 10 
1 2 0.3 1 3 0.7 3 3 0.2 3 4 0.8 2 4 1 4 5 0.9 4 4 0.1 5 6 1.0 6 3 0.5 6 6 0.5

6 0.774000  
3 0.700000
*/

#include <iostream>
#include<vector>
#include<climits>
#include<queue>
#include <iomanip>
using namespace std;

struct node
{
    int to;
    double probab;
};
int m,n;

void doctorProbability(int u,vector<vector<node>>adj,int t,double probability,vector<double>&answer)
{
    if(t<=0)
    {
        answer[u]+=probability;
        return;
    }
    
    for(auto v: adj[u])
    {
        probability *= v.probab;
        doctorProbability(v.to,adj,t-10,probability,answer);
        probability /= v.probab;
    }
}

int main() {

   int T;
   cin>>T;
   while(T--)
   {
       int t;
       cin>>n>>m>>t;
   
       vector<vector<node> >adj(n+1);
       vector<double>answer(n+1);
       
       
       for(int i=0;i<m;i++)
       {
           int u,v;
           double w;
           cin>>u>>v>>w;
           adj[u].push_back({v,w});
       }
       
       doctorProbability(1,adj,t,1.0,answer);
       
       auto maxProbIt = max_element(answer.begin() + 1, answer.end());
       int finalDivision = distance(answer.begin(), maxProbIt);

        cout << finalDivision << " " <<fixed<<setprecision(6)<< *maxProbIt << "\n";
       
      
   
   }
   
    
    
}