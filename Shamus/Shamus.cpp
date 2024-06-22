// Shamus.cpp : Defines the entry point for the application.
//

#include "Shamus.h"
#include "Objects.h"
#include "sprites.h"

#define SCREEN_WIDTH    640
#define SCREEN_HEIGHT   480

map <unsigned char, CMonster*> monsters;
signed char X[5] = { 1,XCOUNT - 1,1,XCOUNT - 2,XCOUNT - 1 }; //Координаты X движущихся объектов
signed char Y[5] = { 1,1,YCOUNT - 1,YCOUNT - 1,YCOUNT - 1 }; //Координаты Y движущихся объектов
CMaze* Maze;
CPlayer Player;
CMonster Monster1, Monster2, Monster3;
CGhost Ghost;
unsigned char counter = 0; //счётчик секунд
SDL_Window* window;
SDL_GLContext context;

//---------------------------------------------------------------------------
//Функция рисования
void Display()
{
	constexpr double stepx = 1 / static_cast<double>(XCOUNT), stepy = 1 / static_cast<double>(YCOUNT); //ширина и высота ячейки
    glClearColor(0, 0, 0, 0); //Установка чёрного цвета очистки экрана
    glClear(GL_COLOR_BUFFER_BIT); //Очистка экрана
    unsigned long* hero[1] = { hero1 };
    unsigned long* goblin[3] = { goblin1, goblin2, goblin3 };
    unsigned long* droid[3] = { droid1, droid2, droid3 };
    unsigned long* spider[2] = { spider1, spider2 };
    unsigned long* ghost[3] = { ghost1, ghost2, ghost3 };
    unsigned long** sprites[MONSTER_COUNT + 2] = { hero,goblin,droid,spider,ghost };
    //Рисование неподвижных объектов
	for (unsigned char i = 0;i < XCOUNT;i++)
    {
        for (unsigned char j = 0;j < YCOUNT;j++)
        {
	        const double I = i * stepx;
	        const double J = j * stepy;
            const unsigned char obj = Maze->RoomNo(Player.rx, Player.ry)->GetItem(i, j);
            switch (obj)
            {
            case LIFE:
                CSprite::Show(kolba, I, J);
                break;
            case AWARD:
                CSprite::Show(ask, I, J);
                break;
            case DOOR:
                CWall::Show(4, I, J, I + stepx, J + stepy);
                break;
            case BLUE_KEY:
            case BROWN_KEY:
            case CYAN_KEY:
            case GREEN_KEY:
            case ORANGE_KEY:
            case PURPLE_KEY:
            case RED_KEY:
                CSprite::Show(key, I, J);
                break;
            case BLUE_LOCK:
            case BROWN_LOCK:
            case CYAN_LOCK:
            case GREEN_LOCK:
            case ORANGE_LOCK:
            case PURPLE_LOCK:
            case RED_LOCK:
                CSprite::Show(keyhole, I, J);
                break;
            case LINE1:
                CWall::Show(0, I, J, I + stepx, J + stepy);
                break;
            case LINE2:
                CWall::Show(1, I, J, I + stepx, J + stepy);
                break;
            case LINE3:
                CWall::Show(2, I, J, I + stepx, J + stepy);
                break;
            case LINE4:
                CWall::Show(3, I, J, I + stepx, J + stepy);
                break;
            case LINE5:
            case WALL1:
            case WALL2:
            case WALL3:
            case WALL4:
            case WALL5:
            case WALL6:
            case WALL7:
            case WALL8:
            case WALL9:
            default:
                break;
            }
        }
    }
    //Рисование подвижных объектов
    CSprite::Show(sprites[0][0], Player.px * stepx, Player.py * stepy);
    static unsigned char img_idx = 0;
    unsigned char i1, i2;
    static unsigned long ticks_s = SDL_GetTicks();
    const unsigned long ticks_e = SDL_GetTicks();
    if (ticks_e - ticks_s > 250)
    {
        ticks_s = ticks_e;
        img_idx++;
    }
    if (img_idx > 5) img_idx = 0;
    switch (img_idx)
    {
    case 0:i1 = 0;i2 = 0;break;
    case 1:i1 = 1;i2 = 1;break;
    case 2:i1 = 2;i2 = 0;break;
    case 3:i1 = 0;i2 = 1;break;
    case 4:i1 = 1;i2 = 0;break;
    case 5:i1 = 2;i2 = 1;break;
    default:;
    }
    for (unsigned char index = 1;index <= MONSTER_COUNT;index++)
    {
        unsigned char idx;
        if (index < MONSTER_COUNT) idx = i1;
        else idx = i2;
        CSprite::Show(sprites[index][idx], monsters[index]->px * stepx, monsters[index]->py * stepy);
    }
    if (counter >= 60)
    {
        glEnable(GL_ALPHA_TEST);
        glEnable(GL_BLEND);
        glAlphaFunc(GL_ALWAYS, 0);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_COLOR);
        CSprite::Show(sprites[MONSTER_COUNT + 1][i1], Ghost.px * stepx, Ghost.py * stepy);
        glDisable(GL_BLEND);
        glDisable(GL_ALPHA);
    }
    glFlush(); //Очистка буфера команд OpenGL
    SDL_GL_SwapWindow(window); //Поменять местами буфера
}
//---------------------------------------------------------------------------
//Функция обработки нажатий клавиш
void Keyboard(SDL_Keycode keycode)
{
    if (keycode == SDLK_LEFT) X[0]--;
    if (keycode == SDLK_RIGHT) X[0]++;
    if (keycode == SDLK_UP) Y[0]++;
    if (keycode == SDLK_DOWN) Y[0]--;
    if (Player.Move(X[0], Y[0], Maze->RoomNo(Player.rx, Player.ry)->GetItem(X[0], Y[0])))
    {
        Maze->RoomNo(Player.rx, Player.ry)->SetItem(X[0], Y[0], 0);
        SDL_Delay(100);
    }
    for (unsigned char index = 1;index <= MONSTER_COUNT;index++)
    {
        if (X[0] == X[index] && Y[0] == Y[index])
        {
            Player.lives--;
            if (Player.lives == 0) exit(EXIT_SUCCESS);
        }
    }
    if (Player.room_changed)
    {
        Maze->SelectRoom(Player.rx, Player.ry);
        counter = 0;
        X[1] = XCOUNT - 1;Y[1] = 1;
        X[2] = 1;Y[2] = YCOUNT - 1;
        X[3] = XCOUNT - 2;Y[3] = YCOUNT - 1;
        for (unsigned char index = 1;index <= MONSTER_COUNT;index++)
        {
	        constexpr unsigned char temp = 0;
	        monsters[index]->Move(X[index], Y[index], temp);
        }
    }
}
//---------------------------------------------------------------------------
//Функция обработки изменения размеров окна
void Reshape(int width, int height)
{
    constexpr double minx = 0, maxx = 1, miny = 0, maxy = 1;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(minx, maxx, miny, maxy);
    glMatrixMode(GL_MODELVIEW);
}
//---------------------------------------------------------------------------
//Функция обработки сообщений от таймера
unsigned Timer(unsigned interval, void* param)
{
    for (unsigned char index = 1;index <= MONSTER_COUNT;index++)
    {
        Maze->Wave(X[index], Y[index], X[0], Y[0]);
        monsters[index]->Move(X[index], Y[index], Maze->RoomNo(Player.rx, Player.ry)->GetItem(X[index], Y[index]));
        if (X[0] == X[index] && Y[0] == Y[index])
        {
            Player.lives--;
            if (Player.lives == 0)
            {
                exit(EXIT_SUCCESS);
            }
        }
    }
    counter++;
    if (counter >= 60)
    {
        if (X[0] < X[MONSTER_COUNT + 1]) X[MONSTER_COUNT + 1]--;
        if (X[0] > X[MONSTER_COUNT + 1]) X[MONSTER_COUNT + 1]++;
        if (Y[0] > Y[MONSTER_COUNT + 1]) Y[MONSTER_COUNT + 1]++;
        if (Y[0] < Y[MONSTER_COUNT + 1]) Y[MONSTER_COUNT + 1]--;
        Ghost.Move(X[MONSTER_COUNT + 1], Y[MONSTER_COUNT + 1], Maze->RoomNo(Player.rx, Player.ry)->GetItem(X[MONSTER_COUNT + 1], Y[MONSTER_COUNT + 1]));
        if (X[0] == X[MONSTER_COUNT + 1] && Y[0] == Y[MONSTER_COUNT + 1])
        {
            Player.lives--;
            if (Player.lives == 0) exit(EXIT_SUCCESS);
        }
    }
    return interval;
}
//---------------------------------------------------------------------------

