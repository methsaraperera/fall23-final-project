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
#ifndef DEGREEPATH_H
#define DEGREEPATH_H

#include <QWidget>

class DegreePath
{
public:
    DegreePath();

    DegreePath(int pathId, const QString& pathName);
    virtual ~DegreePath();

    int getPathId() const;
    QString getPathName() const;
    void setSelectedPath(int);
    int getSelectedPath();
    void setTermPath(int);
    int getTermPath();
    void setSemester(int);
    int getSemester();

private:
    int pathId;
    QString pathName;
    int selectedPath;
    int termPlan = 0; // termplan = 1 if 2 Year Plan
                  // termplan = 2 if 5 Semester Plan
    int semester; // 1, 2, 3, 4, 5
};

#endif // DEGREEPATH_H
