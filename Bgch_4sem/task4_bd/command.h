# ifndef command_H
# define command_H
# include <stdio.h>
# include "record.h"
# include "doubly_linked_list.h"
# include "like.h"
#include "operation.h"
#include "ordering.h"


// Класс, задающий условие для проверки
class command : public record
{
private:
    condition c_name = condition::none;
    condition c_phone = condition::none;
    condition c_group = condition::none;
    ordering output_fields[3] = {ordering::none, ordering::none, ordering::none};
    operation op = operation::none;
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

    bool parse (const char * string);
    void print (FILE *fp = stdout) const;
    bool apply (const record& x) const;
    int apply_list (const list2<record>& A) const;
};
# endif