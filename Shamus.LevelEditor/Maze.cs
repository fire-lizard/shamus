using System;

namespace Shamus.LevelEditor
{
    public enum Item
    {
        NONE,
        LIFE,
        AWARD,
        DOOR,
        LINE1,
        LINE2,
        LINE3,
        LINE4,
        LINE5,
        WALL1,
        WALL2,
        WALL3,
        WALL4,
        WALL5,
        WALL6,
        WALL7,
        WALL8,
        WALL9,
        WALL10,
        BLUE_KEY,
        BLUE_LOCK,
        BROWN_KEY,
        BROWN_LOCK,
        CYAN_KEY,
        CYAN_LOCK,
        GREEN_KEY,
        GREEN_LOCK,
        ORANGE_KEY,
        ORANGE_LOCK,
        PURPLE_KEY,
        PURPLE_LOCK,
        RED_KEY,
        RED_LOCK,
        LEFT_ARROW,
        RIGHT_ARROW
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
