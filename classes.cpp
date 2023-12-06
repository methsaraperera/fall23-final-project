#include "classes.h"

Classes::Classes() : classId(""), className("") {}

Classes::~Classes() {}

Classes::Classes(const QString& classId, const QString& className)
    : classId(classId), className(className) {}

const QString& Classes::getClassId() const {
    return classId;
}

const QString& Classes::getClassName() const {
    return className;
}
