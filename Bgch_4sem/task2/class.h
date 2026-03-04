#ifndef CLASS_H
#define CLASS_H

#include <stdio.h>
#include <memory>
#include "io_status.h"
#include "tree_avl.h"
#include "b_tree.h"
#include "rb_tree.h"
#include "string.h" //


#ifndef BUF
#define BUF 256
#endif

class Word
{
private:
    std::unique_ptr<char []> value; // s
public:
    Word() = default;
    Word(char* n_s) : value(n_s) {}
    ~Word() = default;

    Word (const Word &) = delete;
    Word (Word&& x) = default;
    Word& operator= (const Word& x) = delete;
    Word& operator= (Word&& x) = default;

    int operator>  (const Word& x) const { return cmp(x) >  0; }
    int operator<  (const Word& x) const { return cmp(x) <  0; }
    int operator== (const Word& x) const { return cmp(x) == 0; }

    void print (FILE *fp = stdout) const 
    {
        if(value != nullptr) fprintf (fp, "%s\n", value.get());   
    }

    char* get_value () {return value.get();}

    io_status fun(const char *n_value)
    {
        if(n_value != nullptr) 
        {
            size_t v_len = strlen(n_value);

            value.reset(new char[v_len+1]);

            if(value != nullptr)
            {
                for(size_t i = 0; i < v_len; ++i) value[i] = n_value[i];
                value[v_len] = 0;
            }
            else return io_status::memory;
        }
        return io_status::success;
    }

private: 
    int cmp (const Word& x) const
    {
        if(value == nullptr)
        {
            if(x.value != nullptr) return -1;
            return 0;
        }
        if(x.value == nullptr) return 1;

        return strcmp(value.get(), x.value.get());
    }

};

class Pair_word
{
private:
    std::unique_ptr<char []> value; // s
    std::unique_ptr<char []> name; // x
public:
    Pair_word() = default;
    Pair_word(char* n_s, char*n_t) : value(n_s), name(n_t) {}
    ~Pair_word() = default;

    Pair_word (const Pair_word &) = delete;
    Pair_word (Pair_word&& x) = default;
    Pair_word& operator= (const Pair_word& x) = delete;
    Pair_word& operator= (Pair_word&& x) = default;

    int operator>  (const Pair_word& x) const { return cmp(x) >  0; }
    int operator<  (const Pair_word& x) const { return cmp(x) <  0; }

    void print (const char *c = "", FILE *fp = stdout) const 
    {
        fprintf (fp, "%s %s %c\n", value.get(), name.get(), *c);
    }

    char* get_name () {return name.get();}
    char* get_value () {return value.get();}

    io_status init(const char *n_value, const char *n_name)
    {
        if(n_value != nullptr) 
        {
            size_t v_len = strlen(n_value);
            size_t n_len = strlen(n_name);

            value.reset(new char[v_len+1]);
            name.reset(new char[n_len+1]);

            if(name != nullptr && value != nullptr)
            {
                for(size_t i = 0; i < v_len; ++i) value[i] = n_value[i];
                value[v_len] = 0;

                for(size_t i = 0; i < n_len; ++i) name[i] = n_name[i];
                name[n_len] = 0;

            }
            else return io_status::memory;
        }
        return io_status::success;
    }

private: 
    int cmp (const Pair_word& x) const
    {
        if(value == nullptr)
        {
            if(x.value != nullptr) return -1;
            return 0;
        }
        if(x.value == nullptr) return 1;

        return strcmp(value.get(), x.value.get());
    }

};

class Word_and_condition
{
private:
    std::unique_ptr<char []> value; // s
    char condition[3] = {0,0,0};
public:
    Word_and_condition() = default;
    ~Word_and_condition() = default;

    Word_and_condition (const Word_and_condition &) = delete;
    Word_and_condition (Word_and_condition&& x) = default;
    Word_and_condition& operator= (const Word_and_condition& x) = delete;
    Word_and_condition& operator= (Word_and_condition&& x) = default;

    int operator>  (const Word_and_condition& x) const { return cmp(x) >  0; }
    int operator>= (const Word_and_condition& x) const { return cmp(x) >= 0; }
    int operator<  (const Word_and_condition& x) const { return cmp(x) <  0; }
    int operator<= (const Word_and_condition& x) const { return cmp(x) <= 0; }
    int operator== (const Word_and_condition& x) const { return cmp(x) == 0; }
    int operator!= (const Word_and_condition& x) const { return cmp(x) != 0; }

    int examination(const char* word)
    {
        if (condition[0] == '<' && condition[1] == 0)  return (cmp2(word) < 0);
        if (condition[0] == '>' && condition[1] == 0)  return (cmp2(word) > 0);
        if (condition[0] == '<' && condition[1] == '=') return (cmp2(word) <= 0);
        if (condition[0] == '>' && condition[1] == '=') return (cmp2(word) >= 0);
        if (condition[0] == '=' && condition[1] == 0)  return (cmp2(word) == 0);
        if (condition[0] == '<' && condition[1] == '>') return (cmp2(word) != 0);
        return 0;
    }

