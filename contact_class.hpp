#include <iostream>
#include <string>
#include <vector>
#include <map>

class Contact {

    std::string first_name;
    std::string last_name;
    std::vector<int> phone_number;
    std::vector<std::string> email_address;
    std::string birthday; // Will be inputted and stored as DD/MM/YYYY
    std::vector<std::string> address; // Will be stored as <Street address, City, Province/State, Country, Postal Code>

public:

    Contact( std::string fn, std::string ln, int phone_num, std::string email, std::string bd, std::string street_num, std::string city, std::string prov_state, std::string country, std::string postal_code );

    Contact(std::string fn, std::string ln);

    Contact();

    void set_name( std::string fn, std::string ln );

    void set_name( std::string fn);

    void set_bithday(std::string bd);

    void add_phone_number(int pn);

    void add_email(std::string email);

    void set_address(std::string street_num, std::string city, std::string prov_state, std::string country, std::string postal_code);

    
    
    void print_name();

    void print_contact();
    
    void shared_birthday(Contact other_contact);

    void merge_contacts(Contact other_contact);

    void is_birthday(std::string date);

};