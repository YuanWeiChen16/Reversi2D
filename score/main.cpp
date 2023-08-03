#include <iostream>
#include <string>
#include<vector>

#include <windows.h>
#include <mmsystem.h>
#pragma  comment(lib,"winmm.lib")

#include "Reversi.h"

#include "../include/SDL.h"
#include "../SDL2_image-2.0.3/include/SDL_image.h"
#include "../SDL2_ttf-2.0.14/include/SDL_ttf.h"
#include "../SDL2_mixer-2.0.2/include/SDL_mixer.h"
using namespace std;

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 800;

int battlecouent = 0;
vector <Reversi> gameloop;

int gamemode = 0;
int hackmode = 0;
int win = 0;

string number[10] = { "0","1", "2", "3", "4", "5", "6", "7", "8", "9" };

SDL_Surface* background = NULL;

SDL_Surface* test1 = NULL;
SDL_Surface* test2 = NULL;

SDL_Surface* word = NULL;

SDL_Texture * backimg = NULL;
SDL_Texture * bordimg = NULL;

SDL_Texture * img1 = NULL;
SDL_Texture * img2 = NULL;

SDL_Texture * red = NULL;
SDL_Texture * blue = NULL;
SDL_Texture * green = NULL;
SDL_Texture * black = NULL;

SDL_Texture * wordpvp = NULL;
SDL_Texture * wordpve = NULL;
SDL_Texture * wordexit = NULL;
SDL_Texture * wordnowinner = NULL;
SDL_Texture * wordblackwinner = NULL;
SDL_Texture * wordwhitewinner = NULL;
SDL_Texture * winner = NULL;
SDL_Texture * wordtital = NULL;


SDL_Texture * wordredo = NULL;
SDL_Texture * wordundo = NULL;
SDL_Texture * wordrestart = NULL;
SDL_Texture * wordnow = NULL;
SDL_Texture * wordhint = NULL;

SDL_Texture * wordbp = NULL;
SDL_Texture * wordwp = NULL;
SDL_Texture * wordmadebyme = NULL;

SDL_Texture * wordnum[10] = { NULL };

SDL_Texture * wordee[28] = { NULL };


SDL_Window* screen = NULL;
SDL_Surface* butten = NULL;

SDL_Event events;

SDL_Renderer * renderer = NULL;

SDL_Rect dstrect = { 0,0,0,0 };
SDL_Color textColor = { 255, 0, 255 };
TTF_Font *font = NULL;

class Button
{
private:

	SDL_Rect box;

	SDL_Texture* buttenimg;

public:

	Button(int x, int y, int w, int h);

	int handle_events();

	void show();
};


void clean_up(void);
void init(void);
void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination);
void display(Reversi board);
int boardpress(int, int, int, int);
int checkwin(void);