    void print (FILE *fp = stdout) const 
    {
        if(value!=nullptr) fprintf (fp, "%s %s\n", value.get(), condition);
    }

    char* get_value () {return value.get();}


    io_status init(const char* n_value, const char n_condition[3])
    {
        if(n_value != nullptr)
        {
            size_t v_len = strlen(n_value);

            value.reset(new char[v_len+1]);

            if(value != nullptr)
            {
                for(size_t i = 0; i < v_len; ++i) value[i] = n_value[i];
                value[v_len] = 0;
                delete[] n_value;
            }
            else return io_status::memory;
            for(int i=0; i<3; ++i) condition[i] = n_condition[i];
        }
        return io_status::success;
    }

private:
    int cmp (const Word_and_condition& x) const
    {
        if(value == nullptr)
        {
            if(x.value != nullptr) return -1;
            return 0;
        }
        if(x.value == nullptr) return 1;

        return strcmp(value.get(), x.value.get());
    }

    int cmp2 (const char* word) const
    {
        if(value == nullptr)
        {
            return 0;
        }

        return strcmp(word, value.get());
    }

};


class Construction01
{
private:
    b_tree<Word> *a;
    char *s;
    char *t;
    int spaces[BUF] = {0};
public:
    Construction01(char *n_s, char *n_t, int m) : s(n_s), t(n_t)
    {
        a = new b_tree<Word>(m);
        size_t len_t = strlen(t);
        for(size_t i=0; i<len_t; ++i)
        {
            spaces[(unsigned char)t[i]] = 1;
        }

    }
    ~Construction01()
    {
        delete a;
    }
    b_tree<Word>* get_tree() {return a;}

    io_status creation_tree()
    {
        io_status status;


        const char* str = s;

        while (*str)
        {
            while (*str && spaces[(unsigned char)*str] == 1) ++str; // пропускаем разделители
 
            const char* start = str;

            while (*str && spaces[(unsigned char)*str] != 1) ++str;

            char* word = new char[str - start + 1];
            strncpy(word, start, str - start);
            word[str - start] = '\0';

            Word node(word);

            status = a->insert(node);
            
            if(status != io_status::success) return status; 
        }
        return io_status::success;
    }

    friend class Word;

};

int printfile01(b_tree<Word> *a, FILE *fin, FILE*fout, const char* t)
{
    int r=0;
    // a->print(4);

    int spaces[BUF] = {0};
    size_t len_t = strlen(t);
    for(size_t i=0; i<len_t; ++i)
    {
        spaces[(unsigned char)t[i]] = 1;
    }
    
    char*word;
    int k=0;
    

    while (1)  // по строкам
    {
        char buffer[1024];
        if(!fgets(buffer, sizeof(buffer), fin)) break; // копируем строку в bufer
        
        const char*p = buffer;

        int flag=0;

        while (*p)
        {
            if(*p == '\n') break;
            while (*p && spaces[(unsigned char)*p] == 1) ++p;// пропускаем разделители

            const char* start = p;

            while (*p && spaces[(unsigned char)*p] != 1 && *p!='\n') ++p;

            word = new char[p - start + 1];
            strncpy(word, start, p - start);
            word[p - start] = '\0';

            const Word key(word);

            if(a->prof(key))
            {
                flag=1;
                break;
            }
            delete[] word;
        }
        if(flag)
        {
            if(k)fprintf(fout, "\n");
            for(int i=0; buffer[i]!='\0' && buffer[i] != '\n'; i++)
            {
                fprintf(fout, "%c", buffer[i]);
            }
            r++;
            k=1;
        }
        
    }
    return r;

}

class Construction02
{
private:
    rb_tree<Word> *a;
    char *s;
    char *t;
    int spaces[BUF] = {0};
public:
    Construction02(char *n_s, char *n_t) : s(n_s), t(n_t)
    {
        a = new rb_tree<Word>();
        size_t len_t = strlen(t);
        for(size_t i=0; i<len_t; ++i)
        {
            spaces[(unsigned char)t[i]] = 1;
        }

    }
    ~Construction02() {delete a;}
    rb_tree<Word>* get_tree() {return a;}

    io_status creation_tree()
    {
        io_status status;

        const char* str = s;

        while (*str)
        {
            while (*str && spaces[(unsigned char)*str] == 1) ++str; // пропускаем разделители
 
            const char* start = str;

            while (*str && spaces[(unsigned char)*str] != 1) ++str;

            char* word = new char[str - start + 1];
            strncpy(word, start, str - start);
            word[str - start] = '\0';

            rb_tree_node<Word> *node = new rb_tree_node<Word>;
            node->fun(word);

            status = a->insert(node);
            delete[] word;
            
            if(status != io_status::success) return status; 
        }
        return io_status::success;
    }

    friend class Word;

};

