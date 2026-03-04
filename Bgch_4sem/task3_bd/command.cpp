# include "command.h"

condition operator_ (const char * str, int len)
{
    switch (len)
    {
    case 1:
        if(strncmp(str, "<", 1)==0) return condition::lt;
        if(strncmp(str, ">", 1)==0) return condition::gt;
        if(strncmp(str, "=", 1)==0) return condition::eq;
        return condition::none;
    case 2:
        if(strncmp(str, "<=", 2)==0) return condition::le;
        if(strncmp(str, ">=", 2)==0) return condition::ge;
        if(strncmp(str, "<>", 2)==0) return condition::ne;
        return condition::none;
    case 4:
        if(strncmp(str, "like", 4) == 0) return condition::like;
        return condition::none;
    default:
        return condition::none;
    }
}

bool command::parse (const char * string)
{
    const char *space1;
    const char *space2;
    int cong=0;
    
    space1 = strchr(string, ' ');
    if(space1 == nullptr) return false;
    space1 += 1*sizeof(char);
    space2 = strchr(space1, ' ');
    if(space2 == nullptr) return false;

    cong = (int)(space2 - space1);

    space2 += 1*sizeof(char);


    if(strncmp(string, "name", 4) == 0)
    {
        c_name = operator_(space1, cong);
        if(c_name == condition::none) return false;

        if(!init_name(space2)) return false;

        if(c_name == condition::like)
        {
            curr = new operator_like(get_name());
            int w = curr->parse();
            if(w!=0)
            {
                // printf("Warning: %d\n", w);
                return false;
            }
        }
        return true;
    }
    if(strncmp(string, "phone", 5) == 0)
    {
        c_phone = operator_(space1, cong);
        
        int number;
        if(!sscanf(space2, "%d", &number)) return false;
        init(nullptr, number, 0);

        return true;
    }
    if(strncmp(string, "group", 5) == 0)
    {
        c_group = operator_(space1, cong);
        if(c_group == condition::none) return false;

        int number;
        if(!sscanf(space2, "%d", &number)) return false;
        init(nullptr, 0, number);
        
        return true;
    }
    return false;
}
// Print parsed structure
void command::print (FILE *fp) const
{
    if (c_name != condition::none) fprintf(fp, "%s ", get_name());
        
    if (c_phone != condition::none) fprintf(fp, "%d ", get_phone());
        
    if (c_group != condition::none) fprintf(fp, "%d ", get_group());
}
// Apply command, return comparision result for record ’x’
bool command::apply (const record& x) const 
{
    return (compare_name(c_name, x, curr) && compare_phone(c_phone, x) && compare_group(c_group, x));
}

int command::apply_list (const list2<record>& A) const
{
    int res=0;
    list2_node<record> *tmp = A.get_head();
    if(tmp == nullptr) return 0;

    while(tmp != nullptr)
    {
        // record tmp_record;
        // tmp_record.init(tmp->get_name(), tmp->get_phone(), tmp->get_group());
        if(apply(*tmp))
        {
            tmp->print();
            ++res;
        }
        tmp = tmp->get_next();
    }
    return res;
}