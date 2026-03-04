# include "record.h"
# include "like.h"

int record::init (const char *str, int p, int g)
{
    phone = p; group = g;
    if (str != nullptr) 
    {
        name = std::make_unique<char[]> (strlen(str) + 1);
        if (!name) return -1;
        strcpy(name.get(), str);
    }
    else name = nullptr;
    return 0;
}

int record::init_name (const char *str)
{
    if (str != nullptr) 
    {
        size_t tmp_len = strlen(str);
        if(tmp_len > 0 && str[tmp_len-1] != '\n') ++tmp_len;
        name = std::make_unique<char[]> (tmp_len);
        if (!name) return 0;
        for(size_t i=0; i<tmp_len-1; ++i)
        {
            name[i] = str[i];
        }
        name[tmp_len-1] = 0;
        return 1;
    }
    else name = nullptr;
    return 1;
}

io_status record::read (FILE *fp)
{
    char buf[LEN];
    name = nullptr;
    if (fscanf(fp, "%s%d%d", buf, &phone, &group) != 3) 
    {
        if(feof(fp)) return io_status::eof;
        return io_status::format;
    }
    if (init(buf, phone, group)) return io_status::memory;
    return io_status::success;
}

int tmp (const char *x, const char *y)
{
    return strcmp(x, y);
}

bool record::compare_name (condition x, const record& y, const operator_like *z) const
{
    switch (x)
    {
    case condition::none: // not specified
        return true; // unspecified opeation is true
    case condition::eq: // equal
        return tmp(y.get_name(), get_name()) == 0;
    case condition::ne: // not equal
        return tmp(y.get_name(), get_name()) != 0;
    case condition::lt: // less than
        return tmp(y.get_name(), get_name()) < 0;
    case condition::gt: // less than
        return tmp(y.get_name(), get_name()) > 0;
    case condition::le: // less equal
        return tmp(y.get_name(), get_name()) <= 0;
    case condition::ge: // great equal
        return tmp(y.get_name(), get_name()) >= 0;
    case condition::like: // strings only
        return z->apply(y.get_name());
    }
    return false;
}
bool record::compare_phone (condition x, const record& y) const
{
    switch (x)
    {
    case condition::none: // not specified
        return true; // unspecified opeation is true
    case condition::eq: // equal
        return y.phone == phone;
    case condition::ne: // not equal
        return y.phone != phone;
    case condition::lt: // less than
        return y.phone < phone;
    case condition::gt: // less than
        return y.phone > phone;
    case condition::le: // less equal
        return y.phone <= phone;
    case condition::ge: // great equal
        return y.phone >= phone;
    case condition::like: // strings only: match pattern
        return false; // cannot be used for phone
    }
    return false;
}
bool record::compare_group (condition x, const record& y) const
{
    switch (x)
    {
    case condition::none: // not specified
        return true; // unspecified opeation is true
    case condition::eq: // equal
        return y.group == group;
    case condition::ne: // not equal
        return y.group != group;
    case condition::lt: // less than
        return y.group < group;
    case condition::gt: // less than
        return y.group > group;
    case condition::le: // less equal
        return y.group <= group;
    case condition::ge: // great equal
        return y.group >= group;
    case condition::like: // strings only: match pattern
        return false; // cannot be used for phone
    }
    return false;
}
void record::print (FILE * fp) const
{
    fprintf(fp, "%s %d %d\n", get_name(), phone, group);
}
