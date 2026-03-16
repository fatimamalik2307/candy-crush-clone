#include<iostream>
#include<sstream>
#include <SFML/Graphics/Text.hpp>
#include<windows.h>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
const int rows = 8, columns = 8;
int cellSize = 60;

// ... (main function and other code remains unchanged)

Texture candyTextures[5];
Texture specialcandyTextures[2];

Sprite candySprites[rows][columns];
int grid[rows][columns];
void initializeGrid()
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            grid[i][j] = (rand() % 4);
        }
    }
}
//void loadspecialCandyTextures() {
//    // Load textures for each candy type
//    
//    string filename = "Images/color bomb" + to_string(0) + ".png";
//    if (!specialcandyTextures[0].loadFromFile(filename)) {
//        // Handle error loading texture (print an error message or throw an exception)
//        cerr << "Error loading special candy texture " << 0 << endl;
//    }
//}

void loadCandyTextures() {
    // Load textures for each candy type
    for (int i = 0; i < 5; ++i) {
       string filename = "Images/candy" + to_string(i) + ".png";
        candyTextures[i].loadFromFile(filename);
    }

    // Set textures for each candy sprite
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < columns; ++j) {
            candySprites[i][j].setTexture(candyTextures[grid[i][j]]);
            candySprites[i][j].setPosition(j * cellSize, i * cellSize);
        }
    }
   
}

