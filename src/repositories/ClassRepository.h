#ifndef CLASSREPOSITORY_H
#define CLASSREPOSITORY_H


#include "models/Class.h"

#include <QList>


class ClassRepository
{

public:


    // Get all classes for displaying cards
    static QList<Class> getAllClasses();


    // Get one class by ID
    static Class getClassById(int id);


    // Create new class
    static bool createClass(Class schoolClass);


    // Update class information
    static bool updateClass(Class schoolClass);


    // Delete class
    static bool deleteClass(int id);



    // Card statistics
     static int getStudentCount(QString className);

    // static int getMaleCount(QString className);

    // static int getFemaleCount(QString className);



};


#endif // CLASSREPOSITORY_H