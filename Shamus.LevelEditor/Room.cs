using System;

namespace Shamus.LevelEditor
{
    public struct StartPosition
    {
        public float X;
        public float Y;
    }
    
    public class Room
    {
        private readonly Item[][] _data;

        public StartPosition StartPosition { get; set; }
        
        public Room(int width, int height)
        {
            _data = new Item[width][];
            for (int index = 0; index < width; index++)
            {
                _data[index] = new Item[height];
            }
        }

        public Item GetObject(int x, int y)
        {
            return (x >= 0 && x < Config.XCOUNT && y >= 0 && y < Config.YCOUNT) ? _data[x][y] : Item.NONE;
        }

        public void SetObject(int x, int y, Item item)
        {
            if (x >= 0 && x < Config.XCOUNT && y >= 0 && y < Config.YCOUNT)
            {
                _data[x][y] = item;
            }
        }
    }
}