void popping(int& score) {

    int s = 0;
    // Check for popping horizontally
    while (s == 0)
    {
        s = 1;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns - 2; ++j) {
                if (grid[i][j] == grid[i][j + 1] && grid[i][j] == grid[i][j + 2]) {
                    score += 10;
                    s = 0; //popSound.play();
                    // popSound.play();
                     // Replace the candies with new ones
                    grid[i][j] = (rand() % 5);
                    grid[i][j + 1] =(rand() % 5);
                    grid[i][j + 2] = (rand() % 5);

                    // Update candy sprites
                    candySprites[i][j].setTexture(candyTextures[grid[i][j]]);
                    candySprites[i][j + 1].setTexture(candyTextures[grid[i][j + 1]]);
                    candySprites[i][j + 2].setTexture(candyTextures[grid[i][j + 2]]);
                }
            }
        }


        for (int i = 0; i < rows - 2; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (grid[i][j] == grid[i + 1][j] && grid[i][j] == grid[i + 2][j]) {
                    score += 10;
                    // popSound.play();
                    s = 0;// popSound.play();
                    // Replace the candies with new ones
                    grid[i][j] = (rand() % 5);
                    grid[i + 1][j] = (rand() %5);
                    grid[i + 2][j] = (rand() % 5);

                    // Update candy sprites
                    candySprites[i][j].setTexture(candyTextures[grid[i][j]]);
                    candySprites[i + 1][j].setTexture(candyTextures[grid[i + 1][j]]);
                    candySprites[i + 2][j].setTexture(candyTextures[grid[i + 2][j]]);
                }
            }
        }

        // Check for popping diagonally (top-left to bottom-right)
        for (int i = 0; i < rows - 2; ++i) {
            for (int j = 0; j < columns - 2; ++j) {
                if (grid[i][j] == grid[i + 1][j + 1] && grid[i][j] == grid[i + 2][j + 2]) {
                    score += 10;
                    s = 0;
                    // popSound.play();
                     // Replace the candies with new ones
                    grid[i][j] =(rand() % 5);
                    grid[i + 1][j + 1] = (rand() % 5);
                    grid[i + 2][j + 2] = (rand() % 5);

                    // Update candy sprites
                    candySprites[i][j].setTexture(candyTextures[grid[i][j]]);
                    candySprites[i + 1][j + 1].setTexture(candyTextures[grid[i + 1][j + 1]]);
                    candySprites[i + 2][j + 2].setTexture(candyTextures[grid[i + 2][j + 2]]);
                }
            }
        }

        // Check for popping diagonally (top-right to bottom-left)
        for (int i = 0; i < rows - 2; ++i) {
            for (int j = 2; j < columns; ++j) {
                if (grid[i][j] == grid[i + 1][j - 1] && grid[i][j] == grid[i + 2][j - 2]) {
                    score += 10;
                    s = 0;
                    //popSound.play();
                    // Replace the candies with new ones
                    grid[i][j] = (rand() % 5);
                    grid[i + 1][j - 1] = (rand() % 5);
                    grid[i + 2][j - 2] = (rand() % 5);

                    // Update candy sprites
                    candySprites[i][j].setTexture(candyTextures[grid[i][j]]);
                    candySprites[i + 1][j - 1].setTexture(candyTextures[grid[i + 1][j - 1]]);
                    candySprites[i + 2][j - 2].setTexture(candyTextures[grid[i + 2][j - 2]]);
                }
            }
        }

    }
    //for (int i = 0; i < rows; ++i) {
    //    for (int j = 0; j < columns; ++j)
    //    {
    //        // Check horizontally
    //        if (j + 3 < columns)
    //        {
    //            if (grid[i][j] == grid[i][j + 1] && grid[i][j] == grid[i][j + 2] && grid[i][j] == grid[i][j + 3])
    //            {
    //                score += 50;

    //                // Update the candies with a special candy in the grid
    //                grid[i][j + 2] = CandyType::SPECIAL;
    //                candySprites[i][j + 2].setTexture(specialcandyTextures[0]);
    //            }
    //        }


    //        // Check vertically
    //        if (i + 3 < rows) {
    //            if (grid[i][j] == grid[i + 1][j] && grid[i][j] == grid[i + 2][j] && grid[i][j] == grid[i + 3][j]) {
    //                score += 50;

    //                // Update the candies with a special candy in the grid
    //                grid[i + 2][j] = CandyType::SPECIAL;
    //                candySprites[i + 2][j].setTexture(specialcandyTextures[0]);
    //            }
    //        }

    //        // Check diagonally (top-left to bottom-right)
    //        if (i + 3 < rows && j + 3 < columns) {
    //            if (grid[i][j] == grid[i + 1][j + 1] && grid[i][j] == grid[i + 2][j + 2] && grid[i][j] == grid[i + 3][j + 3]) {
    //                score += 50;

    //                // Update the candies with a special candy in the grid

    //                grid[i + 2][j + 2] = CandyType::SPECIAL;
    //                candySprites[i + 2][j + 2].setTexture(specialcandyTextures[0]);
    //            }
    //        }

    //        // Check diagonally (top-right to bottom-left)
    //        if (i + 3 < rows && j - 3 >= 0) {
    //            if (grid[i][j] == grid[i + 1][j - 1] && grid[i][j] == grid[i + 2][j - 2] && grid[i][j] == grid[i + 3][j - 3]) {
    //                score += 50;

    //                // Update the candies with a special candy in the grid
    //                grid[i + 2][j - 2] = CandyType::SPECIAL;
    //                candySprites[i + 2][j - 2].setTexture(specialcandyTextures[0]);
    //            }
    //        }
    //    }
    //}

    if (score == 70)
    {
        score = 0;
    }
}

