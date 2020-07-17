/*
 	Almost all variables of the programm have been placed in
    one separate file
*/



#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <chrono>
#include <Windows.h>
using namespace std;


float WindowWidth = 1000;							//Width of window
float WindowHeight = 600;							//Height of window



//Texture for background image 
sf::Texture Bctexture;


// Sounds
//defining sound when ball hits the wall 
sf::SoundBuffer Sound;
sf::Sound       HitSound;


//Intro sound-gong
sf::SoundBuffer IntroSound;
sf::Sound       Gong;

//BackgroundMusic
sf::Music BackGroundMusic;

//Texts that are placed into the window
sf::Text Lscore;
sf::Text Rscore;


//All the fonts of the game
sf::Font BasicFont;
sf::Font StartButtonsFont;


//Speed of the ball, in pixels
float x = 400, y = 400;


//initial Speed of the boundries is 0
float RBoderViolocity = 0;
float LBoderViolocity = 0;


//Initial players scores value
//The values are 48 because it is 0 in ASCII
int Lpscore = 48;
int Rpscore = 48;




//SFML objects variables
sf::RenderWindow   MainWindow(sf::VideoMode(WindowWidth, WindowHeight), "Gamee");
sf::RectangleShape BackGround(sf::Vector2f(WindowWidth, WindowHeight));		//Creating Background
sf::RectangleShape LeftPlayer;												//Creaitng left border
sf::RectangleShape RightPlayer;												//Creaitng right border
sf::CircleShape    ball;


//booleans for recognizing key press
bool downKeyPressed  = false;
bool upKeyPressed	 = false;

//Every menu has a number,this variable stores the number of the menu when
//one of the menu is selected 
int  menuSelected;


//Rectangles that make the background of menu
// and rectangles of pointers in both side of the 
//menu options
sf::RectangleShape pointerRectangle1;
sf::RectangleShape pointerRectangle2;
sf::RectangleShape menuSettingsBackGround;


//All the textes of the menu options 
//pause text
sf::Text levelText;
sf::Text menuStartText;
sf::Text mapText;
sf::Text exitText;
sf::Text pauseText;


//boole
bool firstEnter = true;


//starting the clock, for calculating the FPS
auto tp1 = chrono::system_clock::now();
auto tp2 = chrono::system_clock::now();

bool incremented = false;
bool dicrimented = false;