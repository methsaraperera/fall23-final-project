#include "classprerequisites.h"

ClassPrerequisites::ClassPrerequisites()
{

}

ClassPrerequisites::ClassPrerequisites(const QString& classId, const QString& prereqId)
    : Classes(classId, ""), prereqId(prereqId)
{

}

void ClassPrerequisites::addPrerequisite(const QString& prerequisite)
{
    prerequisites.push_back(prerequisite);
}

QVector<QString> ClassPrerequisites::getPrerequisites() const
{
    return prerequisites;
}
