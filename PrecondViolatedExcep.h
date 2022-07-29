#ifndef _PRECOND_VIOLATED_EXCEP
#define _PRECOND_VIOLATED_EXCEP

#include <stdexcept>
#include <string>
using namespace std;

class PrecondViolatedExcep : public logic_error
{
    public:
        PrecondViolatedExcep(const string& message = "");
};

#endif