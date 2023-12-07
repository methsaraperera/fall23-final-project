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
#include <iostream>
#include "databasemanager.h"

#define Path_to_DB "/Users/methsaramp/Developer/BMCC/CSC_211/Final_project_test/testdb.db"

using namespace std;
DatabaseManager::DatabaseManager()
{
    //openDatabase();
}

bool DatabaseManager::openDatabase() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(Path_to_DB);
    QFileInfo checkFile(Path_to_DB);

    if(checkFile.isFile()){
        qDebug() << "Database file exist [1/2]";
        if(db.open()){
            qDebug() << "Database connection established [2/2]";
            return true;
        }
    }
    else{
        qDebug() << "Database file does nor exist [1/1]";
        return false;
    }
    return false;
}

void DatabaseManager::closeDatabase() {
    db.close();
    qDebug() << "Database Closed [1/1]";
}

QSqlDatabase DatabaseManager::getDatabase() {
    return db;
}

bool DatabaseManager::authenticateUser(const QString username, const QString password) {


    QSqlQuery qry;
    //qDebug() << "SELECT * FROM admin WHERE username = \'"+username+"\' AND password=\'"+password+"\'"; // print the query in debug

    if(qry.exec("SELECT * FROM admin WHERE username = \'"+username+"\' AND password=\'"+password+"\'"))
    {
        if(qry.next())
        {
            qDebug() << ">> Login successful. Welcome ";
            qDebug() << "Faculty_ID: " +qry.value(0).toString() + " Name: " + qry.value(1).toString();
            closeDatabase();

            return true;
        }
        else{
            qDebug() << ">> Login data incorrect ";
            closeDatabase();
            return false;
        }
    }
    return false;
}

void DatabaseManager::loadDegreePaths() {
    degreePaths.clear(); // Clear existing data before loading new data

    QSqlQuery qry;
    if (qry.exec("SELECT path_id, path_name FROM degree_path")) {
        while (qry.next()) {
            int pathId = qry.value(0).toInt();
            QString pathName = qry.value(1).toString();
            degreePaths.push_back(DegreePath(pathId, pathName));
        }
    } else {
        qDebug() << "Error loading degree paths: " << qry.lastError().text();
    }
}

QVector<DegreePath> DatabaseManager::getDegreePaths() const {
    return degreePaths;
}

QString DatabaseManager::getDegreePathsAsString() const {
    QString result;
    QTextStream stream(&result);

    if (degreePaths.empty()) {
        stream << "No degree paths available.";
    }
    else {
        stream << "Degree Paths:\n";
        stream << QString("%1\t%2\n").arg("Path ID", -10).arg("Path Name");
        stream << QString("------------------------------------------------------------------------\n");

        for (const auto &path : degreePaths) {
            stream << QString("%1\t%2\n").arg(path.getPathId()).arg(path.getPathName());
        }
    }

    return result;
}

void DatabaseManager::loadRequiredClasses(int selectedPath) {
    requiredClasses.clear(); // Clear existing data before loading new data

    // Fetch class IDs from the path_require table based on the selected path
    QSqlQuery tempQuery;
    qDebug() << "Executing query: " << tempQuery.lastQuery();
    if (tempQuery.exec("SELECT PATH_CLASS FROM path_require WHERE path_id = " + QString::number(selectedPath))) {
        if (tempQuery.lastError().isValid()) {
            qDebug() << "Error executing query: " << tempQuery.lastError().text();
        }
        QStringList classIds;
        while (tempQuery.next()) {
            classIds << tempQuery.value(0).toString();
        }

        qDebug() << "Retrieved class IDs: " << classIds;

        // Fetch detailed information for each class from the class table
        QSqlQuery qry;

        QStringList quotedClassIds;
        for (const QString& classId : classIds) {
            quotedClassIds << "'" + classId + "'";
        }

        if (qry.exec("SELECT class_id, class_name FROM class WHERE class_id IN (" + quotedClassIds.join(',') + ")")) {
            while (qry.next()) {
                QString classId = qry.value(0).toString();
                QString className = qry.value(1).toString();
                requiredClasses.push_back(Classes(classId, className));
            }
        }
        else {
            qDebug() << "Error loading required classes: " << qry.lastError().text();
        }
    }
    else {
        qDebug() << "Error fetching class IDs: " << tempQuery.lastError().text();
    }
}




QVector<Classes> DatabaseManager::getRequiredClasses() const {
    return requiredClasses;
}

QString DatabaseManager::getRequiredClassesAsString() const {
    QString result;
    QTextStream stream(&result);

    qDebug() << "Size of requiredClasses: " << requiredClasses.size();

    if (requiredClasses.empty()) {
        stream << "No required classes available.";
        qDebug() << "err: [1/3]";
    }
    else {
        stream << "Required Classes:\n";
        stream << QString("%1\t%2\n").arg("Class ID", -10).arg("Class Name");
        stream << QString("------------------------------------------------------------------------\n");
        qDebug() << "err: [2/3]";

        for (const auto &cls : requiredClasses) {
            stream << QString("%1\t%2\n").arg(cls.getClassId(), -10).arg(cls.getClassName());
            qDebug() << "err: [3/3]";
        }
    }

    return result;
}

QVector<std::shared_ptr<ClassPrerequisites>> DatabaseManager::getClassPrerequisites() const
{
    return classPrerequisites;
}

// Implementation for loading prerequisites data
void DatabaseManager::loadPrerequisitesData()
{
    // Sample data for class prerequisites
    classPrerequisites.push_back(std::make_shared<ClassPrerequisites>("CSC 111", "CSC 101"));
    classPrerequisites.push_back(std::make_shared<ClassPrerequisites>("CSC 211", "CSC 111"));
    classPrerequisites.push_back(std::make_shared<ClassPrerequisites>("CSC 215", "CSC 111"));
    classPrerequisites.push_back(std::make_shared<ClassPrerequisites>("CSC 231", "CSC 111"));
    classPrerequisites.push_back(std::make_shared<ClassPrerequisites>("CSC 350", "CSC 211"));
    classPrerequisites.push_back(std::make_shared<ClassPrerequisites>("MAT 301", "MAT 206.5"));
    classPrerequisites.push_back(std::make_shared<ClassPrerequisites>("MAT 302", "MAT 301"));
}
