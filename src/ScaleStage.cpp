#include "ScaleStage.hpp"

ScaleStage::ScaleStage(GeneratorStage &input, int width, int height) 
    : FilterStage(input) 
    , width(width)
    , height(height)
{ 
}
 
void ScaleStage::Execute() 
{  
    input.Execute();
    cv::Mat imageIn = input.GetOutputImage();
    output = cv::Mat(width, height, imageIn.type());
    cv::resize(imageIn, output, cv::Size(width, height), 0, 0, cv::INTER_CUBIC);
}
