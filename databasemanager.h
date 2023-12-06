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
    //void printDegreePaths();

    void setAcademicPath(int);


    void loadRequiredClasses(int selectedPath);
    QVector<Classes> getRequiredClasses() const;
    QString getRequiredClassesAsString() const;
    //QVector<QString> determineRemainingClasses(const QVector<QString>& takenClasses);

    QVector<QString> determineRemainingClasses(const QVector<QString>& takenClasses);
    QVector<Classes> getUnsatisfiedClasses(const QVector<QString>& takenClasses);

    QVector<std::shared_ptr<ClassPrerequisites>> getClassPrerequisites() const;

    //QStringList getRequiredClasses(int pathId);
    void loadPrerequisitesData();

};

#endif // DATABASEMANAGER_H
