#ifndef DATABASEINITIALIZER_H
#define DATABASEINITIALIZER_H

class DatabaseInitializer
{
public:
    static void initialize();
    static void createUsersTable();
    static void createStudentsTable();
    static void createTeachersTable();
};

#endif // DATABASEINITIALIZER_H