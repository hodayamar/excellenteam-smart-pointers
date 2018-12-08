#include "s_ptr.h"
#include "shared_ptr.h"
#include <cstring>//strcpy

#ifdef TESTING
#define PRINT(x,num)(std::cout << x <<": "<<num<<std::endl)
#else
#define PRINT(x,num)
#endif

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

void test_shared_ptr_dif()
{
    shared_ptr<Person> p1(new Person("Shlomit"));
    shared_ptr<Person> p2(new Person("Shlomit"));

    if (p1 != p2)
        std::cout << "!= is OK" << std::endl;
}

void test_cpy_shared_ptr()
{
    shared_ptr<Person> p1(new Person("Shlomit"));
    shared_ptr<Person> p2(p1);

    if(p2 == p1)
        std::cout << "cpy and compare is OK " << std::endl;
}

void test_shared_ptr_dtor()
{
    int * couner;
    shared_ptr<Person> p1(new Person("Shlomit"));
    shared_ptr<Person> p2(p1);
    shared_ptr<Person> p3(p1);

    {
        shared_ptr<Person> p4(p1);

    }

    couner = p3.get_ref_counter();
    if(*couner == 3)

        std::cout << "dtor is OK" << std::endl;
}

void test_shared_ptr_assignment()
{
    int * counter_1, * counter_2;

    shared_ptr<Person> p1(new Person("Shlomit"));
    shared_ptr<Person> p2(new Person("Meir"));
    shared_ptr<Person> p3(p2);
    shared_ptr<Person> p4(p1);

    p1 = p2;

    counter_1 = p1.get_ref_counter();
    counter_2 = p4.get_ref_counter();

    if(*counter_1 == 3 && *counter_2 == 1)

        std::cout << "assignment is OK" << std::endl;
}

int main(){

//    person_to_s_ptr();
//    arrow_test();
//    test_bool();
//    test_star();
//    test_shared_ptr_dif ();
//    test_cpy_shared_ptr();
//    test_shared_ptr_dtor();
    test_shared_ptr_assignment();

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


