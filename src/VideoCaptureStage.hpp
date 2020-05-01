#pragma once

#include <string_view>
#include <opencv2/opencv.hpp>
#include "GeneratorStage.hpp"

class VideoCaptureStage: public GeneratorStage
{
public:
    VideoCaptureStage(int device = 0);
    void Execute();
    std::string_view GetStageName() const { return "VideoCaptureStage"; };
    cv::Mat GetOutputImage();
private:
    int device;
    cv::VideoCapture capture;
    cv::Mat frame;
};
