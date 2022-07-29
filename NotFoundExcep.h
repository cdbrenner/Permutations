#pragma once
#include <stdexcept>
#include <string>

class NotFoundExcep : public std::logic_error
{
    public:
        NotFoundExcep(const std::string);
};