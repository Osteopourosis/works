#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

class Contact{

public:
    Contact(){

    }
    Contact(std::string ia,std::string ib,std::string ic,std::string id): a(ia),b(ib),c(ic),d(id){

    }

    void print() const{
        std::cout<<a<<" "<<b<<" "<<c<<" "<<d<<std::endl;
    }

//    int search_contact(const std::vector<Contact>& contacts, std::string first_name, std::string surname){
//        int ind=-1;
//        for(int i=0;i<contacts.size();i++){
//            if(first_name==contacts[i].a && surname==contacts[i].b){
//                ind=i;
//            }
//        }
//
//        return ind;
//    }


    bool cont (std::string A, std::string B ) const{
        if (a == A && b==B) {
            return 1;
        }
        else{
            return 0;
        }
    }



private:
    std::string a;
    std::string b;
    std::string c;
    std::string d;


};

//void print(std::vector<Contact>contacts){
//    for(int i=0; i< contacts.size();i++){
//        contacts[i].print(contacts[i]);
//    }
//}

int search_contact(const std::vector<Contact>& contacts, std::string first_name, std::string surname){
    int ind=-1;
    for(int i=0;i<contacts.size();i++){
        if(contacts[i].cont(first_name,surname)){
            ind=i;
        }
    }

    return ind;
}

void print_contacts(const std::vector<Contact>& contacts){
    for(int i = 0; i < contacts.size(); i++){
        contacts[i].print();
    }
}

int main() {
    std::ifstream infile;
    infile.open("contacts.txt");

    if(!infile.is_open()){
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<Contact> details;
    std::string a,b,c,d,first_name,surname;

    while (infile >> a >> b >> c >> d) {
        Contact tmp(a, b, c, d);
        details.push_back(tmp);

    }
    infile.close();
    Contact C;



    std::cout<<"Please enter the name and surname of the person who's details you would like:"<<std::endl;
    std::cin>>first_name>>surname;
    int ind=search_contact(details,first_name,surname);
    std::cout<<ind<<std::endl;
    if(ind==-1){
        std::cout<<"Contact not found"<<std::endl;
    }
    else{
        details[ind].print();
    }
}
