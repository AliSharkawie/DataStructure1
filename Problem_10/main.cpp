#include <iostream>

using namespace std;

template<class type>
struct node
{
    type data;
    node<type> *next;
};

template<class type>
class myList
{
private:
    int start_size;
    node<type> *head, *tail;

public:
    myList() {}
    myList(type value, int initial_size)
    {
        start_size = initial_size;
        node<type> *tmp=new node<type>;
        tmp->data=value;
        tmp->next=NULL;
        head=tmp;
        tail=tmp;
        tmp=NULL;
        for(int i=0; i<start_size-1; ++i)
        {
            node<type> *tmp=new node<type>;
            tmp->data=value;
            tmp->next=NULL;
            tail->next=tmp;
            tail=tmp;
        }
    }

    int size()
    {
        int count = 0;
        node<type> *t = new node<type>;
        t = head;
        while(t != NULL)
        {
            ++count;
            t = t->next;
        }
        return count;
    }

    myList<type>& operator = (myList<type> another_list)
    {

    }

    class iterator
    {
    public:
        node<type> *node2, *head2;

        iterator()
        {

            node2 = NULL;
            head2 = NULL;
        }
        iterator(node<type> *temp1,node<type> *temp2)
        {

            node2=temp1;
            head2=temp2;
        }


        myList<type>& operator = (myList<type> another_list)
        {
            if( this == &another_list )
                return *this;
            iterator temp =another_list.begin( );
            this->push_back(*temp);
            do
            {
                ++temp;
                this->push_back(*temp);
            }
            while(temp != another_list.end());
            return *this;
        }

        iterator begin()
        {
            return iterator(head,head);
        }

        iterator end()
        {
            return iterator(tail,head);

        }

        void operator ++ ()
        {
            if (node2->next == NULL )
            {
                cout << "\nOut of Range\n";
                return;
            }
            node2 = node2->next;

        }

        void operator -- ()
        {
            iterator temp;
            temp.node2=this->head2;
            temp.head2=this->head2;
            if (this->head2 == this->node2 )
            {
                cout<<"Out of Range";
            }
            else
            {
                while (temp.node2->next != NULL )
                {
                    if(temp.node2->next == this->node2)
                    {
                        this->node2 = temp.node2;
                        return;
                    }
                    ++temp;
                }
            }

        }

        type& operator * ()
        {
            return node2->data;

        }

        bool operator == (const iterator &temp)
        {
            return node2== temp.node2;

        }
        bool operator!=(const iterator& temp) const {
            return node2 != temp.node2;}

    };

    void push_back(type value)
    {
        node<type> *temp=new node<type>;
        temp->data=value;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            tail=temp;
            temp=NULL;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
    }

    iterator erase(iterator p)
        {
            node<type> *Delete = p.node2->next;
            p.node2->next = p.node2->next->next;
            if (Delete == tail) tail = p.node2;
            delete Delete;
            return p;
        }

    void display()
    {

        node<type> *temp=new node<type>;
        temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

     void insert_first(type value)
    {
        node<type> *temp=new node<type>;
        temp->data=value;
        temp->next=head;
        head=temp;
    }

    void delete_first()
    {
        node<type> *temp=new node<type>;
        temp=head;
        head=head->next;
        delete temp;
    }

    void delete_last()
    {
        node<type> *current=new node<type>;
        node<type> *previous=new node<type>;
        current=head;
        while(current->next!=NULL)
        {
          previous=current;
          current=current->next;
        }
        tail=previous;
        previous->next=NULL;
        delete current;
    }

    void delete_position(int p)
    {
        node<type> *current=new node<type>;
        node<type> *previous=new node<type>;
        current=head;
        for(int i=1;i<p;i++)
        {
          previous=current;
          current=current->next;
        }
        previous->next=current->next;
    }


    void insert(int p, type value)
    {
        node<type> *pre=new node<type>;
        node<type> *cur=new node<type>;
        node<type> *temp=new node<type>;
        cur=head;
        for(int i=1; i<p; i++)
        {
            pre=cur;
            cur=cur->next;
        }
        temp->data=value;
        pre->next=temp;
        temp->next=cur;
    }


    iterator begin() {
      return iterator(head,head);
    }

    iterator end() {
      return iterator(tail,head);
    }

    ~myList()
    {

        delete head;
        delete tail;

    }


};

int main()
{

    myList<int> l(6,3);
    l.push_back(2);
    l.push_back(8);
    l.push_back(3);
    cout<< l.size()<<endl;
    l.display();
    l.insert(3,6);
    l.display();
    myList<int>:: iterator i1 = l.begin();
    myList<int>:: iterator i2 = l.begin();
    cout<<*i1;
    ++i1;
    cout<<*i1;
    ++i1;
    cout<<*i1;
    ++i1;
    cout<<*i1;

    ++i1;

    --i1;
    cout<<*i1;
    ++i1;
    cout<<*i1;

    l.erase(i2);

    cout<<endl;

    myList<int> li;
    li = l;
    li.display();

    return 0;
}
