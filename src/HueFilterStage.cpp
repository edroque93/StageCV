#include "HueFilterStage.hpp"

HueFilterStage::HueFilterStage(GeneratorStage &input, int hue, int radius) 
    : FilterStage(input) 
    , hue(hue / 360. * 180.)
    , radius(radius / 360. * 180.)
{ 
}
 
void HueFilterStage::Execute() 
{  
    cv::Mat imageInHSV;
    input.Execute();
    cv::cvtColor(input.GetOutputImage(), imageInHSV, cv::COLOR_BGR2HSV);
    if ((hue - radius) < 0 || (hue + radius) > 179)
    {
        cv::Mat mask1, mask2;
        cv::inRange(imageInHSV, cv::Scalar(0, 60, 60), cv::Scalar(hue + radius, 255, 255), mask2);
        cv::inRange(imageInHSV, cv::Scalar(180 - abs(hue - radius), 60, 60), cv::Scalar(180, 255, 255), mask1);
        output = mask1 | mask2;
    }
    else
    {
        cv::inRange(imageInHSV, cv::Scalar(hue - radius, 60, 60), cv::Scalar(hue + radius, 255, 255), output);
    }
}
