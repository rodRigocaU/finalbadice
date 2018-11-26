#include "Enemigo.h"
#include <SFML/Graphics.hpp>
#include "Objeto.h"
#include "stdlib.h"
#include "time.h"

Enemigo::Enemigo(sf::Sprite &s,int x, int y){

    this->s = s;
    posx = x;
    posy = y;
}

void Enemigo::redifine()
{
    int x  = (rand() % 14 + 1)*50;
    int y = (rand() % 14 + 1)*50;
    posfx = x;
    posfy = y;
}
void Enemigo::Draw(int m[15][15],int xo,int yo,sf::RenderWindow &app){

    mov = ruta[rand() % 9];
    redifine();
    if(llegada == false)
    {if(mov == "Up")
    {
        if(posy == 14*50 - 25)
        {
            posy -= 5;
        }
        else
        {
            posy += 1;
        }

    }
    if(mov == "Down")
    {
        if(posy == 0)
        {
            posy += 5;
        }
        else
        {
            posy -= 1;
        }

    }
    if(mov == "Right")
    {
        if(posx == 14*50)
        {
            posx -= 5;
        }
        else
        {
            posx += 1;
        }

    }
    if(mov == "Left")
    {
        if(posx == 0)
        {
            posx += 5;
        }
        else
        {
            posx -= 1;
        }

    }
    }
    if(posx == posfx && posy == posfy)
    {
        Llegada();
    }
    if(llegada == true)
    {
        redifine();
        llegada == false;
    }
    s.setPosition(posx,posy);
    app.draw(s);
}

int Enemigo::getposx()
{
    return posx;
}

int Enemigo::getposy()
{
    return posy;
}


void Enemigo::Llegada()
{
    llegada = true;
}
