// Shamus.cpp : Defines the entry point for the application.
//

#include "Shamus.h"
#include "sprites.h"
#include "objects.h"

map <unsigned char, CMonster*> monsters;
signed char X[6] = { 25,XCOUNT - 10,8,XCOUNT - 10,8,XCOUNT - 1 }; //Координаты X движущихся объектов
signed char Y[6] = { 10,1,YCOUNT - 2,YCOUNT - 2,1,YCOUNT - 1 };   //Координаты Y движущихся объектов
CMaze* Maze;
CPlayer Player;
CMonster Monster1, Monster2, Monster3, Monster4;
CGhost Ghost;
unsigned char counter = 0; //счётчик секунд
SDL_Window* window;
SDL_GLContext context;
SDL_KeyCode keys[19] = { SDLK_F1, SDLK_F2, SDLK_F3, SDLK_F4, SDLK_F5, SDLK_LEFT, SDLK_RIGHT, SDLK_UP, SDLK_DOWN, SDLK_SPACE,
                         SDLK_KP_1, SDLK_KP_2, SDLK_KP_3, SDLK_KP_4, SDLK_KP_5, SDLK_KP_6, SDLK_KP_7, SDLK_KP_8, SDLK_KP_9 };
Direction direction = CENTER;
Bullet bullet1(0, 0);
bool stopDisplay = false;
bool gamePaused = true;
bool gameOver;
int SCREEN_WIDTH;
int SCREEN_HEIGHT;

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
	for (signed char i = 0;i < XCOUNT;i++)
    {
        for (signed char j = 0;j < YCOUNT;j++)
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
                CWall::Show(6, I, J, I + stepx, J + stepy);
                break;
            case WALL2:
                CWall::Show(7, I, J, I + stepx, J + stepy);
                break;
            case WALL3:
                CWall::Show(8, I, J, I + stepx, J + stepy);
                break;
            case WALL4:
                CWall::Show(9, I, J, I + stepx, J + stepy);
                break;
            case WALL5:
                CWall::Show(10, I, J, I + stepx, J + stepy);
                break;
            case WALL6:
                CWall::Show(11, I, J, I + stepx, J + stepy);
                break;
            case WALL7:
                CWall::Show(12, I, J, I + stepx, J + stepy);
                break;
            case WALL8:
                CWall::Show(13, I, J, I + stepx, J + stepy);
                break;
            case WALL9:
                CWall::Show(14, I, J, I + stepx, J + stepy);
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
        if (monsters[index]->is_alive)
        {
            unsigned char idx;
            if (index < MONSTER_COUNT) idx = i2;
            else idx = i1;
            CSprite::Show(sprites[index][idx], monsters[index]->px * stepx, monsters[index]->py * stepy, 24, 24);
        }
    }
    if ((Player.rx == 41 && Player.ry == 11) || counter >= 60)
    {
        glEnable(GL_ALPHA_TEST);
        glEnable(GL_BLEND);
        glAlphaFunc(GL_ALWAYS, 0);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_COLOR);
        if (!Ghost.is_frozen)
        {
            CSprite::Show(sprites[MONSTER_COUNT + 1][i1], Ghost.px * stepx, Ghost.py * stepy, 24, 24);
        }
        else
        {
            CSprite::Show(sprites[MONSTER_COUNT + 1][0], Ghost.px* stepx, Ghost.py* stepy, 24, 24);
        }
        glDisable(GL_BLEND);
        glDisable(GL_ALPHA);
    }
    if (bullet1.is_fired)
    {
        CWall::PlayerBullet(bullet1.bx * stepx, bullet1.by * stepy, bullet1.bx * stepx + stepx, bullet1.by * stepy + stepy);
    }
    if (gameOver)
    {
        CSprite::Show(gameover, 0.5, 0.5, 152, 24);
    }
    glFlush(); //Очистка буфера команд OpenGL
    SDL_GL_SwapWindow(window); //Поменять местами буфера
}
//---------------------------------------------------------------------------

template<typename C, typename T>
bool contains(C&& c, T e) {
    return find(begin(c), end(c), e) != end(c);
};
//---------------------------------------------------------------------------

void set_window_title(int x, int y)
{
	const string title = "Room " + to_string(x) + ":" + to_string(y) + "; Lives: " + to_string(Player.lives);
    SDL_SetWindowTitle(window, title.c_str());
}
//---------------------------------------------------------------------------

void go_to_level_start()
{
    counter = 0;
    X[0] = 25;
    Y[0] = 10;
    Player.Move(X[0], Y[0], 0);
    if (Player.rx < 14 && Player.ry < 5)
    {
        Player.rx = 3;
        Player.ry = 1;
    }
    else if (Player.rx < 23 && Player.ry < 7)
    {
        Player.rx = 16;
        Player.ry = 2;
    }
    else if (Player.rx < 32 && Player.ry < 11)
    {
        Player.rx = 24;
        Player.ry = 5;
    }
    else
    {
        Player.rx = 35;
        Player.ry = 9;
    }
    set_window_title(Player.rx, Player.ry);
}
//---------------------------------------------------------------------------

