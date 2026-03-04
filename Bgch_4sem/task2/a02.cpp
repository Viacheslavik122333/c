# include <stdio.h>
# include <time.h>
# include "io_status.h"
# include "rb_tree.h"
# include "class.h"

int main(int argc, char *argv[])
{
    // argv[0] - имя образа программы
    // argv[1] - a.txt
    // argv[2] - b.txt
    // argv[3] - s
    // argv[4] - t
    
    char *filename_in = nullptr, *filename_out = nullptr;
    char *s = nullptr, *t = nullptr;
    int r = -1;

    io_status ret;
    FILE *fin, *fout;

    if(argc != 5) 
    {
        printf("Incorrect data entry");
        return 1;
    }
    
    filename_in = argv[1]; filename_out = argv[2];
    s = argv[3]; t = argv[4];


    if (!(fin = fopen(filename_in, "r")))
    {
        printf("%s\n", get_error_message(io_status::open));
        return 2;
    }

    if (!(fout = fopen(filename_out, "w")))
    {
        printf("%s\n", get_error_message(io_status::open));
        fclose(fin);
        return 2;
    }


    Construction02 A(s, t);

    ret = A.creation_tree();
    if(ret != io_status::success)
    {
        printf("%s\n", get_error_message(ret));
        fclose(fin);
        fclose(fout);
        return 2;
    } 
    
    r = printfile02(A.get_tree(), fin, fout, t);

    fclose(fin);
    fclose(fout);

    if(r==-1) return -1;

    return 0;
}
