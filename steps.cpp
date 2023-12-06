#include "steps.h"

Steps::Steps()
{

}

void Steps::stepOne(){
    int id = translate.translateStringToInt(advisor.getMessage());
    qDebug() << id;
}
