#pragma once
#include "Variables.h"

void gameModeActivate();

class MainMenuClass
{

	
	void setText(string txtofButton1,string txtofButton2, string txtofButton3,string txtofButton4)
	{
		int CharSize = 30;
		StartButtonsFont.loadFromFile("Montserrat-Regular.ttf");
		
		menuStartText.setCharacterSize(CharSize);
		menuStartText.setFillColor(sf::Color::Red);
		menuStartText.setOrigin(35, 11);
		menuStartText.setPosition(WindowWidth/2,WindowHeight/2-80);
		menuStartText.setString(txtofButton1);
		menuStartText.setFont(StartButtonsFont);


		levelText.setCharacterSize(CharSize);
		levelText.setFillColor(sf::Color::Red);
		levelText.setPosition(WindowWidth / 2, WindowHeight / 2-40);
		levelText.setOrigin(43, 11);
		levelText.setString(txtofButton2);
		levelText.setFont(StartButtonsFont);

		mapText.setCharacterSize(CharSize);
		mapText.setFillColor(sf::Color::Red);
		mapText.setOrigin(38, 11);
		mapText.setPosition(WindowWidth / 2, WindowHeight / 2);
		mapText.setString(txtofButton3);
		mapText.setFont(StartButtonsFont);
		
		exitText.setCharacterSize(CharSize);
		exitText.setFillColor(sf::Color::Red);
		exitText.setPosition(WindowWidth / 2 , WindowHeight / 2 +40);
		exitText.setString(txtofButton4);
		exitText.setOrigin(27, 11);
		exitText.setFont(StartButtonsFont);

	}

	
	float MenuBcWidth = 400;
	float MenuBcHeight = 500;

	float pointerwidth = 110;
	float pointerheight = 15;


	void setMenuSettingsBackGround()
	{
		

		menuSettingsBackGround.setSize(sf::Vector2f(MenuBcWidth, MenuBcHeight));
		menuSettingsBackGround.setPosition(WindowWidth / 2, WindowHeight / 2);
		menuSettingsBackGround.setOrigin(MenuBcWidth/2,MenuBcHeight/2);
		menuSettingsBackGround.setFillColor(sf::Color::Blue);

		pointerRectangle1.setFillColor(sf::Color::Green);
		pointerRectangle1.setSize(sf::Vector2f(pointerwidth,pointerheight));
		pointerRectangle1.setOrigin(pointerwidth/2,pointerheight/2);
		pointerRectangle1.setPosition(WindowWidth / 2 -MenuBcWidth/2+pointerwidth/2, WindowHeight/2 -70);

		pointerRectangle2.setFillColor(sf::Color::Green);
		pointerRectangle2.setSize(sf::Vector2f(pointerwidth, pointerheight));
		pointerRectangle2.setOrigin(pointerwidth / 2, pointerheight / 2);
		pointerRectangle2.setPosition(WindowWidth / 2 + MenuBcWidth / 2 - pointerwidth / 2, WindowHeight / 2-70);


	}
	
	
	int position = 1;
	
	
	
	void menuTrack()
	{
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) 
			downKeyPressed = true;
			
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			downKeyPressed = false;
		


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) 
			upKeyPressed = true;
		
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) 
			upKeyPressed = false;
		


		if (downKeyPressed) 
		{
			if (!incremented) 
			{
				incremented = true;
				position++;
			}
		}
		else 
		{
			incremented		= false;
			downKeyPressed  = false;
				
		}

		if(upKeyPressed)
		{
			if (!dicrimented) 
			{
				dicrimented = true;
				position--;
			}
		}
		else
		{
			dicrimented = false;
			upKeyPressed = false;
		}

		if (position > 4) position = 1;
		if (position < 1) position = 4;
		

		

		switch (position)
		{
		case 1:
			pointerRectangle1.setPosition(WindowWidth / 2 - MenuBcWidth / 2 + pointerwidth / 2, WindowHeight / 2-70);
			pointerRectangle2.setPosition(WindowWidth / 2 + MenuBcWidth / 2 - pointerwidth / 2, WindowHeight / 2-70);
			break;
		case 2:
			pointerRectangle1.setPosition(WindowWidth / 2 - MenuBcWidth / 2 + pointerwidth / 2, WindowHeight / 2-30);
			pointerRectangle2.setPosition(WindowWidth / 2 + MenuBcWidth / 2 - pointerwidth / 2, WindowHeight / 2-30);
			break;
		case 3:
			pointerRectangle1.setPosition(WindowWidth / 2 - MenuBcWidth / 2 + pointerwidth / 2, WindowHeight / 2+10);
			pointerRectangle2.setPosition(WindowWidth / 2 + MenuBcWidth / 2 - pointerwidth / 2, WindowHeight / 2+10);
			break;

		case 4:
			pointerRectangle1.setPosition(WindowWidth / 2 - MenuBcWidth / 2 + pointerwidth / 2, WindowHeight / 2 + 50);
			pointerRectangle2.setPosition(WindowWidth / 2 + MenuBcWidth / 2 - pointerwidth / 2, WindowHeight / 2 + 50);
			break;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && position==1)
		{
			gameModeActivate();
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && position==4)
		{
			exit(1);
		}
		
		

	}






	public:
	void activate()
	{
		setText("Start", "Levels", "Maps", "Exit");
		setMenuSettingsBackGround();
		
		while (1) 
		{
			

			
			userExit();
			menuTrack();




			MainWindow.clear();
			MainWindow.draw(BackGround);
			MainWindow.draw(menuSettingsBackGround);
			MainWindow.draw(pointerRectangle1);
			MainWindow.draw(pointerRectangle2);
			MainWindow.draw(menuStartText);
			MainWindow.draw(levelText);
			MainWindow.draw(mapText);
			MainWindow.draw(exitText);

			if (!firstEnter) 
				MainWindow.draw(pauseText);
			


			MainWindow.display();
			
		}
	}


};




	void gameModeActivate()
	{

		firstEnter = false;
		while (1)
		{
			tp2 = chrono::system_clock::now();
			chrono::duration<float> elapsedTime = tp2 - tp1;
			tp1 = tp2;
			float fElapsedTime = elapsedTime.count();

			GameLogic thisGmae;
			thisGmae.startLogic(fElapsedTime);


			MainWindow.clear();
			MainWindow.draw(BackGround);
			MainWindow.draw(ball);
			MainWindow.draw(LeftPlayer);
			MainWindow.draw(RightPlayer);
			MainWindow.draw(Lscore);
			MainWindow.draw(Rscore);

			MainWindow.display();

			

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				MainMenuClass mainMenu;
				mainMenu.activate();
			}

		}
	}
