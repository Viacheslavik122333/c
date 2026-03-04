# ifndef record_H
# define record_H
# include <memory>
# include <stdio.h>
# include "condition.h"
#include "ordering.h"
# include "io_status.h"
# include "like.h"

# define LEN 1234

class record
{
private:
    std::unique_ptr<char []> name = nullptr;
    int phone = 0;
    int group = 0;
public:
    record () = default;
    ~record () = default;
    record (record&& x) = default;
    record& operator= (record&& x) = default;
    record (const record&) = delete;
    record& operator= (const record&) = delete;

    const char * get_name () const { return name.get (); }
    int get_phone () const { return phone; }
    int get_group () const { return group; }

    int init (const char *n, int p, int g);
    int init_name (const char *str, const char *str2);
    int init_phone (int p);
    int init_group (int g);

    int compare_name (condition x, const record& y, const operator_like *z) const;
    int compare_phone (condition x, const record& y) const;
    int compare_group (condition x, const record& y) const;
    void print (const ordering order[] = nullptr, FILE * fp = stdout) const;
    io_status read (FILE *fp = stdin);
};

# endif

