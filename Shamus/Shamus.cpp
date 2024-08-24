// Shamus.cpp : Defines the entry point for the application.
//

#include "Shamus.h"
#include "sprites.h"
#include "objects.h"
#include "newitems/wall1.h"
#include "newitems/wall4.h"
#include "newitems/wall5.h"
#include "newitems/wall6.h"
#include "newitems/wall7.h"
#include "newitems/wall8.h"
#include "newitems/wall9.h"

#define SCREEN_WIDTH    640
#define SCREEN_HEIGHT   480

map <unsigned char, CMonster*> monsters;
signed char X[6] = { 25,XCOUNT - 10,8,XCOUNT - 10,8,XCOUNT - 1 }; //Координаты X движущихся объектов
signed char Y[6] = { 10,1,YCOUNT - 2,YCOUNT - 2,1,YCOUNT - 1 }; //Координаты Y движущихся объектов
CMaze* Maze;
CPlayer Player;
CMonster Monster1, Monster2, Monster3, Monster4;
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
    unsigned char* hero[4] = { hero1, hero2, hero3, hero4 };
    unsigned char* goblin[4] = { snapjump1, snapjump2, snapjump3, snapjump4 };
    unsigned char* droid[2] = { robodrod1, robodrod2 };
    unsigned char* spider[2] = { spirdron1, spirdron2 };
    unsigned char* soboloyd[2] = { soboloyd1, soboloyd2 };
    unsigned char* ghost[4] = { shadow1, shadow2, shadow3, shadow4 };
    unsigned char** sprites[MONSTER_COUNT + 2] = { hero,spider,droid,soboloyd,goblin,ghost };
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
                CSprite::Show(extra1, I, J, 24, 24);
                break;
            case AWARD:
                CSprite::Show(mystery, I, J, 24, 24);
                break;
            case DOOR:
                CWall::Show(5, I, J, I + stepx, J + stepy);
                break;
            case LEFT_ARROW:
                CSprite::Show(arrow_left, I, J, 16, 16);
                break;
            case RIGHT_ARROW:
                CSprite::Show(arrow_right, I, J, 16, 16);
                break;
            case BLUE_KEY:
                CSprite::Show(blue_key, I, J, 24, 24);
                break;
            case BROWN_KEY:
                CSprite::Show(brown_key, I, J, 24, 24);
                break;
            case CYAN_KEY:
                CSprite::Show(cyan_key, I, J, 24, 24);
                break;
            case GREEN_KEY:
                CSprite::Show(green_key, I, J, 24, 24);
                break;
            case ORANGE_KEY:
                CSprite::Show(orange_key, I, J, 24, 24);
                break;
            case PURPLE_KEY:
                CSprite::Show(purple_key, I, J, 24, 24);
                break;
            case RED_KEY:
                CSprite::Show(red_key, I, J, 24, 24);
                break;
            case BLUE_LOCK:
                CSprite::Show(blue_lock, I, J, 24, 24);
                break;
            case BROWN_LOCK:
                CSprite::Show(brown_lock, I, J, 24, 24);
                break;
            case CYAN_LOCK:
                CSprite::Show(cyan_lock, I, J, 24, 24);
                break;
            case GREEN_LOCK:
                CSprite::Show(green_lock, I, J, 24, 24);
                break;
            case ORANGE_LOCK:
                CSprite::Show(orange_lock, I, J, 24, 24);
                break;
            case PURPLE_LOCK:
                CSprite::Show(purple_lock, I, J, 24, 24);
                break;
            case RED_LOCK:
                CSprite::Show(red_lock, I, J, 24, 24);
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
                CWall::Show(4, I, J, I + stepx, J + stepy);
                break;
            case WALL1:
                CSprite::Show(wall1, I, J, 8, 8);
                break;
            case WALL2:
                CWall::Show(7, I, J, I + stepx, J + stepy);
                break;
            case WALL3:
                CWall::Show(8, I, J, I + stepx, J + stepy);
                break;
            case WALL4:
                CSprite::Show(wall4, I, J, 8, 8);
                break;
            case WALL5:
                CSprite::Show(wall5, I, J, 8, 8);
                break;
            case WALL6:
                CSprite::Show(wall6, I, J, 8, 8);
                break;
            case WALL7:
                CSprite::Show(wall7, I, J, 8, 8);
                break;
            case WALL8:
                CSprite::Show(wall8, I, J, 8, 8);
                break;
            case WALL9:
                CSprite::Show(wall9, I, J, 8, 8);
                break;
            case WALL10:
                CWall::Show(15, I, J, I + stepx, J + stepy);
                break;
            default:
                break;
            }
        }
    }
    //Рисование подвижных объектов
    static unsigned char img_idx = 0;
    unsigned char i1 = 0, i2 = 0;
    static unsigned long ticks_s = SDL_GetTicks();
    const unsigned long ticks_e = SDL_GetTicks();
    if (ticks_e - ticks_s > 250)
    {
        ticks_s = ticks_e;
        img_idx++;
    }
    if (img_idx > 7) img_idx = 0;
    switch (img_idx)
    {
    case 0:i1 = 0;i2 = 0;break;
    case 1:i1 = 1;i2 = 1;break;
    case 2:i1 = 2;i2 = 0;break;
    case 3:i1 = 3;i2 = 1;break;
    case 4:i1 = 0;i2 = 0;break;
    case 5:i1 = 1;i2 = 1;break;
    case 6:i1 = 2;i2 = 0;break;
    case 7:i1 = 3;i2 = 1;break;
    default:;
    }
    CSprite::Show(sprites[0][i1], Player.px* stepx, Player.py* stepy, 24, 24);
    for (unsigned char index = 1;index <= MONSTER_COUNT;index++)
    {
        unsigned char idx;
        if (index < MONSTER_COUNT) idx = i2;
        else idx = i1;
        CSprite::Show(sprites[index][idx], monsters[index]->px * stepx, monsters[index]->py * stepy, 24, 24);
    }
    if (counter >= 60)
    {
        glEnable(GL_ALPHA_TEST);
        glEnable(GL_BLEND);
        glAlphaFunc(GL_ALWAYS, 0);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_COLOR);
        CSprite::Show(sprites[MONSTER_COUNT + 1][i1], Ghost.px * stepx, Ghost.py * stepy, 24, 24);
        glDisable(GL_BLEND);
        glDisable(GL_ALPHA);
    }
    glFlush(); //Очистка буфера команд OpenGL
    SDL_GL_SwapWindow(window); //Поменять местами буфера
}
//---------------------------------------------------------------------------

