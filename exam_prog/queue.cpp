struct Node
{
    int data;
    int max;
    Node* next;
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
    ~Node()
    {
        delete next;
    }
};


struct queue
{
    Node* front; // начало очереди
    Node* rear;  // конец очереди

    queue()
    {
        front = nullptr;
        rear = nullptr;
    }
    ~queue()
    {
        while (front != nullptr)
        pop_front();
    }


    void push_back(int x)
    {
        Node* tmp = new Node(x);
        
        if (rear == nullptr) 
        {
            front = tmp;
            rear = tmp;
        } 
        else 
        {
            rear->next = tmp;
            rear = tmp;
        }
        return;
    }

    void pop_front()
    {
        if (rear == nullptr) return;
        Node* tmp = front;
        front = front -> next;
        if (front == nullptr) 
        {
            rear = nullptr;
        }
        tmp->next = nullptr;
        delete tmp;
        return;
    }

    int get_front()
    {
        if (front == nullptr) return 0;
        return front->data;
    }

};