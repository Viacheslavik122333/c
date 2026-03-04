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
    case 8:
        if(strncmp(str, "not like", 8) == 0) return condition::nlike;
        return condition::none;
    default:
        return condition::none;
    }
}

const char* skipping_whitespace_characters(const char *str)
{
    while(str)
    {
        if(*str == ' ' || *str == ',') str+=sizeof(char);
        else if(*str == '\n' || *str == '\0') return nullptr;
        else return str;
    }
    return nullptr;
}

bool command::parse (const char * string) // <условие поиска>
{
    if(*string == '*')
    {
        // printf("1\n");
        output_fields[0] = ordering::name;
        output_fields[1] = ordering::phone;
        output_fields[2] = ordering::group;
        string+=2*sizeof(char);
        string = skipping_whitespace_characters(string);
    }
    else
    {
        int i=0;
        while(strncmp(string, "where", 5) != 0 && i<3)
        {
            if(strncmp(string, "name", 4) == 0)
            {
                // printf("name\n");
                output_fields[i] = ordering::name;
                ++i;
                string+=4*sizeof(char);
                string = skipping_whitespace_characters(string);
            }
            else if(strncmp(string, "phone", 5) == 0)
            {
                // printf("phone\n");
                output_fields[i] = ordering::phone;
                ++i;
                string+=5*sizeof(char);
                string = skipping_whitespace_characters(string);
            }
            else if(strncmp(string, "group", 5) == 0)
            {
                // printf("group\n");
                output_fields[i] = ordering::group;
                ++i;
                string+=5*sizeof(char);
                string = skipping_whitespace_characters(string);
            }
            else return false;
        }
    }

    if(strncmp(string, "where", 5) != 0) return false;
    string+=5*sizeof(char);
    string = skipping_whitespace_characters(string);
    for(int k=0; k<3; ++k)
    {
        if(string == nullptr) break;

        const char *space1;
        const char *space2;
        const char *space3;
        int cong=0;

        
        space1 = strchr(string, ' ');
        if(space1 == nullptr) return false;

        space1 += 1*sizeof(char);

        if(strncmp(space1, "not", 3)==0)
        {
            space2 = strchr(space1, ' ');
            space2 += 1*sizeof(char);
            space2 = strchr(space2, ' ');
        }
        else
        {
            space2 = strchr(space1, ' ');
        }

        if(space2 == nullptr) return false;

        cong = (int)(space2 - space1);
        space2 += sizeof(char);

        space3 = space2;

        while(*space3 != ' ' && *space3 != '\0' && *space3 != '\n')
        {
            space3+=sizeof(char);
        }

        if(strncmp(string, "name", 4) == 0)
        {
            c_name = operator_(space1, cong);

            if(c_name == condition::none) return false;

            if(!init_name(space2, space3)) return false;

            if(c_name == condition::like || c_name == condition::nlike)
            {
                curr = new operator_like(get_name());
                int w = curr->parse();
                if(w!=0)
                {
                    // printf("Warning: %d\n", w);
                    return false;
                }
            }
            string = space3;
        }
        else if(strncmp(string, "phone", 5) == 0)
        {
            c_phone = operator_(space1, cong);
            
            int number;
            if(!sscanf(space2, "%d", &number)) return false;
            init_phone(number);
            
            string = space3;
        }
        else if(strncmp(string, "group", 5) == 0)
        {
            c_group = operator_(space1, cong);
            
            int number;
            if(!sscanf(space2, "%d", &number)) return false;
            init_group(number);
            string = space3;
        }
        else return false;

        string = skipping_whitespace_characters(string);

        if(string == nullptr)
        {
            return true;
        }

        
        
        if(strncmp(string, "or", 2) == 0)
        {
            op = operation::lor;
            string+=2*sizeof(char);
        }
        else if(strncmp(string, "and", 3) == 0)
        {
            op = operation::land;
            string+=3*sizeof(char);
        }
        else return false;

        string = skipping_whitespace_characters(string);
    }

    return true;
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
    int int_name = compare_name(c_name, x, curr);
    int int_phone = compare_phone(c_phone, x);
    int int_group = compare_group(c_group, x);

    // printf(" name = %d, phone = %d, group = %d\n", int_name, int_phone, int_group);

    switch (op)
    {
    case operation::none:
        return int_name >=0 && int_phone >= 0 && int_group >= 0;
    
    case operation::land:
        return int_name >=0 && int_phone >= 0 && int_group >= 0;

    case operation::lor:
        return int_name == 1 || int_phone == 1 || int_group == 1;

    default:
        return false;
    }
}

int command::apply_list (const list2<record>& A) const
{
    int res=0;
    list2_node<record> *tmp = A.get_head();
    if(tmp == nullptr) return 0;

    while(tmp != nullptr)
    {
        if(apply(*tmp))
        {
            tmp->print(output_fields);
            ++res;
        }
        tmp = tmp->get_next();
    }
    return res;
}