#include <stdio.h>

struct point
{
	float x;
	float y;
};

struct vp_line
{ //line for vanishing point
	float m; // slope of the line
	point p1; // coordinates of point 1 in the line
	point p2; // coordinates of point 2 in the line
	point intercept; //x and y intercept
};
	
void find_m(vp_line & line)
{
	float rise = line.p2.y - line.p1.y; // the height minus the hight aka the rise
	//testing if the line is vertical
	if(line.p2.x-line.p1.x == 0)
	{
		printf("Line Is Vertical get pogged, setting m to really high value");
		line.m = 999999999;
	}
	else// if the line is not vertical calculate m
	{
		float run = line.p2.x - line.p1.x;
		line.m = rise/run;
	}
	
}

void find_y_intercept(vp_line & line)
{
	line.intercept.y = (line.p1.y)-((line.m)*(line.p1.x));

}

int main()
{
	point p1;
	printf("Cheks if three points lie on the same line.\n");
	printf("Point #1 x : ");
	scanf("%f", &p1.x);
	printf("Point #1 y : ");
	scanf("%f", &p1.y);
	
	point p2;
	printf("Point #2 x : ");
	scanf("%f", &p2.x);
	printf("Point #2 y : ");
	scanf("%f", &p2.y);

	point p3;
	printf("Point #3 x : ");
	scanf("%f", &p3.x);
	printf("Point #3 y : ");
	scanf("%f", &p3.y);
	
	//creating the line that we will be checking.
	
	vp_line test_line;
	test_line.p1 = p1;
	test_line.p2 = p2;

	find_m(test_line); // finds the slope of the line rise over run
	find_y_intercept(test_line);
	printf(" m = %f", test_line.m);
	printf(" b = %f ",test_line.intercept.y);
	
	float h_x3 = ((test_line.m * p3.x) + test_line.intercept.y);
	printf("line at x3 %f", h_x3);
	//testing if point 3 is within 10%
	
	
	//float tmp1 = (test_line.p3.y * 0.9);
	//float tmp2 = (test_line.p3.y * 1.1);  
	
	//printf("\n tmp1 %f tmp2 %f ",tmp1,tmp2);	

	if( h_x3 >= (p3.y * 0.9) && h_x3 <= (p3.y * 1.10))
	{
		printf(" you hit it big boy");
	}

	return 0;
}