int main(int argc, char* argv[])
{
	init();

	PlaySound(TEXT("music.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	renderer = SDL_CreateRenderer(screen, -1, 0);
	backimg = SDL_CreateTextureFromSurface(renderer, background);
	SDL_RenderCopy(renderer, backimg, NULL, 0);


	img1 = SDL_CreateTextureFromSurface(renderer, test1);
	//dstrect = { 5, 5, 10,10 };
	//SDL_RenderCopy(renderer, texture, NULL, &dstrect);

	word = IMG_Load("e_frame_0001.jpg");
	wordee[0] = SDL_CreateTextureFromSurface(renderer, word);

	word = IMG_Load("e_frame_0002.jpg");
	wordee[1] = SDL_CreateTextureFromSurface(renderer, word);
	word = IMG_Load("e_frame_0003.jpg");
	wordee[2] = SDL_CreateTextureFromSurface(renderer, word);
	word = IMG_Load("e_frame_0004.jpg");
	wordee[3] = SDL_CreateTextureFromSurface(renderer, word);
	word = IMG_Load("e_frame_0005.jpg");
	wordee[4] = SDL_CreateTextureFromSurface(renderer, word);
	word = IMG_Load("e_frame_0006.jpg");
	wordee[5] = SDL_CreateTextureFromSurface(renderer, word);
	word = IMG_Load("e_frame_0007.jpg");
	wordee[6] = SDL_CreateTextureFromSurface(renderer, word);
	word = IMG_Load("e_frame_0008.jpg");
	wordee[7] = SDL_CreateTextureFromSurface(renderer, word);
	word = IMG_Load("e_frame_0009.jpg");
	wordee[8] = SDL_CreateTextureFromSurface(renderer, word);

	word = IMG_Load("e_frame_0010.jpg");
	wordee[9] = SDL_CreateTextureFromSurface(renderer, word);
	word = IMG_Load("e_frame_0011.jpg");
	wordee[10] = SDL_CreateTextureFromSurface(renderer, word);
	word = IMG_Load("e_frame_0012.jpg");
	wordee[11] = SDL_CreateTextureFromSurface(renderer, word);
	word = IMG_Load("e_frame_0013.jpg");
	wordee[12] = SDL_CreateTextureFromSurface(renderer, word);
	word = IMG_Load("e_frame_0014.jpg");
	wordee[13] = SDL_CreateTextureFromSurface(renderer, word);
	word = IMG_Load("e_frame_0015.jpg");
	wordee[14] = SDL_CreateTextureFromSurface(renderer, word);
	word = IMG_Load("e_frame_0016.jpg");
	wordee[15] = SDL_CreateTextureFromSurface(renderer, word);
	word = IMG_Load("e_frame_0017.jpg");
	wordee[16] = SDL_CreateTextureFromSurface(renderer, word);
	word = IMG_Load("e_frame_0018.jpg");
	wordee[17] = SDL_CreateTextureFromSurface(renderer, word);


	word = IMG_Load("e_frame_0019.jpg");
	wordee[18] = SDL_CreateTextureFromSurface(renderer, word);
	word = IMG_Load("e_frame_0020.jpg");
	wordee[19] = SDL_CreateTextureFromSurface(renderer, word);
	word = IMG_Load("e_frame_0021.jpg");
	wordee[20] = SDL_CreateTextureFromSurface(renderer, word);
	word = IMG_Load("e_frame_0022.jpg");
	wordee[21] = SDL_CreateTextureFromSurface(renderer, word);
	word = IMG_Load("e_frame_0023.jpg");
	wordee[22] = SDL_CreateTextureFromSurface(renderer, word);
	word = IMG_Load("e_frame_0024.jpg");
	wordee[23] = SDL_CreateTextureFromSurface(renderer, word);
	word = IMG_Load("e_frame_0025.jpg");
	wordee[24] = SDL_CreateTextureFromSurface(renderer, word);
	word = IMG_Load("e_frame_0026.jpg");
	wordee[25] = SDL_CreateTextureFromSurface(renderer, word);
	word = IMG_Load("e_frame_0027.jpg");
	wordee[26] = SDL_CreateTextureFromSurface(renderer, word);
	word = IMG_Load("e_frame_0028.jpg");
	wordee[27] = SDL_CreateTextureFromSurface(renderer, word);



	test1 = IMG_Load("bp.jpg");

	Uint32 colorkey = SDL_MapRGB(test1->format, 0xFF, 0, 0);
	SDL_SetColorKey(test1, 0, colorkey);

	wordbp = SDL_CreateTextureFromSurface(renderer, test1);

	test1 = IMG_Load("wp.jpg");
	wordwp = SDL_CreateTextureFromSurface(renderer, test1);


	word = TTF_RenderText_Solid(font, "-EVEN NO WINNER-", textColor);
	wordnowinner = SDL_CreateTextureFromSurface(renderer, word);


	word = TTF_RenderText_Solid(font, "-BLACK IS WINNER-", textColor);
	wordblackwinner = SDL_CreateTextureFromSurface(renderer, word);

	word = TTF_RenderText_Solid(font, "-WHITE IS WINNER-", textColor);
	wordwhitewinner = SDL_CreateTextureFromSurface(renderer, word);



	test1 = IMG_Load("black.png");
	black = SDL_CreateTextureFromSurface(renderer, test1);

	test1 = IMG_Load("winner.jpg");
	winner = SDL_CreateTextureFromSurface(renderer, test1);

	img2 = SDL_CreateTextureFromSurface(renderer, test2);
	//dstrect = { 100, 100, 200, 200 };
	//SDL_RenderCopy(renderer, texture, NULL, &dstrect);


	word = TTF_RenderText_Solid(font, "Player vs. Player", textColor);
	wordpvp = SDL_CreateTextureFromSurface(renderer, word);


	word = TTF_RenderText_Solid(font, "---REVERSI---", textColor);
	wordtital = SDL_CreateTextureFromSurface(renderer, word);


	word = TTF_RenderText_Solid(font, "Player vs. Computer", textColor);
	wordpve = SDL_CreateTextureFromSurface(renderer, word);

	word = TTF_RenderText_Solid(font, "Exit", textColor);
	wordexit = SDL_CreateTextureFromSurface(renderer, word);



	word = TTF_RenderText_Solid(font, "REDO", textColor);
	wordredo = SDL_CreateTextureFromSurface(renderer, word);

	word = TTF_RenderText_Solid(font, "UNDO", textColor);
	wordundo = SDL_CreateTextureFromSurface(renderer, word);

	word = TTF_RenderText_Solid(font, "RESTART", textColor);
	wordrestart = SDL_CreateTextureFromSurface(renderer, word);

	word = TTF_RenderText_Solid(font, "NOW:", textColor);
	wordnow = SDL_CreateTextureFromSurface(renderer, word);

	word = TTF_RenderText_Solid(font, "HINT", textColor);
	wordhint = SDL_CreateTextureFromSurface(renderer, word);

	word = TTF_RenderText_Solid(font, "Made by B10615016", textColor);
	wordmadebyme = SDL_CreateTextureFromSurface(renderer, word);

	for (int i = 0; i < 10; i++)
	{
		const char *cstr = number[i].c_str();
		word = TTF_RenderText_Solid(font, cstr, textColor);
		wordnum[i] = SDL_CreateTextureFromSurface(renderer, word);
	}

	word = IMG_Load("red.png");
	red = SDL_CreateTextureFromSurface(renderer, word);

	word = IMG_Load("blue.png");
	blue = SDL_CreateTextureFromSurface(renderer, word);

	word = IMG_Load("green.png");
	green = SDL_CreateTextureFromSurface(renderer, word);

	//顯示出來
	SDL_RenderPresent(renderer);

	Button pvpButton(395, 495, 210, 40);
	Button pveButton(370, 595, 260, 40);
	Button exitButton1(465, 695, 70, 40);

	Button nowButton(50, 200, 100, 40);
	Button undoButton(50, 300, 100, 40);
	Button redoButton(50, 400, 100, 40);
	Button hintButton(50, 500, 100, 40);
	Button restartButton(50, 600, 100, 40);
	Button exitButton2(50, 700, 100, 40);


	int cont = 0;
	int c = 0;
	bool quit = false;
	while (quit == false)
	{
		SDL_RenderCopy(renderer, backimg, NULL, 0);

		while (SDL_PollEvent(&events))
		{
			if (events.type == SDL_QUIT)
			{
				quit = true;
			}

			if (gamemode == 0)
			{
				if (pvpButton.handle_events() == 1)
				{
					gamemode = 1;
					break;
				}
				if (pveButton.handle_events() == 1)
				{
					gamemode = 2;
					break;
				}
				if (exitButton1.handle_events() == 1)
				{
					quit = true;
				}
			}
			if ((gamemode == 1) || (gamemode == 2))
			{

				int poiz = boardpress(300, 100, 75, 75);
				int chwin = checkwin();
				if (chwin == -1)
				{
					cout << "black fuck" << endl;
					
					break;
				}
				else if (chwin == -2)
				{
					cout << "white fuck" << endl;
				
					break;
				}

				if (chwin == 1)
				{
					win = 1;
					dstrect = { 400, 100, 400, 400 };
					SDL_RenderCopy(renderer, winner, NULL, &dstrect);
					dstrect = { 500, 150, 75, 75 };
					SDL_RenderCopy(renderer, wordbp, NULL, &dstrect);
					dstrect = { 400, 25, 400, 75 };
					SDL_RenderCopy(renderer, wordblackwinner, NULL, &dstrect);
				}
				else if (chwin == 2)
				{
					win = 2;
					dstrect = { 400, 100, 400, 400 };
					SDL_RenderCopy(renderer, winner, NULL, &dstrect);
					dstrect = { 500, 150, 75, 75 };
					SDL_RenderCopy(renderer, wordwp, NULL, &dstrect);
					dstrect = { 400, 25, 400, 75 };
					SDL_RenderCopy(renderer, wordwhitewinner, NULL, &dstrect);
				}
				else if (chwin == 100)
				{
					win = 100;
					dstrect = { 50, 50, 75, 75 };
					SDL_RenderCopy(renderer, wordnowinner, NULL, &dstrect);
				}

				if (poiz !=-1)
				{
					int hand = 1;
					if (battlecouent % 2 == 0)
					{
						hand = 1;
					}
					else if (battlecouent % 2 == 1)
					{
						hand = 2;
					}

					if (gameloop[battlecouent].board[poiz % 8 + 1][poiz / 8 + 1] == 0)
					{
						if (gameloop[battlecouent].CheckputPoint(poiz % 8 + 1, poiz / 8 + 1, hand, 0) != 0)
						{
							while (gameloop.size() > battlecouent + 1)
							{
								gameloop.pop_back();
							}
							gameloop.push_back(gameloop[battlecouent]);
							battlecouent = battlecouent + 1;
							gameloop[battlecouent].CheckputPoint(poiz % 8 + 1, poiz / 8 + 1, hand, 1);
							display(gameloop[battlecouent]);

							if (gamemode == 2)
							{
								int more = 0;
								int temp = 0;
								for (int i = 0; i < 8; i++)
								{
									for (int j = 0; j < 8; j++)
									{
										if (gameloop[battlecouent].board[i + 1][j + 1] == 0)
										{
											if (gameloop[battlecouent].CheckputPoint(i + 1, j + 1, 2, 0) > more)
											{
												temp = i + j * 8;
												more = gameloop[battlecouent].CheckputPoint(i + 1, j + 1, 2, 0);
											}
										}
									}
								}
								while (gameloop.size() > battlecouent + 1)
								{
									gameloop.pop_back();
								}
								gameloop.push_back(gameloop[battlecouent]);
								battlecouent = battlecouent + 1;
								gameloop[battlecouent].CheckputPoint(temp % 8 + 1, temp / 8 + 1, 2, 1);
							}

							display(gameloop[battlecouent]);
						}
					}

				}
				if (undoButton.handle_events() == 1)
				{
					for (int i = 0; i < gamemode; i++)
					{
						if (battlecouent != 0)
						{
							battlecouent = battlecouent - 1;
						}
					}
					win = 0;
					winner = 0;
				}

				if (redoButton.handle_events() == 1)
				{
					for (int i = 0; i < gamemode; i++)
					{
						if (gameloop.size() > (battlecouent + 1))
						{
							battlecouent = battlecouent + 1;
						}
					}
				}

				if (hintButton.handle_events() == 1)
				{
					int temp = 0;
					if (hackmode == 0)
					{
						temp = 1;
					}
					if (temp == 1)
					{
						hackmode = 1;
					}
					else
					{
						hackmode = 0;
					}
				}
				if (restartButton.handle_events() == 1)
				{
					battlecouent = 0;
					gameloop.clear();
					gameloop.push_back(Reversi());
					win = 0;
					winner = 0;
					hackmode = 0;
				}
				if (exitButton2.handle_events() == 1)
				{
					battlecouent = 0;
					gameloop.clear();
					gameloop.push_back(Reversi());
					hackmode = 0;
					gamemode = 0;
					win = 0;
					winner = 0;
				}
			}
		}

		if (gamemode == 0)
		{
			pvpButton.show();
			pveButton.show();
			exitButton1.show();
			dstrect = { 200, 50, 600, 90 };
			SDL_RenderCopy(renderer, wordtital, NULL, &dstrect);
			dstrect = { 400, 500, 200, 30 };
			SDL_RenderCopy(renderer, wordpvp, NULL, &dstrect);
			dstrect = { 375, 600, 250, 30 };
			SDL_RenderCopy(renderer, wordpve, NULL, &dstrect);
			dstrect = { 470, 700, 60, 30 };
			SDL_RenderCopy(renderer, wordexit, NULL, &dstrect);
			dstrect = { 50, 750, 200, 25 };
			SDL_RenderCopy(renderer, wordmadebyme, NULL, &dstrect);

			if (cont == 6)
			{
				c = c + 1;
				if (c == 28)
				{
					c = 0;
				}
				cont = 0;
			}
			cont = cont + 1;
			dstrect = { 900, 700, 70,70 };
			SDL_RenderCopy(renderer, wordee[c], NULL, &dstrect);

		}

		if ((gamemode == 1) || (gamemode == 2))
		{
			nowButton.show();
			undoButton.show();
			redoButton.show();
			hintButton.show();
			restartButton.show();
			exitButton2.show();
			dstrect = { 170, 190, 60, 60 };
			if (battlecouent % 2 == 0)
			{
				SDL_RenderCopy(renderer, wordbp, NULL, &dstrect);
			}
			else if (battlecouent % 2 == 1)
			{
				SDL_RenderCopy(renderer, wordwp, NULL, &dstrect);
			}
			int bc = 0;
			int wc = 0;
			wc = gameloop[battlecouent].TotalPoint(1);
			bc = gameloop[battlecouent].TotalPoint(2);

			dstrect = { 50, 50, 75, 75 };
			SDL_RenderCopy(renderer, wordbp, NULL, &dstrect);

			dstrect = { 150, 50, 75, 75 };
			SDL_RenderCopy(renderer, wordwp, NULL, &dstrect);

			dstrect = { 50, 130, 30, 60 };
			SDL_RenderCopy(renderer, wordnum[wc / 10], NULL, &dstrect);
			dstrect = { 80, 130, 30, 60 };
			SDL_RenderCopy(renderer, wordnum[wc % 10], NULL, &dstrect);
			dstrect = { 150, 130, 30, 60 };
			SDL_RenderCopy(renderer, wordnum[bc / 10], NULL, &dstrect);
			dstrect = { 180, 130, 30, 60 };
			SDL_RenderCopy(renderer, wordnum[bc % 10], NULL, &dstrect);

			dstrect = { 50, 200, 100, 40 };
			SDL_RenderCopy(renderer, wordnow, NULL, &dstrect);
			dstrect = { 50, 300, 100, 40 };
			SDL_RenderCopy(renderer, wordundo, NULL, &dstrect);
			dstrect = { 50, 400, 100, 40 };
			SDL_RenderCopy(renderer, wordredo, NULL, &dstrect);
			dstrect = { 50, 500, 100, 40 };
			SDL_RenderCopy(renderer, wordhint, NULL, &dstrect);
			dstrect = { 50, 600, 100, 40 };
			SDL_RenderCopy(renderer, wordrestart, NULL, &dstrect);
			dstrect = { 50, 700, 100, 40 };
			SDL_RenderCopy(renderer, wordexit, NULL, &dstrect);

			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					dstrect = { 300 + (i * 75), 100 + (j * 75), 74,74 };
					SDL_RenderCopy(renderer, img2, NULL, &dstrect);
				}
			}


			display(gameloop[battlecouent]);
			if (win == 1)
			{
				dstrect = { 400, 100, 400, 400 };
				SDL_RenderCopy(renderer, winner, NULL, &dstrect);
				dstrect = { 400, 25, 400, 75 };
				SDL_RenderCopy(renderer, wordblackwinner, NULL, &dstrect);
			}
			else if (win == 2)
			{
				dstrect = { 400, 100, 400, 400 };
				SDL_RenderCopy(renderer, winner, NULL, &dstrect);
				dstrect = { 400, 25, 400, 75 };
				SDL_RenderCopy(renderer, wordwhitewinner, NULL, &dstrect);
			}
			else if (win == 100)
			{
				dstrect = { 50, 50, 75, 75 };
				SDL_RenderCopy(renderer, wordnowinner, NULL, &dstrect);
			}
		}

		SDL_RenderPresent(renderer);
		SDL_Delay(8);
	}
	clean_up();

	return 0;
}
void init(void)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_JPG);
	TTF_Init();

	screen = SDL_CreateWindow("REVERSI", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	font = TTF_OpenFont("Asap-Regular-webfont.ttf", 100);

	background = IMG_Load("brain.jpg");
	test1 = IMG_Load("e.gif");
	test2 = IMG_Load("back2.jpg");


	gameloop.push_back(Reversi());
}
void clean_up(void)
{

	IMG_Quit();

	SDL_Quit();
}

