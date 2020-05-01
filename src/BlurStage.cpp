#include "BlurStage.hpp"

BlurStage::BlurStage(GeneratorStage &input, int kernelRadius) 
    : FilterStage(input) 
    , kernelRadius(kernelRadius)
{ 
}
 
void BlurStage::Execute() 
{  
    input.Execute();
    cv::GaussianBlur(input.GetOutputImage(), output, cv::Size(kernelRadius, kernelRadius), 0);
}
