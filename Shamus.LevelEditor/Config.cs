using System;

namespace Shamus.LevelEditor
{
    public static class Config
    {
        public const int XCOUNT = 40; //Размер игрового поля по горизонтали
        public const int YCOUNT = 25; //Размер игрового поля по вертикали
        public const int MAX_ROOM_X = 45; //Количество комнат по горизонтали
        public const int MAX_ROOM_Y = 12; //Количество комнат по вертикали
        public const int DATA_SIZE = MAX_ROOM_X * MAX_ROOM_Y * XCOUNT * YCOUNT;
        public const int MONSTER_COUNT = 3; //количество монстров  

        public const float SPRITE_WIDTH = 32;
        public const float SPRITE_HEIGHT = 32;
    }
}