int printfile02(rb_tree<Word> *a, FILE *fin, FILE*fout, const char* t)
{
    int r=0;
    a->print(4);

    int spaces[BUF] = {0};
    size_t len_t = strlen(t);
    for(size_t i=0; i<len_t; ++i)
    {
        spaces[(unsigned char)t[i]] = 1;
    }

    char*word;

    int k=0;
    

    while (1)  // по строкам
    {
        char buffer[1024];
        if(!fgets(buffer, sizeof(buffer), fin)) break; // копируем строку в bufer
        
        const char*p = buffer;

        int flag=0;

        while (*p)
        {
            if(*p == '\n') break;

            while (*p && spaces[(unsigned char)*p] == 1) ++p;// пропускаем разделители

            const char* start = p;

            while (*p && spaces[(unsigned char)*p] != 1 && *p!='\n') ++p;

            word = new char[p - start + 1];
            strncpy(word, start, p - start);
            word[p - start] = '\0';

            const Word *key = new Word(word);


            if(a->prof(key) == 0) // не нашли
            {
                delete[] word;
                delete key;
                flag=1;
                break;
            }
            delete[] word;
            delete key;
        }
        if(flag==0)
        {
            if(k)fprintf(fout, "\n");
            for(int i=0; buffer[i]!='\0' && buffer[i] != '\n'; i++)
            {
                fprintf(fout, "%c", buffer[i]);
            }
            r++;
            k=1;
        }
    }
    return r;

}

class Construction03
{
private:
    avl_tree<Pair_word> *a;
    char *s;
    char *t;
    char *x;
    int spaces[BUF] = {0};
public:
    Construction03(char *n_s, char *n_t, char *n_x) : s(n_s), t(n_t), x(n_x)
    {
        a = new avl_tree<Pair_word>;
        size_t len_t = strlen(t);
        for(size_t i=0; i<len_t; ++i)
        {
            spaces[(unsigned char)t[i]] = 1;
        }
    }
    ~Construction03()
    {
        delete a;
    }
    avl_tree<Pair_word>* get_tree() {return a;}

    io_status creation_tree()
    {
        io_status status;
        
        char* word_v;
        char* word_n;

        while (*s)
        {
            while (*s && spaces[(unsigned char)*s] == 1) ++s; // пропускаем разделители
 
            const char* start = s;

            while (*s && spaces[(unsigned char)*s] != 1) ++s;

            word_v = new char[s - start + 1];
            strncpy(word_v, start, s - start);
            word_v[s - start] = '\0';

            if(*x)
            {
                while (*x && spaces[(unsigned char)*x] == 1) ++x; // пропускаем разделители
 
                const char* st = x;

                while (*x && spaces[(unsigned char)*x] != 1) ++x;

                word_n = new char[x - st + 1];
                strncpy(word_n, st, x - st);
                word_n[x - st] = '\0';
            }
            else
            {
                word_n = new char[1];
                word_n[0] = '\0';
            }

            avl_tree_node<Pair_word> *node = new avl_tree_node<Pair_word>;
            status = node->init(word_v, word_n);

            if(status != io_status::success) 
            {
                delete[] word_v;
                delete[] word_n;
                return status; 
            }

            status = a->add_node(node);

            if(status != io_status::success) 
            {
                delete[] word_v;
                delete[] word_n;
                return status; 
            }

            delete[] word_v;
            delete[] word_n;
 
        }

        return io_status::success;
    }

    friend class Pair_word;

};

int printfile03(avl_tree<Pair_word> *a, FILE *fin, FILE*fout, const char* t)
{
    int r=0;
    // a->print(4);

    int spaces[BUF] = {0};
    size_t len_t = strlen(t);
    for(size_t i=0; i<len_t; ++i)
    {
        spaces[(unsigned char)t[i]] = 1;
    }

    char*word;
    

    while (1) 
    {
        char buffer[1024];
        if(!fgets(buffer, sizeof(buffer), fin)) break;
        
        const char*p = buffer;

        size_t i = 0;

        while (*p)
        {
            if(*p == '\n')
            {
                fprintf(fout, "\n"); 
                break;
            } 
            while (*p && spaces[(unsigned char)*p] == 1) // пропускаем разделители
            {
                fprintf(fout, "%c", p[i]);
                ++p;
            }
            const char* start = p;

            while (*p && spaces[(unsigned char)*p] != 1 && *p!='\n') ++p;

            word = new char[p - start + 1];
            strncpy(word, start, p - start);
            word[p - start] = '\0';

            const char* found = a->search(word);

            if (found) fprintf(fout, "%s", found);
            else fprintf(fout, "%s", word); 

            delete[] word;
        }

        r++;
    }
    return r;
}

class Construction04
{
private:
    Word_and_condition *a;
    char *s;
    char *t;
    char *x;
    int spaces[BUF] = {0};
    size_t size;
public:
    Construction04(char *n_s, char *n_t, char *n_x) : s(n_s), t(n_t), x(n_x)
    {
        a = new Word_and_condition[BUF];
        size = 0;
        size_t len_t = strlen(t);
        for(size_t i=0; i<len_t; ++i)
        {
            spaces[(unsigned char)t[i]] = 1;
        }
    }
    ~Construction04()
    {
        delete[] a;
    }

    Construction04(const Construction04&) = delete;
    Construction04& operator=(const Construction04&) = delete;
    Construction04(Construction04&&) = delete;
    Construction04& operator=(Construction04&&) = delete;

    Word_and_condition* get_tree() {return a;}

