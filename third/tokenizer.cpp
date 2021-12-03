//
//  tokenizer.cpp
//  third
//
//  Created by Артемий Данилов on 26.11.2021.
//

#include "tokenizer.hpp"

tokenizer :: tokenizer(){
        number_of_sep = 0;
    }

tokenizer :: tokenizer(string *tokens, int number_of_tokens, unsigned long *lengts){
    this->tokens = new string[number_of_tokens];
    this->lengts = new unsigned long[number_of_tokens];
    this->number_of_tokens = number_of_tokens;
    for(int i = 0; i < number_of_tokens; i++){
        this->tokens[i] = tokens[i];
        this->lengts[i] = lengts[i];
        this->text += tokens[i];
        this->text += ' ';
    }
    this->sep = new char[1];
    this->sep[0] = ' ';
    
}

tokenizer :: tokenizer(char *sep, int number_of_sep){
        this->number_of_sep = number_of_sep;
        this->sep = new char[number_of_sep];
        for(int i = 0; i < number_of_sep; i++){
            this->sep[i] = sep[i];
        }
    }


void tokenizer :: give_adress(char* name_of_file){
        strcpy(this->name_of_file, name_of_file);
    }


int tokenizer :: create_tokens(){
        ifstream txt;
        txt.open(name_of_file);
        string str;
        string buffer;
        unsigned long n = 0;
        int a = 0, c = 0;
        if(!txt.is_open()){
            cout << "We can't create tokens: invalid file adress..." << endl;
            return 0;
        }
        if(sep[number_of_sep-1] == '\n'){
            a = 1;
        }
    while(getline(txt, str)){
            if(a > 0){
                if(a > 1){
                    text += '\n';
                }
                a++;
            }
            text += str;
            }
        a = 0;
        txt.close();
        n = text.size();
        for(int i = 0; i < n-1; i++){
            a = 0;
            for(int j = 0; j < number_of_sep; j++){
                if(text[i] == sep[j]){
                    a = 1;
                    j += number_of_sep;
                }
            }
                if(a == 1 && i != 0){
                    number_of_tokens++;
                }
                while(a == 1 && i < n-1){
                    a = 0;
                    for(int j = 0; j < number_of_sep; j++){
                        if(text[i+1] == sep[j]){
                            a = 1;
                            j += number_of_sep;
                        }
                    }
                    if(a == 1){
                        i++;
                    }
                    if(i == n-1){
                        number_of_tokens--;
                    }
                }
            }
        tokens = new string[number_of_tokens];
        lengts = new unsigned long[number_of_tokens];
        for(int i = 0; i < n; i++){
           a = 0;
            for(int j = 0; j < number_of_sep; j++){
                if(text[i] == sep[j]){
                    a = 1;
                    j += number_of_sep;
                }
            }
            if(a == 0){
                buffer += text[i];
                if(i == n - 1){
                    tokens[c] = buffer;
                    lengts[c] = buffer.size();
                    buffer.clear();
                }
            }
            if(a == 1 && i != 0){
                tokens[c] = buffer;
                lengts[c] = buffer.size();
                c++;
                buffer.clear();
            }
            while(a == 1 && i < n - 1){
                a = 0;
                for(int j = 0; j < number_of_sep; j++){
                    if(text[i+1] == sep[j]){
                        a = 1;
                        j += number_of_sep;
                    }
                }
                if(a == 1){
                    i++;
                }
            }
        }
    if(number_of_tokens == 1 && tokens[0] == buffer){
        number_of_tokens = 0;
    }
        return 1;
    }


void tokenizer :: get_token_by_n(int n){
        cout << tokens[n] << endl;
    }


int tokenizer :: get_number_of_tokens(){
    return  number_of_tokens;
}

void tokenizer :: see_all_tokens(){
    for(int i = 0; i < number_of_tokens; i++){
        cout << i << "." << tokens[i] << endl;
    }
}

void tokenizer :: change_sep(char *sep, int number_of_sep){
    this->number_of_sep = number_of_sep;
    number_of_tokens = 1;
    delete [] this->sep;
    delete [] lengts;
    this->sep = new char[number_of_sep];
    for(int i = 0; i < number_of_sep; i++){
        this->sep[i] = sep[i];
    }
    delete [] tokens;
    string buffer;
    unsigned long n = 0;
    int a = 0, c = 0;
    n = text.size();
    for(int i = 0; i < n-1; i++){
        a = 0;
        for(int j = 0; j < number_of_sep; j++){
            if(text[i] == sep[j]){
                a = 1;
                j += number_of_sep;
            }
            if(a == 1 && i != 0){
                number_of_tokens++;
            }
            while(a == 1 && i < n-1){
                a = 0;
                for(int j = 0; j < number_of_sep; j++){
                    if(text[i+1] == sep[j]){
                        a = 1;
                        j += number_of_sep;
                    }
                }
                if(a == 1){
                    i++;
                }
            }
        }
    }
    tokens = new string[number_of_tokens];
    lengts = new unsigned long[number_of_tokens];
    for(int i = 0; i < n; i++){
       a = 0;
        for(int j = 0; j < number_of_sep; j++){
            if(text[i] == sep[j]){
                a = 1;
                j += number_of_sep;
            }
        }
        if(a == 0){
            buffer += text[i];
            if(i == n - 1){
                tokens[c] = buffer;
                lengts[c] = buffer.size();
                buffer.clear();
            }
        }
        if(a == 1 && i != 0){
            tokens[c] = buffer;
            lengts[c] = buffer.size();
            c++;
            buffer.clear();
        }
        while(a == 1 && i < n - 1){
            a = 0;
            for(int j = 0; j < number_of_sep; j++){
                if(text[i+1] == sep[j]){
                    a = 1;
                    j += number_of_sep;
                }
            }
            if(a == 1){
                i++;
            }
        }
    }
}


string tokenizer :: get_str_token(int n){
    return tokens[n];
}


void tokenizer :: get_lengths_arr(){
    cout << "Lengths[";
    for (int i = 0; i < number_of_tokens; i++){
        cout << lengts[i];
        if(i != number_of_tokens - 1){
            cout << ",";
        }
    }
    cout << "]" << endl;
}


unsigned long tokenizer :: get_lengths_by_n(int n){
    return lengts[n];
}


bool &tokenizer :: operator==(tokenizer &other){
    bool k = true;
    if(this->number_of_tokens != other.get_number_of_tokens()){
        k = false;
        return k;
    }
    for(int i = 0; i < this->number_of_tokens; i++){
        if(this->lengts[i] != other.get_lengths_by_n(i)){
            k = false;
            return k;
        }
    }
    for(int i = 0; i < this->number_of_tokens; i++){
        if(this->tokens[i] != other.get_str_token(i)){
            k = false;
    }
    }
    return k;
}


tokenizer :: ~tokenizer(){
    text.clear();
    if(*sep != 0){
    delete [] sep;
    }
    if(*lengts != 0){
    delete [] lengts;
    }
    if(tokens){
    delete [] tokens;
    }
}
    
