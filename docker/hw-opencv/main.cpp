#include <iostream>
#include <opencv2/opencv.hpp>

int main(int, char**) {
    cv::VideoCapture camera(0);
    if (!camera.isOpened()) {
        std::cerr << "ERROR: Could not open camera\n";
        return 1;
    }

    cv::namedWindow("Webcam");

    cv::Mat frame;

    while (1) {
        camera >> frame;

        cv::imshow("Webcam", frame);

        if (cv::waitKey(10) >= 0) {
            break;
        }
    }

    return 0;
}