void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination)
{
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	SDL_BlitSurface(source, NULL, destination, &offset);
}

int Button::handle_events()
{
	//The mouse offsets
	int x = 0, y = 0;

	//If the mouse moved
	if (events.type == SDL_MOUSEMOTION)
	{
		//Get the mouse offsets
		x = events.motion.x;
		y = events.motion.y;

		//If the mouse is over the button
		if ((x > box.x) && (x < box.x + box.w) && (y > box.y) && (y < box.y + box.h))
		{
			//Set the button sprite
			this->buttenimg = red;
			return 0;
		}
		//If not
		else
		{
			//Set the button sprite
			this->buttenimg = blue;
			return 0;
		}
	}
	//If a mouse button was pressed
	if (events.type == SDL_MOUSEBUTTONDOWN)
	{
		//If the left mouse button was pressed
		if (events.button.button == SDL_BUTTON_LEFT)
		{
			//Get the mouse offsets
			x = events.button.x;
			y = events.button.y;

			//If the mouse is over the button
			if ((x > box.x) && (x < box.x + box.w) && (y > box.y) && (y < box.y + box.h))
			{
				//Set the button sprite
				this->buttenimg = green;
				return 1;
			}
		}
	}
	//If a mouse button was released
	if (events.type == SDL_MOUSEBUTTONUP)
	{
		//If the left mouse button was released
		if (events.button.button == SDL_BUTTON_LEFT)
		{
			//Get the mouse offsets
			x = events.button.x;
			y = events.button.y;

			//If the mouse is over the button
			if ((x > box.x) && (x < box.x + box.w) && (y > box.y) && (y < box.y + box.h))
			{
				//Set the button sprite
				this->buttenimg = red;
				return 0;
			}
		}
	}
	return 0;
}


