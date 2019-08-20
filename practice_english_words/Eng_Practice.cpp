//
// Created by denis on 09.08.19.
//

#include "Eng_Practice.hpp"



const unsigned int width = 800;
const unsigned int height = 640;


Eng_Practice::Eng_Practice(const char *path_to_words):
path_to_words(path_to_words)
{
    gen.seed(time(NULL));
}

void Eng_Practice::run(){

    try{
        //Preparations for main part of this application
        MakeNiceStructOfData();
        //----------------------------------------------//

        sf::RenderWindow window(sf::VideoMode(width, height), "__A_WORD__");

        //------------------Creating Background------------------------//
        if(!background.loadFromFile("background.jpg")){
            std::cout << "Cannot open file background.jpg";
            return;
        }
        texture_background.loadFromImage(background);
        sprite_background.setTexture(texture_background);
        //------------------------------------------------------------//


        if(!font.loadFromFile("rus.ttf")){
            std::cout << "File rus.ttf cannot be opened" << std::endl;
            return;
        }

        //__________________Text with some welcome words______________//
        texts.emplace_back(L"Меню нажми на : [M]", font, 35);   // the first text will contain the start phrase
        MakeDecorForText(0, 180, 220, sf::Color::Black, sf::Text::Italic);

        //----------------------------------------------------------//

        state_w.resize(map_.size(), static_cast<char>(Symbols::VACANT_PLACE));   // mark all words free for choosing
        GenerateStartPosition();                                                //   generate a word to start with

        while(window.isOpen()){
            process_events(window);
            render(window, texts.size() - 1);
        }


    }catch(My_Exception* ex){
        std::cout << ex->what() << std::endl;
        THROW_NEXT(CodeErrors::ERROR_IN_STRING, ex)
    }
}

void Eng_Practice::MakeDecorForText(int num, float x, float y,
        const sf::Color& color, const sf::Text::Style& style) {

    CHECK_POSSOBILITY_FOR_ACCESS

    texts[num].setFillColor(color);
    texts[num].setStyle(style);
    texts[num].setPosition(x, y);
}

void Eng_Practice::render(sf::RenderWindow& window, int num) {
    window.clear();
    window.draw(sprite_background);

    for(int i = 0; i <= num; ++i)
        window.draw(texts[i]);

    window.display();
}

void Eng_Practice::CheckHyphens(const String& data_, int num_line)const{

    int num_hyphen{0};
    for(int i = 0; i < data_.GetNumBytes() - 1; ++i){
        if(*(data_.GetStr() + i) == static_cast<char>(Symbols::HYPHEN))
            ++num_hyphen;
    }

    if(num_hyphen != num_line){
        FIRST_THROW(CodeErrors::ERROR_IN_STRING, "This list of words is invalid, "
                                                 "because of wrong quantity of hyphens")
    }
}

void Eng_Practice::ChangeText(int num, const sf::String& st, int character_size) {
    CHECK_POSSOBILITY_FOR_ACCESS
    texts[num].setString(st);
    texts[num].setCharacterSize(character_size);
}

void Eng_Practice::ChooseOptions(sf::Keyboard::Key key, sf::RenderWindow& window){

    if(key == sf::Keyboard::M){
        if(texts.size() != 1){
            for(int i = 1; i < texts.size(); ++i)
                ChangeText(i, "", 0);
        }

        ChangeText(0, "From Russian into English press : [R];\n"
                      "From English into Russian press : [E];\n"
                      "To see the options press : [M];\n"
                      "To finish practicing press : [Escape];\n", 24);
        MakeDecorForText(0, 180, 220, sf::Color::Red, sf::Text::Style::Italic);
        return;
    }

    else if(key == sf::Keyboard::R){
        if(texts.size() == 4)
            ChangeText(3, "", 0);
        ChangeText(0, sf::String((itr_->second).to_wide_string()), 30);
        render(window, 0);
        if(!CheckEqualityOfWords()){
            render(window, 2);
            if(texts.size() == 3){
                texts.emplace_back(L"Не то! За подсказкой жми [H]", font, 28);
                MakeDecorForText(3, 180, 180, sf::Color::Black, sf::Text::Bold);
            }
            else
                ChangeText(3, L"Не то! За подсказкой жми [H]", 28);

            render(window, 3);
            opt = true;
        }
    }

    else if(key == sf::Keyboard::H){
        ProcessingWithHints();
        render(window, 3);
    }

    else if(key == sf::Keyboard::A) {
        if(!CheckEqualityOfWords()){
            render(window, 2);
            ChangeText(3, L"Не то! За подсказкой жми [H]", 28);
            render(window, 3);
        }
        else
            ChangeText(3, "", 0);
    }

    else if(key == sf::Keyboard::E){
        if(texts.size() == 4)
            ChangeText(3, "", 0);
        ChangeText(0, itr_->first.GetStr(), 30);
        render(window, 0);
        if(!CheckAmongMatchingRussianWords()){
            render(window, 2);
            if(texts.size() == 3){
                texts.emplace_back(L"Не то! За подсказкой жми [H]", font, 28);
                MakeDecorForText(3, 180, 180, sf::Color::Black, sf::Text::Bold);
            }
            else
                ChangeText(3, L"Не то! За подсказкой жми [H]", 28);

            render(window, 3);
            opt = false;
        }

    }
    else if(key == sf::Keyboard::Escape){
        window.close();
    }


}

