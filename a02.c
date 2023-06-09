#include<stdio.h>
#define MAX 10

int main(){
	int i,j,n;
	float x,h,u,nu,f,ans,data[MAX][MAX];

	printf("Enter the number of observations = ");
	scanf("%d",&n);
	
	printf("Enter %d observations:\n",n);
	for(i=0;i<n;i++){
		// printf("Enter %d x value = ",i+1);
		scanf("%f",&data[i][0]);
		// printf("Enter %d f(x) = ",i+1);
		scanf("%f",&data[i][1]);
		
		if(i==1) h=data[1][0]-data[0][0];
		
		if(i>1 && data[i][0]!=data[i-1][0]+h){
			printf("Not equispaced inputs for x value!!");
			return 0;
		}
		
	}
	printf("Enter the interpolated value = ");
	scanf("%f",&x);
	
	//Calculate the table
	for(i=n-1;i>=1;--i)
		for(j=2;j<n-i+2;++j)
			data[i-1][j]=data[i][j-1]-data[i-1][j-1];
	
	//Print the table
	for(i=0;i<n;i++){
		for(j=0;j<n-i+1;j++)
			printf("%0.2f ",data[i][j]);
		printf("\n");
	}
	
	//Calculate the final interpolated value
	u=(x-data[n-1][0])/h;
	ans=data[n-1][1];
	
	for(i=1;i<n;i++){
		nu=u;
		for(j=1;j<n-i;++j) nu*=(u+j);
		f=1;
		for(j=2;j<=n-i;++j) f*=j;
		ans+=((nu*data[i-1][n-i+1])/f);
	}

	
	printf("Required Solution f(%0.1f)=%0.3f",x,ans);	
}
/*
Enter the number of observations = 4
Enter 4 observations:                                                                                                                                                             
0 1
1 0
2 1
3 10
Enter the interpolated value = 2.5
0.00 1.00 -1.00 2.00 6.00                                                                                                                                                         
1.00 0.00 1.00 8.00                                                                                                                                                               
2.00 1.00 9.00                                                                                                                                                                    
3.00 10.00                                                                                                                                                                        
Required Solution f(2.5)=4.125
*/

// code by jay-neo
