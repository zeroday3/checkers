#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;

int board[8][8] =
	{0, -1, 0, -1, 0, -1, 0, -1,
	 -1, 0, -1, 0, -1, 0, -1, 0,
	 0, -1, 0, -1, 0, -1, 0, -1,
	 0, 0, 0, 0, 0, 0, 0, 0,
	 0, 0, 0, 0, 0, 0, 0, 0,
	 1, 0, 1, 0, 1, 0, 1, 0,
	 0, 1, 0, 1, 0, 1, 0, 1,
	 1, 0, 1, 0, 1, 0, 1, 0
	};


int main()
{
	RenderWindow window(VideoMode(453, 468), "The Checkers");
	
	Texture white;
	white.loadFromFile("images/white.png");

	Sprite s(white);

	bool isMove=false;
	float dx = 0, dy = 0;

	while (window.isOpen())
	{
		Vector2i pos = Mouse::getPosition(window);

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::MouseButtonPressed)
				if (event.key.code == Mouse::Left)
					if (s.getGlobalBounds().contains(pos.x,pos.y))
					{
						isMove = true;
						dx = pos.x - s.getPosition().x;
						dy = pos.y - s.getPosition().y;
					}
			if (event.type == Event::MouseButtonReleased)
				if (event.key.code == Mouse::Left)
					isMove=false;
		}

		if (isMove) s.setPosition(pos.x - dx, pos.y - dy);

		window.clear();
		window.draw(s);
		window.display();
	}

	return 0;
}
