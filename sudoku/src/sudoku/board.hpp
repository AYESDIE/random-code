//
// Created by ayesdie on 16/08/19.
//

#ifndef SUDOKU_BOARD_HPP
#define SUDOKU_BOARD_HPP

#include <ostream>
#import "../sudoku.hpp"

class Board {
public:
    Board() {
        board.fill(0);
    }

    Board(const std::array<size_t, 81>& board) :
            board(board) {};

    friend std::ostream &operator<<(std::ostream &os, const Board &board) {
        size_t i = 0;
        for (auto x : board.board) {
            if (x == 0)
                std::cout << "  ";
            else
                std::cout << x << " ";

            i++;
            if (i % 9 == 0)
                std::cout << "\n";
        }
    }

private:
    std::array<size_t, 81> board;
};

#endif //SUDOKU_BOARD_HPP
