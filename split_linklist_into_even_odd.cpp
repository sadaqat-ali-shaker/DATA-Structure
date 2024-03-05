#include<iostream>
using namespace std;

class node{
public:
    int data;
    node *prev;
    node *next;

    node(){
        this->data = 0;
        prev = NULL;
        next = NULL;
    }
    
    node(int dta){
        this->data = dta;
        prev = NULL;
        next = NULL;
    }
};

int main(){
    int choice;
    node *head = NULL;
    node *temp = NULL;

    while(1){
        cout << "1 for insertion and 0 for stop" << endl;
        cin >> choice;
        
        if(choice == 0){
            cout << "No further insertions." << endl;
            break;
        }
        else{
            node *new_node = new node();
            cout << "Enter element for the linked list: ";
            cin >> new_node->data;

            if(head == NULL){
                head = new_node;
                temp = head;
            }
            else{
                temp->next = new_node;
                new_node->prev = temp;
                temp = new_node;
            }
        }
    }

    // Display the original linked list
    cout << "Original Linked List: ";
    temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Splitting the linked list into two based on even and odd data
    temp = head;
    node *h1 = NULL;
    node *h2 = NULL;
    node *t1 = NULL;
    node *t2 = NULL;

    while(temp != NULL){
        if(temp->data % 2 == 0){
            node *e = new node(temp->data);
            if(h1 == NULL){
                h1 = e;
                t1 = h1;
            }
            else{
                t1->next = e;
                e->prev = t1;
                t1 = e;
            }
        }
        else{
            node *o = new node(temp->data);
            if(h2 == NULL){
                h2 = o;
                t2 = h2;
            }
            else{
                t2->next = o;
                o->prev = t2;
                t2 = o;
            }
        }
        temp = temp->next;
    }

    // Display the even linked list
    cout << "Even Linked List: ";
    temp = h1;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Display the odd linked list
    cout << "Odd Linked List: ";
    temp = h2;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Freeing memory
    temp = head;
    while(temp != NULL){
        node *toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }

    return 0;
}

