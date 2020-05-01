 #include "VideoCaptureStage.hpp"

VideoCaptureStage::VideoCaptureStage(int device)
    : device(device)
{
    if (!capture.open(device))
    {
        throw std::runtime_error("Cannot open capture device");
    }
}

void VideoCaptureStage::Execute()
{
    capture >> frame;
    if (frame.empty())
    {
        throw std::runtime_error("Cannot fetch frame from capture device");
    }
}

cv::Mat VideoCaptureStage::GetOutputImage()
{
    return frame;
}