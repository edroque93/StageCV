#pragma once

#include <memory>
#include <string_view>
#include <opencv2/opencv.hpp>
#include "GeneratorStage.hpp"
#include "FilterStage.hpp"

class ScaleStage : public FilterStage
{
public:
    ScaleStage(GeneratorStage &input, int width, int height);
    void Execute();
    std::string_view GetStageName() const { return "ScaleStage"; };
    cv::Mat GetOutputImage() { return output; };
private:
    cv::Mat output;
    int width;
    int height;
};