void set_window_title(int x, int y)
{
    string title = "Room " + to_string(x) + ":" + to_string(y);
    SDL_SetWindowTitle(window, title.c_str());
}

//---------------------------------------------------------------------------
//Функция обработки нажатий клавиш
void Keyboard(SDL_Keycode keycode)
{
    if (keycode == SDLK_LEFT) X[0]--;
    if (keycode == SDLK_RIGHT) X[0]++;
    if (keycode == SDLK_UP) Y[0]++;
    if (keycode == SDLK_DOWN) Y[0]--;
    if (keycode == SDLK_1 || keycode == SDLK_2 || keycode == SDLK_3 || keycode == SDLK_4)
    {
        if (keycode == SDLK_1)
        {
            Player.rx = 3;
            Player.ry = 1;
        }
        if (keycode == SDLK_2)
        {
            Player.rx = 16;
            Player.ry = 2;
        }
        if (keycode == SDLK_3)
        {
            Player.rx = 24;
            Player.ry = 5;
        }
        if (keycode == SDLK_4)
        {
            Player.rx = 35;
            Player.ry = 9;
        }
        Maze->SelectRoom(Player.rx, Player.ry);
        set_window_title(Player.rx, Player.ry);
        X[0] = 25;
        Y[0] = 10;
        Player.Move(X[0], Y[0], 0);
    }
    auto item = Maze->RoomNo(Player.rx, Player.ry)->GetItem(X[0], Y[0]);
    if (Player.Move(X[0], Y[0], item))
    {
        if (item == BLUE_LOCK || item == BROWN_LOCK || item == CYAN_LOCK || item == GREEN_LOCK ||
            item == ORANGE_LOCK || item == PURPLE_LOCK || item == RED_LOCK)
        {
            for (unsigned char index = 10; index <= 15; index++)
            {
                Maze->RoomNo(Player.rx, Player.ry)->SetItem(0, index, 0);
                Maze->RoomNo(Player.rx, Player.ry)->SetItem(XCOUNT - 1, index, 0);
            }
        }
        if (item == LEFT_ARROW)
        {
            X[0] -= 10;
            Player.Move(X[0], Y[0], 0);
        }
        if (item == RIGHT_ARROW)
        {
            X[0] += 10;
            Player.Move(X[0], Y[0], 0);
        }
        Maze->RoomNo(Player.rx, Player.ry)->SetItem(X[0], Y[0], 0);
        SDL_Delay(100);
    }
    for (unsigned char index = 1;index <= MONSTER_COUNT;index++)
    {
        if (X[0] == X[index] && Y[0] == Y[index])
        {
            //Player.lives--;
            if (Player.lives == 0) exit(EXIT_SUCCESS);
        }
    }
    if (Player.room_changed)
    {
        Maze->SelectRoom(Player.rx, Player.ry);
        set_window_title(Player.rx, Player.ry);
        counter = 0;
        X[1] = XCOUNT - 10;Y[1] = 2;
        X[2] = 8;Y[2] = YCOUNT - 2;
        X[3] = XCOUNT - 10;Y[3] = YCOUNT - 2;
        X[4] = 8;Y[4] = 2;
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
            //Player.lives--;
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
            //Player.lives--;
            if (Player.lives == 0) exit(EXIT_SUCCESS);
        }
    }
    return interval;
}
//---------------------------------------------------------------------------