void displayImageAndWaitForKey(const char* imagePath, bool centered = false)
{
    stopDisplay = true;

	// Create a renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        stopDisplay = false;
        return;
    }

    // Load image
    SDL_Surface* imageSurface = IMG_Load(imagePath);
    if (imageSurface == nullptr) {
        printf("Unable to load image %s! SDL_image Error: %s\n", imagePath, IMG_GetError());
        SDL_DestroyRenderer(renderer);
        stopDisplay = false;
        return;
    }

    SDL_Texture* imageTexture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    SDL_FreeSurface(imageSurface); // Free the surface now that we have a texture

    if (imageTexture == nullptr) {
        printf("Unable to create texture! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        stopDisplay = false;
        return;
    }

    if (centered)
    {
        // Get the dimensions of the image
        int imageWidth, imageHeight;
        SDL_QueryTexture(imageTexture, nullptr, nullptr, &imageWidth, &imageHeight);

        // Get the dimensions of the window
        int windowWidth, windowHeight;
        SDL_GetWindowSize(window, &windowWidth, &windowHeight);

        // Calculate position to center the image
        const int x = (windowWidth - imageWidth) / 2;
        const int y = (windowHeight - imageHeight) / 2;

        const SDL_Rect destRect = { x, y, imageWidth, imageHeight };
        SDL_RenderCopy(renderer, imageTexture, nullptr, &destRect);
    }
    else
    {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, imageTexture, nullptr, nullptr);
    }

    // Display the image
    SDL_RenderPresent(renderer);

	// Wait for any key press
    bool quit = false;
    SDL_Event e;
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT || e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_ESCAPE) exit(0);
            	quit = true;
                stopDisplay = false;
            }
        }
    }

    // Clean up
    SDL_DestroyTexture(imageTexture);
    SDL_DestroyRenderer(renderer);
}
//---------------------------------------------------------------------------

void game_over()
{
    gamePaused = true;
    gameOver = true;
}
//---------------------------------------------------------------------------

void game_win()
{
    displayImageAndWaitForKey("finish.png");
    exit(0);
}
//---------------------------------------------------------------------------

