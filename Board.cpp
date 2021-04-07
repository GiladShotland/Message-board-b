#include "Board.hpp"
#include "Direction.hpp"
#include <string>
#include <map>
#include <iostream>
using namespace std;
namespace ariel
{

    void Board::post(unsigned int row, unsigned int column, Direction direction, string const &post)
    {
        this->minCollumn = min(this->minCollumn, column);
        this->minRow = min(this->minRow, row);
        for (char letter : post)
        {
            this->data[row][column].letter = letter;
            if (direction == Direction::Vertical)
            {
                row++;
            }
            else
            {
                column++;
            }
        }
        this->maxCollumn = max(this->maxCollumn, column);
        this->maxRow = max(this->maxRow, row);
    }

    std::string Board::read(unsigned int row, unsigned int column, Direction direction, unsigned int numberOfChars)
    {
        string ans;
        for (unsigned int i = 0; i < numberOfChars; i++)
        {
            ans += this->data[row][column].letter;
            if (direction == Direction::Vertical)
            {
                row++;
            }
            else
            {
                column++;
            }
        }
        return ans;
    }

    void Board::show()
    {
        for (unsigned int i = this->minRow; i < this->maxRow; i++)
        {
            for (unsigned int j = this->minCollumn; j < this->maxCollumn; j++)
            {
                cout << this->data[i][j].letter;
            }
            cout << "\n";
        }
    }

}