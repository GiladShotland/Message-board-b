#pragma once
#include "Direction.hpp"
#include <string>
#include <unordered_map>
using namespace std;
#include <climits>
struct place
{
    char letter = '_';
};

namespace ariel
{
    class Board
    {
        unsigned int maxRow, maxCollumn, minRow, minCollumn;
        unordered_map<unsigned int, unordered_map<unsigned int, place>> data;

    public:
        //constructor
        Board()
        {
            maxRow = 0;
            maxCollumn = 0;
            minRow = UINT_MAX;
            minCollumn = UINT_MAX;
        }
        //destructor
        ~Board() {}

        void post(unsigned int row, unsigned int column, Direction direction, string const &post);

        string read(unsigned int row, unsigned int column, Direction direction, unsigned int numberOfChars);

        void show();
    };
}