void Eng_Practice::MakeAnswer(const String& s){
    if(texts.size() == 1){
        if(s.is_ascii())
            texts.emplace_back(s.GetStr(), font, 30);
        else
            texts.emplace_back(s.to_wide_string(), font, 30);
        MakeDecorForText(1, 200, 320, sf::Color::Red, sf::Text::Style::Bold);
        texts.emplace_back(L"Ваш перевод : ", font, 30);
        MakeDecorForText(2, 180, 270, sf::Color::Black, sf::Text::Style::Bold);
    }
    else{
        if(s.is_ascii())
            ChangeText(1, s.GetStr(), 30);
        else
            ChangeText(1, s.to_wide_string(), 30);
        ChangeText(2, L"Ваш перевод : ", 30);
    }

}

bool Eng_Practice::CheckEqualityOfWords(){
    String my_answer;
    std::cin >> my_answer;

    MakeAnswer(my_answer);

    if(my_answer == itr_->first){
        ChangeText(0, L"Молодец", 30);
        MakeNewPosOfItr();
        id_letter = 1;
        return true;
    }
    return false;
}

bool Eng_Practice::CheckAmongMatchingRussianWords() {

    String my_answer;
    std::cin >> my_answer;

    MakeAnswer(my_answer);

    auto pair = map_.equal_range(itr_->first);

    for(auto it = pair.first; it != pair.second; ++it){
        if(it->second == my_answer){
            ChangeText(0, L"Молодец", 30);
            MakeNewPosOfItr();
            id_letter = 1;
            return true;
        }
    }
    return false;
}


void Eng_Practice::ProcessingWithHints(){
    if((opt && (id_letter == itr_->first.size())) || (!opt && (id_letter == itr_->second.size()))) {
        ChangeText(3, L"Нету больше подсказок :(", 30);
        if(opt)
            ChangeText(1, sf::String(itr_->first.GetStr()), 30);
        else
            ChangeText(1, sf::String(itr_->second.to_wide_string()), 30);
        ChangeText(2, L"Good ответ : ", 30);
        MakeNewPosOfItr();
        id_letter = 1;
        return;
    }


    ChangeText(2, sf::String(std::to_wstring(id_letter)), 30);
    if(opt)
        ChangeText(1, itr_->first(0, id_letter).GetStr(), 30);
    else {
        ChangeText(1, sf::String(itr_->second(0, id_letter).to_wide_string()), 30);
    }
    ++id_letter;

    ChangeText(3, L"Готов [A], нет подсказка [H]", 25);
}




void Eng_Practice::process_events(sf::RenderWindow& window){
    sf::Event event;

    while(window.pollEvent(event)){

        switch(event.type){

            case sf::Event::KeyPressed :{
                ChooseOptions(event.key.code, window);
                break;
            }

            case sf::Event::Closed :
                window.close();
        }
    }
}



void Eng_Practice::MakeNewPosOfItr(){

    if(std::count(state_w.begin(), state_w.end(), static_cast<char>(Symbols::BUSY)) == map_.size()){
        for(int i = 0; i < state_w.size(); ++i)
            state_w[i] = static_cast<char>(Symbols::VACANT_PLACE);
        GenerateStartPosition();
        return;
    }

    std::uniform_int_distribution<> dist(0, map_.size() - 1);
    int new_pos = dist(gen);

    if(state_w[new_pos] != static_cast<char>(Symbols::VACANT_PLACE)){

        auto it = std::find(state_w.begin() + new_pos, state_w.end(),
                         static_cast<char>(Symbols::VACANT_PLACE));

        if(it != state_w.end()){
            new_pos = std::distance(state_w.begin() + new_pos, it);
            /*for(int i = new_pos; i < state_w.size(); ++i){
                if(state_w[i] == static_cast<char>(Symbols::VACANT_PLACE))
                    new_pos = i;
            }*/
        }

        else{
            new_pos = std::distance(state_w.begin(),
                    std::find(state_w.begin(), state_w.end(), static_cast<char>(Symbols::VACANT_PLACE)));
            /*for(int i = 0; i < new_pos; ++i){
                if(state_w[i] == static_cast<char>(Symbols::VACANT_PLACE))
                    new_pos = i;
            }*/
        }
    }

    MovingItr(new_pos);
}

