#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/calib3d.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(){
    Mat book1 = imread("../assets/book1.jpg");
    Mat book2 = imread("../assets/book2.jpg");

    vector<Point2f> pts_book1, pts_book2;

    pts_book1.push_back(Point2f(650, 1326));
    pts_book1.push_back(Point2f(2113, 1333));
    pts_book1.push_back(Point2f(2159, 3680));
    pts_book1.push_back(Point2f(578, 3680));

    pts_book2.push_back(Point2f(1456, 1580));
    pts_book2.push_back(Point2f(2237, 2048));
    pts_book2.push_back(Point2f(1417, 3668));
    pts_book2.push_back(Point2f(604, 2750));

    Mat result1, result2;

    Mat homographyMat1 = findHomography(pts_book1, pts_book2);
    Mat homographyMat2 = findHomography(pts_book2, pts_book1);

    warpPerspective(book1, result1, homographyMat1, result1.size());
    warpPerspective(book2, result2, homographyMat2, result2.size());

    namedWindow("book1", WINDOW_NORMAL);
    namedWindow("book2", WINDOW_NORMAL);
    namedWindow("result1", WINDOW_NORMAL);
    namedWindow("result2", WINDOW_NORMAL);

    imshow("book1", book1);
    imshow("book2", book2);
    imshow("result1", result1);
    imshow("result2", result2);

    waitKey(0);

    destroyAllWindows();
    return 0;
}