    io_status creation_tree()
    {
        io_status status;
        
        char* word_v;
        char word_n[3] = {0,0,0};

        while (*s)
        {
            while (*s && spaces[(unsigned char)*s] == 1) ++s; // пропускаем разделители
 
            const char* start = s;

            while (*s && spaces[(unsigned char)*s] != 1) ++s;

            word_v = new char[s - start + 1];
            strncpy(word_v, start, s - start);
            word_v[s - start] = '\0';

            while (*x == ' ') ++x; // пропускаем пробелы

            const char* st = x;

            if(*x == '<' || *x == '>')
            {
                x++;
                if(*x != ' ') ++x;
            }
            else x++;
            strncpy(word_n, st, x - st);
            word_n[x - st] = '\0';

            Word_and_condition *node = new Word_and_condition;

            status = node->init(word_v, word_n);

            if(status != io_status::success) 
            {
                delete[] word_v;
                return status; 
            }
            
            a[size] = std::move(*node);
            
            // a[size].print();
            size++;

            if(status != io_status::success) 
            {
                delete[] word_v;
                return status; 
            }
            delete[] word_v;
        }

        return io_status::success;
    }

    friend class Word_and_condition;

};

int prof_condition04(Word_and_condition *a, const char *word)
{
    int i=0;

    while(a[i].get_value() != nullptr)
    {
        if(a[i].examination(word))
        {
            return 1;
        }
        i++;
    }
    return 0;
}

int printfile04(Word_and_condition *a, FILE *fin, FILE*fout, const char* t)
{
    int r=0;
    // for(int i=0; i<BUF; ++i) a[i].print();

    int spaces[BUF] = {0};
    size_t len_t = strlen(t);
    for(size_t i=0; i<len_t; ++i)
    {
        spaces[(unsigned char)t[i]] = 1;
    }

    char*word;

    int k=0;
    
    while (1)  // по строкам
    {
        char buffer[1024];
        if(!fgets(buffer, sizeof(buffer), fin)) break; // копируем строку в bufer
        
        const char*p = buffer;
        int flag=0;

        while (*p)
        {
            if(*p == '\n') break;
            while (*p && spaces[(unsigned char)*p] == 1) ++p;// пропускаем разделители

            const char* start = p;

            while (*p && spaces[(unsigned char)*p] != 1 && *p!='\n') ++p;

            word = new char[p - start + 1];
            strncpy(word, start, p - start);
            word[p - start] = '\0';

            // printf("%s ", key);

            if(prof_condition04(a, word)==1)
            {
                delete[] word;
                flag=1;
                break;
            }
            delete[] word;
        }

        if(flag)
        {
            if(k)fprintf(fout, "\n");
            for(int i=0; buffer[i]!='\0' && buffer[i] != '\n'; i++)
            {
                fprintf(fout, "%c", buffer[i]);
            }
            r++;
            k=1;
        }
        
    }
    
    return r;

}

int printfile05(Word_and_condition *a, FILE *fin, FILE*fout, const char* t)
{
    int r=0;
    // for(int i=0; i<BUF; ++i) a[i].print();
    
    int spaces[BUF] = {0};
    size_t len_t = strlen(t);
    for(size_t i=0; i<len_t; ++i)
    {
        spaces[(unsigned char)t[i]] = 1;
    }

    char*word;

    int k=0;
    

    while (1)  // по строкам
    {
        char buffer[1024];
        if(!fgets(buffer, sizeof(buffer), fin)) break; // копируем строку в bufer
        
        const char*p = buffer;

        int flag=0;

        while (*p)
        {
            flag = 1;
            if(*p == '\n') break;
            while (*p && spaces[(unsigned char)*p] == 1) ++p;// пропускаем разделители

            const char* start = p;

            while (*p && spaces[(unsigned char)*p] != 1 && *p!='\n') ++p;

            word = new char[p - start + 1];
            strncpy(word, start, p - start);
            word[p - start] = '\0';

            // printf("%s ", key);

            if(prof_condition04(a, word)==0)
            {
                delete[] word;
                flag=0;
                break;
            }
            delete[] word;
        }

        if(flag)
        {
            if(k)fprintf(fout, "\n");
            for(int i=0; buffer[i]!='\0' && buffer[i] != '\n'; i++)
            {
                fprintf(fout, "%c", buffer[i]);
            }
            r++;
            k=1;
        }
        
    }
    
    return r;

}

class Construction06
{
private:
    Word *a;
    char *s;
    char *t;
    int spaces[BUF] = {0};
    size_t size;
public:
    Construction06(char *n_s, char *n_t) : s(n_s), t(n_t)
    {
        a = new Word[BUF];
        size = 0;
        size_t len_t = strlen(t);
        for(size_t i=0; i<len_t; ++i)
        {
            spaces[(unsigned char)t[i]] = 1;
        }
    }
    ~Construction06()
    {
        delete[] a;
    }

    Construction06(const Construction06&) = delete;
    Construction06& operator=(const Construction06&) = delete;
    Construction06(Construction06&&) = delete;
    Construction06& operator=(Construction06&&) = delete;

    Word* get_tree() {return a;}

