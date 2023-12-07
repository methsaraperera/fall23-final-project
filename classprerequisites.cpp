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
