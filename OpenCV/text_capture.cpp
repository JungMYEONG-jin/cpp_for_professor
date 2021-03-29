#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using namespace cv;

void detect_text(string input) {
    Mat large = imread(input);

    Mat rgb;
    // downsample and use it for processing
    pyrDown(large, rgb);
    pyrDown(rgb, rgb);
    Mat small;
    cvtColor(rgb, small, CV_BGR2GRAY);
    // morphological gradient
    Mat grad;
    Mat morphKernel = getStructuringElement(MORPH_ELLIPSE, Size(3, 3));
    morphologyEx(small, grad, MORPH_GRADIENT, morphKernel);
    // binarize
    Mat bw;
    threshold(grad, bw, 0.0, 255.0, THRESH_BINARY | THRESH_OTSU);
    // connect horizontally oriented regions
    Mat connected;
    morphKernel = getStructuringElement(MORPH_RECT, Size(9, 1));
    morphologyEx(bw, connected, MORPH_CLOSE, morphKernel);
    // find contours
    Mat mask = Mat::zeros(bw.size(), CV_8UC1);
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    findContours(connected, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
    // filter contours
    for (int idx = 0; idx >= 0; idx = hierarchy[idx][0]) {
        Rect rect = boundingRect(contours[idx]);
        Mat maskROI(mask, rect);
        maskROI = Scalar(0, 0, 0);
        // fill the contour
        drawContours(mask, contours, idx, Scalar(255, 255, 255), CV_FILLED);

        RotatedRect rrect = minAreaRect(contours[idx]);
        double r = (double)countNonZero(maskROI) / (rrect.size.width * rrect.size.height);

        Scalar color;
        int thickness = 1;
        // assume at least 25% of the area is filled if it contains text
        if (r > 0.25 &&
            (rrect.size.height > 8 && rrect.size.width > 8) // constraints on region size
            // these two conditions alone are not very robust. better to use something 
            //like the number of significant peaks in a horizontal projection as a third condition
            ) {
            thickness = 2;
            color = Scalar(0, 255, 0);
        }
        else
        {
            thickness = 1;
            color = Scalar(0, 0, 255);
        }

        Point2f pts[4];
        rrect.points(pts);
        for (int i = 0; i < 4; i++)
        {
            line(rgb, Point((int)pts[i].x, (int)pts[i].y), Point((int)pts[(i + 1) % 4].x, (int)pts[(i + 1) % 4].y), color, thickness);
        }
    }

    imwrite("cont.jpg", rgb);
}

static void detect_mser(const string input, bool pred)
{
    Mat img = imread(input, 1);
    Mat rgb;
    
    pyrDown(img, rgb);
    pyrDown(rgb, rgb);

    Mat small;
    cvtColor(rgb, small, CV_BGR2GRAY);

    Ptr<MSER> ms = MSER::create();

    Mat dMat;
    small.copyTo(dMat);

    vector<vector<Point>> reg;
    vector<Rect> mser_box;
    
    ms->detectRegions(dMat, reg, mser_box);

    RNG rng(12345);

    if (pred)
    {
        int idx = 0;
        for (auto i : reg)
        {
            Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
            rectangle(rgb, mser_box[idx], color);
            idx++;
        }
    }
    else {
        for (auto i : reg)
        {
            unsigned b = rng.uniform(0, 255);
            unsigned g = rng.uniform(0, 255);
            unsigned r = rng.uniform(0, 255);

            for (auto p : i)
            {
                rgb.at<Vec3b>(p.y, p.x)[0] = b;
                rgb.at<Vec3b>(p.y, p.x)[1] = g;
                rgb.at<Vec3b>(p.y, p.x)[2] = r;
            }
        }
    }
    imshow("mser", rgb);
    waitKey(0);

}



static void merged_mser(const string input, bool pred)
{
    Mat large = imread(input);

    Mat rgb;

    pyrDown(large, rgb);
    pyrDown(rgb, rgb);
    Mat small;
    cvtColor(rgb, small, CV_BGR2GRAY);

    Mat grad;
    Mat kernel = getStructuringElement(MORPH_ELLIPSE, Size(3, 3));
    morphologyEx(small, grad, MORPH_CLOSE, kernel);

    Mat bin;
    threshold(grad, bin, 0.0, 255.0, THRESH_BINARY | THRESH_OTSU);

    Mat connected;
    kernel = getStructuringElement(MORPH_RECT, Size(9, 1));
    morphologyEx(bin, connected, MORPH_CLOSE, kernel);

   

    Mat dMat;
    bin.copyTo(dMat);

    Ptr<MSER> ms = MSER::create();

    vector<vector<Point>> reg;
    vector<Rect> mser_box;
    ms->detectRegions(dMat, reg, mser_box);

    RNG rng(12345);

    if (pred)
    {
        for (int i = 0; i < reg.size(); i++)
        {
            Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
            rectangle(rgb, mser_box[i], color);
        }
    }
    else {

        for (auto i : reg)
        {
            unsigned b = rng.uniform(0, 255);
            unsigned g = rng.uniform(0, 255);
            unsigned r = rng.uniform(0, 255);

            for (auto p : i)
            {
                rgb.at<Vec3b>(p.y, p.x)[0] = b;
                rgb.at<Vec3b>(p.y, p.x)[1] = g;
                rgb.at<Vec3b>(p.y, p.x)[2] = r;
            }
        }


    }

    imshow("Mser2", rgb);
    waitKey(0);
}



int main()
{

	const string filename = "Handicap_Sign.jfif";
	const bool pred = false;
    //pred = true;
    //detect_text(filename);
    //detect_mser(filename, pred);
    merged_mser(filename, pred);



}
