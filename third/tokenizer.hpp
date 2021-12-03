#pragma once
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
using namespace std;

class tokenizer
{
private:
    int number_of_sep;
    unsigned long *lengts;
    char *sep;
    char name_of_file[256];
    int number_of_tokens = 1;
    string *tokens;
    string text;
public:
    tokenizer();
    tokenizer(char*, int);
    tokenizer(string*,int,unsigned long*);
    void give_adress(char*);
    int create_tokens();
    void get_token_by_n(int);
    int get_number_of_tokens();
    void see_all_tokens();
    void change_sep(char*, int);
    void get_lengths_arr();
    unsigned long get_lengths_by_n(int);
    string get_str_token(int);
    bool &operator==(tokenizer &other);
    ~tokenizer();
};
