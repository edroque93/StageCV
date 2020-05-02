#pragma once

#include <string_view>
#include <opencv2/opencv.hpp>
#include "Stage.hpp"
#include "GeneratorStage.hpp"
#include "AnalysisStage.hpp"

class ContourDetectionStage: public AnalysisStage
{
public:
    ContourDetectionStage(GeneratorStage &input);
    void Execute();
    std::string_view GetStageName() const { return "ContourDetectionStage"; }
    std::vector<cv::Rect> GetBoundingBoxes(cv::Size targetSize = cv::Size(0, 0)) const;
    cv::Size GetInputSize() const { return input.GetOutputImage().size(); }
private:
    std::vector<cv::Rect> boundingBoxes;
};
