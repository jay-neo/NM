#include<stdio.h>
#define MAX 20

float M[MAX][MAX];

float Abs(float a){ return a>=0?a:((-1)*a); }

void Swap(float *a,float *b){ *b=*a+*b-(*a=*b); }

void Gauss_Seidel(int n){
    int i,j,f,idx;
    float sum,prev[n],curr[n];

    for(i=0;i<n;++i) prev[i]=curr[i]=0;

    // Rearrange agumented matrix i.e. prerequisite of Gauss-Sadel formula
    for(i=0;i<n;++i){
        idx=i;
        for(j=0;j<n;++j){
            if(Abs(M[i][i])<Abs(M[i][j]))
                idx=j;
        }
        if(idx!=i){
            for(j=0;j<=n;++j)
                Swap(&M[i][j],&M[idx][j]);
        }
    }

    // Calculate the main solution
    while(1){
        f=0;

        for(i=0;i<n;++i){
            sum=0;
            prev[i]=curr[i];
            for(j=0;j<n;++j){
                if(j!=i)
                    sum+=M[i][j]*curr[j];
            }
            curr[i]=(M[i][n]-sum)/M[i][i];

        }

        for(i=0;i<n;++i){
            if(Abs(curr[i]-prev[i])<0.00001)
                f+=1;
        }

        if(f==3) break;
    }

    printf("The final solution set:\n");
    for(i=0;i<n;++i)
        printf("x[%d] = %0.2f\n",i+1,curr[i]);
    
}

int main(){
    int i,j,n;

    printf("Enter the number of terms = ");
    scanf("%d",&n);

    printf("Enter the %dx%d agumented matrix:\n",n,n+1);
    for(i=0;i<n;++i)
        for(j=0;j<=n;++j)
            scanf("%f",&M[i][j]);

    Gauss_Seidel(n);
}

/*
Enter the number of terms = 3
Enter the 3x4 agumented matrix:                                                                                                                                                   
3 1 5 13                                                                                                                                                                          
5 -2 1 4                                                                                                                                                                          
1 6 -2 -1
The final solution set:                                                                                                                                                           
x[1] = 0.55                                                                                                                                                                       
x[2] = 0.47                                                                                                                                                                       
x[3] = 2.18
*/

// code by jay-neo
