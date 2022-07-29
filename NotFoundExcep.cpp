#include "NotFoundExcep.h"

NotFoundExcep::NotFoundExcep(const std::string message)
    : logic_error("Not Found Exception: " + message) {}