# ifndef command_H
# define command_H
# include <stdio.h>
# include "record.h"
# include "doubly_linked_list.h"
# include "like.h"

// Класс, задающий условие для проверки
class command : public record
{
private:
    condition c_name = condition::none;
    condition c_phone = condition::none;
    condition c_group = condition::none;
    operator_like *curr = nullptr;
public:
    command () = default;
    ~command ()
    {
        if(curr != nullptr) delete curr;
    }
    command (command&& x) = delete;
    command& operator= (command&& x) = delete;
    command (const command&) = delete;
    command& operator= (const command&) = delete;
    // Convert string command to data structure
    // Example 1: "phone = 1234567" parsed to
    // (command::phone = 1234567, command::c_phone = condition::eq)
    // other fields are unspecified
    // Example 2: "name like St%" parsed to
    // (command::name = "St%", command::c_name = condition::like)
    // other fields are unspecified
    bool parse (const char * string);
    void print (FILE *fp = stdout) const;
    bool apply (const record& x) const;
    int apply_list (const list2<record>& A) const;
};
# endif