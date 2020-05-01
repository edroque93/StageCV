#pragma once

#include <string_view>
#include <memory>
#include <opencv2/opencv.hpp>
#include "GeneratorStage.hpp"

class FilterStage: public GeneratorStage
{
public:
    FilterStage(GeneratorStage &input) : input(input) {};
    virtual void Execute() = 0;
    virtual std::string_view GetStageName() const = 0;
    virtual cv::Mat GetOutputImage() = 0;
protected:
    GeneratorStage &input;
};
