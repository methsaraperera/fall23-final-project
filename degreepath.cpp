#include "degreepath.h"

DegreePath::DegreePath() : pathId(0), pathName("") {}
DegreePath::DegreePath(int pathId, const QString& pathName)
    : pathId(pathId), pathName(pathName) {}

DegreePath::~DegreePath() {}

int DegreePath::getPathId() const {
    return pathId;
}

QString DegreePath::getPathName() const {
    return pathName;
}

void DegreePath::setSelectedPath(int setPathId){
    selectedPath = setPathId;
}

int DegreePath::getSelectedPath(){
    return selectedPath;
}
