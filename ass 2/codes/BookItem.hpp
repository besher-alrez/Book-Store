#ifndef BOOKITEM_HPP
#define BOOKITEM_HPP
#include <iostream>
#include <string>
using namespace std;

class BookItem
{

public:
    int target;
    int serialNum;
    string title;
    string author;
    int yearPublished;
    int copiesSold;
    BookItem(int serialNum=0, string title="", string ath="", int year=0, int copiesSold=0)
    : serialNum(serialNum), title(title), author(ath), yearPublished(year), copiesSold(copiesSold) {}
    int getcopiessold (){return copiesSold;}
    string gettitle(){return title;}

    	friend std::ostream& operator<<(std::ostream& os, const BookItem& s);
    	friend std::istream & operator<<(std::istream& is,  BookItem& s);
    	friend bool operator==( BookItem&b1,  BookItem&b2);
    	//int gettarget(){return target;}

};

#endif // BOOKITEM_HPP
