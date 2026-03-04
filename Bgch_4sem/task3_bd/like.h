# ifndef LIKE_H
# define LIKE_H

#include "stdio.h"
# include <string.h>

enum class spec_s
{
    standard, // '//'
    underscore, // '_'
    percent, // '%'
    segment, // '[n-m]'
    nsegment, // '[^n-m]'
};

class operator_like 
{
private:
    const char *s = nullptr;
    size_t len=0;
    spec_s *symbols = nullptr;
    size_t symbols_num=0;
    bool status = false;
public:
    operator_like() = delete;
    operator_like(const char *str)
    {
        s = str;
        len = strlen(s);
        symbols = new spec_s[len]();
        if(symbols) status = true;
    }
    ~operator_like()
    {
        delete[] symbols;
    }
    int parse()
    {
        if(!status) return -1;

        for(size_t i=0; i<len; ++i)
        {
            switch (s[i])
            {
            case '\\':
                symbols[symbols_num] = spec_s::standard;
                ++symbols_num;
                ++i;
                if(i==len) return -2; // конец слова
                break;
            case '_':
                symbols[symbols_num] = spec_s::underscore;
                ++symbols_num;
                break;
            case '%':
                symbols[symbols_num] = spec_s::percent;
                ++symbols_num;
                break;
            case '[':
                if(i+4>len) return -3;
                if(s[i+1] == '^')
                {
                    if(i+5>len) return -4;
                    if(s[i+5] != ']' || s[i+3] != '-') return -5;
                    symbols[symbols_num] = spec_s::nsegment;
                    ++symbols_num;
                    i+=5;
                }
                else
                {
                    if(s[i+4] != ']' || s[i+2] != '-') return -6;
                    symbols[symbols_num] = spec_s::segment;
                    ++symbols_num;
                    i+=4;
                }
                break;
            default:
                symbols[symbols_num] = spec_s::standard;
                ++symbols_num;
                break;
            }
        }
        return 0;
    }
    bool apply(const char * str) const
    {
        size_t word_len = strlen(str);
        size_t index_str = 0; // по str
        size_t index_s = 0; // по s
        int q=0, flag=0;
        const char *t;
        const char *t2;

        for(size_t i=0; i<symbols_num; ++i) // кол-во значимых символов
        {
            if(str[index_str] == '\0') return false;
            if((s[index_s]) == '\\') ++index_s;

            switch (symbols[i])
            {
            case spec_s::standard:
                if(s[index_s]!=str[index_str]) return false;
                ++index_s; ++index_str;
                break;
            case spec_s::underscore:
                ++index_s; ++index_str;
                break;
            case spec_s::segment:
                if((unsigned char)str[index_str] < (unsigned char)s[index_s+1] || (unsigned char)str[index_str] > (unsigned char)s[index_s+3]) return false;
                index_s+=5; 
                ++index_str;
                break;

            case spec_s::nsegment:
                if((unsigned char)str[index_str] >= (unsigned char)s[index_s+2] && (unsigned char)str[index_str] <= (unsigned char)s[index_s+4]) return false;
                index_s+=6; 
                ++index_str;
                break;

            case spec_s::percent:

                if(i == symbols_num-1) return true; // text%
                

                if(i==0 && symbols[symbols_num-1] == spec_s::percent) // %text%
                {
                    q = symbols_num - 2; // кол-во оставшихся символов
                    flag = 0;
                    index_s = 1;

                    for(size_t j=1; j<len-1; ++j)
                    {
                        if((s[index_s]) == '\\') ++index_s;

                        if(str[index_str] == '\0') return false;
                        switch (symbols[j])
                        {
                            case spec_s::standard:
                                if(s[index_s]!=str[index_str])
                                {
                                    flag=-1;
                                }
                                ++index_s; ++index_str; ++flag;  
                                break;
                            case spec_s::underscore:
                                ++index_s; ++index_str; ++flag;
                                break;
                            case spec_s::segment:
                                if((unsigned char)str[index_str] < (unsigned char)s[index_s+1] || (unsigned char)str[index_str] > (unsigned char)s[index_s+3])
                                {
                                    flag=-1;
                                }
                                index_s+=5; 
                                ++index_str;
                                ++flag;
                                break;

                            case spec_s::nsegment:
                                if((unsigned char)str[index_str] >= (unsigned char)s[index_s+2] && (unsigned char)str[index_str] <= (unsigned char)s[index_s+4])
                                {
                                    flag=-1;
                                }
                                index_s+=6; 
                                ++index_str;
                                ++flag;
                                break;
                            case spec_s::percent:
                                return false; // %text%text% - warning
                        }
                        if(flag == q) return true;
                        if(flag == 0)
                        {
                            index_s = 1;
                            j=0;
                        }
                    }
                    return false;
                }
                else // text1%text2 || %text
                {
                    q = symbols_num - i - 1; // кол-во оставшихся символов

                    ++index_s; ++index_str;

                    t = &s[index_s];
                    t2 = &str[word_len-q];

                    operator_like tmp(t);
                    tmp.parse();
                    return tmp.apply(t2);
                }
                break; 
            }
        }
        if(str[index_str] != '\0') return false;
        return true;
    }
};

#endif