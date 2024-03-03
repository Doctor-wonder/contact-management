#include "contact_class.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <map>

int main(){

    std::cout << "Hello World!" << std::endl;

    Contact Niaomi("Niaomi", "Peck");

    Contact Jordan("Jordan", "Lastname");

    Niaomi.print_name();
    Jordan.print_name();

    Niaomi.set_bithday("27/04/2002");
    Jordan.set_bithday("29/11/1996");

    Niaomi.shared_birthday(Jordan);

    Niaomi.add_phone_number(1234567890);
    Niaomi.add_email("email@address.com");
    Niaomi.set_address("123 Street Ave", "Cityville", "State County", "Republic of Country", "A1B 2C3");

    Niaomi.print_contact();

    return 0;
}