//void specialcandypopping(int &score) {
//    for (int i = 0; i < rows; ++i) {
//        for (int j = 0; j < columns; ++j)
//            if (grid[i][j] == CandyType::SPECIAL) {
//                // Pop the 3x3 region around the special candy
//                for (int ii = i - 1; ii <= i + 1; ++ii) {
//                    for (int jj = j - 1; jj <= j + 1; ++jj) {
//                        if (ii >= 0 && ii < rows && jj >= 0 && jj < columns) {
//                            score += 10;
//
//                            // Replace the candies with new ones
//                            grid[ii][jj] = static_cast<CandyType>(rand() % 4);
//
//                            // Update candy sprites
//                            candySprites[ii][jj].setTexture(candyTextures[grid[ii][jj]]);
//                        }
//                    }
//                }
//
//                // Reset the special candy in the original position
//                grid[i][j] = static_cast<CandyType>(rand() % NUM_CANDY_TYPES);
//                candySprites[i][j].setTexture(candyTextures[grid[i][j]]);
//            }
//    }
//}
void shuffleBoard(RenderWindow& window)
{
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            grid[i][j] = (rand() % 5);
            candySprites[i][j].setTexture(candyTextures[grid[i][j]]);
            candySprites[i][j].setPosition(j * cellSize, i * cellSize);
            window.draw(candySprites[i][j]);
        }
    }
}
bool shufflecommand = false;

    int main()
    {
        RenderWindow window(sf::VideoMode(1274, 800), "SFML");
        sf::Music backgroundMusic;
        if (!backgroundMusic.openFromFile("popSound.mp3")) {
            // Handle error loading music (print an error message or throw an exception)
            cerr << "Error loading background music" << endl;
        }

        backgroundMusic.setVolume(50);  // Adjust the volume as needed
        backgroundMusic.setLoop(true);   // Make the music loop

        // Play the background music
        backgroundMusic.play();

        Image image;
        sf::Font font;
        int moves = 15;
        int timer = 15;
        int display = 1;
        int score = 0;
       // loadspecialCandyTextures();
        if (!(image.loadFromFile("Images/back1.png")))
            cout << "Cannot load image";   //Load Image
        Texture texture;
        texture.loadFromFile("Images/back1.png");  //Load Texture from image
        Sprite sprite(texture);
        Image image2;
        if (!(image2.loadFromFile("Images/play1.png")))
            cout << "Cannot load image";   //Load Image
        Texture texture2;
        texture2.loadFromFile("Images/play1.png");  //Load Texture from image
        Sprite sprite2(texture2);
        sprite2.setOrigin(0, 0);
        sprite2.setPosition(470, 400);
        Texture texture3;
        texture3.loadFromFile("Images/back21.jpg");
        Sprite sprite3(texture3);
        Texture texture4;
        texture4.loadFromFile("Images/exit.png");  //Load Texture from image
        Sprite sprite4(texture4);
        sprite4.setPosition(470, 570);
        Texture texture8;
        texture8.loadFromFile("Images/shuffle.png");  //Load Texture from image
        Sprite sprite8(texture8);
        sprite8.setPosition(1080.f, 300.f);
        Texture texture10;
        texture10.loadFromFile("Images/output.png");  //Load Texture from image
        Sprite sprite10(texture10);
        Texture texture5;
        texture5.loadFromFile("Images/orange.png");  //Load Texture from image
        Sprite sprite5(texture5);

        if (!font.loadFromFile("newfont.ttf")) {
            cout << "ERROR OPENING THE FILE." << endl;
        }

        sf::Text movesText;
        movesText.setFont(font);
        movesText.setCharacterSize(40);
        movesText.setFillColor(Color::Magenta);
        movesText.setString("Moves:30");
        movesText.setPosition(1100.f, 10.f);

        Text timerText;
        timerText.setFont(font);
        timerText.setCharacterSize(40);
        timerText.setFillColor(sf::Color::Magenta);
        timerText.setString("Timer:15");
        timerText.setPosition(1100.f, 80.f);

        Text scoreText;
        scoreText.setFont(font);
        scoreText.setCharacterSize(40);
        scoreText.setFillColor(sf::Color::Magenta);
        scoreText.setString("SCORE:0");
        scoreText.setPosition(1100.f, 160.f);

        Text finalText;
        finalText.setFont(font);
        finalText.setCharacterSize(100);
        finalText.setFillColor(sf::Color::Magenta);
        finalText.setString("END GAME");
        finalText.setPosition(200.f, 100.f);

        bool timerstarted = false;
        initializeGrid();
        loadCandyTextures();
        Vector2i selectedPosition(-1, -1);
        RectangleShape highlightRectangle(Vector2f(46, 45));
        highlightRectangle.setOutlineThickness(2.f);
        highlightRectangle.setOutlineColor(Color::White);
        highlightRectangle.setFillColor(Color(150, 150, 150, 50));

        Clock clock;
       

        while (window.isOpen()) {
            sf::Event event;
            
           
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed) {
                    window.close();
                }

                if (event.type == Event::MouseButtonPressed) {
                    Vector2i localPos = Mouse::getPosition(window);

                    if (sprite2.getGlobalBounds().contains(localPos.x, localPos.y)) {
                        display = 2;

                    }

                    if (sprite4.getGlobalBounds().contains(localPos.x, localPos.y)) {
                        display = 3;
                    }
                    if (sprite8.getGlobalBounds().contains(localPos.x, localPos.y)) {
                        shufflecommand = true;
                    }


                    for (int i = 0; i < rows; ++i) {
                        for (int j = 0; j < columns; ++j) {
                            if (candySprites[i][j].getGlobalBounds().contains(static_cast<float>(localPos.x), static_cast<float>(localPos.y))) {
                                if (selectedPosition.x == -1 && selectedPosition.y == -1) {
                                    // First candy selected
                                    selectedPosition.x = i;
                                    selectedPosition.y = j;
                                }
                                else {
                                    // Second candy selected, swap them
                                   int temp = grid[i][j];
                                    grid[i][j] = grid[selectedPosition.x][selectedPosition.y];
                                    grid[selectedPosition.x][selectedPosition.y] = temp;

                                    // Update candy sprites
                                    candySprites[i][j].setTexture(candyTextures[grid[i][j]]);
                                    candySprites[selectedPosition.x][selectedPosition.y].setTexture(candyTextures[temp]);
                                    timer = 15;
                                    moves--;

                                    stringstream movesString;
                                    movesString << "Moves: " << moves;
                                    movesText.setString(movesString.str());

                                    stringstream TimerString;
                                    TimerString << "Timer: " << timer << "s";
                                    timerText.setString(TimerString.str());

                                    window.draw(timerText);
                                    window.draw(movesText);

                                    // Reset selected position
                                    selectedPosition.x = -1;
                                    selectedPosition.y = -1;
                                }
                            }
                        }
                    }
                }
            }

            window.clear();
           
            Time elapsed = clock.getElapsedTime();
            if (shufflecommand) {
                shuffleBoard(window);
                shufflecommand = false;
            }
            if (timerstarted && elapsed.asSeconds() >= 1.0f)
            {
                if (timer > 0)
                {
                    timer--;
                }
                else
                {
                    --moves;
                    timer = 15;
                }
                clock.restart();
            }

            if (display == 1) {
                window.draw(sprite);
                window.draw(sprite2);
                window.draw(sprite4);
            }
            else if (display == 2) {

                window.draw(sprite3);
                window.draw(sprite8);
                timerstarted = true;
                for (int i = 0; i < rows; ++i) {
                    for (int j = 0; j < columns; ++j) {
                        window.draw(candySprites[i][j]);
                        if (i == selectedPosition.x && j == selectedPosition.y) {
                            highlightRectangle.setPosition(j * cellSize, i * cellSize);
                            window.draw(highlightRectangle);
                        }
                        /*if (grid[i][j] == CandyType::SPECIAL) {
                            candySprites[i][j].setTexture(specialcandyTextures[0]);
                            grid[i][j]==CandyType::GREEN;
                        }*/

                    }
                }
                for (int i = 1; i < rows; ++i) {
                    for (int j = 1; j < columns; ++j) {
                        candySprites[i][j].setPosition((j * cellSize), i * cellSize);
                        window.draw(candySprites[i][j]);
                    }
                } 
                
              
                

                
                popping(score);
                

            }
           
            else if (display == 3) {
                window.draw(sprite5);
            }
           
           
            if (timerstarted) {
                stringstream scoreString;
                scoreString << "Score: " << score << "s";
                scoreText.setString(scoreString.str());
                stringstream TimerString;
                TimerString << "Timer: " << timer << "s";
                timerText.setString(TimerString.str());
                stringstream movesString;
                movesString << "Moves: " << moves;
                movesText.setString(movesString.str());
                window.draw(movesText);
                window.draw(timerText);
                window.draw(scoreText);
            }
            if (moves == 0)
            {
                window.clear();
                window.draw(sprite3);
                scoreText.setCharacterSize(100);
                stringstream scoreString;
                scoreString << "Score: " << score << "s";
                scoreText.setString(scoreString.str());
                scoreText.setPosition(200.f, 180.f);
                window.draw(finalText);
                window.draw(scoreText);



            }
            
            window.display();
        }

        system("pause");
        return 0;
    }
