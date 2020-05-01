#pragma once

#include <string_view>

class Stage
{
    virtual void Execute() = 0;
    virtual std::string_view GetStageName() const = 0;
};
