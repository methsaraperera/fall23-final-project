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
#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QtSql>
#include "degreepath.h"
#include "classes.h"
#include "classprerequisites.h"

class DatabaseManager
{
private:
    QSqlDatabase db;
    QVector<DegreePath> degreePaths;
    int dereePath; //degree path user selected
    QVector<Classes> requiredClasses;
    QVector<std::shared_ptr<ClassPrerequisites>> classPrerequisites;  // Vector of shared pointers to ClassPrerequisites

public:
    DatabaseManager();
    bool openDatabase();
    void closeDatabase();
    QSqlDatabase getDatabase();
    bool authenticateUser(const QString username, const QString password);
    void loadDegreePaths();
    QVector<DegreePath> getDegreePaths() const;
    QString getDegreePathsAsString() const;
    void setAcademicPath(int);

    void loadRequiredClasses(int selectedPath);
    QVector<Classes> getRequiredClasses() const;
    QString getRequiredClassesAsString() const;

    QVector<QString> determineRemainingClasses(const QVector<QString>& takenClasses);
    QVector<Classes> getUnsatisfiedClasses(const QVector<QString>& takenClasses);
    QVector<std::shared_ptr<ClassPrerequisites>> getClassPrerequisites() const;

    void loadPrerequisitesData();
};

#endif // DATABASEMANAGER_H
