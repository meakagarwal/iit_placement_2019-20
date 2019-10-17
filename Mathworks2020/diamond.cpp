#include<bits/stdc++.h>
using namespace std;
 int solve(vector<vector<int>>& grid,vector<vector<vector<int> > > &dp, int x1, int y1,int x2 ){
   
    int m=grid.size();
    int n=grid[0].size();
    int ans=0;       
    int y2= x1 + y1 - x2;
     
    if(dp[x1][y1][x2] != -1)
        return dp[x1][y1][x2];
    
    if(grid[x1][y1]==-1 || grid[x2][y2]==-1){
        ans=INT_MIN;
        return dp[x1][y1][x2]=ans;
    }
    
    if(x1==x2 && y1==y2){
        if(grid[x1][y1]==1)
            ans+=1;
         
         if(x1==m-1 && y1==n-1)
             return dp[x1][y1][x2]=ans;
    }
    else{
        if(grid[x1][y1]==1)
            ans++;
    
        if(grid[x2][y2]==1)
            ans++;
    }
    
    int cost1=INT_MIN, cost2=INT_MIN,cost3=INT_MIN,cost4=INT_MIN;
    
    //right down
    if(y1+1<n && x2+1<m)
        cost1=solve(grid,dp,x1,y1+1,x2+1);
        
    //right right
    if(y1+1<n && y2+1<n ) 
        cost2=solve(grid,dp,x1,y1+1,x2);
        
    //down right
    if(x1+1<m && y2+1<n )
        cost3=solve(grid,dp,x1+1,y1,x2);
        
    //down down
    if(x1+1<m && x2+1<m)
        cost4= solve(grid,dp,x1+1,y1,x2+1);
    
    ans += max(cost1, max(cost2, max(cost3,cost4)));
    
    
    return dp[x1][y1][x2] = ans;
}

int main() {
    
    int m,n;
    cin>>m>>n;
    vector<vector<int>> grid(m,vector<int>(n,0));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cin>>grid[i][j];
    }
    
    vector<vector<vector<int> > > dp(n, vector<vector<int> >(m, vector<int>(n,-1)));
    
    int ans= solve(grid, dp, 0,0,0);
    cout<<max(ans,0)<<endl;
    
    return 0;
}

