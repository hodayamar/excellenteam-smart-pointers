#include "s_ptr.h"
#include <cstring>//strcpy

class Person {

public:

    Person();
    Person(const char * full_name);

    void print()const;

private:

    char m_full_name[32];

};


int main(){

    UniquePtr<Person> p(new Person("Shlomit"));

    if (p)
        
        p -> print();

    return 0;
}

Person::Person(const char * full_name)
{
    strcpy(m_full_name, full_name);
}
void Person::print()const
{
    std::cout << "m_full_name: " << m_full_name << std::endl;
}

