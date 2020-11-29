#include <opencv2/imgcodecs.hpp> //imgcodecs for imgread
#include <opencv2/imgproc.hpp> //imgproc for line
#include <opencv2/highgui.hpp> //highgui for name window and setmousecallback
#include <opencv2/core/types.hpp> // for point;
#include <opencv2/core/matx.hpp> // gives us some hot vectors
#include <vector> // for them vecs bro
#include <string>// for that command line argument input baaaaaby
#include <iostream> // in and out you know the drill

int rows;
int cols;

int main(int argc, char * argv[])
{
	cv::String init_image;
	if( argc == 2)
	{
			init_image = argv[1];
	}
	else{
		std::cout << "error, include the name of the file after the exe file. example: run_me_in_cmd.exe test.png";
		return 0;
	}
	std::cout << "number of columns(x):  ";
	std::cin >> cols;
	std::cout << "number of rows(y):  ";
	std::cin >> rows;
	
	std::cout << "number of sub images: " << rows * cols << "\n"; 
	cv::Mat img = cv::imread(init_image);
	
	int xWidth = img.cols / cols;
	int yWidth = img.rows / rows;
	std::cout << xWidth; 
	
	for (int i =0; i < rows; i++){
		for(int j =0; j< cols; j++){
			int tlx = j*xWidth;
			int brx = xWidth;
			int tly = i*yWidth;
			int bry = yWidth;
			std::cout << " " <<  tlx << "," << tly << "," << brx << "," << bry << "\r";
			cv::Rect myROI(tlx,tly, brx, bry);
			cv::Mat croppedRef(img, myROI);
			cv::Mat cut_mat;
			croppedRef.copyTo(cut_mat);
			cv::String file_name =  std::to_string(i) + "-" + std::to_string(j) + ".jpg";
			std::cout << file_name;
			cv::imwrite(file_name, cut_mat);
		}
	}
	
	
	
	cv::namedWindow("Cyrus Crabb", cv::WINDOW_NORMAL);
	cv::imshow("Cyrus Crabb", img);
	cv::waitKey(0);
	
	return 0;
}