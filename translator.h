#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <QString>

class Translator
{
public:
    Translator();
    int translateStringToInt(const QString& message);
};

#endif // TRANSLATOR_H
