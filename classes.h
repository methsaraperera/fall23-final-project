#ifndef CLASSES_H
#define CLASSES_H

#include "degreepath.h"
#include <QString>
#include <QVector>

class Classes : public DegreePath {
public:
    Classes();
    Classes(const QString& classId, const QString& className);
    const QString& getClassId() const;
    const QString& getClassName() const;

    virtual ~Classes();

private:
    QString classId;
    QString className;
};

#endif // CLASSES_H
