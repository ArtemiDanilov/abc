#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include "tokenizer.hpp"
#include "Autotest.hpp"

using namespace std;



int main(){
    Autotest();
    int n = 0, d = 0, r = 0;
    char s = ' ';
    char name_of_file[256];
    cout << "How many separators do you want to use?" << endl;
    cin >> n;
    if(n < 0){
        cout << "Please enter a natural number" << endl;
        cin >> n;
    }
    cout << "Do you want to use:" << endl << "0.No" << endl << "1.Space" << endl << "2.Sapce and enter" << endl << "3.Enter" << endl;
    cin >> r;
    if(r != 0){
        d++;
        n++;
        if(r == 2){
            n++;
            d++;
        }
    }
    
    if(n == 0){
    for(int i = 0; i < 4; i++){
        cout << "We can't create tokens without separators" << endl << "Please enter how many separators do you want to use:" << endl;
        cin >> n;
        cout << "Do you want to use:" << endl << "0.No" << endl << "1.Space" << endl << "2.Sapce and enter" << endl << "3.Enter" << endl;
        cin >> r;
        if(r != 0){
            d++;
            n++;
            if(r == 2){
                n++;
                d++;
            }
        }
        if(n != 0){
            i += 20;
        }
    }
    }
    char *sep = new char[n];
    if(n > 0){
        for(int i = 0; i < n-d; i++){
            cout << "Enter " << i+1 <<"th separator: "<< endl;
            cin >> s;
            sep[i] = s;
        }
        if(r == 1){
            sep[n-1] = ' ';
        }
        if(r == 2){
            sep[n-2] = ' ';
            sep[n-1] = '\n';
        }
        if(r == 3){
            sep[n-1] = '\n';
        }
    }
    d = 0;
    cout << "Enter name of file:" << endl;
    cin >> name_of_file;
    tokenizer text(sep, n);
    delete [] sep;
    text.give_adress("/Users/artemijdanilov/Desktop/эвм/third/third/text.txt");
    while(text.create_tokens() == 0){
        cout << "Enter correct name of file:" << endl;
        cin >> name_of_file;
        text.give_adress(name_of_file);
        d++;
        if(d == 10){
            return 10;
        }
    }
    int k = 0;
    while(k != 7 && d < 40){
        cout << "What do you wanna do?" << endl << "1.Get token by index" << endl << "2.Get all tokens" << endl << "3.Get number of tokens" << endl << "4.Change separators" << endl << "5.Get lenghts array"<< endl << "6.Get lenght of token by index" << endl << "7.Exit" << endl;
        cin >>  k;
        cout << endl;
        if(k == 1){
            if(text.get_number_of_tokens() > 0){
            cout << "Write the number of token: ";;
            cin >> k;
            cout << "token[" << k << "] = ";
            text.get_token_by_n(k);
            cout << endl;
            k = 1;
            }
        else{
            cout << "There is no tokens in text with this separators" << endl;
        }
        }
        if(k == 2){
            if(text.get_number_of_tokens() > 0){
            cout << "TOKENS:" << endl;
            text.see_all_tokens();
            cout << endl;
            }
            else{
            cout << "There is no tokens in text with this separators" << endl;
            }
        }
        if(k == 3){
            cout << endl << "Number of tokens: " << text.get_number_of_tokens() << endl << endl;
        }
        if(k == 4){
            cout << "How many separators do you want to use?" << endl;
            cin >> n;
            if(n < 0){
                cout << "Please enter a natural number" << endl;
                cin >> n;
            }
            cout << "Do you want to use:" << endl << "0.No" << endl << "1.Space" << endl <<  "2.Sapce and enter" << endl << "3.Enter" << endl;
            cin >> r;
            if(r != 0){
                d = 1;
                n++;
                if(r == 2){
                    n++;
                    d++;
                }
            }
            char *sep = new char[n];
            if(n > 0){
                for(int i = 0; i < n-d; i++){
                    cout << "Enter " << i+1 <<"th separator: "<< endl;
                    cin >> s;
                    sep[i] = s;
                }
            }
            else{
                cout << "Please enter a natural number" << endl;
            }
            text.change_sep(sep, n);
            delete [] sep;
        }
        if(k == 5){
            if(text.get_number_of_tokens() > 0){
            text.get_lengths_arr();
            }
            else{
                cout << "There is no tokens in text with this separators" << endl;
            }
        }
        if(k == 6){
            if(text.get_number_of_tokens() > 0){
                cout << "Lenght = " << text.get_lengths_by_n(n) << endl;
            }
            else{
                cout << "There is no tokens in text with this separators" << endl;
            }
        }
        d++;
    }
    return 0;
}
