#pragma once

#include <string_view>
#include <opencv2/opencv.hpp>
#include "GeneratorStage.hpp"
#include "FilterStage.hpp"
#include "ContourDetectionStage.hpp"

class ContourPlotStage : public FilterStage
{
public:
    ContourPlotStage(GeneratorStage &input, ContourDetectionStage &contour);
    void Execute();
    std::string_view GetStageName() const { return "ContourPlotStage"; };
    cv::Mat GetOutputImage() { return output; };
private:
    cv::Mat output;
    ContourDetectionStage contour;
    cv::RNG rng;
};
