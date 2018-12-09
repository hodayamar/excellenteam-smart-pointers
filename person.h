#ifndef EXCELLENTEAM_ELLA_CPP_SMART_POINTERS_HODAYAMAR_PERSON_H
#define EXCELLENTEAM_ELLA_CPP_SMART_POINTERS_HODAYAMAR_PERSON_H

#include <cstring>//strcpy
#include <iostream>//cout

class Person {

public:

    Person();
    Person(const char * full_name);

    void print()const;
    const char * get_full_name()const;

private:

    char m_full_name[32];

};

#endif //EXCELLENTEAM_ELLA_CPP_SMART_POINTERS_HODAYAMAR_PERSON_H
