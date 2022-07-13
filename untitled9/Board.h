#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <fstream>
#include <random>
#include "Tile.h"
using namespace std;
using namespace sf;

class Board {
public:
    int columns;
    int rows;
    int mines;
    int numBoardMines;
    int minesFlagged;
    int numFlagged = 0;
    int numRevealed = 0;
    int recursiveP = 600;
    int recursiveCount = 0;
    bool gameOver = false;
    bool gameWon = false;
    bool toggled = false;
    bool debugging = false;
    bool smiley = false;
    string fileName = "boards/lots_o_mines.brd";

    map<string, Sprite> sprites;
    vector <bool> board;
    vector <int> randomMines;
    vector <Tile> tiles;
    vector <int> neighbors;

    Board();
    void LoadBoard();
    void UpdateCounter(RenderWindow &window);
    void Update(RenderWindow &window, Event event);
    void Smiley();
    void RecursiveReveal(int p, int n);

    Texture backgroundTile;
    Texture coverTile;
    Texture flag;
    Texture mine;
    // smileys
    Texture face_happy;
    Texture face_lose;
    Texture face_win;
    // test board icons
    Texture test_1;
    Texture test_2;
    Texture test_3;
    Texture debug;

    Texture num1;
    Texture num2;
    Texture num3;
    Texture num4;
    Texture num5;
    Texture num6;
    Texture num7;
    Texture num8;

