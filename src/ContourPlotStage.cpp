#include "ContourPlotStage.hpp"

ContourPlotStage::ContourPlotStage(GeneratorStage &input, ContourDetectionStage &contour) 
    : FilterStage(input) 
    , contour(contour)
{ 
}
 
void ContourPlotStage::Execute() 
{  
    contour.Execute();
    output = input.GetOutputImage().clone();
    cv::Size outputSize = output.size();
    std::vector<cv::Rect> boundingBoxes = contour.GetBoundingBoxes(outputSize);
    const int minArea = outputSize.width * outputSize.height * 0.0025;
    for (const cv::Rect &boundingBox: contour.GetBoundingBoxes(output.size()))
    {
        if (boundingBox.width * boundingBox.height > minArea)
        {
            // TODO: cache bboxes position so we track with unique color
            // cv::Scalar randomColor = cv::Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
            cv::rectangle(output, boundingBox.tl(), boundingBox.br(), cv::Scalar(0, 0, 255), 2);
        }
    }
}
