#include<stdio.h>
#define MAX 20

float M[MAX][MAX];

void Gauss_Elimination(int n){
    int i,j,k;
    float ans[n];

    ans[n-1]=M[n-1][n]/M[n-1][n-1];

    for(i=n-2;i>=0;--i){
        ans[i]=M[i][n];

        for(j=i+1;j<n;++j)
            ans[i]-=M[i][j]*ans[j];

        ans[i]/=M[i][i];
    }

    printf("The final solution set:\n");
    for(i=0;i<n;++i)
        printf("x[%d] = %0.3f\n",i+1,ans[i]);
}


float Check(int n){
    int i,j,k;
    float ratio,det=1.0;

    for(i=0;i<n;++i){
        for(j=i+1;j<=n;++j){
            if(M[j][j]) ratio=M[j][i]/M[i][i];
            for(k=0;k<=n;++k){
                M[j][k]=M[j][k]-(ratio*M[i][k]);
            }
        }       
    }

    for(i=1;i<=n;i++)
        det*=M[i][i];

    return det;
}


int main(){
    int i,j,n;

    printf("Enter the number of terms = ");
    scanf("%d",&n);

    printf("Enter the %dx%d agumented matrix:\n",n,n+1);
    for(i=0;i<n;++i)
        for(j=0;j<=n;++j)
            scanf("%f",&M[i][j]);

    if(Check(n)){
        printf("After determinant operation the agumented matrix:\n");
        for(i=0;i<n;++i){
            for(j=0;j<=n;++j)
                printf("%0.2f\t",M[i][j]);
            printf("\n");
        }
        Gauss_Elimination(n);
    }
    else{
        printf("The determinant value is 0\n");
        printf("So there no gauss operation should be done!!\n");
    }

}

/*
Enter the number of terms = 3                                                                                                                                                     
Enter the 3x4 agumented matrix:                                                                                                                                                   
5 -1 1 10                                                                                                                                                                         
2 4 0 12                                                                                                                                                                          
1 1 5 -1                                                                                                                                                                          
After determinant operation the agumented matrix:                                                                                                                                 
5.00    -1.00   1.00    10.00                                                                                                                                                     
-0.00   4.40    -0.40   8.00                                                                                                                                                      
-0.00   -0.00   4.91    -5.18                                                                                                                                                     
The final solution set:                                                                                                                                                           
x[1] = 2.556                                                                                                                                                                      
x[2] = 1.722                                                                                                                                                                      
x[3] = -1.056 
*/

/*
Enter the number of terms = 3                                                                                                                                                     
Enter the 3x4 agumented matrix:                                                                                                                                                   
1 1 1 9                                                                                                                                                                           
2 -3 1 13                                                                                                                                                                         
3 4 5 40                                                                                                                                                                          
After determinant operation the agumented matrix:                                                                                                                                 
1.00    1.00    1.00    9.00                                                                                                                                                      
0.00    -5.00   -1.00   -5.00                                                                                                                                                     
0.00    -0.00   1.80    12.00                                                                                                                                                     
The final solution set:                                                                                                                                                           
x[1] = 2.667                                                                                                                                                                      
x[2] = -0.333                                                                                                                                                                     
x[3] = 6.667    
*/


// code by jay-neo
