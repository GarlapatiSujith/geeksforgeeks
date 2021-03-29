#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 


int lcs(char* x, char* y,int m, int n)
{
    // trying bottom up manner

    int dp[m+1][n+1]; // creating a matrix for the table

    //filling base cases 
    for(int i=0;i<=m;i++)
    {
        dp[i][0] = 0;
    }
    for(int j=0;j<=m;j++)
    {
        dp[0][j] = 0;
    }
    for(int i=1;i<=m;i++ ){
        for(int j=1;j<=n;j++){
            if(x[i-1] == y[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                //cout << "!";
            }
            else {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }//change
      
    return dp[m][n];
}   
int main(){
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m  = strlen(X);
    int n = strlen(Y);

     cout << "Length of LCS is " << lcs( X, Y, m, n ); 
}
