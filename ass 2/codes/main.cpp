#include<algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "BookItem.hpp"
#include "BookItem.cpp"

using namespace std;

/* DO NOT MODIFY THIS FUNCTION IF YOU ARE NOT FAMILIAR! */
ostream& operator<<(ostream& os, const BookItem& s)
{
    os << "<" << s.serialNum << "> " << s.title << " : "
       << s.author << " (" << s.yearPublished << ") - "
       << s.copiesSold << " copies sold";
    return os;
}
istream& operator>> (istream& is, BookItem &s)
{
    is >> s.serialNum >> s.title >> s.author >> s.yearPublished >> s.copiesSold;
    return is;
}
bool operator <(BookItem &b1, BookItem& b2)
{
    bool found = false;
    if (b1.serialNum < b2.serialNum)
    {
        found = true;
    }
    else if (b1.title < b2.title)
    {
        found = true;
    }


    else
    {
        found = false;
    }
    return found;
}
bool operator == (BookItem& b1, BookItem &b2)
{
    bool found = false;
    if (b1.serialNum == b2.serialNum)
    {
        found = true;
    }
    if (b1.title == b2.title)
    {
        found = true;
    }

    return found;
}

template <typename T>
struct Node
{
    T info;
    Node<T> *next;
};

template <typename T>
class LinkedList
{
    //Node<T> *start;
    bool once = false;

public:
    Node<T> *first;
    Node<T> *start;
    LinkedList()
    {
        start = NULL;
        //first = NULL;
    }
    void Insert(T & newElement)
    {
        Node<T> *newNode = new Node<T>;
        newNode->info = newElement;
        newNode->next = start;
        start = newNode;
        if (!once)
        {
            first = newNode;
            //once = true;
        }
    }
    void sortedinsert(T &element)
    {
        // bool found = false;
        Node <T> *newnode = new Node <T>;
        newnode->info = element;
        if (first == NULL) // 1st case: list is empty
        {
            cout << "list is empty\n";

            first = newnode;
            newnode->next = NULL;

            cout << "xxx";
            // found = true;
        }
        /* if (newnode->info < start->info)
        {
        newnode->next = start;
        start = newnode;
        found = true;


        */
        if (newnode->info < first->info) // 2nd case: new element < first element
        {
            newnode->next = start;
            first = newnode;
            //found = true;
        }
        Node <T> *ptr = start;










        while (ptr->next->info < newnode->info)
        {
            ptr = ptr->next;
        }
        newnode->next = ptr->next;
        ptr->next = newnode;
        cout << "z";





        //found = true;

        //return found;

    }
    bool retrieve(T& target)
    {
        bool found = false;
        Node<T>* ptr = start;

        while (ptr != NULL && !found)
        {
            ///cout << "ptr->info = " << ptr->info << endl;
            if (target.serialNum == ptr->info.serialNum)
            {
                cout << "FOUND! ---> " << ptr->info << endl;
                found = true;
                break;
            }
            if (!found)
                ptr = ptr->next;
        }
        return found;
    }

    bool Delete(T & target)
    {

       // cout << start->info;

        bool found = false;

        if (start == NULL)
        {
            found = false;

        }


        Node<T> *ptr = start;



        if (ptr->info == target) // case: found at first (node 0 or root node)
        {
            //cout << "ptr->info == target\n";
            start = start->next;

            delete ptr;
            found = true;
            return found;
        }
//

        cout << "del 4\n";
        // Node<T> *ptr = start;

        while (ptr->next != NULL)
        {
            //cout << "inside del while\n";
            if (ptr->next->info == target)
            {
                Node<T> *tempPtr = ptr->next;
                ptr->next = tempPtr->next;
                delete tempPtr;
                found = true;
                return found;
            }
            ptr = ptr->next;
        }

        return false;

    }
    bool Booksearch(T & target)
    {
        bool found = false;
        Node<T>* ptr = start;

        while (ptr != NULL && !found)
        {
            //cout << "ptr->info = " << ptr->info << endl;
            if (target.title == ptr->info.title)
            {
                cout << "FOUND! ---> " << ptr->info << endl;
                found = true;
                break;
            }
            if (!found)
                ptr = ptr->next;

        }
        if (ptr == NULL)
        {
            cout << " no matches found";
            found =  false;

        }
        return found;
    }
    class sortTop_Seller
    {
    public:
        bool operator()( BookItem b1 , BookItem b2)
        {
            return b1.getcopiessold() > b2.getcopiessold();
        }
    };

