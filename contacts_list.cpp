#include "contact_class.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <map>

int main(){

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

    Contact Mary("Mary", "Smith");
    Mary.set_bithday("03/03/2000");

    Mary.is_birthday("03/03/2023");

    return 0;
}