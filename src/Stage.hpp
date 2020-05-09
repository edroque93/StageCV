#pragma once

#include <string_view>

class Stage
{
public:
    virtual void Execute() = 0;
    virtual std::string_view GetStageName() const = 0;
};
