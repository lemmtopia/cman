#include <SDL2/SDL.h>
#include <stdio.h>

SDL_Window* window;
SDL_Renderer* renderer;
int running;

void initalizePlatform()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) 
	{
		printf("%s", SDL_GetError());
	}

	window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 360, 0);

	if (window == NULL)
	{
		printf("%s", SDL_GetError());
	}
	
	renderer = SDL_CreateRenderer(window, -1, 0);

	if (window == NULL)
	{
		printf("%s", SDL_GetError());
	}

	running = 1;
}

void platformLoop()
{
	SDL_Event ev;
	
	if (SDL_PollEvent(&ev))
	{
		if (ev.type == SDL_QUIT)
		{
			running = 0;
		}
	}

	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

int main(void)
{
	initalizePlatform();

	while (running)
	{
		platformLoop();
		SDL_Delay(1000 / 60);
	}

	SDL_Quit();
	return 0;
}
