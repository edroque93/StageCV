#include "ContourDetectionStage.hpp"

ContourDetectionStage::ContourDetectionStage(GeneratorStage &input) 
    : AnalysisStage(input) 
{ 
}
 
void ContourDetectionStage::Execute() 
{  
    std::vector<std::vector<cv::Point>> contours;
    input.Execute();
    cv::findContours(input.GetOutputImage().clone(), contours, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE);
    boundingBoxes.resize(contours.size());
    std::vector<std::vector<cv::Point>> Polygons(contours.size());
    for (size_t i = 0; i < contours.size(); i++)
    {
        approxPolyDP(contours[i], Polygons[i], 5, true);
        boundingBoxes[i] = boundingRect(Polygons[i]);
    }
}

std::vector<cv::Rect> ContourDetectionStage::GetBoundingBoxes(cv::Size targetSize) const
{ 
    if (targetSize.width == 0 && targetSize.height == 0) return boundingBoxes;
    std::vector<cv::Rect> transformedBoundingBoxes(boundingBoxes.size());
    cv::Size originalSize = input.GetOutputImage().size();
    for (size_t i = 0; i < boundingBoxes.size(); i++)
    {
        int scaleX = targetSize.width / originalSize.width;
        int scaleY = targetSize.height / originalSize.height;
        transformedBoundingBoxes[i] = cv::Rect(
            boundingBoxes[i].x * scaleX, boundingBoxes[i].y * scaleY,
            boundingBoxes[i].width * scaleX, boundingBoxes[i].height * scaleY);
    }
    return transformedBoundingBoxes;
}
