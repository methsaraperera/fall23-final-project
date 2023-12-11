# Automated Academic Guidance System

Automatic academic guidance chatbot system which allows students to select their major and semester and gives them personalized academic suggestions for the selected major and semester.

## Languages used:
C++ (Apple clang version 15.0.0 (clang-1500.0.40.1))\
SQLite (Version 3.41.2)

## Environment
QT Framework 6.6.0 for Mac OS \
DBeaver version 23.2.4.202311051706

## Project links: 
[Video](https://www.youtube.com/watch?v=5PbESbaHiAc)\
[Website](https://sites.google.com/view/advisementchatbot/)


## Prerequisites

Before you begin, make sure you have the following prerequisites installed:

1. **SQLite:** Check if SQLite is installed on your Mac by opening the Terminal and entering `sqlite3`. If not installed, follow the instructions [here](https://www.tutorialspoint.com/sqlite/sqlite_installation.htm) or download SQLite from [https://www.sqlite.org/download.html](https://www.sqlite.org/download.html).

## Database Setup

1. Open the Terminal.
2. Navigate to the directory where you want to create the SQLite database.
3. Enter the following command to create the database:

    ```bash
    $ sqlite3 testDB.db
    ```

4. Copy and execute the table creation queries from the file [sqlite-script-create-tables.sql](https://github.com/methsaraperera/fall23-final-project/blob/main/sqlite-script-create-tables.sql).

    ```bash
    $ sqlite> copy sqlite-script-create-tables.sql content here and execute
    ```

5. Insert data into the tables by copying and executing queries from the file [database-data.sql](https://github.com/methsaraperera/fall23-final-project/blob/main/database-data.sql).

    ```bash
    $ sqlite> copy database-data.sql content here and execute
    ```

## BMCC Virtual Advisor Bot Project Setup

1. Open the QT project located in the file `final_project -> BMCC-Virtual-Advisor-Bot -> CMakeLists.txt`.
2. This will import the project into QT.
3. Click on the "RUN" button in QT to execute the project.




