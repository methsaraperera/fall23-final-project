#ifndef PREREQUISITES_H
#define PREREQUISITES_H

#include <QWidget>

class PreRequisites
{
public:
    PreRequisites();
    QString className;
    QVector<QString> prerequisites;
};

#endif // PREREQUISITES_H
