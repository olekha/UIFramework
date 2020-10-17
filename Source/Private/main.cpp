// RayTracingInAWeekend.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Public/UFTextLabel.h"
#include "Public/UFImage.h"

const int ScreenSizeX = 800;
const int ScreenSizeY = 600;

int main()
{
   sf::RenderWindow window(sf::VideoMode(ScreenSizeX, ScreenSizeY), "NewWindow");

   sf::RenderTexture MainCanvas;
   if (!MainCanvas.create(800, 600))
	   return -1;

   /* UFTextLabel Widget("Hello World!!!");
	Widget.SetColor(sf::Color::Red);

	Widget.SetPosition(UFVector2Df(10, 10));*/

    UFTexture Texture;
    Texture.loadFromFile("Content/Textures/duck.png");

    UFImage Image(&Texture);
    Image.SetScale(UFVector2Df(0.2f, 0.2f));

    while (window.isOpen())
    {
        MainCanvas.clear(sf::Color::Black);

        Image.Draw(MainCanvas);
        //MainCanvas.draw(Text);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(); 
        

        MainCanvas.display();
        sf::Sprite sprite(MainCanvas.getTexture());
        window.draw(sprite);

        window.display();
    }

    return 0;
}