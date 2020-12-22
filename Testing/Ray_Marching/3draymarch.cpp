#include <opencv2/imgcodecs.hpp> //imgcodecs for imgread
#include <opencv2/imgproc.hpp> //imgproc for line
#include <opencv2/highgui.hpp> //highgui for name window and setmousecallback
#include <opencv2/core/types.hpp> // for point;
#include <opencv2/core/matx.hpp> // gives us some hot vectors
#include <vector> // for them vecs bro
#include <iostream> // in and out you know the drill

int rows =3;
int cols =3;

int main()
{
	std::cout << "fancy a libner?" << "\n"; 
	
	
	cv::Mat A;
	A = cv::Mat::zeros(rows, cols, CV_64F);
	cv::namedWindow("Cyrus Crabb", cv::WINDOW_NORMAL);
	int y = 1;
	int x = 1;
	uchar b = 100;
	int r = 100;
	int g = 100;
	
	cv::Point3_<uchar>* p = A.ptr<cv::Point3_<uchar> >(y,x);
	p -> x = 100;
	p -> y = 100;
	p -> z = 100;
	std::cout << A;
	cv::imshow("Cyrus Crabb", A);
	cv::waitKey(0);
	
	return 0;
}