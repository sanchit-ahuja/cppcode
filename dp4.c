#include<stdio.h>

int min(int x, int y) 
{ 
	if(x<y){
        return x;
    }
    return y;
} 

int editDistDP(int str1[], int str2[], int m, int n) 
{ 
	// Create a table to store results of subproblems 
	int dp[m+1][n+1]; 

	// Fill d[][] in bottom up manner 
	for (int i=0; i<=m; i++) 
	{ 
		for (int j=0; j<=n; j++) 
		{ 
			// If first string is empty, only option is to 
			// insert all characters of second string 
			if (i==0) 
				dp[i][j] = j; // Min. operations = j 

			// If second string is empty, only option is to 
			// remove all characters of second string 
			else if (j==0) 
				dp[i][j] = i; // Min. operations = i 

			// If last characters are same, ignore last char 
			// and recur for remaining string 
			else if (str1[i-1] == str2[j-1]) 
				dp[i][j] = dp[i-1][j-1]; 

			// If the last character is different, consider all 
			// possibilities and find the minimum 
			else
				dp[i][j] = 1 + min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1]); // Replace 
		} 
	} 

	return dp[m][n]; 
} 

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int m;
        scanf("%d",&m);
        int arr1[m];
        for(int i=0;i<m;i++){
            scanf("%d",&arr1[i]);
        }
        int n;
        scanf("%d",&n);
        int arr2[n];
        for(int i=0;i<n;i++){
            scanf("%d",&arr2[i]);
        }
        printf("%d\n",editDistDP(arr1,arr2,m,n));
    }
}