Button::Button(int x, int y, int w, int h)
{
	//Set the button's attributes
	box.x = x;
	box.y = y;
	box.w = w;
	box.h = h;
	//Set the default sprite
	buttenimg = red;
}

void Button::show()
{
	//Show the button
	dstrect = { box.x, box.y, box.w, box.h };
	SDL_RenderCopy(renderer, buttenimg, NULL, &dstrect);
}

int boardpress(int bx, int by, int w, int h)
{

	if (events.type == SDL_MOUSEBUTTONDOWN)
	{
		int x;
		int y;
		//If the left mouse button was pressed
		if (events.button.button == SDL_BUTTON_LEFT)
		{
			//Get the mouse offsets
			x = events.button.x;
			y = events.button.y;
			x = x - 300;
			y = y - 100;
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if ((x > (i * w)) && (x < (i * w + w)) && (y > (j * h)) && (y < (j * h + h)))
					{
						cout << i << " " << j << endl;
						return (i + j * 8);
					}
				}
			}
		}
	}
	return -1;
}

void display(Reversi board)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i + 1][j + 1] == 1)
			{
				dstrect = { 300 + i * 75, 100 + j * 75, 75,75 };
				SDL_RenderCopy(renderer, wordbp, NULL, &dstrect);
			}
			if (board.board[i + 1][j + 1] == 2)
			{
				dstrect = { 300 + i * 75 + 1, 100 + j * 75 + 1, 73,73 };
				SDL_RenderCopy(renderer, wordwp, NULL, &dstrect);
			}
			else if ((board.board[i + 1][j + 1] == 0) && (hackmode == 1))
			{
				int temp = board.CheckputPoint(i + 1, j + 1, battlecouent % 2 + 1, 0);
				if (temp > 0)
				{
					dstrect = { 300 + i * 75, 100 + j * 75, 37, 75 };
					SDL_RenderCopy(renderer, wordnum[temp / 10], NULL, &dstrect);
					dstrect = { 300 + i * 75 + 37, 100 + j * 75, 37, 75 };
					SDL_RenderCopy(renderer, wordnum[temp % 10], NULL, &dstrect);
				}
			}
		}
	}
}

int checkwin(void)
{
	int	Bcanput = 0;
	int	Wcanput = 0;
	for (int i = 1; i < 9; i++)
	{
		for (int j = 1; j < 9; j++)
		{
			if (gameloop[battlecouent].board[i][j] == 0)
			{
				Wcanput = Wcanput + gameloop[battlecouent].CheckputPoint(i, j, 1, 0);
				Bcanput = Bcanput + gameloop[battlecouent].CheckputPoint(i, j, 2, 0);
			}
		}
	}
	if ((Wcanput == 0) && (Bcanput == 0))
	{
		cout << endl;
		if (gameloop[battlecouent].TotalPoint(1) > gameloop[battlecouent].TotalPoint(2))
		{
			return 1;
		}
		else if (gameloop[battlecouent].TotalPoint(1) < gameloop[battlecouent].TotalPoint(2))
		{
			return 2;
		}
		else
		{
			return 100;
		}
	}
	else if ((battlecouent % 2 == 0) && (Wcanput == 0) && (Bcanput != 0))
	{
		return -1;
	}
	else if ((battlecouent % 2 == 1) && (Bcanput == 0) && (Wcanput != 0))
	{
		return -2;
	}
	return 0;
}
