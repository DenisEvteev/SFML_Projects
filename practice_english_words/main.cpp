#include <iostream>

#include "Eng_Practice.hpp"

void MyNewHandler();

int main() {


    /*change the pointer for function new_handler which will
    *finish the process of program if new won't manage with allocation the memory.
    *This will deliver us from generating bad_alloc */
    std::set_new_handler(MyNewHandler);

    try{

        Eng_Practice prac("words.txt");

        prac.run();

    }catch(My_Exception* ex){

        ex->dump_info_in_console();
        ex->clear();
    }

    return 0;
}

void MyNewHandler(){
    printf("Cannot allocate memory. The program will end!\n");
    std::abort();
}