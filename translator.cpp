#include "translator.h"

Translator::Translator()
{

}

int Translator::translateStringToInt(const QString& message){
    bool conversionOk;
    int result = message.toInt(&conversionOk);
    if (!conversionOk) {
        return -1;
    }
    return result;
}
