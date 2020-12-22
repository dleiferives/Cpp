#include <stdio.h>


//used structures
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


// global variables
	point vp_3;
	point vp_2;
	point vp_1;
	int point_iterator =1;



//templates
 	


//functions
void fill_point(point & i_point)
{
	printf("Point #%i x : ",point_iterator);
	scanf("%f", &i_point.x);
	printf("Point #%i y : ",point_iterator);
	scanf("%f", &i_point.y);
	point_iterator++;
}
void find_m(vp_line & line) // just some simple arithmetic to find the slope of the line
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

void find_y_intercept(vp_line & line) // a function that finds the y intercept of a given line
{				      // stores the value into the intercept value
	line.intercept.y = (line.p1.y)-((line.m)*(line.p1.x));

}

void find_vp(point &vp, vp_line line1, vp_line line2)// finds the intersection point of two given lines, aka my guy the vanishing point
{
	if( line1.m != line2.m) 
	{
		vp.x = ((line2.intercept.y-line1.intercept.y)/(line1.m-line2.m));
	        vp.y = (line1.m * vp.x) + line1.intercept.y;	
	}
	else
	{
		printf("lines are parrelel no vanishing point\n");
	}
}

void fill_vp_line(vp_line & line, point vp1, point vp2)
{
	line.p1 = vp1;
	line.p2 = vp2;
	find_m(line);
	find_y_intercept(line);
}

int main()
{
	printf("Cheks if three points lie on the same line.\n");
	point p1, p2, p3, p4;
	fill_point(p1);
	fill_point(p2);
	fill_point(p3);
	fill_point(p4);


	
	//creating the line that we will be checking.
	
	vp_line vp1_line1, vp1_line2, vp2_line1, vp2_line2;
	fill_vp_line(vp1_line1, p1, p2);
	fill_vp_line(vp1_line2, p3, p4);	
	fill_vp_line(vp2_line1, p1, p3);
	fill_vp_line(vp2_line2, p2, p4);
	
	printf(" m = %f ", vp1_line1.m);
	printf(" b = %f \n",vp1_line1.intercept.y);

	printf(" m = %f ", vp1_line2.m);
	printf(" b = %f \n",vp1_line2.intercept.y);

	printf(" m = %f ", vp2_line1.m);
	printf(" b = %f \n",vp2_line1.intercept.y);
	
	printf(" m = %f ", vp2_line2.m);
	printf(" b = %f \n",vp2_line2.intercept.y);

	float h_x3 = ((vp1_line1.m * p3.x) + vp1_line1.intercept.y);
	printf("line at x3 %f\n", h_x3); // the height where the line given by p1 and p2 crosses point 3's x coordinate
	//testing if point 3 is within 10%

	if( h_x3 >= (p3.y * 0.9) && h_x3 <= (p3.y * 1.10))
	{
		printf(" you hit it big boy\n");
	}
	
	find_vp(vp_1, vp1_line1, vp1_line2);
	find_vp(vp_2, vp2_line1, vp2_line2);

	printf(" Vanishing Point(%f,%f) \n",vp_2.x, vp_2.y);
	printf(" Vanishing Point(%f,%f) \n",vp_1.x, vp_1.y);

	return 0;
}
	
