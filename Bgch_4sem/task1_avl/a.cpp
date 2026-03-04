# include <stdio.h>
# include <time.h>
# include "io_status.h"
# include "student.h"
# include "tree_avl.h"


int main(int argc, char *argv[])
{
    // argv[0] - имя образа программы
    // argv[1] - r
    // argv[2] - s
    // argv[3] - filename

	const char* s_all = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int r;
    char* filename = nullptr, *s = nullptr;

    io_status ret;
	int res_all, res;
    double t_all, t;
    FILE *fp;

    if( !( argc == 4 && sscanf(argv[1], "%d", &r) == 1 )) 
    {
        printf("Usage: %s r s filename\n", argv[0]);
        return 1;
    }
	s = argv[2];
    filename = argv[3];

    if(!(fp = fopen(filename, "r")))
    {
        printf("%s\n", get_error_message(io_status::open));
        return 2;
    }

    avl_tree<student> *a = new avl_tree<student>;

    ret = a->read(fp); // читаем дерево

    if(ret != io_status::success)
    {
        printf("%s\n", get_error_message(ret));
        fclose(fp);
		delete a;
        return 2;
    }
    fclose(fp);

    a->print(r); // исходное дерево

    int table_all[256] = {1};
    for(int i=0; i<256; ++i) table_all[i] = 1;

    int table[256] = {0};
    for(int i=0; s[i]; ++i) table[(unsigned char)s[i]] = 1;

    for(int task=1; task<=5; task++)
    {
        t_all = clock();
        res_all = a->tasks(task, table_all);
        t_all = (clock()-t_all) / CLOCKS_PER_SEC;

        printf ("%s : Task = %d S = %s Result = %d Elapsed = %.2f\n", argv[0], task, s_all, res_all, t_all);

        t = clock();
        res = a->tasks(task, table);
        t = (clock()-t) / CLOCKS_PER_SEC;

        printf ("%s : Task = %d S = %s Result = %d Elapsed = %.2f\n", argv[0], task, s, res, t);
    }
    delete a;
    return 0;
}