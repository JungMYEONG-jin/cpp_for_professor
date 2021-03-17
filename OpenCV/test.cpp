#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace cv;

int main()
{


	VideoCapture cap(0); // 내장웹켐은 거의 0

	if (!cap.isOpened())
	{
		cout << "카메라를 열 수 없습니다. 카메라 번호를 다시 확인해주세요.";
		return -1;
	}


	namedWindow("카메라", 1);
	CascadeClassifier face_;

	face_.load("C:/opencv/sources/data/haarcascades/haarcascade_frontalface_default.xml");


	Mat frame;

	while (true)
	{
		bool frame_valid = true;
		try {
			cap >> frame;
		}
		catch (cv::Exception& e)
		{
			cerr << "Exception Occured!" << e.err << endl;
			frame_valid = false;
		}

		
		if (frame_valid)
		{
			try {

				Mat grayFrame;
				cvtColor(frame, grayFrame, CV_BGR2GRAY);
				equalizeHist(grayFrame, grayFrame);


				// vector를 이용해 face 저장
				vector<Rect> faces;

				face_.detectMultiScale(grayFrame, faces, 1.1, 3, CV_HAAR_FIND_BIGGEST_OBJECT | CV_HAAR_SCALE_IMAGE, Size(30, 30));


				for (auto i : faces)
				{
					Point lb(i.x + i.width, i.y + i.height);
					Point tr(i.x, i.y);

					rectangle(frame, lb, tr, Scalar(0, 255, 0), 3, 4, 0);
				}

				imshow("webcam", frame);
			}
			catch (cv::Exception& e)
			{
				cerr << "Exception Occured!" << e.err << endl;
			}
		}
		
		
		if (waitKey(1) == 27)
			break; //esc 누르면 종료


	}





	return 0;



}
