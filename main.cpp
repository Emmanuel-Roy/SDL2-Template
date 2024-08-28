#include <iostream>
#include <SDL2/SDL.h>
#include <windows.h>

using namespace std;

//Function Declarations
void DisplayOut(SDL_Renderer *renderer, int scalefactor, int WIDTH, int HEIGHT);

//System Globals.
int EmulatedDisplay[160][144];



int main(int argc, char *argv[]) 
{
	int IntegerScaleFactor = 10; //If you change the scale factor, remember to change the textures as well
    //This scale factor system enables users to implement whatever resolution requirements they have.
    cout << "Please enter the scale factor for the Chip-8 System." << endl << "Common Scale Factors are 10x for 640x320, 20x for 1280x640, 30x for 1920x960, 40x for 2560x1280, and 60x for 3840x1920." << endl << "Please note that this is what determines pixel size." << endl;
    cin >> IntegerScaleFactor;

    while (IntegerScaleFactor < 1) {
        cout << "Please enter a valid number greater than zero." << endl;
        cin >> IntegerScaleFactor;
    }
	int WIDTH = 160, HEIGHT = 144;
    
	WIDTH *= IntegerScaleFactor;
    HEIGHT *= IntegerScaleFactor;

    //SDL initilization and window + Renderer creation
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow("SDL Template", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    //Randomize Pixels for testing purposes, remove from main after the cpu can update the display on its own.
    for (int i = 0; i < 160; i++) {
        for (int j = 0; j < 144; j++) {
            //insert code here for updating tile map;
            EmulatedDisplay[i][j] = (rand() % 2); //Returns either case 0 or 1.
        }
    }
    

    //Populate Screen with a rectange per pixel based on scale factor
    DisplayOut(renderer, IntegerScaleFactor, WIDTH, HEIGHT);

    //Poll for exit event, check if application needs to be closed
    SDL_Event event;
    while (true) {
        if (SDL_PollEvent(&event)) {
            if (SDL_QUIT == event.type) {
                break;
            }
            else if (SDL_KEYDOWN  == event.type) {
                SDL_RenderClear(renderer);
                if(SDLK_a == event.key.keysym.sym) {
                    //Randomize Pixels for testing purposes, remove from main after the cpu can update the display on its own.
                    for (int i = 0; i < 160; i++) {
                        for (int j = 0; j < 144; j++) {
                            //insert code here for updating tile map;
                            EmulatedDisplay[i][j] = (rand() % 2); //Returns either case 0 or 1.
                        }
                    }
                }
                else if(SDLK_s == event.key.keysym.sym) {
                    //Randomize Pixels for testing purposes, remove from main after the cpu can update the display on its own.
                    for (int i = 0; i < 160; i++) {
                        for (int j = 0; j < 144; j++) {
                            //insert code here for updating tile map;
                            EmulatedDisplay[i][j] = (rand() % 2); //Returns either case 0 or 1.
                        }
                    }
                }
                else if(SDLK_d == event.key.keysym.sym) {
                    //Randomize Pixels for testing purposes, remove from main after the cpu can update the display on its own.
                    for (int i = 0; i < 160; i++) {
                        for (int j = 0; j < 144; j++) {
                            //insert code here for updating tile map;
                            EmulatedDisplay[i][j] = (rand() % 2); //Returns either case 0 or 1.
                        }
                    }
                }
                DisplayOut(renderer, IntegerScaleFactor, WIDTH, HEIGHT);
            }

            else if (SDL_KEYUP == event.type) {
                SDL_RenderClear(renderer);
                if(SDLK_a == event.key.keysym.sym) {
                    //Randomize Pixels for testing purposes, remove from main after the cpu can update the display on its own.
                    for (int i = 0; i < 160; i++) {
                        for (int j = 0; j < 144; j++) {
                            //insert code here for updating tile map;
                            EmulatedDisplay[i][j] = (rand() % 2); //Returns either case 0 or 1.
                        }
                    }
                }
                else if(SDLK_s == event.key.keysym.sym) {
                    //Randomize Pixels for testing purposes, remove from main after the cpu can update the display on its own.
                    for (int i = 0; i < 160; i++) {
                        for (int j = 0; j < 144; j++) {
                            //insert code here for updating tile map;
                            EmulatedDisplay[i][j] = (rand() % 2); //Returns either case 0 or 1.
                        }
                    }
                }
                else if(SDLK_d == event.key.keysym.sym) {
                    //Randomize Pixels for testing purposes, remove from main after the cpu can update the display on its own.
                    for (int i = 0; i < 160; i++) {
                        for (int j = 0; j < 144; j++) {
                            //insert code here for updating tile map;
                            EmulatedDisplay[i][j] = (rand() % 2); //Returns either case 0 or 1.
                        }
                    }
                }
                DisplayOut(renderer, IntegerScaleFactor, WIDTH, HEIGHT);
            }
        }
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
};

void DisplayOut(SDL_Renderer *renderer, int scalefactor, int WIDTH, int HEIGHT) {
    //Reset rendered image, so that the new frame doesn't overlap the old one;
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); //accepts R, G, B, A in that order
    SDL_RenderClear(renderer);

    SDL_Rect DisplayOut[160][144];
    for (int a = 0; a < 160; a++) {
        for (int b = 0; b < 144; b++) {
            DisplayOut[a][b].x = a * scalefactor; 
            DisplayOut[a][b].y = b * scalefactor;
            DisplayOut[a][b].w = scalefactor;
            DisplayOut[a][b].h = scalefactor;
        }
    }

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); //accepts R, G, B, A in that order
    //Render each tile
    for (int x = 0; x < 160; x++) {
        for (int y = 0; y < 144; y++) {
            switch (EmulatedDisplay[x][y]) {
                case 0:
                        break;
                case 1:
                        SDL_RenderFillRect(renderer, &DisplayOut[x][y]);
                        break;
            }
        }
    }
    SDL_RenderPresent(renderer);
    return;
}
