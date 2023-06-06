#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>

using namespace cv;
using namespace std;

void main() {
    string path = "Documents/cpp/test.png";
    Mat img = imread(path);

    CascadeClassifier faceCascade;
    faceCascade.load("Documents/cpp/haarcascade.xml");

    if (faceCascade.empty()) {
        cout << "XML file not loaded" << endl;
    }

    vector<Rect> faces;
    faceCascade.detectMultiScale(img, faces, 1.1, 10);

    for (int i = 0; i < faces.size(); i++) {
        rectangle(img, faces[i].tl(), face[i].br(), Scalar(0, 255, 0), FILLED);
    }

    imshow("Result", img);
    waitKey(0);
    
} 