    io_status creation_tree()
    {
        io_status status;
        
        char* word;

        while (*s)
        {
            while (*s && spaces[(unsigned char)*s] == 1) ++s; // пропускаем разделители
 
            const char* start = s;

            while (*s && spaces[(unsigned char)*s] != 1) ++s;

            word = new char[s - start + 1];
            strncpy(word, start, s - start);
            word[s - start] = '\0';

            Word *node = new Word;

            status = node->fun(word);

            if(status != io_status::success) 
            {
                delete node;
                delete[] word;
                return status; 
            }
            
            a[size] = std::move(*node);
            
            // a[size].print(); //
            size++;

            if(status != io_status::success) 
            {
                delete node;
                delete[] word;
                return status; 
            }
            delete node;
            delete[] word;
        }

        s--;
        if(*s == '\\') return io_status::format;
        return io_status::success;
    }

    friend class Word;

};

int prof_condition06(Word *a, const char *word)
{
    size_t len = strlen(word);
    for(int k=0; a[k].get_value() != 0; ++k) // по словам из s
    {  
        int res = 1; 
        size_t i=0;
        size_t j=0;

        while(i<len) 
        {
            if((a[k].get_value())[j] == '\\')  j++;

            if ((a[k].get_value())[j] == '\0') res = 0;

            if((a[k].get_value())[j] != word[i] && (a[k].get_value())[j] != '_' ) res = 0;

            i++; j++;
        }

        if((a[k].get_value())[j] != '\0') res = 0;

        if(res) return 1;
    }
    return 0;
}

int printfile06(Word *a, FILE *fin, FILE*fout, const char* t)
{
    int r=0;
    // for(int i=0; i<BUF; ++i) a[i].print();

    int spaces[BUF] = {0};
    size_t len_t = strlen(t);
    for(size_t i=0; i<len_t; ++i)
    {
        spaces[(unsigned char)t[i]] = 1;
    }

    char*word;

    int k=0;
    

    while (1)  // по строкам
    {
        char buffer[1024];
        if(!fgets(buffer, sizeof(buffer), fin)) break; // копируем строку в bufer
        
        const char*p = buffer;

        int flag=0;

        while (*p)
        {
            if(*p == '\n') break;

            while (*p && spaces[(unsigned char)*p] == 1) ++p;// пропускаем разделители

            const char* start = p;

            while (*p && spaces[(unsigned char)*p] != 1 && *p!='\n') ++p;

            word = new char[p - start + 1];
            strncpy(word, start, p - start);
            word[p - start] = '\0';

            if(prof_condition06(a, word) == 1)
            {
                flag=1;
                break;
            }
            delete[] word;
        }
        if(flag)
        {
            if(k)fprintf(fout, "\n");
            for(int i=0; buffer[i]!='\0' && buffer[i] != '\n'; i++)
            {
                fprintf(fout, "%c", buffer[i]);
            }
            r++;
            k=1;
        }
    }
    return r;

}

