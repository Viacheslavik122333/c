# ifndef list2_H
# define list2_H

# include "io_status.h"
# include <stdio.h>
#include <utility>

template <class T> class list2;
template<class T> class list2_node : public T
{
private:
    list2_node *prev = nullptr;
    list2_node *next = nullptr;
public:
    list2_node () = default;
    list2_node (const list2_node &x) = delete;
    list2_node (list2_node&& x) : T ((T&&)x)
    {
        next = x.next; x.next = nullptr;
        prev = x.prev; x.prev = nullptr;
    }
    ~list2_node () 
    {
        next = nullptr;
        prev = nullptr;
    }
    list2_node& operator= (const list2_node& x) = delete;
    list2_node& operator= (list2_node&& x) 
    {
        if(this == &x) return *this;
        *(T*)this = (T&&)x;
        next = x.next; x.next = nullptr;
        prev = x.prev; x.prev = nullptr;
        return *this;
    }

    list2_node *get_next () const 
    {
        return next;
    }
    list2_node *get_prev () const 
    {
        return prev;
    }
    void set_next (list2_node *x)
    {
        next = x;
    }
    void set_prev (list2_node *x)
    {
        prev = x;
    }
    friend class list2<T>;
};

template <class T> class list2 
{
private:
    list2_node<T> *head = nullptr; // начало списка
    list2_node<T> *tail = nullptr; // конец списка
    size_t size; // кол-во элементов
public:
    list2 () = default;
    list2 (const list2& x) = delete;
    list2 (list2&& x) 
    {
        head = x.head; x.head = nullptr;
    }
    ~list2 () 
    {
        while (head) 
        {
            list2_node<T> *tmp = head;
            head = head->next;
            delete tmp;
        }
    }
    list2& operator= (const list2& x) = delete;

    io_status read(FILE *fp = stdin) 
    {
        return _read(fp);
    }

    list2_node<T>* get_head () const 
    {
        return head;
    }

    size_t get_len () const
    {
        return size;
    }

    void print (FILE *fp = stdout, int spaces = 0) const 
    {
        list2_node<T> *curr = head;
        size_t i=0;
        while(curr && i < size)
        {
            for(int j = 0; j < spaces; j++) fprintf(fp, " ");
            curr->print(fp);
            curr = curr->next;
            ++i;
        }
    }

private:
    io_status _read(FILE *fp)
    {
        list2_node<T> *first_n = nullptr;
        list2_node<T> *last_n = nullptr;
        int count = 0;
        io_status status;

        list2_node<T> buffer;

        while ((status = buffer.read(fp)) == io_status::success) 
        {
            list2_node<T> *node = new list2_node<T>;
            if (!node) 
            {
                while (first_n)
                {
                    list2_node<T> *tmp = first_n;
                    first_n = first_n->next;
                    delete tmp;
                }
                return io_status::memory;
            }

            *node = std::move(buffer);
            node->next = nullptr;

            if (!last_n) 
            {
                first_n = node;
                node->prev = nullptr;
            } 
            else 
            {
                last_n->next = node;
                node->prev = last_n;
            }
            last_n = node;
            ++count;
        }

        if (status != io_status::eof) 
        {
            while (first_n) 
            {
                list2_node<T> *tmp = first_n;
                first_n = first_n->next;
                delete tmp;
            }
            return status;
        }

        if (first_n) 
        {
            if (!head)
            {
                head = first_n;
                tail = last_n;
            }
            else 
            {
                tail->next = first_n;
                first_n->prev = tail;
                tail = last_n;
            }
            size += count;
        }

        return io_status::success;
    }

};
#endif