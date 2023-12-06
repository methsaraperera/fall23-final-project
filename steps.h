#ifndef STEPS_H
#define STEPS_H

#include <QString>

#include "translator.h"
#include "advisor.h"

class Steps
{
private:
    Translator translate;
    Advisor advisor;
public:
    Steps();
    void stepOne();

};

#endif // STEPS_H