#if defined WIN32
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
#else
int main(int argc, char* argv[])
#endif
{
    unsigned char maze_data[MAX_ROOM_X * MAX_ROOM_Y * XCOUNT * YCOUNT];
    for (unsigned char& index : maze_data)
    {
	    index = 0;
    }
    const char *fileName = "C:/Code/shamus/Shamus/x64/Debug/maze.dat";
	FILE* file;
    errno_t err = fopen_s(&file, fileName, "rb");
    int cnt = fread(maze_data, 1, MAX_ROOM_X * MAX_ROOM_Y * XCOUNT * YCOUNT, file);
    err = fclose(file);
    CMazeBuilder MazeBuilder;
    MazeBuilder.BuildMaze(maze_data);
    Maze = MazeBuilder.GetMaze();
    Maze->SelectRoom(0, 0);
    monsters[1] = &Monster1;
    monsters[2] = &Monster2;
    monsters[3] = &Monster3;
    constexpr unsigned char temp = 0;
    Player.Move(X[0], Y[0], temp);
    for (unsigned char index = 1;index <= MONSTER_COUNT;index++)
    {
        monsters[index]->X = &X[0];
        monsters[index]->Y = &Y[0];
        monsters[index]->number = index;
        monsters[index]->Move(X[index], Y[index], temp);
    }
    Ghost.Move(X[MONSTER_COUNT + 1], Y[MONSTER_COUNT + 1], temp);
    for (unsigned short index = 0;index < 400;index++)
    {
        ghost1[index] += 0xBF000000;
        ghost2[index] += 0xBF000000;
        ghost3[index] += 0xBF000000;
    }
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
    {
        fprintf_s(stderr, "SDL could not be initialized! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_EventState(SDL_MOUSEMOTION, SDL_IGNORE);
    SDL_EventState(SDL_MOUSEBUTTONDOWN, SDL_IGNORE);
    SDL_EventState(SDL_MOUSEBUTTONUP, SDL_IGNORE);
    window = SDL_CreateWindow("Shamus", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    if (!window)
    {
        fprintf_s(stderr, "Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }
    context = SDL_GL_CreateContext(window);
    if (!context)
    {
        fprintf_s(stderr, "Context could not be created! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }
    const SDL_TimerID timer = SDL_AddTimer(1000, Timer, nullptr);
    SDL_Event event;
    SDL_Keycode key;
    Reshape(SCREEN_WIDTH, SCREEN_HEIGHT);
    bool done = false;
    while (!done)
    {
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT) done = true;
        if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_RESIZED) Reshape(event.window.data1, event.window.data2);
        if (event.key.state == SDL_PRESSED)
        {
            key = event.key.keysym.sym;
            if (key == SDLK_LEFT || key == SDLK_RIGHT || key == SDLK_UP || key == SDLK_DOWN)
            {
                Keyboard(key);
            }
            else if (key == SDLK_ESCAPE)
            {
                done = true;
            }
        }
        Display();
    }
    SDL_RemoveTimer(timer);
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
