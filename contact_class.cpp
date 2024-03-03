#include "contact_class.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <map>


Contact::Contact( std::string fn, std::string ln, int phone_num, std::string email, std::string bd, std::string street_num, std::string city, std::string prov_state, std::string country, std::string postal_code ){
    first_name = fn;
    last_name = ln;
    phone_number.push_back(phone_num);
    email_address.push_back(email);
    std::string temp;
    birthday = bd;
    address.push_back(street_num), address.push_back(city), address.push_back(prov_state), address.push_back(country), address.push_back(postal_code);

}

Contact::Contact(std::string fn, std::string ln){
    first_name = fn;
    last_name = ln;
}

Contact::Contact(){
    first_name = "None";
}

void Contact::set_name( std::string fn, std::string ln ){
    first_name = fn;
    last_name = ln;
}

void Contact::set_name( std::string fn){
    first_name = fn;
}

void Contact::set_bithday(std::string bd){
    birthday = bd;
}

void Contact::add_phone_number(int pn){
    phone_number.push_back(pn);
}

void Contact::add_email(std::string email){
    email_address.push_back(email);
}

void Contact::set_address(std::string street_num, std::string city, std::string prov_state, std::string country, std::string postal_code){
    address.push_back(street_num);
    address.push_back(city);
    address.push_back(prov_state);
    address.push_back(country);
    address.push_back(postal_code);
}



void Contact::print_name(){
    std::cout << first_name << " " << last_name << std::endl;

}

void Contact::print_contact(){
    std::cout << first_name << " " << last_name << std::endl;
    std::cout << "Phone number(s):" << std::endl;
    for(int pn : phone_number){
        std::cout << pn << std::endl;
    }
    std::cout << "Email Address(es):" << std::endl;
    for(std::string email : email_address){
        std::cout << email << std::endl;
    }
    std::cout << "Birthday: " << birthday << std::endl;
    std::cout << "Address: " << address.at(0) << ", " << address.at(1) << " " << address.at(2) << ", " << address.at(3) << ", " << address.at(4) << std::endl;

}

void Contact::shared_birthday(Contact other_contact){
    std::string temp_birth1 = birthday;
    std::string temp_birth2 = other_contact.birthday;

    temp_birth1.resize(5);
    temp_birth2.resize(5);

    if(!temp_birth1.compare(temp_birth2)){
        std::cout << first_name << " and " << other_contact.first_name << " have the same birthday!" << std::endl;
    }else{
        std::cout << first_name << " and " << other_contact.first_name << " don't have the same birthday." << std::endl;
    }
}

void Contact::merge_contacts(Contact other_contact){

    if(first_name + last_name != other_contact.first_name + other_contact.last_name){
        std::cout << "Contact name not the same, cannot merge information!" << std::endl;
        return;
    }else{
        bool duplicate = false;
        for(int pn : other_contact.phone_number){
            for(int other_pn : phone_number){
                if(pn == other_pn) duplicate = true;
            }
            if(!duplicate) phone_number.push_back(pn);
        }

        duplicate = false;
        for(std::string email : other_contact.email_address){
            for(std::string other_email : email_address){
                if(email.compare(other_email)) duplicate = true;
            }
            if(!duplicate) email_address.push_back(email);
        }
    }

}

void Contact::is_birthday(std::string date){
    std::string temp_birth = birthday;

    temp_birth.resize(5);
    date.resize(5);

    if(!temp_birth.compare(date)){
        std::cout << "It is " << first_name << "'s birthday!" << std::endl;
    }else{
        std::cout << "It isn't " << first_name << "'s birthday." << std::endl;
    }
}
