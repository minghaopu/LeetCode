//
//  353.cpp
//  LeetCode
//
//  Created by roneil on 12/11/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class SnakeGame {
private:
    vector<pair<int, int>> snake;
    int head;
    int right;
    int down;
    vector<pair<int, int>> foods;
    int nextFood;
    // pair<int, int> nextFood;
public:
    /** Initialize your data structure here.
     @param width - screen width
     @param height - screen height
     @param food - A list of food positions
     E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        snake.push_back({0,0});
        head = 0;
        // for (auto f : food) foods.push(f);
        foods = food;
        foods.push_back({-2, -2});
        nextFood = 0;
        right = width - 1;
        down = height - 1;
    }
    
    /** Moves the snake.
     @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
     @return The game's score after the move. Return -1 if game over.
     Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        pair<int, int> next = snake[head];
        if (direction == "U") {
            if (next.first == 0) return -1;
            next.first--;
        } else if (direction == "L") {
            if (next.second == 0) return -1;
            next.second--;
        } else if (direction == "R") {
            if (next.second == right) return -1;
            next.second++;
        } else {
            if (next.first == down) return -1;
            next.first++;
        }
        for (int i = head; i > 0; i--) if(snake[i] == next) return -1;
        if (foods[nextFood] == next) {
            snake.push_back(next);
            nextFood++;
            head++;
        } else {
            snake.push_back(next);
            snake.erase(snake.begin());
        }
        return head;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */
