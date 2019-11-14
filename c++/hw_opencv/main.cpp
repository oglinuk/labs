#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        printf("Usage: ./OpenCVDisplayImg <image_path>\n");
        return -1;
    }

    Mat img;
    img = imread(argv[1], 1);

    if (!img.data) {
        printf("No image data\n");
        return -1;
    }

    namedWindow("Image", WINDOW_AUTOSIZE);
    imshow("Image", img);

    waitKey(0);

    return 0;
}