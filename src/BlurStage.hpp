#pragma once

#include <string_view>
#include <opencv2/opencv.hpp>
#include "GeneratorStage.hpp"
#include "FilterStage.hpp"

class BlurStage : public FilterStage
{
public:
    BlurStage(GeneratorStage &input, int kernelRadius);
    void Execute();
    std::string_view GetStageName() const { return "BlurStage"; };
    cv::Mat GetOutputImage() { return output; };
private:
    cv::Mat output;
    int kernelRadius;
};
