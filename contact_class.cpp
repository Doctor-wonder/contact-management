#include "contact_class.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <map>


Contact::Contact( std::string fn, std::string ln, int phone_num, std::string email, std::string bd, std::string street_num, std::string line_2, std::string city, std::string prov_state, std::string country, std::string postal_code ){
    first_name = fn;
    last_name = ln;
    phone_number.push_back(phone_num);
    email_address.push_back(email);
    std::string temp;

    temp.push_back(bd.at(0)), temp.push_back(bd.at(1));
    birthday.push_back(stoi(temp));
    temp.at(0) = bd.at(3), temp.at(1) = bd.at(4);
    birthday.push_back(stoi(temp));
    temp.at(0) = bd.at(6), temp.at(1) = bd.at(7), temp.push_back(bd.at(8)), temp.push_back(bd.at(9));
    birthday.push_back(stoi(temp));
    // ^ Gotta be an easier way to do that but I felt clever doing it so shrug

    address.push_back(street_num), address.push_back(line_2), address.push_back(city), address.push_back(prov_state), address.push_back(country), address.push_back(postal_code);

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
    std::string temp;

    temp.push_back(bd.at(0)), temp.push_back(bd.at(1));
    birthday.push_back(stoi(temp));
    temp.at(0) = bd.at(3), temp.at(1) = bd.at(4);
    birthday.push_back(stoi(temp));
    temp.at(0) = bd.at(6), temp.at(1) = bd.at(7), temp.push_back(bd.at(8)), temp.push_back(bd.at(9));
    birthday.push_back(stoi(temp));
}

void Contact::add_phone_number(int pn){
    phone_number.push_back(pn);
}

void Contact::add_email(std::string email){
    email_address.push_back(email);
}

void Contact::set_address(std::string street_num, std::string line_2, std::string city, std::string prov_state, std::string country, std::string postal_code){
    address.push_back(street_num);
    address.push_back(line_2);
    address.push_back(city);
    address.push_back(prov_state);
    address.push_back(country);
    address.push_back(postal_code);
}

void Contact::print_name(){
    std::cout << first_name << " " << last_name << std::endl;

}

void Contact::print_contact(){
    // TODO
}

void Contact::shared_birthday(Contact other_contact){
    if(birthday.at(0) == other_contact.birthday.at(0) && birthday.at(1) == other_contact.birthday.at(1)){
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