int prof_condition07(Word *a, const char *word)
{
    int len = strlen(word);
    for(int k=0; a[k].get_value() != 0; ++k) // по словам из s
    {
        const int len_a = strlen(a[k].get_value());
        if(len_a==1)
        {
            if(a[k].get_value()[0] == '%' || a[k].get_value()[0] == word[0]) return 1;
            else break;
        }

        int tmp=1;
        // tmp = 1 text
        // tmp = 2 %text
        // tmp = 3 text% 
        // tmp = 4 %text% 
        // tmp = 5 text1%text2

        if(a[k].get_value()[0] == '%')
        {
            if(a[k].get_value()[len_a-1] == '%' && a[k].get_value()[len_a-2] != '\\') tmp = 4;
            else tmp = 2;
        }
        else if(a[k].get_value()[len_a-1] == '%'&& a[k].get_value()[len_a-2] != '\\') tmp = 3;

        for(int i=1; i<len_a-1; ++i)
        {
            if(a[k].get_value()[i] == '%' && a[k].get_value()[i-1] != '\\') tmp = 5;
        }


        int res, i, j, size, size1, size2, flag;

        switch (tmp)
        {
        case 1: //text
            // printf("1\n");

            res = 1;
            i =0;
            j =0;
            while(i<len) 
            {
                if((a[k].get_value())[j] == '\\')  j++;

                if ((a[k].get_value())[j] == '\0' &&  word[i] != '\0') 
                {
                    res = 0;
                    break;
                }

                if((a[k].get_value())[j] != word[i])
                {
                    res = 0;
                    break;
                }

                i++; j++;
            }

            if(res) return 1;
            break;
            
        case 2: // %text
            // printf("2\n");

            size = 0;
            j=1;
            while((a[k].get_value())[j] != '\0')
            {
                if((a[k].get_value())[j] == '\\') j++;
                size++; j++;
            }

            res=1;
            i=len - size;
            if(i<0) break;

            j=1;

            while(i<len)
            {

                if((a[k].get_value())[j] == '\\')  j++;

                if((a[k].get_value())[j] != word[i])
                {
                    res = 0;
                    break;
                }
                i++; j++;
            }

            if(word[i] != '\0') break;

            if(res) return 1;
            break;


        case 3: // text%
            // printf("3\n");

            res=1;
            i=0;
            j=0;

            while(i<len)
            {
                if((a[k].get_value())[j] == '%' && (a[k].get_value())[j-1] != '\\') break;

                if((a[k].get_value())[j] == '\\')  j++;

                if((a[k].get_value())[j] != word[i])
                {
                    res = 0;
                    break;
                }
                i++; j++;
            }

            if(res) return 1;

            break;
        case 4: // %text%
            // printf("4\n");

            res = 0;

            size = 0;
            j=1;
            while((a[k].get_value())[j] != '%' && (a[k].get_value())[j-1] != '\\')
            {
                if((a[k].get_value())[j] == '\\') j++;
                size++; j++;
            }

            flag = 0;
            j=1;
            i=0;
            while(i<len)
            {
                if((a[k].get_value())[j] == '\\')  j++;

                if((a[k].get_value())[j] == word[i]) flag++;
                else
                {
                    j=0;
                    flag = 0;
                }
                if(flag == size)
                {
                    res = 1;
                    break;
                }
                i++; j++;

            }
            if(res) return 1;
            break;
        case 5: //text1%text2
            // printf("5\n");

            res = 0;

            size1 = 0;
            size2 = 0;
            j=0;
            while((a[k].get_value())[j] != '%' && (a[k].get_value())[j-1] != '\\')
            {
                if((a[k].get_value())[j] == '\\') j++;
                size1++; j++;
            }
            j++;
            while((a[k].get_value())[j] != '\0')
            {
                if((a[k].get_value())[j] == '\\') j++;
                size2++; j++;
            }

            i=0;
            j=0;

            while(i<len)
            {

                if((a[k].get_value())[j] == '%' && (a[k].get_value())[j-1] != '\\')
                {
                    res = 1;
                    break;
                }

                if((a[k].get_value())[j] == '\\')  j++;

                if((a[k].get_value())[j] != word[i]) break;

                i++; j++;

            }

            if(word[i] == '\0' || res == 0) break;

            j++;

            if(i > len - size2) break;
            i = len-size2;

            res = 1;
            
            while(i<len)
            {

                if ((a[k].get_value())[j] == '\0')
                {
                    res = 0;
                    break;
                }

                if((a[k].get_value())[j] == '\\')  j++;

                if((a[k].get_value())[j] != word[i])
                {
                    res = 0;
                    break;
                }

                i++; j++;

            }

            if(res) return 1;

            break;
        default:
            break;
        }
    }
    return 0;
}

int printfile07(Word *a, FILE *fin, FILE*fout, const char* t)
{
    int r=0;
    // for(int i=0; i<BUF; ++i) a[i].print();

    int spaces[BUF] = {0};
    size_t len_t = strlen(t);
    for(size_t i=0; i<len_t; ++i) spaces[(unsigned char)t[i]] = 1;

    char*word;

    int k=0;
    

    while (1)  // по строкам
    {
        char buffer[1024];
        if(!fgets(buffer, sizeof(buffer), fin)) break; // копируем строку в bufer
        
        const char*p = buffer;

        int flag=0;

        while (*p)
        {
            if(*p == '\n')
            {
                flag = 0;
                break;
            }

            while (*p && spaces[(unsigned char)*p] == 1) ++p;// пропускаем разделители

            const char* start = p;

            while (*p && spaces[(unsigned char)*p] != 1 && *p!='\n') ++p;

            word = new char[p - start + 1];
            strncpy(word, start, p - start);
            word[p - start] = '\0';

            if(prof_condition07(a, word) == 1)
            {
                delete[] word;
                flag=1;
                break;
            }
            delete[] word;
        }
        if(flag)
        {
            if(k)fprintf(fout, "\n");
            for(int i=0; buffer[i]!='\0' && buffer[i] != '\n'; i++) fprintf(fout, "%c", buffer[i]);
            r++;
            k=1;
        }
    }
    return r;

}


class Construction08
{
private:
    Word *a;
    char *s;
    char *t;
    int spaces[BUF] = {0};
    size_t size;
public:
    Construction08(char *n_s, char *n_t) : s(n_s), t(n_t)
    {
        a = new Word[BUF];
        size = 0;
        size_t len_t = strlen(t);
        for(size_t i=0; i<len_t; ++i)
        {
            spaces[(unsigned char)t[i]] = 1;
        }
    }
    ~Construction08()
    {
        delete[] a;
    }

    Construction08(const Construction08&) = delete;
    Construction08& operator=(const Construction08&) = delete;
    Construction08(Construction08&&) = delete;
    Construction08& operator=(Construction08&&) = delete;

    Word* get_tree() {return a;}

