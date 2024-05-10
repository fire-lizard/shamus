using System;

namespace Shamus.LevelEditor
{
    public class MazeBuilder
    {
        private Maze _currentMaze;

        public byte[] Data(Maze maze)
        {
            const int length = Config.DATA_SIZE;
            byte[] data = new byte[length];
            int position = 0;
            for (int index1 = 0; index1 < Config.MAX_ROOM_X; index1++)
            {
                for (int index2 = 0; index2 < Config.MAX_ROOM_Y; index2++)
                {
                    maze.SelectRoom(index1, index2);
                    Room room = maze.CurrentRoom;
                    if (room != null)
                    {
                        for (int i = 0; i < Config.XCOUNT; i++)
                        {
                            for (int j = 0; j < Config.YCOUNT; j++)
                            {
                                data[position] = (byte) room.GetObject(i, j);
                                position++;
                            }
                        }
                    }
                }
            }
            return data;
        }

        public Maze CurrentMaze => _currentMaze;

        public void BuildMaze(byte[] data)
        {
            int position = 0;
            _currentMaze = new Maze();
            for (int index1 = 0; index1 < Config.MAX_ROOM_X; index1++)
            {
                for (int index2 = 0; index2 < Config.MAX_ROOM_Y; index2++)
                {
                    Room room = new Room(Config.XCOUNT, Config.YCOUNT);
                    for (int i = 0; i < Config.XCOUNT; i++)
                    {
                        for (int j = 0; j < Config.YCOUNT; j++)
                        {
                            room.SetObject(i, j, (Item)data[position]);
                            position++;
                        }
                    }
                    _currentMaze.AddRoom(index1, index2, room);
                }
            }
        }
    }
}
