#include<iostream>
using namespace std;
struct node
{
    int info;
    node *next,*prev;
}*start,*newptr,*temp,*loc;
node *create_new_node(int n)
{
    node *ptr;
    ptr = new node;
    ptr->info = n;
    ptr->next = NULL;
    ptr->prev = NULL;
    return(ptr);
}
void Traversing()
{
    if(start==NULL)
    {
        cout<<"Linked List is Empty!..."<<endl;
    }
    else
    {
        temp = start;
        while(temp!=NULL)
        {
            cout<<temp->info<<" <- ";
            temp = temp->next;
        }
        cout<<"!!!"<<endl;
    }
}
void Reverse_Traversing()
{
    if(start==NULL)
    {
        cout<<"Linked List is Empty!..."<<endl;
    }
    else
    {
        temp = start;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        cout<<"!!!";
        while(temp!=NULL)
        {
            cout<<" -> "<<temp->info;
            temp = temp->prev;
        }
        cout<<endl;
    }
}
node *Searching(int n)
{
    if(start == NULL)
    {
        cout<<"Linked List is Empty!..."<<endl;
    }
    else
    {
        temp = start;
        while(temp!=NULL)
        {
            if(temp->info == n)
            {
                return (temp);
            }
            else
            {
                temp = temp->next;
            }
        }
    }
    return(NULL);
}
void Insert_beg(node *p)
{
    if(start == NULL)
    {
        start = p;
    }
    else
    {
        p->next = start;
        start->prev = p;
        start = p;
    }
}
void Insert_end(node *p)
{
    if(start == NULL)
    {
        start = p;
    }
    else
    {
        temp = start;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
        p->prev = temp;
    }
}
void Insert_after(node *p,node *l)
{
    if(start == NULL)
    {
        start = p;
    }
    else
    {
       p->next = l->next;
       l->next->prev = p;
       p->prev = l;
       l->next = p;
    }
}

