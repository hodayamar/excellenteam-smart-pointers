#include "shared_ptr.h"
#include "person.h"

void test_shared_ptr_dif()
{
    shared_ptr<Person> p1(new Person("Shlomit"));
    shared_ptr<Person> p2(new Person("Meir"));

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


        std::cout << "Dtor is OK" << std::endl;
}

void test_shared_ptr_assignment()
{
    int * counter_before_assignment, * counter_after_assignment;

    shared_ptr<Person> p1(new Person("Shlomit"));
    shared_ptr<Person> p2(new Person("Meir"));
    shared_ptr<Person> p3(p2);
    shared_ptr<Person> p4(p1);

    p1 = p2;

    counter_before_assignment = p1.get_ref_counter();
    counter_after_assignment = p4.get_ref_counter();

    if(*counter_before_assignment == 3 && *counter_after_assignment == 1)

        std::cout << "assignment is OK" << std::endl;
}

int main(){

    test_shared_ptr_dif ();
    test_cpy_shared_ptr();
    test_shared_ptr_dtor();
    test_shared_ptr_assignment();

    return 0;
}


