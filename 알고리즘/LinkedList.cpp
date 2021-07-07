template <typename T>
struct Node
{
    T data;
    Node<T>* next = nullptr;
};

template <typename T>
class LinkedList
{
private:
    Node<T>* head;
    Node<T>* tail;
    int size = 0;
public:
    LinkedList() : head(nullptr), tail(nullptr)
    {}
    ~LinkedList() {}

    void add(T data)
    {
        Node<T>* new_node = new Node<T>();
        size++;
        new_node->data = data;
        new_node->next = nullptr;

        if (head == nullptr)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = tail->next;

        }
    }


    void show()
    {
        Node<T>* node = head;
        while (node != nullptr)
        {
            cout << node->data << " ";
            node = node->next;
        }
        cout << endl;
    }

    void addPosition(int idx, T data)
    {
        if (size < idx || idx < 0)
            return;

        Node<T>* node = head;
        Node<T>* temp = node;
        Node<T>* temp_node = new Node<T>();

        temp_node->data = data;
        temp_node->next = nullptr;
        for (int i = 0; i < idx ; i++)
        {
            temp = node;
            node = node->next;
        }
        temp->next = temp_node;
        temp_node->next = node;
        size++;


    }
};







int main()
{
    


    
    vector<int> arr{ 5,10,17,9,13,7,19 };
    LinkedList<int> list;
    for (auto i : arr)
        list.add(i);

    list.show();

    list.addPosition(4, 33);
    list.show();

}