    Texture zero;
    Texture one;
    Texture two;
    Texture three;
    Texture four;
    Texture five;
    Texture six;
    Texture seven;
    Texture eight;
    Texture nine;
    Texture negative;

};
Board::Board() {
    //Texture backgroundTile;
    backgroundTile.loadFromFile("images/tile_revealed.png");
    Sprite backgroundTileSprite(backgroundTile);
    sprites.emplace("backgroundTileSprite", backgroundTileSprite);

    coverTile.loadFromFile("images/tile_hidden.png");
    Sprite coverTileSprite(coverTile);
    sprites.emplace("coverTileSprite", coverTileSprite);

    flag.loadFromFile("images/flag.png");
    Sprite flagSprite(flag);
    sprites.emplace("flagSprite",  flagSprite);

    mine.loadFromFile("images/mine.png");
    Sprite mineSprite(mine);
    sprites.emplace("mineSprite", mineSprite);

    face_happy.loadFromFile("images/face_happy.png");
    Sprite faceHappySprite(face_happy);
    sprites.emplace("faceHappySprite", faceHappySprite);

    face_lose.loadFromFile("images/face_lose.png");
    Sprite faceLoseSprite(face_lose);
    sprites.emplace("faceLoseSprite", faceLoseSprite);

    face_win.loadFromFile("images/face_win.png");
    Sprite faceWinSprite(face_win);
    sprites.emplace("faceWinSprite", faceWinSprite);

    test_1.loadFromFile("images/test_1.png");
    Sprite testBoard1Sprite(test_1);
    sprites.emplace("testBoard1Sprite", testBoard1Sprite);

    test_2.loadFromFile("images/test_2.png");
    Sprite testBoard2Sprite(test_2);
    sprites.emplace("testBoard2Sprite", testBoard2Sprite);

    test_3.loadFromFile("images/test_3.png");
    Sprite testBoard3Sprite(test_3);
    sprites.emplace("testBoard3Sprite", testBoard3Sprite);

    debug.loadFromFile("images/debug.png");
    Sprite debugSprite(debug);
    sprites.emplace("debugSprite", debugSprite);

    num1.loadFromFile("images/number_1.png");
    Sprite num1Sprite(num1);
    sprites.emplace("num1Sprite", num1Sprite);

    num2.loadFromFile("images/number_2.png");
    Sprite num2Sprite(num2);
    sprites.emplace("num2Sprite", num2Sprite);

    num3.loadFromFile("images/number_3.png");
    Sprite num3Sprite(num3);
    sprites.emplace("num3Sprite", num3Sprite);

    num4.loadFromFile("images/number_4.png");
    Sprite num4Sprite(num4);
    sprites.emplace("num4Sprite", num4Sprite);

    num5.loadFromFile("images/number_5.png");
    Sprite num5Sprite(num5);
    sprites.emplace("num5Sprite", num5Sprite);

    num6.loadFromFile("images/number_6.png");
    Sprite num6Sprite(num6);
    sprites.emplace("num6Sprite", num6Sprite);

    num7.loadFromFile("images/number_7.png");
    Sprite num7Sprite(num7);
    sprites.emplace("num7Sprite", num7Sprite);

    num8.loadFromFile("images/number_8.png");
    Sprite num8Sprite(num8);
    sprites.emplace("num8Sprite", num8Sprite);

    zero.loadFromFile("images/digits.png", sf::IntRect(0, 0, 21, 32));
    Sprite zeroSprite(zero);
    sprites.emplace("zeroSprite", zeroSprite);

    one.loadFromFile("images/digits.png", sf::IntRect(21, 0, 21, 32));
    Sprite oneSprite(one);
    sprites.emplace("oneSprite", oneSprite);

    two.loadFromFile("images/digits.png", sf::IntRect(42, 0, 21, 32));
    Sprite twoSprite(two);
    sprites.emplace("twoSprite", twoSprite);

    three.loadFromFile("images/digits.png", sf::IntRect(63, 0, 21, 32));
    Sprite threeSprite(three);
    sprites.emplace("threeSprite", threeSprite);

    four.loadFromFile("images/digits.png", sf::IntRect(84, 0, 21, 32));
    Sprite fourSprite(four);
    sprites.emplace("fourSprite", fourSprite);

    five.loadFromFile("images/digits.png", sf::IntRect(105, 0, 21, 32));
    Sprite fiveSprite(five);
    sprites.emplace("fiveSprite", fiveSprite);

    six.loadFromFile("images/digits.png", sf::IntRect(126, 0, 21, 32));
    Sprite sixSprite(six);
    sprites.emplace("sixSprite", sixSprite);

    seven.loadFromFile("images/digits.png", sf::IntRect(147, 0, 21, 32));
    Sprite sevenSprite(seven);
    sprites.emplace("sevenSprite", sevenSprite);

    eight.loadFromFile("images/digits.png", sf::IntRect(168, 0, 21, 32));
    Sprite eightSprite(eight);
    sprites.emplace("eightSprite", eightSprite);

    nine.loadFromFile("images/digits.png", sf::IntRect(189, 0, 21, 32));
    Sprite nineSprite(nine);
    sprites.emplace("nineSprite", nineSprite);

    negative.loadFromFile("images/digits.png", sf::IntRect(210, 0, 21, 32));
    Sprite negativeSprite(negative);
    sprites.emplace("negativeSprite", negativeSprite);

    ifstream file;
    file.open("boards/config.cfg");
    if (file.is_open()) {
        columns = 0;
        rows = 0;
        mines = 0;
        file >> columns;
        file >> rows;
        file >> mines;
    }
    file.close();

    for (int i = 0; i < (columns * rows); i++) {
        Tile t;
        tiles.push_back(t);
    }
    LoadBoard();
}
void Board::LoadBoard() {

    // load the board
    if (smiley == true) {
        numBoardMines = 0;
        board.clear();
        // set randomMine vector to size columns*rows
        // assign all to 0
        // iterate through randomMine vector
        // use the ints to assign mine locations for board
        for (int i = 0; i < (columns * rows); i++) {
            board.push_back(false);
        }
        for (int i = 0; i < randomMines.size(); i++) {
            int mineIndex = randomMines[i];
            board[mineIndex] = true;
            numBoardMines++;
        }
    } else {
        numBoardMines = 0;
        ifstream file;
        file.open(fileName);
        if (file.is_open()) {
            char mine;
            board.clear();
            while (file >> mine) {
                if (mine == '0') {
                    board.push_back(false);
                } else {
                    board.push_back(true);
                    numBoardMines++;
                }
            }
        }
        file.close();
    }

    // configure neighbors and create vector of Tile objects
    neighbors = Neighbors(board, columns, rows);
    for (int i = 0; i < board.size(); i++) {
        if (board[i] == true) {
            //Tile t;
            //tiles.push_back(t);
            tiles[i].isBomb = true;
        } else {
            //Tile t;
            //tiles.push_back(t);
            tiles[i].isBomb = false;
        }
    }
}
//if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
void Board::Update(RenderWindow &window, Event event) {
    LoadBoard();
    UpdateCounter(window);

    //if (event.type = sf::Event::KeyReleased) {
    //if (event.type = sf::Event::MouseButtonPressed) {
    if(Mouse::isButtonPressed((Mouse::Left))) {
        //if (event.type = sf::Event::MouseButtonReleased) {
        //if (event.mouseButton.button == sf::Mouse::Left) {
        cout << "mouse click" << endl;
        sf::Vector2i pos = sf::Mouse::getPosition(window);
        // click tile
        if (pos.y >= 0 && pos.y < 512) {
            if (pos.x >= 0 && pos.x <= 800) {
                if (!gameOver) {
                    int x = (pos.x / 32);
                    int y = (pos.y / 32);
                    int p = (y * 25) + x;
                    cout << "p: " << p << endl;
                    if (!tiles[p].isFlagged) {
                        //tiles[p].isRevealed = true;
                        // recursive reveal
                        if (recursiveP != p) {
                            cout << "recursive function" << endl;
                            recursiveP = p;
                            RecursiveReveal(p, 0);
                            recursiveCount = 0;
                        }
                        tiles[p].isRevealed = true;
                    }
                    if ((tiles[p].isBomb) && (!tiles[p].isFlagged)) {
                        gameOver = true;
                    }
                }
            }
        } else if (pos.y >= (rows * 32) && pos.y < (rows * 32) + 64) {
            // smiley
            if (pos.x >= ((columns * 32) / 2 - 32) && pos.x < ((columns * 32) / 2 + 64)) {
                gameOver = false;
                gameWon = false;
                debugging = false;
                smiley = true;
                for (int i = 0; i < tiles.size(); i++) {
                    tiles[i].isRevealed = false;
                    tiles[i].isFlagged = false;
                }
                Smiley();
            }
            // debug
            if (pos.x >= 544 && pos.x < 608) {
                debugging = true;
            }
            // load test board 1
            if (pos.x >= 608 && pos.x < 672) {
                gameOver = false;
                gameWon = false;
                debugging = false;
                smiley = false;
                //tiles.clear();
                for (int i = 0; i < tiles.size(); i++) {
                    tiles[i].isRevealed = false;
                    tiles[i].isFlagged = false;
                }
                fileName = "boards/testboard1.brd";
            }
            // load test board 2
            if (pos.x >= 672 && pos.x < 736) {
                gameOver = false;
                gameWon = false;
                debugging = false;
                smiley = false;
                //tiles.clear();
                for (int i = 0; i < tiles.size(); i++) {
                    tiles[i].isRevealed = false;
                    tiles[i].isFlagged = false;
                }
                fileName = "boards/testboard2.brd";
            }
            // load test board 3
            if (pos.x >= 736 && pos.x < 800) {
                gameOver = false;
                gameWon = false;
                debugging = false;
                smiley = false;
                //tiles.clear();
                for (int i = 0; i < tiles.size(); i++) {
                    tiles[i].isRevealed = false;
                    tiles[i].isFlagged = false;
                }
                fileName = "boards/testboard3.brd";
            }
        }
    }

        //if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
    //if (event.type = sf::Event::KeyReleased) {
    //if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
    //if (event.type == sf::Event::MouseButtonReleased) {
    // if (event.mouseButton.button == sf::Mouse::Right) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
        //if (sf::Event::MouseButtonReleased) {
        sf::Vector2i pos = sf::Mouse::getPosition(window);
        int p;
        // click over tile
        //event.type = sf::Event::MouseButtonReleased;
        if (pos.y >= 0 && pos.y < 512) {
            if (pos.x >= 0 && pos.x <= 800) {
                int x = (pos.x / 32);
                int y = (pos.y / 32);
                p = (y * 25) + x;
                if (!tiles[p].isRevealed) {
                    cout << "toggled: " << tiles[p].isRevealed << endl;
                    //tiles[p].ToggleFlag();

                    if (!toggled) {

                        if (tiles[p].isFlagged == false) {
                            cout << "toggle" << endl;
                            //sprites["flagSprite"].setPosition(x * 32, y * 32);
                            //window.draw(sprites["flagSprite"]);
                            toggled = true;

                            //tiles[p].isFlagged = true;
                        }
                    }
                    // }
                    //numFlagged--;


                    tiles[p].ToggleFlag();
                    cout << "after toggle " << tiles[p].isRevealed << endl;
                }
            }
        }
    }
        //}
    //}


    int boardIndex = 0;
    numFlagged = 0;
    minesFlagged = 0;
    numRevealed = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (board[boardIndex] == true) {
                sprites["backgroundTileSprite"].setPosition(j * 32, i * 32);
                window.draw(sprites["backgroundTileSprite"]);
                sprites["mineSprite"].setPosition(j * 32, i * 32);
                window.draw(sprites["mineSprite"]);
            }
            else {
                sprites["backgroundTileSprite"].setPosition(j * 32, i * 32);
                window.draw(sprites["backgroundTileSprite"]);
            }
            // draw neighbor sprites
            switch (neighbors[boardIndex]) {
                case 0: break;
                case 1: sprites["num1Sprite"].setPosition(j * 32, i * 32);
                    window.draw(sprites["num1Sprite"]);
                    break;
                case 2: sprites["num2Sprite"].setPosition(j * 32, i * 32);
                    window.draw(sprites["num2Sprite"]);
                    break;
                case 3: sprites["num3Sprite"].setPosition(j * 32, i * 32);
                    window.draw(sprites["num3Sprite"]);
                    break;
                case 4: sprites["num4Sprite"].setPosition(j * 32, i * 32);
                    window.draw(sprites["num4Sprite"]);
                    break;
                case 5: sprites["num5Sprite"].setPosition(j * 32, i * 32);
                    window.draw(sprites["num5Sprite"]);
                    break;
                case 6: sprites["num6Sprite"].setPosition(j * 32, i * 32);
                    window.draw(sprites["num6Sprite"]);
                    break;
                case 7: sprites["num7Sprite"].setPosition(j * 32, i * 32);
                    window.draw(sprites["num7Sprite"]);
                    break;
                case 8: sprites["num8Sprite"].setPosition(j * 32, i * 32);
                    window.draw(sprites["num8Sprite"]);
                    break;
            }
            if (!tiles[boardIndex].isRevealed) {
                sprites["coverTileSprite"].setPosition(j * 32, i * 32);
                window.draw(sprites["coverTileSprite"]);
                toggled = false;
                if (debugging && tiles[boardIndex].isBomb) {
                    sprites["mineSprite"].setPosition(j * 32, i * 32);
                    window.draw(sprites["mineSprite"]);
                }
            }
            if (tiles[boardIndex].isFlagged) {
                sprites["flagSprite"].setPosition(j * 32, i * 32);
                window.draw(sprites["flagSprite"]);
                minesFlagged++;
                numFlagged++;
            }
            if (tiles[boardIndex].isRevealed) {
                numRevealed++;
            }
            boardIndex++;
        }
    }
    if (minesFlagged + numRevealed == (columns * rows)) {
        gameOver = true;
        gameWon = true;
    }
    for (int i = 0; i < tiles.size(); i++) {
        tiles[i].neighborCount = neighbors[i];
    }
    // smiley
    if (gameOver) {
        if (gameWon) {
            sprites["faceWinSprite"].setPosition(((columns*32)/2 - 32), (rows*32));
            window.draw(sprites["faceWinSprite"]);
        }
        else {
            sprites["faceLoseSprite"].setPosition(((columns*32)/2 - 32), (rows*32));
            window.draw(sprites["faceLoseSprite"]);
            for (int i = 0; i < tiles.size(); i++) {
                if (tiles[i].isBomb) {
                    tiles[i].isRevealed = true;
                }
            }
        }
    }
    else {
        sprites["faceHappySprite"].setPosition(((columns*32)/2 - 32), (rows*32));
        window.draw(sprites["faceHappySprite"]);
    }
    sprites["testBoard1Sprite"].setPosition((columns*32)-192, (rows*32));
    window.draw(sprites["testBoard1Sprite"]);
    sprites["testBoard2Sprite"].setPosition((columns*32)-128, (rows*32));
    window.draw(sprites["testBoard2Sprite"]);
    sprites["testBoard3Sprite"].setPosition((columns*32)-64, (rows*32));
    window.draw(sprites["testBoard3Sprite"]);
    sprites["debugSprite"].setPosition((columns*32)-256, (rows*32));
    window.draw(sprites["debugSprite"]);
}

