#pragma once

#include <string_view>
#include <opencv2/opencv.hpp>
#include "Stage.hpp"

class GeneratorStage: public Stage
{
public:
    virtual void Execute() = 0;
    virtual std::string_view GetStageName() const = 0;
    virtual cv::Mat GetOutputImage() = 0;
};
