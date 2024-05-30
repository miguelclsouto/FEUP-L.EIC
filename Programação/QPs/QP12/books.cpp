#include "Page.h"
#include "Book.h"
#include <iostream>
#include <sstream>

using namespace std;

bool word_is_in_page(const string& word, const Page& p);
bool word_is_in_line(const string& word, const string& line);
bool word_is_a_key(const string& s, std::map<std::string, std::set<size_t>>& index);

void Book::build_index(const set<string>& words)
{
    // so we need to check / search for these words in the book
    // we will need to check each page to see if there are any occurences of the word
    // if there are, we will add a pair with the word and a vector with the number of the page to the map if it isnt there already any occurences of this word in the map
    // else (if it is already there), i just need to add the number of the page the word
    // occurs to the vector

    for(auto itr = words.begin(); itr != words.end(); itr++)
    {
        // for each page we need to check if it exists

        unsigned int page_num = 1; // this is to count the page number

        for(const Page& p : book_)
        {
            if (word_is_in_page(*itr , p))
            {   
                // agora tenho que verificar se a word esta no map
                if(word_is_a_key(*itr, index_))
                {

                    index_.at(*itr).insert(page_num); // set.insert() // index_.at(*itr) is a set
                    // or index_[*itr].insert(page_num);

                }
                else // it is not in the set and we need to add it
                {

                    index_.insert({*itr, {page_num}}); // set.insert() // (this) --> {*itr, {page_num}} is a pair
                    // or index_[*itr] = {page_num};

                }

            }

            page_num++;
        }
    }
}

bool word_is_a_key(const string& s, std::map<std::string, std::set<size_t>>& index)
{
    return index.find(s) != index.end();
}

bool word_is_in_page(const string& word, const Page& p)
{

    bool flag = false;

    for(unsigned int x = 0; x < p.get_num_lines(); x++)
    {
       string s = p.get_line(x);

       if(word_is_in_line(word, s))
       {
            flag = true;
            break;
       }

    }

    return flag;

}

bool word_is_in_line(const string& word, const string& line)
{
    istringstream iss(line);

    string s;

    bool flag = false;

    while(iss >> s)
    {
        // here i wont count words like c == C --> these are different (!=)
        if (s == word)
        {
            flag = true;
            break;
        }

        // sera que nao devo usar o ignore()
        // isto pode dar erro talvez caso a linha acabe
        // n sei se este iss.ignore daria erro

        // iss.ignore();
    }

    return flag;

}

int main()
{
    { Book b;
  if (!(b.import("book_01.txt"))) cout << "book not found! \n";
  set<string> words = { "C++", "linux", "computer" };
  b.build_index(words);
  b.show_index(); }
  { Book b;
  if (!(b.import("book_02.txt"))) cout << "book not found! \n";
  set<string> words = { "C++", "program", "computer", "windows" };
  b.build_index(words);
  b.show_index(); }
  { Book b;
  if (!(b.import("book_03.txt"))) cout << "book not found! \n";
  set<string> words = { "linux", "program", "cpu" };
  b.build_index(words);
  b.show_index(); }
  { Book b;
  if (!(b.import("book_04.txt"))) cout << "book not found! \n";
  set<string> words = { "computer", "program", "file","windows" };
  b.build_index(words);
  b.show_index(); }
  { Book b;
  if (!(b.import("book_05.txt"))) cout << "book not found! \n";
  set<string> words = { "linux", "byte", "cpu" };
  b.build_index(words);
  b.show_index(); }

    return 0;
}