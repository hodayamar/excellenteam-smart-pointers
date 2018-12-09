#include "person.h"

Person::Person(const char * full_name)
{
    strcpy(m_full_name, full_name);
}

void Person::print()const
{
    std::cout << "m_full_name: " << m_full_name << std::endl;
}

const char * Person::get_full_name()const
{
    return m_full_name;
}