void Board::UpdateCounter(RenderWindow &window) {

    bool neg = false;
    int num;
    // if negative number, else if positive
    if (numBoardMines - numFlagged < 0) {
        neg = true;
        num = numBoardMines - numFlagged;
        num = (num * (-2) / 2);
    } else {
        num = numBoardMines - numFlagged;
    }
    int ones = num % 10;
    int tens = (num / 10) % 10;
    int hund = (num / 100) % 10;

    switch (ones) {
        case (0):
            sprites["zeroSprite"].setPosition(64, (rows*32));
            window.draw(sprites["zeroSprite"]);
            break;
        case (1):
            sprites["oneSprite"].setPosition(64, (rows*32));
            window.draw(sprites["oneSprite"]);
            break;
        case (2):
            sprites["twoSprite"].setPosition(64, (rows*32));
            window.draw(sprites["twoSprite"]);
            break;
        case (3):
            sprites["threeSprite"].setPosition(64, (rows*32));
            window.draw(sprites["threeSprite"]);
            break;
        case (4):
            sprites["fourSprite"].setPosition(64, (rows*32));
            window.draw(sprites["fourSprite"]);
            break;
        case (5):
            sprites["fiveSprite"].setPosition(64, (rows*32));
            window.draw(sprites["fiveSprite"]);
            break;
        case (6):
            sprites["sixSprite"].setPosition(64, (rows*32));
            window.draw(sprites["sixSprite"]);
            break;
        case (7):
            sprites["sevenSprite"].setPosition(64, (rows*32));
            window.draw(sprites["sevenSprite"]);
            break;
        case (8):
            sprites["eightSprite"].setPosition(64, (rows*32));
            window.draw(sprites["eightSprite"]);
            break;
        case (9):
            sprites["nineSprite"].setPosition(64, (rows*32));
            window.draw(sprites["nineSprite"]);
            break;
    }
    switch (tens) {
        case (0):
            sprites["zeroSprite"].setPosition(43, (rows*32));
            window.draw(sprites["zeroSprite"]);
            break;
        case (1):
            sprites["oneSprite"].setPosition(43, (rows*32));
            window.draw(sprites["oneSprite"]);
            break;
        case (2):
            sprites["twoSprite"].setPosition(43, (rows*32));
            window.draw(sprites["twoSprite"]);
            break;
        case (3):
            sprites["threeSprite"].setPosition(43, (rows*32));
            window.draw(sprites["threeSprite"]);
            break;
        case (4):
            sprites["fourSprite"].setPosition(43, (rows*32));
            window.draw(sprites["fourSprite"]);
            break;
        case (5):
            sprites["fiveSprite"].setPosition(43, (rows*32));
            window.draw(sprites["fiveSprite"]);
            break;
        case (6):
            sprites["sixSprite"].setPosition(43, (rows*32));
            window.draw(sprites["sixSprite"]);
            break;
        case (7):
            sprites["sevenSprite"].setPosition(43, (rows*32));
            window.draw(sprites["sevenSprite"]);
            break;
        case (8):
            sprites["eightSprite"].setPosition(43, (rows*32));
            window.draw(sprites["eightSprite"]);
            break;
        case (9):
            sprites["nineSprite"].setPosition(43, (rows*32));
            window.draw(sprites["nineSprite"]);
            break;
    }
    switch (hund) {
        case (0):
            sprites["zeroSprite"].setPosition(22, (rows*32));
            window.draw(sprites["zeroSprite"]);
            break;
        case (1):
            sprites["oneSprite"].setPosition(22, (rows*32));
            window.draw(sprites["oneSprite"]);
            break;
        case (2):
            sprites["twoSprite"].setPosition(22, (rows*32));
            window.draw(sprites["twoSprite"]);
            break;
        case (3):
            sprites["threeSprite"].setPosition(22, (rows*32));
            window.draw(sprites["threeSprite"]);
            break;
        case (4):
            sprites["fourSprite"].setPosition(22, (rows*32));
            window.draw(sprites["fourSprite"]);
            break;
        case (5):
            sprites["fiveSprite"].setPosition(22, (rows*32));
            window.draw(sprites["fiveSprite"]);
            break;
        case (6):
            sprites["sixSprite"].setPosition(22, (rows*32));
            window.draw(sprites["sixSprite"]);
            break;
        case (7):
            sprites["sevenSprite"].setPosition(22, (rows*32));
            window.draw(sprites["sevenSprite"]);
            break;
        case (8):
            sprites["eightSprite"].setPosition(22, (rows*32));
            window.draw(sprites["eightSprite"]);
            break;
        case (9):
            sprites["nineSprite"].setPosition(22, (rows*32));
            window.draw(sprites["nineSprite"]);
            break;
    }
    if (neg) {
        sprites["negativeSprite"].setPosition(1, (rows*32));
        window.draw(sprites["negativeSprite"]);
    }

}
void Board::Smiley() {
    // create 50 randomly indexed mines and set new board
    // 21 x 32
    // offset by 21 width
    cout << "smiley func " << endl;
    int r;
    randomMines.clear();
    for (int i = 0; randomMines.size() < 50; i++) {
        r = rand() % (columns * rows);
        cout << "random " << i << ": " << r << endl;
        if (find(randomMines.begin(), randomMines.end(), r) == randomMines.end()) {
            randomMines.push_back(r);
        }
    }
    cout << "randomMines size: " << randomMines.size() << endl;
}
void Board::RecursiveReveal(int p, int n) {
    recursiveCount++;
    if (recursiveCount > (3000)) {
        cout << "exiting recursion" << endl;
        return;
    }
    if (p >= (columns*rows)) {
        cout << "return from greater than 400: " << p << endl;
        return;
    }
    if (p < 0) {
        cout << "return from p < 0 p: " << p << endl;
        return;
    }
    if (tiles[p].isBomb) {
        return;
    }
    // left wall check
    if ((p) % columns == 0) {
        if (!tiles[p].isBomb){
            //tiles[p].isRevealed = true;
            numRevealed++;
            //RecursiveReveal(p + columns, n);
            //RecursiveReveal(p - columns, n);
        }
        cout << "return from left wall p: " << p << endl;
        //return;
    }
    // right wall check
    if (((p) + 1) % columns == 0) {
        if (!tiles[p].isBomb) {
            //tiles[p].isRevealed = true;
            numRevealed++;
            //RecursiveReveal(p + columns, n);
            //RecursiveReveal(p - columns, n);
        }
        cout << "return from right wall p: " << p << endl;
        //return;
    }
    // top wall check
    if ((p - columns) < columns) {
        if (!tiles[p - columns].isBomb) {
            //tiles[p - columns].isRevealed = true;
            numRevealed++;
            //RecursiveReveal(p + 1, n);
            //RecursiveReveal(p - 1, n);
        }
        cout << "return from top wall p: " << p << endl;
        //return;
    }
    // bottom wall check
    if ((p + columns) >= ((columns*rows) - columns)) {
        if (!tiles[p + columns].isBomb) {
            //tiles[p + columns].isRevealed = true;
            numRevealed++;
            //RecursiveReveal(p + 1, n);
            //RecursiveReveal(p - 1, n);
        }
        cout << "return from bottom wall p: " << p << endl;
        //return;
    }
    // check for bombs
    if (!tiles[p].isBomb) {
        if (!tiles[p].isRevealed) {
            if (!tiles[p].isFlagged) {
                tiles[p].isRevealed = true;
                numRevealed++;
                n++;
                RecursiveReveal(p + 1, n);
                RecursiveReveal(p - 1, n);
                RecursiveReveal(p + columns, n);
                RecursiveReveal(p - columns, n);
            }
        }
    }
    else {
        return;
    }
}

