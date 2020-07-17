
/*
		The programm have been devided into 6files ,
	this should help me to modify the game and add 
	new features if needed and also should make code
	more readable and easy to work on programm in   
	future


*/


#include "Variables.h"
#include "Elements.h"
#include "Logic.h"
#include "Music.h"
#include "Display.h"
#include "Menu.h"
using namespace std;




int main()
{
	
	//should get rid of console
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);
	
	
	
	
	//	placing all elements ,
	//	defining their positions ,colors,origins and other characteristics 
	setBorderProps(LeftPlayer,10.f,200.f,5.f,100.f,5.f, WindowHeight / 2,sf::Color::Red);
	setBorderProps(RightPlayer, 10.f, 200.f, 5.f, 100.f, WindowWidth - 5.0f,WindowHeight/2,sf::Color::Blue);
	setBallProperties(30.0f, WindowWidth / 2, WindowHeight / 8);
	setText();
	setStartText();
	setRoundText();
	setFont();
	setBackGroundTexture();
	


	//Loading music
	//Playing background music and the gong
	loadMusic();
	backGroundMusicPlay();
	gongPlay();


	//creating instance of menu class
	//and activating the main menu
	MainMenuClass mainMenu;
	mainMenu.activate();
		
		
	
	
	

}






