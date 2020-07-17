#pragma once
#include "Variables.h"

void loadMusic()
{
	BackGroundMusic.openFromFile("Superiority - AShamaluevMusic.wav");
	BackGroundMusic.setPlayingOffset(sf::seconds(48.f));
	BackGroundMusic.setVolume(25.0f);
	Gong.setVolume(25.0f);
	HitSound.setVolume(25.0f);

	//Initial sound Gong
	IntroSound.loadFromFile("Metal_Gong-Dianakc-109711828.wav");
	Gong.setBuffer(IntroSound);


	//Hit sound 
	Sound.loadFromFile("HitSound.wav");
	HitSound.setBuffer(Sound);

}

void backGroundMusicPlay()
{
	BackGroundMusic.play();
}

void gongPlay()
{
	Gong.play();
}
