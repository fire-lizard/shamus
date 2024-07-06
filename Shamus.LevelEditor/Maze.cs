using System;

namespace Shamus.LevelEditor
{
    public enum Item
    {
        NONE = 0,
        LIFE = 1,
        AWARD = 2,
        DOOR = 3,
        LINE1 = 4,
        LINE2 = 5,
        LINE3 = 6,
        LINE4 = 7,
        LINE5 = 8,
        WALL1 = 9,
        WALL2 = 10,
        WALL3 = 11,
        WALL4 = 12,
        WALL5 = 13,
        WALL6 = 14,
        WALL7 = 15,
        WALL8 = 16,
        WALL9 = 17,
        BLUE_KEY = 18,
        BLUE_LOCK = 19,
        BROWN_KEY = 20,
        BROWN_LOCK = 21,
        CYAN_KEY = 22,
        CYAN_LOCK = 23,
        GREEN_KEY = 24,
        GREEN_LOCK = 25,
        ORANGE_KEY = 26,
        ORANGE_LOCK = 27,
        PURPLE_KEY = 28,
        PURPLE_LOCK = 29,
        RED_KEY = 30,
        RED_LOCK = 31
    }

    public class Maze
    {
	    private readonly byte[,,,] _data;

        public Maze()
        {
            _data = new byte[Config.MAX_ROOM_X, Config.MAX_ROOM_Y, Config.XCOUNT, Config.YCOUNT];
        }

        public bool IsEmptyRoom(int rx, int ry)
        {
            for (int i = 0; i < Config.XCOUNT; i++)
            {
                for (int j = 0; j < Config.YCOUNT; j++)
                {
                    if (GetObject(rx, ry, i, j) != Item.NONE)
                    {
                        return false;
                    }
                }
            }

            return true;
        }

        public Item GetObject(int rx, int ry, int x, int y)
        {
            return (Item)_data[rx, ry, x, y];
        }
        
        public void SetObject(int rx, int ry, int x, int y, Item item)
        {
            _data[rx, ry, x, y] = (byte)item;
        }
    }
}
