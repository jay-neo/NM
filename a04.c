#include<stdio.h>

float fn(float a){
	return (1.0/(1.0+a*a));
}

void Trapezoidal(int n,float l,float u){
	int i;
	float ans=0.0,h=(u-l)/n;
	for(i=0;i<=n;++i){
		if(i==0 || i==n) ans+=fn(l+i*h);
		else ans+=2*fn(l+i*h);
	}
	ans=(h/2)*ans;
	printf("Using Trapezoidal Rule The Integration Value = %0.3f\n",ans);
}

void Simpson(int n,float l,float u){
	int i;
	float ans=0.0,h=(u-l)/n;
	for(i=0;i<=n;++i){
		if(i==0 || i==n) ans+=fn(l+i*h);
		else if(i%2==0) ans+=2*fn(l+i*h);
		else ans+=4*fn(l+i*h);
	}
	ans=(h/3)*ans;
	printf("Using Simpson's 1/3 Rule The Integration Value = %0.3f\n",ans);
}


int main(){
	int i,n;
	float l,u;
	printf("Enter the number of intervals = ");
	scanf("%d",&n);
	printf("Enter the lower limit = ");
	scanf("%f",&l);
	printf("Enter the upper limit = ");
	scanf("%f",&u);

	Trapezoidal(n,l,u);
	Simpson(n,l,u);

	return 0;
}
/*
Enter the number of intervals = 7                                                                                                                                                 
Enter the lower limit = 0                                                                                                                                                         
Enter the upper limit = 1                                                                                                                                                         
Using Trapezoidal Rule The Integration Value = 0.785                                                                                                                              
Using Simpson's 1/3 Rule The Integration Value = 0.760 
*/

// code by jay-neo
