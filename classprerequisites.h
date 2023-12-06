#ifndef CLASSPREREQUISITES_H
#define CLASSPREREQUISITES_H

#include "classes.h"
#include <QVector>
#include <QString>
#include <memory>

class ClassPrerequisites : public Classes
{
public:
    ClassPrerequisites();
    //ClassPrerequisites(const QString& classId, const QString& className);
    ClassPrerequisites(const QString& classId, const QString& prereqId);
    void addPrerequisite(const QString& prerequisite);
    QVector<QString> getPrerequisites() const;

private:
    QVector<QString> prerequisites;
    QString prereqId;
};

#endif // CLASSPREREQUISITES_H
