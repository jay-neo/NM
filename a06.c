#include<stdio.h>

double fn(double x,double y){ return (y-x)/(y+x);}

void RK(double h,double x,double y,double xn){
	double k1,k2,k3,k4;
	while(x<xn){
		k1=h*fn(x,y);
		k2=h*fn(x+h/2,y+k1/2);
		k3=h*fn(x+h/2,y+k2/2);
		k4=h*fn(x+h,y+k3);
		y+=(k1+2*k2+2*k3+k4)/6;
		x+=h;
	}
	printf("Using R-K method the value of yn = %0.3lf\n",y);
}

void Euler(double h,double x,double y,double xn){
	while(x<xn){
		y+=h*fn(x,y);
		x+=h;
	}
	printf("Using Euler method the value of yn = %0.3lf\n",y);
}


int main(){
	double x0,y0,xn,h;

	printf("Enter the step size = ");
	scanf("%lf",&h);
	printf("Enter the x0 value = ");
	scanf("%lf",&x0);
	printf("Enter the y0 value = ");
	scanf("%lf",&y0);
	printf("Enter the xn value = ");
	scanf("%lf",&xn);


	RK(h,x0,y0,xn);
	Euler(h,x0,y0,xn);
}

/*
Enter the step size = 0.02
Enter the x0 value = 0
Enter the y0 value = 1
Enter the xn value = 0.1
Using R-K method the value of yn = 1.091                                                                                                                                          
Using Euler method the value of yn = 1.093    
*/

// code by jay-neo

