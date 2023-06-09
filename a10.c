#include<stdio.h>
#include<math.h>
#define MAX 10
double data[2][MAX];

int main(){
	int i,j,n,e;
	double x=0,y=0,xy=0,x2=0,a,b;
	
	printf("1. Stright Line\n2. Exponential Curve\nChoice the equation = ");
	scanf("%d",&e);
	
	printf("Enter the number of observations = ");
	scanf("%d",&n);
	
	printf("Enter the obersation:\n");
	for(i=0;i<n;++i){
		// printf("Enter the value of %dth x = ",i+1);
		scanf("%lf",&data[0][i]);
		// printf("Enter the value of %dth y = ",i+1);
		scanf("%lf",&data[1][i]);
		if(e==2) data[1][i]=log(data[1][i]);
	}
	
	for(i=0;i<n;++i){
		x+=data[0][i];
		y+=data[1][i];
		xy+=(data[0][i]*data[1][i]);
		x2+=(data[0][i]*data[0][i]);
	}
	
	printf("The Data table is:\n");
	for(i=0;i<n;i++) printf("%0.2lf ",data[0][i]); printf("\n");
	for(i=0;i<n;i++) printf("%0.2lf ",data[1][i]); printf("\n");
	
	a=(y*x2-x*xy)/(n*x2-x*x);
	b=(x*y-n*xy)/((x*x-n*x2)*1.0);

	printf("The final euation :\n");
	if(e==1) printf("y=%0.1lf+%0.2lfx",a,b);
	else if(e==2) printf("y=%0.4lfe^(%0.3lf)",exp(a),b);
	
}
/*
1. Stright Line                                                                                                                                                                   
2. Exponential Curve                                                                                                                                                              
Choice the equation = 1
Enter the number of observations = 5
Enter the obersation:                                                                                                                                                             
0 1
1 3
3 2
6 5
8 4
The final euation :                                                                                                                                                               
y=1.6+0.38x

1. Stright Line                                                                                                                                                                   
2. Exponential Curve                                                                                                                                                              
Choice the equation = 2
Enter the number of observations = 5
Enter the obersation:                                                                                                                                                             
1 10
5 15
7 12
9 15
12 21
The final euation :                                                                                                                                                               
y=9.4751e^(0.059)
*/
// code by jay-neo