//
// Created by denis on 09.08.19.
//

#pragma once


#include "/home/denis/CLionProjects/String_Lib/String.hpp"
#include "/home/denis/CLionProjects/MyExceptions/My_Exception.hpp"
#include "/home/denis/CLionProjects/vec_lib/TrackingAllocator.hpp"

#include <SFML/Graphics.hpp>

#include <map>
#include <functional>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>

#define CHECK_POSSOBILITY_FOR_ACCESS if(num < 0 || num >= texts.size()){\
std::cout << "No such a text in vector of texts for this application!" << std::endl;\
std::cout << num << std::endl;\
return;\
}\

enum class Symbols : const char{
    HYPHEN = '-',
    COMMA = ',',
    ENDSTR = '\n',
    SPACE = ' ',
    VACANT_PLACE = '\0',
    BUSY = 'b'

};

extern const unsigned int width;
extern const unsigned int height;


class Eng_Practice {
public:

    explicit Eng_Practice(const char* path_to_words);

    void run();


private:
    const char* path_to_words = nullptr;

    std::mt19937_64 gen;

    typedef std::multimap<String, String> my_map;

    my_map map_;
    my_map::const_iterator itr_ = map_.cbegin();
    int pos_it = 0;

    /*These variables were created for working with hints;
     * opt will contain the information about the current type of translation (if opt == true => R->E)
     * id_letter will contain index of current letter for output*/
    bool opt = false;
    int id_letter = 1;
    //_________________________________________________________//

    std::vector<char> state_w;

    /* this vector will contain different texts for drawing in the window
     * and the second text will contain my_answer
     * it will be drawn right after entering*/

    std::vector<sf::Text> texts;

    sf::Sprite sprite_background;
    sf::Texture texture_background;
    sf::Image background;
    sf::Font font;

    void MakeDecorForText(int num, float x, float y, const sf::Color& color,
            const sf::Text::Style& style);

    void ChangeText(int num, const sf::String& st, int character_size);
    void render(sf::RenderWindow& window, int num);
    void process_events(sf::RenderWindow& window);
    void ChooseOptions(sf::Keyboard::Key key, sf::RenderWindow& window);


    void MakeNiceStructOfData();
    void MakeAnswer(const String& s);
    void ParceOneString(const String& data_, int& current_counter, int& pos_special_symbol);

    int FindPosEndingWord(const char c, const String& data_, int& current_counter, int& pos_special_symbol);

    void MakePair(String& change, const String& another, int& pos_end_word, bool order,
                  const String& data_, int& current_counter, int& pos_special_symbol);

    void CheckHyphens(const String& data_, int num_line)const;
    void GenerateStartPosition();
    bool CheckEqualityOfWords();
    bool CheckAmongMatchingRussianWords();
    void MakeNewPosOfItr();
    void MovingItr(int new_pos);
    void ProcessingWithHints();
};


