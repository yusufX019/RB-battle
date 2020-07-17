#include "Variables.h"




void setBorderProps(sf::RectangleShape &border,float width,float height, float originX, float originY, float positionX, float positionY,sf::Color color) 
	{
		border.setSize(sf::Vector2f(width, height));
		border.setOrigin(originX, originY);
		border.setPosition(positionX, positionY);
		border.setFillColor(color);
	
	}

void setBallProperties(float Radius, float x, float y)
	{
		ball.setRadius(Radius);
		ball.setOrigin(Radius, Radius);
		ball.setPosition(x, y);
	}
	
void setText()
{
	int CharSize = 50;

	Lscore.setFont(BasicFont);
	Rscore.setFont(BasicFont);

	Lscore.setCharacterSize(CharSize);
	Rscore.setCharacterSize(CharSize);

	Lscore.setPosition(WindowWidth / 2 - CharSize, 30);
	Rscore.setPosition(WindowWidth / 2 + CharSize, 30);

	Lscore.setFillColor(sf::Color::Red);
	Rscore.setFillColor(sf::Color::Blue);


	Rscore.setString((char)Rpscore);
	Lscore.setString((char)Lpscore);


	pauseText.setString("Pause");
	pauseText.setOrigin(132/2,22);
	pauseText.setCharacterSize(CharSize);
	pauseText.setFont(BasicFont);
	pauseText.setFillColor(sf::Color::Green);
	pauseText.setPosition(WindowWidth/2,WindowHeight/2-200);
}





void userExit()
{
	sf::Event MainEvent;
	while (MainWindow.pollEvent(MainEvent)) if (MainEvent.type == sf::Event::Closed) MainWindow.close();
}




void setFont()
{
	//font
	BasicFont.loadFromFile("mexcellent rg.ttf");
}

void setBackGroundTexture()
{
	//textures
	Bctexture.loadFromFile("Bc.jpg");
	BackGround.setTexture(&Bctexture);
}