    bool toptenSeller()
    {
        Node<T> *ptr2 = start ;

        LinkedList<T> a;
        vector<T> b;
        T c;
        T g;


        while (ptr2 != NULL)
        {



            b.push_back(ptr2->info);
            ptr2 = ptr2->next;
        }

        sort(b.begin() , b.end() , sortTop_Seller());





        cout << endl;
        cout << endl;
        cout << endl;

        int count=0;
        for (typename vector<T>::iterator it = b.begin(); it != b.end(); ++it)
        {
            count++;
            cout << *it << endl;
            if(count == 10)
                break;

        }


    }
    class sortbook
    {
    public:
        bool operator()( BookItem b1 , BookItem b2)
        {
            return b1.gettitle() <
         b2.gettitle();
        }
    };
    bool sorttitle()
    {
        Node<T> *ptr2 = start ;

        LinkedList<T> a;
        vector<T> b;
        T c;
        T g;


        while (ptr2 != NULL)
        {



            b.push_back(ptr2->info);
            ptr2 = ptr2->next;
        }

        sort(b.begin() , b.end() , sortbook());





        cout << endl;
        cout << endl;
        cout << endl;

        int count=0;
        for (typename vector<T>::iterator it = b.begin(); it != b.end(); ++it)
        {

            cout << *it << endl;



        }
        return true;

    }

    friend ostream& operator<< (ostream& os, LinkedList<T>& List)
    {
        os << "start -> ";
        Node<T> *ptr = List.start;
        while (ptr != NULL)
        {
            os << ptr->info << " -> ";
            ptr = ptr->next;
        }
        os << "NULL\n";
        return os;
    }


};
void readData(const char* filename, LinkedList<BookItem>*&stBooks)
{
    string line;
    ifstream ifs(filename);
    if (ifs.is_open())
    {
        cout << "Reading data...\n";
        int c = 0;
        while (getline(ifs, line) && (*line.c_str() != '\0'))
        {
            string delimiter = ",";
            size_t pos = 0;
            string* token = new string[5];
            int f = -1;
            while ((pos = line.find(delimiter)) != string::npos)
            {
                token[++f] = line.substr(0, pos);
                cout << " " << token[f] << " | ";
                line.erase(0, pos + delimiter.length());
            }
            token[++f] = line;
            cout << token[f] << endl;       // last item in string
            c++;

            // push to vector (numerical data converted to int)
            BookItem b(atoi(token[0].c_str()), token[1], token[2], atoi(token[3].c_str()), atoi(token[4].c_str()));
            stBooks->Insert(b);
            //cout << "inserting a book...\n";
        }
        cout << c << " row(s) read." << endl;
        ifs.close();
    }
    else
        cout << "Unable to open file";
}
/* ************************************************ */



int main()
{
    LinkedList<BookItem>* List = new LinkedList<BookItem>;

    readData("db_small.txt", List);


    //LinkedList<BookItem> List;


    BookItem newItem, target;
    bool found;
    int choice;
    do
    {
        string str;
        cout << " list " << endl;
        cout << "choise\n"
             << " 1 : top 10 sellers\n"
             << "2: retrive information\n"
             << "3: delete book \n"
             << "4: Book search\n"
             << " 5: book sort title\n"
             << "others exit" << endl;
        //cin >> choice;
        getline(cin, str);
        choice = atoi(str.c_str());
        switch (choice)
        {
                    case 5:
            cout << " book sort by title";
            List->sorttitle();
            break;
        case 1:
            cout <<" top 10 sillers ";
            List->toptenSeller();
            break;
        case 2:
            cout << "write a target\n";
            getline(cin, str);
            //cin >> target.serialNum;
            target.serialNum = atoi(str.c_str());
            cout << "target.serialNum = " << target.serialNum << endl;

            //found=stBooks->retrieveTest(target);
            //found = List.retrieve(target);
            found = List->retrieve(target);
            if (!found)
                cout << "target not found" << endl;
            else
                cout << "target found";
            break;

        case 3:
            cout << "write a target\n";
            getline(cin, str);
            //cin >> target.serialNum;
            target.serialNum = atoi(str.c_str());
            found = List->Delete(target);
            if (!found) cout << "target not found" << endl;
            else  cout << "target found\n";
            break;
        case 4:
            string g;
            cout << "write a target\n";
            //getline(cin, str);
            getline(cin, g); //cin >>target.title;
            target.title = g;


            //target.title = atoi(str.c_str());
            cout << "target.title = " << target.title << endl;
            found = List->Booksearch(target);
            if (!found)
            {
                cout << "not found"<<endl;
            }
            break;

        }
    }
    while (choice >= 1 && choice <= 4);





    return 0;
}

