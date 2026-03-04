# include <stdio.h>
# include <time.h>

# include "io_status.h"
# include "doubly_linked_list.h"
# include "record.h"
# include "condition.h"
# include "command.h"

int main(int argc, char *argv[])
{
    // argv[0] - имя образа программы
    // argv[1] - a.txt
    char *filename_in = nullptr;
    io_status status;
    FILE *fin;
    double t;
    int res=0;
    char buffer[LEN];

    if(argc != 2) 
    {
        printf("Incorrect data entry");
        return 1;
    }
    filename_in = argv[1];
    if (!(fin = fopen(filename_in, "r")))
    {
        printf("%s\n", get_error_message(io_status::open));
        return 2;
    }
    
    list2<record> A;

    t = clock();

    status = A.read(fin);
    // A.print();

    if(status != io_status::success) return 0;

    while(fgets(buffer, LEN, stdin))
    {
        command a;
        if(a.parse(buffer) == false)
        {
            // printf("неправильно\n");
            continue;
        }
        res += a.apply_list(A);
        printf("\n");

    }
    t = (clock() - t) / CLOCKS_PER_SEC;

    printf("%s : Result = %d Elapsed = %.2f\n", argv[0], res, t);
    return 0;
}
