#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <string.h>
#include <memory>
#include "io_status.h"
// #include "utility"
#include "queue"

class student {
    private:
        std::unique_ptr<char []> name;
        int value = 0;
    public:
        student () = default;
        student (const student& x) = delete;
        student (student&& x) = default;
        ~student () = default;
        student& operator= (const student& x) = delete;
        student& operator= (student&& x) = default;
        void print (const char *c = "", FILE *fp = stdout) const {
            fprintf (fp, "%s %d %c\n", name.get(), value, *c);
        }
        io_status read (FILE *fp = stdin) {
            const int LEN = 1234;
            char n[LEN];
            int v;
            if(fscanf(fp, "%s%d", n, &v) != 2)
            {  
                return io_status::format;
            }
            erase();
            return init(n, v);
        }
        int cmp (const student& x) const {
            if(name == nullptr){
                if(x.name != nullptr)
                    return -1;
                return value - x.value;
            }
            if(x.name.get () == nullptr)
                return 1;
            int res = strcmp(name.get(), x.name.get());
            if(res)
                return res;
            return value - x.value;
        }

        int examination(const int table[256]) const
        {
            for(int i=0; name[i]; ++i)
            {
                if(table[(unsigned char)name[i]] == 0) return 0;
            }
            return 1;
        }

        int operator< (const student& x) const { return cmp(x) < 0; }
        int operator<= (const student& x) const { return cmp(x) <= 0; }
        int operator> (const student& x) const { return cmp(x) > 0; }
        int operator>= (const student& x) const { return cmp(x) >= 0; }
        int operator== (const student& x) const { return cmp(x) == 0; }
        int operator!= (const student& x) const { return cmp(x) != 0; }
    private:
        io_status init (const char *n, int v) 
        {
            value = v;
            if(n != nullptr){
                size_t len = strlen(n);
                name = std::make_unique<char []> (len + 1);
                if(name != nullptr){
                    for(size_t i = 0; i <= len; i++)
                        name[i] = n[i];
                }
                else
                    return io_status::memory;
            }
            return io_status::success;
        }
        void erase () {
            value = 0;
            name.reset();
        }
};

#endif //STUDENT_H