void Insert_before(node *p,node *l)
{
    if(start == NULL)
    {
        start = p;
    }
    else
    {
        p->prev = l->prev;
        p->next = l;
        l->prev->next = p;
        l->prev = p;
    }
}
void Delete_beg()
{
    if(start == NULL)
    {
        cout<<"Linked List is Empty!..."<<endl;
    }
    else
    {
        temp = start;
        start = start->next;
        start->prev = NULL;
        cout<<temp->info<<" Deleted from Linked List!..."<<endl;
        delete(temp);
    }
}
void Delete_end()
{
    if(start == NULL)
    {
        cout<<"Linked List is Empty!..."<<endl;
    }
    else
    {
        temp = start;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        cout<<temp->info<<" Deleted from Linked List!..."<<endl;
        delete(temp);
    }
}
void Delete_after(int n)
{
    if(start == NULL)
    {
        cout<<"Linked List is Empty!..."<<endl;
    }
    else
    {
        node *temp2;
        temp = Searching(n);
        temp2 = temp->next;
        temp->next = temp2->next;
        temp2->next->prev = temp;
        cout<<temp2->info<<" Deleted from the Linked List"<<endl;
        delete(temp2);
    }
}
void Delete_before(int n)
{
    if(start == NULL)
    {
        cout<<"Linked List is Empty!..."<<endl;
    }
    else
    {
        node *temp2;
        temp = Searching(n);
        temp2 = temp->prev;
        temp->prev = temp2->prev;
        temp2->prev->next = temp;
        cout<<temp2->info<<" Deleted from the Linked List"<<endl;
        delete(temp2);
    }
}
void Delete_ll()
{
    if(start == NULL)
    {
        cout<<"Linked List is Already Empty!..."<<endl;
    }
    else
    {
        while(start!=NULL)
        {
            temp = start;
            start = start->next;
            cout<<temp->info<<" Deleted from LL..."<<endl;
            delete(temp);
        }
        cout<<"Entire LL Deleted!..."<<endl;
    }
}
int main()
{
    start = NULL;
    cout<<"Ordered Linked List and its Various Operations!..."<<endl;
    int choice,item,flag;
    char ch = 'y';
    x:
    while (ch=='y'||ch=='Y')
    {
        cout<<endl;
        cout<<"Enter your Choice : "<<endl;
        cout<<" 1. Traversing "<<endl;
        cout<<" 2. Searching "<<endl;
        cout<<"Insertion : "<<endl;
        cout<<" 3. Insertion in the Beginning "<<endl;
        cout<<" 4. Insertion in the End "<<endl;
        cout<<" 5. Insertion after a Given Node "<<endl;
        cout<<" 6. Insertion before a Given Node "<<endl;
        cout<<"Deletion : "<<endl;
        cout<<" 7. Deletion in the Beginning "<<endl;
        cout<<" 8. Deletion in the End "<<endl;
        cout<<" 9. Deletion after a Given Node "<<endl;
        cout<<" 10. Deletion before a Given Node "<<endl;
        cout<<" 11. Deletion of a Particular Node "<<endl;
        cout<<" 12. Reverse Traversing "<<endl;
        cout<<" 13. Delete Entire Linked List "<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1 :
            cout<<"Traversing Operation "<<endl;
            cout<<"The Linked List is : "<<endl;
            Traversing();
            break;

        case 2 :
            cout<<"Searching Operation "<<endl;
            cout<<"Enter the Item to be Searched : ";
            cin>>item;
            loc = Searching(item);
            if(loc==NULL)
            {
                cout<<item<<" not Found in the Linked List "<<endl;
            }
            else
            {
                cout<<loc->info<<" Found in the Linked List "<<endl;
            }
            break;

        case 3 :
            cout<<"Insertion in the Beginning "<<endl;
            cout<<"Enter the Item to be Inserted : ";
            cin>>item;
            newptr = create_new_node(item);
            Insert_beg(newptr);
            //cout<<"The Linked List is : "<<endl;
            //Traversing();
            break;

        case 4 :
            cout<<"Insertion in the End "<<endl;
            cout<<"Enter the Item to be Inserted : ";
            cin>>item;
            newptr = create_new_node(item);
            Insert_end(newptr);
            //cout<<"The Linked List is : "<<endl;
            //Traversing();
            break;

        case 5 :
            cout<<"Insertion after a Given Node "<<endl;
            cout<<"Enter the Item to be Inserted : ";
            cin>>item;
            cout<<"Enter the Info part of the Node after which you want to Insert the Item : ";
            cin>>flag;
            loc = Searching(flag);
            if(loc == NULL)
            {
                cout<<flag<<" not Found in the Linked List "<<endl;
            }
            else
            {
                newptr = create_new_node(item);
                temp = start;
                while(temp->next!=NULL)
                {
                    temp = temp->next;
                }
                if(loc->info == temp->info)
                {
                    Insert_end(newptr);
                }
                else
                {
                    Insert_after(newptr,loc);
                }
                //cout<<"The Linked List is : "<<endl;
                //Traversing();
            }
            break;

        case 6 :
            cout<<"Insertion before a Given Node "<<endl;
            cout<<"Enter the Item to be Inserted : ";
            cin>>item;
            cout<<"Enter the Info part of the Node before which you want to Insert the Item : ";
            cin>>flag;
            loc = Searching(flag);
            if(loc == NULL)
            {
                cout<<flag<<" not Found in the Linked List "<<endl;
            }
            else
            {
                newptr = create_new_node(item);
                if(loc->info == start->info)
                {
                    Insert_beg(newptr);
                }
                else
                {
                    Insert_before(newptr,loc);
                }
                //cout<<"The Linked List is : "<<endl;
                //Traversing();
            }
            break;

        case 7 :
            cout<<"Deletion in the Beginning "<<endl;
            Delete_beg();
            break;

        case 8 :
            cout<<"Deletion in the End "<<endl;
            Delete_end();
            break;

        case 9 :
            cout<<"Deletion after a Given Node "<<endl;
            cout<<"Enter the Item : ";
            cin>>item;
            loc = Searching(item);
            if(loc == NULL)
            {
                cout<<"Element Not Found in the Linked List"<<endl;
            }
            else
            {
                temp = start;
                while(temp->next!=NULL)
                {
                    temp = temp->next;
                }
                if(loc->info == temp->info)
                {
                    cout<<"You Entered the Last Node...Error...Try Again"<<endl;
                }
                else
                {
                    if(loc->info == temp->prev->info)
                    {
                        Delete_end();
                    }
                    else
                    {
                        Delete_after(item);
                    }
                }
            }
            break;


        case 10 :
            cout<<"Deletion before a Given Node "<<endl;
            cout<<"Enter the Item : ";
            cin>>item;
            loc = Searching(item);
            if(loc == NULL)
            {
                cout<<"Element Not Found in the Linked List"<<endl;
            }
            else
            {
                if(item == start->info)
                {
                    cout<<"You Entered the First Node...Error...Try Again"<<endl;
                }
                else
                {
                    if(loc->info == start->next->info)
                    {
                        Delete_beg();
                    }
                    else
                    {
                        Delete_before(item);
                    }
                }
            }
            break;

        case 11:
            cout<<"Deletion of a Particular Node "<<endl;
            cout<<"Enter the Item to be Deleted From the Linked List : ";
            cin>>item;
            loc = Searching(item);
            if(loc == NULL)
            {
                cout<<"Element Not Found in the Linked List"<<endl;
            }
            else
            {
                if(loc->info == start->info)
                {
                    Delete_beg();
                }
                else
                {
                    temp = start;
                    while(temp->next!=NULL)
                    {
                        temp = temp->next;
                    }
                    if(loc->info == temp->info)
                    {
                        Delete_end();
                    }
                    else
                    {
                        loc->prev->next = loc->next;
                        loc->next->prev = loc->prev;
                        cout<<loc->info<<" Deleted From the Linked List "<<endl;
                        delete(loc);
                    }
                }
            }
            break;

        case 12 :
            cout<<"Reverse Traversing Operation "<<endl;
            cout<<"The Linked List is : "<<endl;
            Reverse_Traversing();
            break;

        case 13 :
            cout<<"Deletion of the Entire Linked List "<<endl;
            Delete_ll();
            break;

        default :
            cout<<"Wrong Choice Entered!...Try Again"<<endl;
        }
        cout<<"Want to Try Another Operation...[Y/N] : ";
        cin>>ch;
    }
    cout<<"Want to Quit...[Y/N] : ";
    cin>>ch;
    if(ch=='n'||ch=='N')
    {
        ch = 'y';
        goto x;
    }
    Delete_ll();
    return 0;
}
