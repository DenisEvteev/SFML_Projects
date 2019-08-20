#include <iostream>

#include "Eng_Practice.hpp"

int main() {


    try{

        Eng_Practice prac("words.txt");

        prac.run();

    }catch(My_Exception* ex){

        ex->dump_info_in_console();
        ex->clear();
    }

    return 0;
}