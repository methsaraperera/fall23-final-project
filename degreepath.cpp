/*
 * Developed by:    Methsara Perera
 * Course:          CSC 211H - Advanced Programming Techniques (Honors)
 * College:         Borough of Manhattan Community College, CUNY
 * Semester:        Fall 2023
 * Submitted on:    12/7/2023
 * Professor:       Dr. Azhar
 * Environment:     QT Framework 6.6.0 for Mac OS
 *                  DBeaver version 23.2.4.202311051706
 * Languages used:  C++, SQLite
 * Subject:         BMCC Accessible Education
 * Topic:           Automated Academic Guidance System: A Personalized Chatbot
*/
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

void DegreePath::setTermPath(int setTerm){
    termPlan = setTerm;
}

int DegreePath::getTermPath(){
    return termPlan;
}

void DegreePath::setSemester(int setSem){
    semester = setSem;
}

int DegreePath::getSemester(){
    return semester;
}
