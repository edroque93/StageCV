#pragma once

#include <string_view>
#include <opencv2/opencv.hpp>
#include "Stage.hpp"
#include "GeneratorStage.hpp"

class ReceptorStage: public Stage
{
public:
    ReceptorStage(GeneratorStage &input) : input(input) {};
    virtual void Execute() = 0;
    virtual std::string_view GetStageName() const = 0;
protected:
    GeneratorStage &input;
};
