
/*
	This file is for the logic(physics) of the game 
*/


#pragma once
#include "Variables.h"


//All the code is in the class
class GameLogic {



	//this function is responsible for colision detection
	//particularly for Right border of the window
	void IfHitRightBoder()
	{
		if (ball.getPosition().y+30 > RightPlayer.getPosition().y - 100.0f && ball.getPosition().y-30 < RightPlayer.getPosition().y + 100.0f)
		{
			if ((int)ball.getPosition().x + 30 == (int)WindowWidth - 10)
			{
				x = -x;
				x += abs(RBoderViolocity);
				ball.setFillColor(sf::Color::Blue);
				HitSound.play();
			}
		}

	}

	void BottomBorder()
	{
		if ((int)ball.getPosition().y == WindowHeight - 30)
		{
			y = -y;

		}
	}



	void IfHitLeftBoder()
	{
		if (ball.getPosition().y+30 > LeftPlayer.getPosition().y - 100 && ball.getPosition().y-30 < LeftPlayer.getPosition().y + 100)
		{
			if ((int)ball.getPosition().x - 30 == 10)
			{
				x = -x;
				x += abs(LBoderViolocity);
				ball.setFillColor(sf::Color::Red);
				HitSound.play();
			}
		}
	}

	void TopBorder()
	{
		
		if ((int)ball.getPosition().y == 30)
		{
			y = -y;
		}
	}



	//This function moves the ball,
	//during the game cycle
	void MoveBall(float SPF)
	{
		ball.move(x * SPF, y * SPF);
	}



	//this function tracs the user input
	//
	void UserInputTracking(float SPF)
	{
		//if W was pressed reduce the speed
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			LBoderViolocity -= 10 * SPF;
		}
		//if s was pressed increase the speed
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			LBoderViolocity += 10 * SPF;
		}
		//
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
		{
			RBoderViolocity -= 10 * SPF;
		}
		//
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
		{
			RBoderViolocity += 10 * SPF;
		}

		//Boders are going to be in constant move 
		LeftPlayer.move(0, LBoderViolocity);
		RightPlayer.move(0, RBoderViolocity);


		//checking if players are in the window
		if (((int)LeftPlayer.getPosition().y + 100 > WindowHeight) || ((int)LeftPlayer.getPosition().y - 100 < 0))
		{
			LBoderViolocity = 0;
		}

		if ((int)RightPlayer.getPosition().y + 100 > WindowHeight || ((int)RightPlayer.getPosition().y - 100 < 0))
		{
			RBoderViolocity = 0;
		}

		//Stopping borders
		if (LBoderViolocity < 0)
		{
			LBoderViolocity += 6 * SPF;
		}
		if (LBoderViolocity > 0)
		{
			LBoderViolocity -= 6 * SPF;
		}
		if (RBoderViolocity < 0)
		{
			RBoderViolocity += 6 * SPF;
		}
		if (RBoderViolocity > 0)
		{
			RBoderViolocity -= 6 * SPF;
		}

	}



	
	void Scores()
	{

		if (ball.getPosition().x > WindowWidth+300)
		{

			ball.setPosition(WindowWidth / 2, WindowHeight / 8);

			Lpscore++;
			Lscore.setString((char)Lpscore);
			ball.setFillColor(sf::Color::Red);
		}

		if (ball.getPosition().x < -300)
		{

			ball.setPosition(WindowWidth / 2, WindowHeight / 8);

			 Rpscore++;
			 Rscore.setString((char)Rpscore);
			 ball.setFillColor(sf::Color::Blue);


		}
	}
	public:
	void startLogic(float SPF)
	{
		IfHitLeftBoder();
		IfHitRightBoder();
		BottomBorder();
		TopBorder();
		MoveBall(SPF);
		UserInputTracking(SPF);
		Scores();
	}
	

};



