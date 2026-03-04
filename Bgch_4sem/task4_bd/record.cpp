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

int record::init_phone (int p)
{
    phone = p;
    return 0;
}
int record::init_group (int g)
{   
    group = g;
    return 0;
}

int record::init_name (const char *str, const char *str2)
{
    // printf("%s, %zu\n", str, strlen(str));
    if (str != nullptr)
    {
        size_t tmp_len = (int)(str2 - str)+1;
        // printf("tmp_len = %zu\n", tmp_len);
        // if(str[tmp_len-1] != '\n') ++tmp_len;
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

int record::compare_name (condition x, const record& y, const operator_like *z) const
{
    // printf("y.group = %s,  group = %s\n", y.name.get(), name.get());
    switch (x)
    {
    case condition::none: // not specified
        return 0; // unspecified opeation is true
    case condition::eq: // equal
        if(tmp(y.get_name(), get_name()) == 0) return 1;
        return -1;
    case condition::ne: // not equal
        if(tmp(y.get_name(), get_name()) != 0) return 1;
        return -1;
    case condition::lt: // less than
        if(tmp(y.get_name(), get_name()) < 0) return 1;
        return -1;
    case condition::gt: // less than
        if(tmp(y.get_name(), get_name()) > 0) return 1;
        return -1;
    case condition::le: // less equal
        if(tmp(y.get_name(), get_name()) <= 0) return 1;
        return -1;
    case condition::ge: // great equal
        if(tmp(y.get_name(), get_name()) >= 0) return 1;
        return -1;
    case condition::like: // strings only
        if(z->apply(y.get_name())) return 1;
        return -1;
    case condition::nlike: // strings only
        if(z->apply(y.get_name())) return -1;
        return 1;
    }
    return false;
}

int record::compare_phone (condition x, const record& y) const
{
    // printf("y.phone = %d,  phone = %d\n", y.phone, phone);
    switch (x)
    {
    case condition::none: // not specified
        return 0; // unspecified opeation is true
    case condition::eq: // equal
        if(y.phone == phone) return 1;
        return -1;
    case condition::ne: // not equal
        if(y.phone != phone) return 1;
        return -1;
    case condition::lt: // less than
        if(y.phone < phone) return 1;
        return -1;
    case condition::gt: // great than
        if(y.phone > phone) return 1;
        return -1;
    case condition::le: // less equal
        if(y.phone <= phone) return 1;
        return -1;
    case condition::ge: // great equal
        if(y.phone >= phone) return 1;
        return -1;
    case condition::like: // strings only: match pattern
        return -1; // cannot be used for phone
    case condition::nlike: // strings only: match pattern
        return -1; // cannot be used for phone
    }
    return false;
}

int record::compare_group (condition x, const record& y) const
{
    // printf("y.group = %d,  group = %d\n", y.group, group);
    switch (x)
    {
    case condition::none: // not specified
        return 0; // unspecified opeation is true
    case condition::eq: // equal
        if(y.group == group) return 1;
        return -1;
    case condition::ne: // not equal
        if(y.group != group) return 1;
        return -1;
    case condition::lt: // less than
        if(y.group < group) return 1;
        return -1;
    case condition::gt: // great than
        if(y.group > group) return 1;
        return -1;
    case condition::le: // less equal
        if(y.group <= group) return 1;
        return -1;
    case condition::ge: // great equal
        if(y.group >= group) return 1;
        return -1;
    case condition::like: // strings only: match pattern
        return -1; // cannot be used for phone
    case condition::nlike: // strings only: match pattern
        return -1; // cannot be used for phone
    }
    return false;
}

void record::print (const ordering order[], FILE *fp) const
{
    const int max_items = 3;
    const ordering default_ordering[max_items] = {ordering::name, ordering::phone, ordering::group};
    const ordering * p = (order ? order : default_ordering);
    for (int i = 0; i < max_items; i++)
    switch (p[i])
    {
        case ordering::name:
            printf ("%s ", name.get()); break;
        case ordering::phone:
            printf ("%d ", phone); break;
        case ordering::group:
            printf ("%d ", group); break;
        case ordering::none:
            continue;
    }
    fprintf (fp, "\n");
}