void player_moves()
{
	const auto item = Maze->RoomNo(Player.rx, Player.ry)->GetItem(X[0], Y[0]);
    if (Player.Move(X[0], Y[0], item))
    {
        if (item == BLUE_LOCK || item == BROWN_LOCK || item == CYAN_LOCK || item == GREEN_LOCK ||
            item == ORANGE_LOCK || item == PURPLE_LOCK || item == RED_LOCK)
        {
            for (signed char index = 10; index <= 15; index++)
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
        if (X[0] == X[index] && Y[0] == Y[index] && monsters[index]->is_alive)
        {
            Player.lives--;
            if (Player.lives == 0) game_over();
            go_to_level_start();
        }
    }
    if (Player.room_changed)
    {
        Maze->SelectRoom(Player.rx, Player.ry);
        set_window_title(Player.rx, Player.ry);
        counter = 0;
        if (Maze->RoomNo(Player.rx, Player.ry)->GetItem(10, 2) == 0)
        {
            X[1] = XCOUNT - 10;Y[1] = 2;
            X[2] = 8;Y[2] = YCOUNT - 2;
            X[3] = XCOUNT - 10;Y[3] = YCOUNT - 2;
            X[4] = 8;Y[4] = 2;
        }
        else
        {
            X[1] = (XCOUNT / 2) - 2;Y[1] = (YCOUNT / 2) - 2;
            X[2] = (XCOUNT / 2) + 2;Y[2] = (YCOUNT / 2) - 2;
            X[3] = (XCOUNT / 2) - 2;Y[3] = (YCOUNT / 2) + 2;
            X[4] = (XCOUNT / 2) + 2;Y[4] = (YCOUNT / 2) + 2;
        }
        bullet1.is_fired = false;
        for (unsigned char index = 1;index <= MONSTER_COUNT;index++)
        {
            constexpr unsigned char temp = 0;
            monsters[index]->is_alive = true;
            monsters[index]->Move(X[index], Y[index], temp);
        }
    }
}
//---------------------------------------------------------------------------

//Функция обработки нажатий клавиш
void Keyboard(SDL_Keycode keycode)
{
    if (keycode == SDLK_LEFT || keycode == SDLK_KP_4) direction = WEST;
    if (keycode == SDLK_RIGHT || keycode == SDLK_KP_6) direction = EAST;
    if (keycode == SDLK_UP || keycode == SDLK_KP_8) direction = NORTH;
    if (keycode == SDLK_DOWN || keycode == SDLK_KP_2) direction = SOUTH;
    if (keycode == SDLK_KP_5) direction = CENTER;
    if (keycode == SDLK_KP_7) direction = NORTHWEST;
    if (keycode == SDLK_KP_9) direction = NORTHEAST;
    if (keycode == SDLK_KP_1) direction = SOUTHWEST;
    if (keycode == SDLK_KP_3) direction = SOUTHEAST;
    if (keycode == SDLK_SPACE && !bullet1.is_fired)
    {
        bullet1.bx = X[0];
        bullet1.by = Y[0];
        bullet1.is_fired = true;
        bullet1.direction = direction == CENTER ? EAST : direction;
    }
    if (keycode == SDLK_F2 || keycode == SDLK_F3 || keycode == SDLK_F4 || keycode == SDLK_F5)
    {
        if (keycode == SDLK_F2)
        {
            Player.rx = 3;
            Player.ry = 1;
        }
        if (keycode == SDLK_F3)
        {
            Player.rx = 16;
            Player.ry = 2;
        }
        if (keycode == SDLK_F4)
        {
            Player.rx = 24;
            Player.ry = 5;
        }
        if (keycode == SDLK_F5)
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
//Функция обработки сообщений от таймера (для игрока)
unsigned Timer(unsigned interval, void* param)
{
    if (gamePaused) return interval;
	if (direction == WEST) X[0]--;
    if (direction == EAST) X[0]++;
    if (direction == NORTH) Y[0]++;
    if (direction == SOUTH) Y[0]--;
    if (direction == NORTHWEST)
    {
        if (X[0] == 0)
        {
            X[0]--;
        }
        else if (Y[0] == YCOUNT - 1)
        {
            Y[0]++;
        }
        else
        {
            Y[0]++; X[0]--;
        }
    }
    if (direction == NORTHEAST)
    {
        if (X[0] == XCOUNT - 1)
        {
            X[0]++;
        }
        else if (Y[0] == YCOUNT - 1)
        {
            Y[0]++;
        }
        else
        {
            Y[0]++; X[0]++;
        }
    }
    if (direction == SOUTHWEST)
    {
        if (X[0] == 0)
        {
            X[0]--;
        }
        else if (Y[0] == 0)
        {
            Y[0]--;
        }
        else
        {
            Y[0]--; X[0]--;
        }
    }
    if (direction == SOUTHEAST)
    {
        if (X[0] == XCOUNT - 1)
        {
            X[0]++;
        }
        else if (Y[0] == 0)
        {
            Y[0]--;
        }
        else
        {
            Y[0]--; X[0]++;
        }
    }
    player_moves();
    return interval;
}
//---------------------------------------------------------------------------

//Функция обработки сообщений от таймера (для монстров)
unsigned Timer2(unsigned interval, void* param)
{
    if (gamePaused) return interval;
	for (unsigned char index = 1;index <= MONSTER_COUNT;index++)
    {
        if (monsters[index]->is_alive)
        {
            Maze->Wave(X[index], Y[index], X[0], Y[0]);
            monsters[index]->Move(X[index], Y[index], Maze->RoomNo(Player.rx, Player.ry)->GetItem(X[index], Y[index]));
            if (X[0] == X[index] && Y[0] == Y[index] && monsters[index]->is_alive)
            {
                Player.lives--;
                if (Player.lives == 0) game_over();
                go_to_level_start();
            }
        }
    }
    counter++;
    if ((Player.rx == 41 && Player.ry == 11) || counter >= 60)
    {
        if (!Ghost.is_frozen)
        {
            if (X[0] < X[MONSTER_COUNT + 1]) X[MONSTER_COUNT + 1]--;
            if (X[0] > X[MONSTER_COUNT + 1]) X[MONSTER_COUNT + 1]++;
            if (Y[0] > Y[MONSTER_COUNT + 1]) Y[MONSTER_COUNT + 1]++;
            if (Y[0] < Y[MONSTER_COUNT + 1]) Y[MONSTER_COUNT + 1]--;
            Ghost.Move(X[MONSTER_COUNT + 1], Y[MONSTER_COUNT + 1], Maze->RoomNo(Player.rx, Player.ry)->GetItem(X[MONSTER_COUNT + 1], Y[MONSTER_COUNT + 1]));
        }
        if (X[0] == X[MONSTER_COUNT + 1] && Y[0] == Y[MONSTER_COUNT + 1])
        {
            Player.lives--;
            if (Player.lives == 0) game_over();
            go_to_level_start();
        }
    }
    return interval;
}
//---------------------------------------------------------------------------

//Функция обработки сообщений от таймера (для пуль игрока)
unsigned Timer3(unsigned interval, void* param)
{
    if (bullet1.is_fired)
    {
        if (bullet1.direction == WEST) bullet1.bx--;
        if (bullet1.direction == EAST) bullet1.bx++;
        if (bullet1.direction == NORTH) bullet1.by++;
        if (bullet1.direction == SOUTH) bullet1.by--;
        if (bullet1.direction == NORTHWEST)
        {
            bullet1.by++; bullet1.bx--;
        }
        if (bullet1.direction == NORTHEAST)
        {
            bullet1.by++; bullet1.bx++;
        }
        if (bullet1.direction == SOUTHWEST)
        {
            bullet1.by--; bullet1.bx--;
        }
        if (bullet1.direction == SOUTHEAST)
        {
            bullet1.by--; bullet1.bx++;
        }
        if (bullet1.bx < 0 || bullet1.bx >= XCOUNT || bullet1.by < 0 || bullet1.by >= YCOUNT)
        {
            bullet1.is_fired = false;
        }
        else if (Maze->RoomNo(Player.rx, Player.ry)->GetItem(bullet1.bx, bullet1.by) > 0)
        {
            //bullet1.is_fired = false;
        }
        for (unsigned char index = 1; index <= MONSTER_COUNT; index++)
        {
            if (bullet1.bx == X[index] && bullet1.by == Y[index] && monsters[index]->is_alive)
            {
                monsters[index]->is_alive = false;
                X[index] = 0;
                Y[index] = 0;
                bullet1.is_fired = false;
            }
        }
        if (bullet1.bx == X[5] && bullet1.by == Y[5])
        {
            if (Player.rx == 41 && Player.ry == 11)
            {
                game_win();
            }
            else
            {
                Ghost.is_frozen = true;
                bullet1.is_fired = false;
            }
        }
    }
    return interval;
}
//---------------------------------------------------------------------------

//Функция обработки сообщений от таймера (для заморозки Тени)
unsigned Timer4(unsigned interval, void* param)
{
    if (Ghost.is_frozen)
    {
        Ghost.is_frozen = false;
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
    // Reading maze file
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
    const size_t cnt = fread(maze_data, 1, MAX_ROOM_X * MAX_ROOM_Y * XCOUNT * YCOUNT, file);
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
    // Reading ini file
    const IniFile ini("config.ini");
    const int speed = stoi(ini.get("game", "speed", "500"));
	SCREEN_WIDTH = stoi(ini.get("game", "width", "1280"));
    SCREEN_HEIGHT = stoi(ini.get("game", "height", "960"));
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
    window = SDL_CreateWindow("Shamus", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);// | SDL_WINDOW_RESIZABLE);
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
    const SDL_TimerID timer = SDL_AddTimer(speed, Timer, nullptr);
    const SDL_TimerID timer2 = SDL_AddTimer(static_cast<int>(speed * 1.2), Timer2, nullptr);
    const SDL_TimerID timer3 = SDL_AddTimer(static_cast<int>(speed * 0.1), Timer3, nullptr);
    const SDL_TimerID timer4 = SDL_AddTimer(1000, Timer4, nullptr);
    SDL_Event event;
    Reshape(SCREEN_WIDTH, SCREEN_HEIGHT);

    displayImageAndWaitForKey("logotype.png");
start:
    gameOver = false;
    displayImageAndWaitForKey("begin.png");
    gamePaused = false;

    bool done = false;
    while (!done)
    {
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT) done = true;
        if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_RESIZED) Reshape(event.window.data1, event.window.data2);
        if (event.key.state == SDL_PRESSED)
        {
	        const SDL_Keycode keycode = event.key.keysym.sym;
            if (contains(keys, keycode))
            {
                if (keycode == SDLK_F1)
                {
                    gamePaused = true;
                    displayImageAndWaitForKey("plot.png");
                    gamePaused = false;
                }
                else Keyboard(keycode);
            }
            else if (keycode == SDLK_ESCAPE)
            {
                //done = true;
                Player.rx = 3;
                Player.ry = 1;
                Maze->SelectRoom(3, 1);
                X[0] = 25; Y[0] = 10;
            	X[1] = XCOUNT - 10;Y[1] = 2;
                X[2] = 8;Y[2] = YCOUNT - 2;
                X[3] = XCOUNT - 10;Y[3] = YCOUNT - 2;
                X[4] = 8;Y[4] = 2;
                counter = 0;
            	goto start;
            }
        }
        if (!stopDisplay)
        {
            Display();
        }
    }
    SDL_RemoveTimer(timer);
    SDL_RemoveTimer(timer2);
    SDL_RemoveTimer(timer3);
    SDL_RemoveTimer(timer4);
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();
    delete[] maze_data;
    return 0;
}
