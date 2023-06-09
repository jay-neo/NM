#include<stdio.h>
#define MAX 10

int main(){
	int i,j,n;
	float x,p,ans=0.0,data[MAX][2];

	printf("Enter the number of observations = ");
	scanf("%d",&n);
	
	printf("Enter %d observations:\n",n);
	for(i=0;i<n;i++){
		// printf("Enter %d x value = ",i+1);
		scanf("%f",&data[i][0]);
		// printf("Enter %d f(x) = ",i+1);
		scanf("%f",&data[i][1]);
	}

	printf("Enter the interpolated value = ");
	scanf("%f",&x);

	for(i=0;i<n;++i){
		p=1.0;
		for(j=0;j<n;++j)
			if(i!=j)
				p*=(x-data[j][0])/(data[i][0]-data[j][0]);
		ans+=(p*data[i][1]);
	}

	printf("Required Solution f(%0.1f)=%0.3f",x,ans);
}

/*
Enter the number of observations = 4
Enter 4 observations:                                                                                                                                                             
-2 -9
-1 -1
2 11
4 69
Enter the interpolated value = 0
Required Solution f(0.0)=1.000
*/

// code by jay-neo
