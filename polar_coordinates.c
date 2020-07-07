#include<stdio.h>
#include<math.h>

//Define polar structure to work with points in two-dimensional plane. Define type for the structure. Properties of polar structure: 
//- r stores real values distance of the point to origin. 
//- a stores real valued angle of the point to origin, in unit of degrees, valid value range is [0.0, 360.0). 
//Values out of the range are corrected to the range, i.e. 380.0 is corrected to 20.0 or 20.0 is corrected to 340.0.
//Define following functions: 
//- pprint prints a polar variable on console in form of (5.0/_30.0). 
//- pscan prompts user to enter coordinates of polar point. 
//- pmul computes multiplication of two polar and returns result 
//- pdiv computes division of one polar to another.
//Test your function in a program that receives two points in polar from user, computes multiplication and division, and prints result on console in polar form.   

struct polar{
	float r;
	double angle;
};
int main(){
	
	struct polar p;
	struct polar p2;
	
	printf("Enter r of point one:");
	scanf("%f",&p.r);
	printf("Enter angle of point one:");
	scanf("%lf",&p.angle);
	if(p.angle>360.0){
		printf("(%.1f,%.1f)",p.r,p.angle-360.0);
	}
	else if(p.angle<0.0){
		printf("(%.1f,%.1f)",p.r,p.angle+360.0);
	}
	else{
		printf("(%.1f,%.1f)",p.r,p.angle);
	}
	printf("\nEnter r of point two:");
	scanf("%f",&p2.r);
	printf("Enter angle of point two:");
	scanf("%lf",&p2.angle);
	if(p2.angle>360.0){
		p2.angle-=360.0;
		printf("(%.1f,%.1f)",p2.r,p2.angle);
	}
	else if(p2.angle<0.0){
		p2.angle+=360.0;
		printf("(%.1f,%.1f)",p2.r,p2.angle);
	}
	else{
		printf("(%.1f,%.1f)",p2.r,p2.angle);
	}
	
	double mltp_r=(+p.r)*(+p2.r)*1.0;
	double a=p.angle;
	double b=p2.angle;
	if(p2.angle>a){
		a=p2.angle;
		b=p.angle;
	}
	double mltp_a=(a-b)*1.0;
	double skaler=mltp_r*cos(mltp_a)*1.0;
	printf("\nSkaler multiplication: |r1|.|r2|.cos(Q)=%.2f",skaler);
	
	return 0;
}
