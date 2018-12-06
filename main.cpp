#include "s_ptr.h"
#include <cstring>//strcpy

class Person {

public:

    Person();
    Person(const char * full_name);

    void print()const;
    const char * get_full_name()const;

private:

    char m_full_name[32];

};


void person_to_s_ptr()
{
    char * first_ptr = new char[1];

    {
        UniquePtr<Person> p(new Person("Shlomit"));
    }

    char * second_ptr = new char[1];

    if(&second_ptr - &first_ptr == 1)

        std::cout << "smart_ptr is smart!" << std::endl;
}

void arrow_test()
{
    UniquePtr<Person> p(new Person("Shlomit"));

    if (strcmp(p->get_full_name(), "Shlomit") == 0)
        std::cout << "arrow is OK" << std::endl;
}

void test_bool()
{
    UniquePtr<Person> p(new Person("Shlomit"));

    if (p)
        std::cout << "Bool is OK" << std::endl;;

}

void test_star()
{
    UniquePtr<Person> p(new Person("Shlomit"));

    if (strcmp((*p).get_full_name(), "Shlomit") == 0)
        std::cout << "star is OK" << std::endl;
}

int main(){

    person_to_s_ptr();
    arrow_test();
    test_bool();
    test_star();


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

const char * Person::get_full_name()const
{
    return m_full_name;
}


