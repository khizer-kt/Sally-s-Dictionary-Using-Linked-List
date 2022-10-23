#pragma once
#include <string>
using namespace std;

class Dictionary //definition of class Dictionary
{
public:
    string word; 
    string meaning;

    Dictionary() //default constructor
    {
        word.push_back('\0');
        meaning.push_back('\0');
    }

    Dictionary(string word, string meaning) //constructor#2 with parameters
    {
        this->word = word;
        this->meaning = meaning;
    }

    //overloading of boolean comparison operators for Storing data in list
    bool operator==(Dictionary dictionaryEntry)
    {
        return word == dictionaryEntry.word;
    }

    bool operator!=(Dictionary dictionaryEntry)
    {
        return word != dictionaryEntry.word;
    }

    bool operator>(Dictionary dictionaryEntry)
    {
        return word > dictionaryEntry.word;
    }

    bool operator<(Dictionary dictionaryEntry)
    {
        return word < dictionaryEntry.word;
    }

    // << was overloaded for printing and file writing purposes
    friend ostream& operator<<(ostream& output, const Dictionary& dict)
    {
        output << dict.word << " :: " << dict.meaning;
        return output;
    };
};