#include <iostream>
#include <opencv2/opencv.hpp>
#include "VideoCaptureStage.hpp"
#include "ScaleStage.hpp"

int main(int argc, char** argv )
{
/*
    if ( argc != 2 )
    {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }

    Mat image;
    image = imread( argv[1], 1 );

    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }
    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", image);

    waitKey(0);
// */

/*
    const cv::Mat asd(2, 2, CV_8U);
    std::cout << "Original: " << (int) asd.data[0] << std::endl;
    ScaleStage s(asd);
    std::cout << "After: " << (int) asd.data[0] << std::endl;
    std::cout << s.GetStageName() << std::endl;
// */

    VideoCaptureStage vcs;
    ScaleStage ss(vcs, 640, 480);
    ss.Execute();
    auto asd = ss.GetOutputImage();

    cv::imshow("test", asd);
    cv::waitKey(0);

    return 0;
}
