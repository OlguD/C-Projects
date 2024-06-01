#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <math.h>
#include <settings.h>



void throwBall(int h, float gravity, SDL_Renderer *renderer, TTF_Font *font);

int main() {
    const float g = 9.8;  // Gerçek hayatta yerçekimi ivmesi
    int height = 10;  // Topun başlangıç yüksekliği (ekranın en üstünden 10 piksel aşağıda)
    // int mass = 5;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    if (TTF_Init() != 0) {
        printf("TTF_Init Error: %s\n", TTF_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Window *win = SDL_CreateWindow("Bouncing Ball", 100, 100, 940, 580, SDL_WINDOW_SHOWN);
    if (win == NULL) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        TTF_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        SDL_DestroyWindow(win);
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_Quit();
        TTF_Quit();
        return 1;
    }

    TTF_Font *font = TTF_OpenFont("/System/Library/Fonts/Supplemental/Arial.ttf", 20); // Font dosya yolunu doğru ayarladığınızdan emin olun
    if (font == NULL) {
        printf("TTF_OpenFont Error: %s\n", TTF_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(win);
        SDL_Quit();
        TTF_Quit();
        return 1;
    }

    throwBall(height, g, renderer, font);

    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win); SDL_Quit();
    TTF_Quit();
    return 0;
}

void throwBall(int h, float gravity, SDL_Renderer *renderer, TTF_Font *font) {
    float initialY = h;
    float time = 0.0;
    float Y;
    float velocity = 0.0;
    int running = 1;
    SDL_Event event;

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;

    char buffer[128];
    SDL_Color textColor = {255, 255, 255, 255};
    SDL_Color bgColor = {50, 50, 50, 255};

    while (running) {
        frameStart = SDL_GetTicks();

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }

        // Zamanla artan hız ile topun yüksekliğini hesaplayalım
        Y = initialY + velocity * time + (0.5 * gravity * pow(time, 2));
        velocity += gravity * time;
        if (Y >= 580) {
            Y = 580;
            running = 0;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Topu çiz
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_Rect ball = {460 - 10, (int)(Y - 10), 20, 20};
        SDL_RenderFillRect(renderer, &ball);

        // Bilgileri çiz
        snprintf(buffer, sizeof(buffer), "Zaman: %.2f s\nYukseklik: %.2f px\nHiz: %.2f px/s", time, Y, velocity);
        //SDL_Surface *surfaceMessage1 = TTF_RenderText_Shaded(font, "Zaman: %.2f s", textColor, bgColor);
        //SDL_Surface *surfaceMessage2 = TTF_RenderText_Shaded(font, "Yukseklik: %.2f px", textColor, bgColor);
        //SDL_Surface *surfaceMessage3 = TTF_RenderText_Shaded(font, "Hiz: %.2f px/s", textColor, bgColor);
        SDL_Surface *surfaceMessage = TTF_RenderText_Shaded(font, buffer, textColor, bgColor);
        SDL_Texture *Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

        SDL_Rect Message_rect; // Sağ üst köşede göstermek için
        Message_rect.x = 530;  // X koordinatı
        Message_rect.y = 10;   // Y koordinatı
        Message_rect.w = surfaceMessage->w;
        Message_rect.h = surfaceMessage->h;

        SDL_RenderCopy(renderer, Message, NULL, &Message_rect);

        SDL_FreeSurface(surfaceMessage);
        SDL_DestroyTexture(Message);

        SDL_RenderPresent(renderer);

        time += 1.0 / FPS;

        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }
}

