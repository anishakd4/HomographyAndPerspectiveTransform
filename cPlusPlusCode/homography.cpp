#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/calib3d.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(){

    //Read both the book images
    Mat book1 = imread("../assets/book1.jpg");
    Mat book2 = imread("../assets/book2.jpg");


    //These are the four corners of the book in both the images
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

    //Calculate homography from book1 to book2
    Mat homographyMat1 = findHomography(pts_book1, pts_book2);
    //Calculate homography from book2 to book1
    Mat homographyMat2 = findHomography(pts_book2, pts_book1);

    //warp book1 to book2
    warpPerspective(book1, result1, homographyMat1, book2.size());
    //warp book2 to book1
    warpPerspective(book2, result2, homographyMat2, book1.size());

    //create windows to show images
    namedWindow("book1", WINDOW_NORMAL);
    namedWindow("book2", WINDOW_NORMAL);
    namedWindow("result1", WINDOW_NORMAL);
    namedWindow("result2", WINDOW_NORMAL);

    //display images
    imshow("book1", book1);
    imshow("book2", book2);
    imshow("result1", result1);
    imshow("result2", result2);

    //Press esc to exit the program
    waitKey(0);

    //Close all the opened windows
    destroyAllWindows();
    
    return 0;
}