void Eng_Practice::MovingItr(int new_pos){
    if(pos_it > new_pos){
        for(int i = pos_it; i > new_pos; --i)
            --itr_;
    }
    else{
        for(int i = pos_it; i < new_pos; ++i)
            ++itr_;
    }
    pos_it = new_pos;
    state_w[pos_it] = static_cast<char>(Symbols::BUSY);
}


void Eng_Practice::GenerateStartPosition(){
    std::uniform_int_distribution<> dist(0, static_cast<int>(map_.size()/2));
    int start_pos = dist(gen);

    int counter{0};

    for(itr_ = map_.cbegin(); itr_ != map_.cend(); ++itr_){
        if(counter == start_pos)
            break;
        ++counter;
    }

    state_w[start_pos] = static_cast<char>(Symbols::BUSY);
    pos_it = start_pos;
}

void Eng_Practice::MakeNiceStructOfData() {

    String data_;
    int num_lines_{0};
    int current_counter{0};      // this field will contain current index in data_ during parcing
    int pos_special_symbol{0};  //  variable for reminding position of hyphen or comma

    try{
        data_.MakeStrFromFile(path_to_words);
        for(int i = 0; i < data_.GetNumBytes() - 1; ++i){
            if(*(data_.GetStr() + i) == static_cast<const char>(Symbols::ENDSTR))
                ++num_lines_;
        }
        CheckHyphens(data_, num_lines_);

    }catch(My_Exception* ex){
        std::cout << ex->what() << std::endl;
        THROW_NEXT(CodeErrors::ERROR_N, ex)
    }


    while(current_counter < data_.size())
        ParceOneString(data_, current_counter, pos_special_symbol);
}

void Eng_Practice::ParceOneString(const String& data_, int& current_counter, int& pos_special_symbol){


    //---------Work with the first word in string (The word before the hyphen)------------------//

    int pos_end_word = FindPosEndingWord(static_cast<const char>(Symbols::HYPHEN), data_,
            current_counter, pos_special_symbol);

    String key = data_(current_counter,  pos_end_word);  // this line provides with english translation
    current_counter = pos_special_symbol + 1;
    String value;

    //---------------------------------------------------------------------------------------//

    //_____________________Working with the rest part of the line__________________________//
    if(!key.is_ascii()){
        value = key;
        MakePair(key, value, pos_end_word, true, data_, current_counter, pos_special_symbol);
    }

    else{
        while(data_[current_counter - 1] != static_cast<const char>(Symbols::ENDSTR)){
            MakePair(value, key, pos_end_word, false, data_, current_counter, pos_special_symbol);
        }
    }
    
    //---------------------------------------------------------------------------------------------//
}

void Eng_Practice::MakePair(String &change, const String &another, int& pos_end_word, bool order,
        const String& data_, int& current_counter, int& pos_special_symbol) {

    pos_end_word = FindPosEndingWord(static_cast<const char>(Symbols::COMMA),
            data_, current_counter, pos_special_symbol);

    change = data_(current_counter, pos_end_word);

    current_counter = pos_special_symbol + 1;

    if(order)
        map_.insert(std::make_pair(change, another));
    else
        map_.insert(std::make_pair(another, change));
}

int Eng_Practice::FindPosEndingWord(const char c, const String& data_, int& current_counter, int& pos_special_symbol){
    while(data_[current_counter] == static_cast<const char>(Symbols::SPACE))
        ++current_counter;

    pos_special_symbol = current_counter;

    while(data_[pos_special_symbol] != static_cast<const char>(Symbols::ENDSTR)){
        if(data_[pos_special_symbol] == c)
            break;
        ++pos_special_symbol;
    }

    if(data_[pos_special_symbol] == static_cast<const char>(Symbols::ENDSTR) && c == static_cast<const char>(Symbols::HYPHEN)){
        FIRST_THROW(CodeErrors::ERROR_BAD_DATA, "This string doesn't contain "
                                                "a hyphen so i cannot understand where is the word boundaries ")
    }

    else if(data_[pos_special_symbol] == static_cast<const char>(Symbols::ENDSTR) && c == static_cast<const char>(Symbols::COMMA)){
        int pos = pos_special_symbol;
        while(data_[pos - 1] == static_cast<const char>(Symbols::SPACE)){
            --pos;

        }
        return pos;
    }

    else if(c == static_cast<const char>(Symbols::COMMA))
        return pos_special_symbol;


    int first_end = pos_special_symbol - 1;

    while(first_end >= 0){
        if(data_[first_end] != static_cast<const char>(Symbols::SPACE)){
            ++first_end;   // due to method cut in string need the second argument pos after the last letter
            break;
        }
        --first_end;
    }

    return first_end;
}