void print_error(errno_t err)
{
    char buffer[256]; // Buffer to store the error message

    // strerror_s returns zero on success
    if (strerror_s(buffer, sizeof(buffer), err) == 0) {
        printf("Error code %d: %s\n", err, buffer);
    }
    else {
        printf("Unknown error code %d\n", err);
    }
}
//---------------------------------------------------------------------------

#if defined _WIN32
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
#else
int main(int argc, char* argv[])
#endif
{
    unsigned char *maze_data = new unsigned char[MAX_ROOM_X * MAX_ROOM_Y * XCOUNT * YCOUNT];
    for (int index = 0; index < MAX_ROOM_X * MAX_ROOM_Y * XCOUNT * YCOUNT; index++)
    {
        maze_data[index] = 0;
    }
    const char *fileName = "maze.dat";
	FILE* file;
    errno_t err = fopen_s(&file, fileName, "rb");
    if (err != 0)
    {
        print_error(err);
        delete[] maze_data;
        exit(err);
    }
    size_t cnt = fread(maze_data, 1, MAX_ROOM_X * MAX_ROOM_Y * XCOUNT * YCOUNT, file);
    if (cnt != MAX_ROOM_X * MAX_ROOM_Y * XCOUNT * YCOUNT)
    {
        printf("Invalid maze.dat file size\n");
        delete[] maze_data;
        exit(-1);
    }
    err = fclose(file);
    if (err != 0)
    {
        print_error(err);
        delete[] maze_data;
        exit(err);
    }
    CMazeBuilder MazeBuilder;
    MazeBuilder.BuildMaze(maze_data);
    Maze = MazeBuilder.GetMaze();
    Maze->SelectRoom(3, 1);
    monsters[1] = &Monster1;
    monsters[2] = &Monster2;
    monsters[3] = &Monster3;
    monsters[4] = &Monster4;
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
    for (unsigned short index = 0;index < 576;index++)
    {
        if ((index + 1) % 4 == 0)
        {
            shadow1[index] += 0xBF;
            shadow2[index] += 0xBF;
            shadow3[index] += 0xBF;
            shadow4[index] += 0xBF;
        }
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
    Reshape(SCREEN_WIDTH, SCREEN_HEIGHT);
    bool done = false;
    while (!done)
    {
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT) done = true;
        if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_RESIZED) Reshape(event.window.data1, event.window.data2);
        if (event.key.state == SDL_PRESSED)
        {
            SDL_Keycode keycode = event.key.keysym.sym;
            if (keycode == SDLK_LEFT || keycode == SDLK_RIGHT || keycode == SDLK_UP || keycode == SDLK_DOWN ||
                keycode == SDLK_1 || keycode == SDLK_2 || keycode == SDLK_3 || keycode == SDLK_4)
            {
                Keyboard(keycode);
            }
            else if (keycode == SDLK_ESCAPE)
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
    delete[] maze_data;
    return 0;
}
