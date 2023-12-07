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
    ClassPrerequisites(const QString& classId, const QString& prereqId);
    void addPrerequisite(const QString& prerequisite);
    QVector<QString> getPrerequisites() const;

private:
    QVector<QString> prerequisites;
    QString prereqId;
};

#endif // CLASSPREREQUISITES_H
