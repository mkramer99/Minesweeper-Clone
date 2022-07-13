#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;
using namespace sf;

class Tile {
public:
    bool gameOver;
    bool isBomb;
    bool isFlagged;
    bool isRevealed;
    int neighborCount;
    Tile();
    bool TileIsBomb();
    void ToggleFlag();
    bool TileIsRevealed();
    vector <int> Neighbors(vector <bool> bombs, int columns, int rows);
};
Tile::Tile() {
    isBomb = false;
    isRevealed = false;
    isFlagged = false;
    neighborCount = 0;
}
bool Tile::TileIsBomb() {
    return isBomb;
}
void Tile::ToggleFlag() {
    isFlagged = !isFlagged;
}
bool Tile::TileIsRevealed() {
    return isRevealed;
}


vector <int> Neighbors(vector <bool> bombs, int columns, int rows) {
    vector <int> numbers;
    // keep track of neighbors for each location
    int number = 0;
    int zero = 0;
    for (int i = 0; i < bombs.size(); i++) {
        if (bombs[i]) {
            numbers.push_back(zero);
            continue;
        }
        // left top corner
        if (i == 0) {
            // if is bomb, continue
            if (bombs[i + 1] == true) {
                number++;
            }
            if (bombs[i + columns] == true) {
                number++;
            }
            if (bombs[i + columns + 1] == true) {
                number++;
            }
            numbers.push_back(number);
            number = 0;
            continue;
        }
        // right top corner
        if (i == columns - 1) {
            if (bombs[i - 1] == true) {
                number++;
            }
            if (bombs[i + columns] == true) {
                number++;
            }
            if (bombs[i + columns - 1] == true) {
                number++;
            }
            numbers.push_back(number);
            number = 0;
            continue;
        }
        // left bottom corner
        if (i == ((columns*rows)-columns)) {
            if (bombs[i + 1] == true) {
                number++;
            }
            if (bombs[i - columns] == true) {
                number++;
            }
            if (bombs[i - columns + 1] == true) {
                number++;
            }
            numbers.push_back(number);
            number = 0;
            continue;
        }
        // right bottom corner
        if (i == ((columns*rows)-1)) {
            if (bombs[i - 1] == true) {
                number++;
            }
            if (bombs[i - columns] == true) {
                number++;
            }
            if (bombs[i - columns - 1] == true) {
                number++;
            }
            numbers.push_back(number);
            number = 0;
            continue;
        }
        // top row, not a corner
        if (i > 0 && i < columns) {
            if (bombs[i + 1] == true) {
                number++;
            }
            if (bombs[i - 1] == true) {
                number++;
            }
            if (bombs[i + columns] == true) {
                number++;
            }
            if (bombs[i + columns + 1] == true) {
                number++;
            }
            if (bombs[i + columns - 1] == true) {
                number++;
            }
            numbers.push_back(number);
            number = 0;
            continue;
        }
        // bottom row, not a corner
        if (i > ((columns*rows) - columns) && i < columns*rows) {
            if (bombs[i + 1] == true) {
                number++;
            }
            if (bombs[i - 1] == true) {
                number++;
            }
            if (bombs[i - columns] == true) {
                number++;
            }
            if (bombs[i - columns + 1] == true) {
                number++;
            }
            if (bombs[i - columns - 1] == true) {
                number++;
            }
            numbers.push_back(number);
            number = 0;
            continue;
        }
        // left side, not a corner
        if (i < ((columns*rows) - columns) && i > 0) {
            if (i % 25 == 0) {
                if (bombs[i + 1] == true) {
                    number++;
                }
                if (bombs[i - columns] == true) {
                    number++;
                }
                if (bombs[i + columns] == true) {
                    number++;
                }
                if (bombs[i + columns + 1] == true) {
                    number++;
                }
                if (bombs[i - columns + 1] == true) {
                    number++;
                }
                numbers.push_back(number);
                number = 0;
                continue;
            }
        }
        // right side, not a corner
        if (i < (columns*rows) && i > columns) {
            if ((i - (columns - 1)) % 25 == 0) {
                if (bombs[i - 1] == true) {
                    number++;
                }
                if (bombs[i - columns] == true) {
                    number++;
                }
                if (bombs[i + columns] == true) {
                    number++;
                }
                if (bombs[i + columns - 1] == true) {
                    number++;
                }
                if (bombs[i - columns - 1] == true) {
                    number++;
                }
                numbers.push_back(number);
                number = 0;
                continue;
            }
        }
        // any middle tile
        if (bombs[i - 1] == true) {
            number++;
        }
        if (bombs[i + 1] == true) {
            number++;
        }
        if (bombs[i + columns] == true) {
            number++;
        }
        if (bombs[i - columns] == true) {
            number++;
        }
        if (bombs[i + columns + 1] == true) {
            number++;
        }
        if (bombs[i + columns - 1] == true) {
            number++;
        }
        if (bombs[i - columns + 1] == true) {
            number++;
        }
        if (bombs[i - columns - 1] == true) {
            number++;
        }
        numbers.push_back(number);
        number = 0;

    }
    return numbers;
}