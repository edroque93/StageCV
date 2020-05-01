#pragma once

#include <string_view>
#include <opencv2/opencv.hpp>
#include "GeneratorStage.hpp"
#include "FilterStage.hpp"

class HueFilterStage : public FilterStage
{
public:
    HueFilterStage(GeneratorStage &input, int hue, int radius);
    void Execute();
    std::string_view GetStageName() const { return "HueFilterStage"; };
    cv::Mat GetOutputImage() { return output; };
private:
    cv::Mat output;
    int hue;
    int radius;
};
