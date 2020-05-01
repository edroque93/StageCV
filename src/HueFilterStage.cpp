#include "HueFilterStage.hpp"

HueFilterStage::HueFilterStage(GeneratorStage &input, int hue, int radius) 
    : FilterStage(input) 
    , hue(hue)
    , radius(radius)
{ 
}
 
void HueFilterStage::Execute() 
{  
    cv::Mat imageInHSV;
    input.Execute();
    cv::cvtColor(input.GetOutputImage(), imageInHSV, cv::COLOR_BGR2HSV);
    // H => [0, 179]
    if ((hue - radius) < 0 || (hue + radius) > 179)
    {
        // TODO
        // cv::Mat mask1, mask2;
        // cv::inRange(imageInHSV, cv::Scalar(hue - radius, 70, 70), cv::Scalar(180, 255, 255), mask2);
        // output = mask1 | mask2;
    }
    else
    {
        cv::inRange(imageInHSV, cv::Scalar(24.86, 70, 70), cv::Scalar(37.29, 255, 255), output);
    }
    
}
