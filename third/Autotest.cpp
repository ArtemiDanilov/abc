//
//  Autotest.cpp
//  third
//
//  Created by Артемий Данилов on 26.11.2021.
//

#include "Autotest.hpp"

int autotest_1(){
    ofstream fout("Test.txt");
    fout << "Aaa aa aa";
    fout.close();
    char *sep = new char[2];
    sep[0] = ' ';
    sep[1] = '\n';
    tokenizer test_text(sep, 2);
    test_text.give_adress("Test.txt");
    test_text.create_tokens();
    string *answer = new string[3];
    unsigned long* len;
    len = new unsigned long[3];
    answer[0] += "Aaa";
    answer[1] += "aa";
    answer[2] += "aa";
    len[0] = 3;
    len[1] = 2;
    len[2] = 2;
    tokenizer ans(answer, 3, len);
    delete [] answer;
    delete [] len;
    delete [] sep;
    if(ans == test_text){
        return 1;
    }
    return 0;
}

int autotest_2(){
    ofstream fout("Test.txt");
    fout << "Aaa aa aa \n";
    fout.close();
    char *sep = new char[1];
    sep[0] = '\n';
    tokenizer test_text(sep, 1);
    test_text.give_adress("Test.txt");
    test_text.create_tokens();
    string *answer = new string[3];
    unsigned long* len;
    len = new unsigned long[10];
    answer[0] += "Aaa aa aa ";
    len[0] = 10;
    tokenizer ans(answer, 1, len);
    delete [] answer;
    delete [] len;
    delete [] sep;
    if(ans == test_text){
        return 1;
    }
    return 0;
}

int autotest_3(){
    ofstream fout("Test.txt");
    fout << "\nAaa aa aa\na a\n a\n";
    fout.close();
    char *sep = new char[1];
    sep[0] = '\n';
    tokenizer test_text(sep, 1);
    test_text.give_adress("Test.txt");
    test_text.create_tokens();
    string *answer = new string[3];
    unsigned long* len;
    len = new unsigned long[3];
    answer[0] += "Aaa aa aa";
    answer[1] += "a a";
    answer[2] += " a";
    len[0] = 9;
    len[1] = 3;
    len[2] = 2;
    tokenizer ans(answer, 3, len);
    delete [] answer;
    delete [] len;
    delete [] sep;
    if(ans == test_text){
        return 1;
    }
    return 0;
}

int autotest_4(){
    ofstream fout("Test.txt");
    fout << "a1a1";
    fout.close();
    char *sep = new char[1];
    sep[0] = 'a';
    tokenizer test_text(sep, 1);
    test_text.give_adress("Test.txt");
    test_text.create_tokens();
    string *answer = new string[2];
    unsigned long* len;
    len = new unsigned long[2];
    answer[0] += "1";
    answer[1] += "1";
    len[0] = 1;
    len[1] = 1;
    tokenizer ans(answer, 2, len);
    if(ans == test_text){
        answer[0].clear();
        answer[1].clear();
        answer[0] += "a";
        answer[1] += "a";
        tokenizer ans(answer, 2, len);
        sep[0] = '1';
        test_text.change_sep(sep, 1);
        delete [] answer;
        delete [] len;
        delete [] sep;
        if(ans == test_text){
            return 1;
        }
        
    }
    else{
        delete [] answer;
        delete [] len;
        delete [] sep;
    }
    return 0;
}

void Autotest(){
    int k = 0;
    if(autotest_1() == 1){
        k++;
    }
    else{
        cout << "First autotest failed!" << endl;
    }
    
    if(autotest_2() == 1){
        k++;
    }
    else{
        cout << "Second autotest failed!" << endl;
    }
    
    if(autotest_3() == 1){
        k++;
    }
    else{
        cout << "Third autotest failed!" << endl;
    }
    
    if(autotest_4() == 1){
        k++;
    }
    else{
        cout << "Fourth autotest failed!" << endl;
    }
    
    cout << k << "/4 autotests have passed" << endl;
}
