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
