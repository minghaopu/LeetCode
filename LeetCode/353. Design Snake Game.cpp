//
//  353. Design Snake Game.cpp
//  LeetCode
//
//  Created by roneil on 11/21/16.
//  Copyright © 2016 Minghao Pu. All rights reserved.
//

#include "Header.h"
class SnakeGame {
private:
    vector<pair<int, int>> snake;
    int head;
    int right;
    int down;
    queue<pair<int, int>> foods;
    pair<int, int> nextFood;
public:
    /** Initialize your data structure here.
     @param width - screen width
     @param height - screen height
     @param food - A list of food positions
     E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        snake.push_back({0,0});
        head = 0;
        for (auto f: food) {
            foods.push(f);
        }
        foods.push({-2, -2});
        nextFood = foods.front();
        right = width - 1;
        down = height - 1;
    }
    
    /** Moves the snake.
     @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
     @return The game's score after the move. Return -1 if game over.
     Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        pair<int,int> next;
        if (direction == "U") {
            if (snake[head].first == 0) return -1;
            next = {snake[head].first - 1, snake[head].second};
        } else if (direction == "L") {
            if (snake[head].second == 0) return -1;
            next = {snake[head].first, snake[head].second - 1};
        } else if (direction == "R") {
            if (snake[head].second == right) return -1;
            next = {snake[head].first, snake[head].second + 1};
        } else {
            if (snake[head].first == down) return -1;
            next = {snake[head].first + 1, snake[head].second};
        }
        for (int i = head; i > 0; i--) if(snake[i] == next) return -1;
        if (nextFood == next) {
            snake.push_back(next);
            foods.pop();
            nextFood = foods.front();
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