    io_status creation_tree()
    {
        io_status status;
        
        char* word;

        int len = strlen(s);
        if(s[len-1] == '\\') return io_status::format;

        for(int i=0; i<len; ++i)
        {
            if(i==0 && s[i]!= '\\')
            {
                if(s[i] == ']') return io_status::format;

                if(s[i] == '[')
                {
                    if(i+4>len) return io_status::format;
                    else
                    {
                        if(s[i+4] != ']' || s[i+2] != '-') return io_status::format;
                    }
                    i+=4;
                }
            }
            else if(s[i]!= '\\')
            {
                if(s[i] == ']' && s[i-1]!= '\\' ) return io_status::format;

                if(s[i] == '[' && s[i-1]!= '\\')
                {
                    if(i+4>len) return io_status::format;
                    else
                    {
                        if(s[i+4] != ']' || s[i+2] != '-') return io_status::format;
                    }
                    i+=4;
                }
            }

        }

        while (*s)
        {
            while (*s && spaces[(unsigned char)*s] == 1) ++s; // пропускаем разделители
 
            const char* start = s;

            while (*s && spaces[(unsigned char)*s] != 1) ++s;

            word = new char[s - start + 1];
            strncpy(word, start, s - start);
            word[s - start] = '\0';

            Word *node = new Word;

            status = node->fun(word);

            if(status != io_status::success) 
            {
                delete node;
                delete[] word;
                return status; 
            }
            
            a[size] = std::move(*node);
            
            // a[size].print(); //
            size++;

            if(status != io_status::success) 
            {
                delete node;
                delete[] word;
                return status; 
            }
            delete node;
            delete[] word;
        }

        return io_status::success;
    }

    friend class Word;

};

int prof_condition08(Word *a, const char *word)
{
    int len = strlen(word);
    int flag=0;

    for(int k=0; a[k].get_value() != 0; ++k) // по словам из s
    {
        int j=0;
        int size =0;
        flag=1;
        for(int i=0; i<(int)strlen(a[k].get_value()); ++i)
        {
            if(a[k].get_value()[i] == '\\') i++;

            if(i==0)
            {
                if(a[k].get_value()[i] == '[') i+=4;
            }
            else
            {
                if(a[k].get_value()[i] == '[' && a[k].get_value()[i-1] != '\\') i+=4;
            }
            
            size++;
        }

        if(size!=len) continue;

        for(int i=0; i<size; ++i)
        {
            if(a[k].get_value()[j] == '\\') ++j;

            if(j==0)
            {
                if(a[k].get_value()[j] == '[')
                {
                    if((unsigned char)word[i] < (unsigned char)a[k].get_value()[j+1] || (unsigned char)word[i] > (unsigned char)a[k].get_value()[j+3])
                    {
                        flag = 0;
                        break;
                    }
                    j+=4;
                }
                else
                {
                    if(word[i]!=a[k].get_value()[j])
                    {
                        flag = 0;
                        break;
                    }
                }
            }
            else
            {
                if(a[k].get_value()[j] == '[' && a[k].get_value()[j-1] != '\\')
                {
                    if((unsigned char)word[i] < (unsigned char)a[k].get_value()[j+1] || (unsigned char)word[i] > (unsigned char)a[k].get_value()[j+3])
                    {
                        flag = 0;
                        break;
                    }
                    j+=4;
                }
                else
                {
                    if(word[i]!=a[k].get_value()[j])
                    {
                        flag = 0;
                        break;
                    }
                } 
            }
             
            j++;
        }
        if(flag) return 1;
    }
    return 0;
}

int printfile08(Word *a, FILE *fin, FILE*fout, const char* t)
{
    int r=0;

    int spaces[BUF] = {0};
    size_t len_t = strlen(t);
    for(size_t i=0; i<len_t; ++i) spaces[(unsigned char)t[i]] = 1;

    char*word;

    int k=0;
    

    while (1)  // по строкам
    {
        
        char buffer[1024];
        if(!fgets(buffer, sizeof(buffer), fin)) break; // копируем строку в bufer
        
        const char*p = buffer;

        int flag=0;

        while (*p)
        {
            if(*p == '\n')
            {
                flag = 0;
                break;
            }

            while (*p && spaces[(unsigned char)*p] == 1) ++p;// пропускаем разделители

            const char* start = p;

            while (*p && spaces[(unsigned char)*p] != 1 && *p!='\n') ++p;

            word = new char[p - start + 1];
            strncpy(word, start, p - start);
            word[p - start] = '\0';

            if(prof_condition08(a, word) == 1)
            {
                delete[] word;
                flag=1;
                break;
            }
            delete[] word;
        }
        if(flag)
        {
            if(k)fprintf(fout, "\n");
            for(int i=0; buffer[i]!='\0' && buffer[i] != '\n'; i++)
            {
                fprintf(fout, "%c", buffer[i]);
            }
            r++;
            k=1;
        }
    }
    return r;

}

class Construction09
{
private:
    Word *a;
    char *s;
    char *t;
    int spaces[BUF] = {0};
    size_t size;
public:
    Construction09(char *n_s, char *n_t) : s(n_s), t(n_t)
    {
        a = new Word[BUF];
        size = 0;
        size_t len_t = strlen(t);
        for(size_t i=0; i<len_t; ++i) spaces[(unsigned char)t[i]] = 1;
    }
    ~Construction09()
    {
        delete[] a;
    }

    Construction09(const Construction09&) = delete;
    Construction09& operator=(const Construction09&) = delete;
    Construction09(Construction09&&) = delete;
    Construction09& operator=(Construction09&&) = delete;

    Word* get_tree() {return a;}

    io_status creation_tree()
    {
        io_status status;
        
        char* word;

        int len = strlen(s);
        if(s[len-1] == '\\') return io_status::format;

        for(int i=0; i<len; ++i)
        {
            if(i==0 && s[i]!= '\\')
            {
                if(s[i] == ']') return io_status::format;

                if(s[i] == '[')
                {
                    if(i+5>len) return io_status::format;
                    else
                    {
                        if(s[i+5] != ']' || s[i+3] != '-' || s[i+1] != '^') return io_status::format;
                    }
                    i+=5;
                }
            }
            else if(s[i]!= '\\')
            {
                if(s[i] == ']' && s[i-1]!= '\\' ) return io_status::format;

                if(s[i] == '[' && s[i-1]!= '\\')
                {
                    if(i+5>len) return io_status::format;
                    else
                    {
                        if(s[i+5] != ']' || s[i+3] != '-' || s[i+1] != '^') return io_status::format;
                    }
                    i+=5;
                }
            }

        }

        while (*s)
        {
            while (*s && spaces[(unsigned char)*s] == 1) ++s; // пропускаем разделители
 
            const char* start = s;

            while (*s && spaces[(unsigned char)*s] != 1) ++s;

            word = new char[s - start + 1];
            strncpy(word, start, s - start);
            word[s - start] = '\0';

            Word *node = new Word;

            status = node->fun(word);

            if(status != io_status::success) 
            {
                delete node;
                delete[] word;
                return status; 
            }
            
            a[size] = std::move(*node);
            
            // a[size].print(); //
            size++;

            if(status != io_status::success) 
            {
                delete node;
                delete[] word;
                return status; 
            }
            delete node;
            delete[] word;
        }

        return io_status::success;
    }

    friend class Word;

};

int prof_condition09(Word *a, const char *word)
{
    int len = strlen(word);
    int flag=0;

    for(int k=0; a[k].get_value() != 0; ++k) // по словам из s
    {
        int j=0;
        int size =0;
        flag=1;
        for(int i=0; i<(int)strlen(a[k].get_value()); ++i)
        {
            if(a[k].get_value()[i] == '\\') i++;

            if(i==0)
            {
                if(a[k].get_value()[i] == '[') i+=5;
            }
            else
            {
                if(a[k].get_value()[i] == '[' && a[k].get_value()[i-1] != '\\') i+=5;
            }
            
            size++;
        }

        if(size!=len) continue;


        for(int i=0; i<size; ++i)
        {
            if(a[k].get_value()[j] == '\\') ++j;

            if(j==0)
            {
                if(a[k].get_value()[j] == '[')
                {
                    if((unsigned char)word[i] >= (unsigned char)a[k].get_value()[j+2] && (unsigned char)word[i] <= (unsigned char)a[k].get_value()[j+4])
                    {
                        flag = 0;
                        break;
                    }
                    j+=5;
                }
                else
                {
                    if(word[i]!=a[k].get_value()[j])
                    {
                        flag = 0;
                        break;
                    }
                }
            }
            else
            {
                if(a[k].get_value()[j] == '[' && a[k].get_value()[j-1] != '\\')
                {
                    if((unsigned char)word[i] < (unsigned char)a[k].get_value()[j+2] || (unsigned char)word[i] > (unsigned char)a[k].get_value()[j+4])
                    {
                        flag = 0;
                        break;
                    }
                    j+=5;
                }
                else
                {
                    if(word[i]!=a[k].get_value()[j])
                    {
                        flag = 0;
                        break;
                    }
                } 
            }
             
            j++;
        }
        if(flag) return 1;
    }
    return 0;
}

int printfile09(Word *a, FILE *fin, FILE*fout, const char* t)
{
    int r=0;
    // for(int i=0; i<BUF; ++i) a[i].print();

    int spaces[BUF] = {0};
    size_t len_t = strlen(t);
    for(size_t i=0; i<len_t; ++i) spaces[(unsigned char)t[i]] = 1;

    char*word;

    int k=0;
    
    while (1)  // по строкам
    {
        
        char buffer[1024];
        if(!fgets(buffer, sizeof(buffer), fin)) break; // копируем строку в bufer
        
        const char*p = buffer;

        int flag=0;

        while (*p)
        {
            if(*p == '\n')
            {
                flag = 0;
                break;
            }

            while (*p && spaces[(unsigned char)*p] == 1) ++p;// пропускаем разделители

            const char* start = p;

            while (*p && spaces[(unsigned char)*p] != 1 && *p!='\n') ++p;

            word = new char[p - start + 1];
            strncpy(word, start, p - start);
            word[p - start] = '\0';

            if(prof_condition09(a, word) == 1)
            {
                delete[] word;
                flag=1;
                break;
            }
            delete[] word;
        }
        if(flag)
        {
            if(k)fprintf(fout, "\n");
            for(int i=0; buffer[i]!='\0' && buffer[i] != '\n'; i++)
            {
                fprintf(fout, "%c", buffer[i]);
            }
            r++;
            k=1;
        }
    }
    return r;
}

#endif
