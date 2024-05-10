using System.Collections.Generic;
using System.Linq;

namespace Shamus.LevelEditor
{
    public enum Item
    {
        NONE = 0,
        LIFE = 1,
        KEY = 2,
        DOOR = 3,
        AWARD = 4
    }

    public class Maze
    {
	    private readonly Room[][] _rooms;
	    private readonly int[][] _path;
	    private readonly int[][] _pathFind;
        private int _rx;
        private int _ry;

        public int RX => _rx;

        public int RY => _ry;

        public Maze()
        {
            _path = new int[Config.XCOUNT + 2][];
            _pathFind = new int[Config.XCOUNT + 2][];
            for (int index = 0; index < Config.XCOUNT + 2; index++)
            {
                _path[index] = new int[Config.YCOUNT + 2];
                _pathFind[index] = new int[Config.YCOUNT + 2];
            }

            _rooms = new Room[Config.MAX_ROOM_X][];
            for (int index = 0; index < Config.MAX_ROOM_X; index++)
            {
                _rooms[index] = new Room[Config.MAX_ROOM_Y];
            }
        }

        private void SetPaths()
        {
            for (int index1 = 0; index1 < Config.XCOUNT + 2; index1++)
            {
                for (int index2 = 0; index2 < Config.YCOUNT + 2; index2++)
                {
                    if (index1 > 0 && index1 < Config.XCOUNT + 1 && index2 > 0 && index2 < Config.YCOUNT + 1)
                    {
                        Item item = _rooms[_rx][_ry].GetObject(index1 - 1, index2 - 1);
                        if (item != Item.NONE)
                        {
                            _path[index1][index2] = 255;
                        }
                        else
                        {
                            _path[index1][index2] = 254;
                        }
                    }
                    else
                    {
                        _path[index1][index2] = 255;
                    }
                }
            }
        }

        private void MinValue(int x1, int y1, ref int x, ref int y)
        {
            List<int> v = new List<int>(new[] { 
                _pathFind[x1 - 1][y1], 
                _pathFind[x1 + 1][y1], 
                _pathFind[x1][y1 - 1], 
                _pathFind[x1][y1 + 1] });
            int b = v.Min();
            if (b == v[0])
            {
                x = x1 - 1;
                y = y1;
                return;
            }
            if (b == v[1])
            {
                x = x1 + 1;
                y = y1;
                return;
            }
            if (b == v[2])
            {
                x = x1;
                y = y1 - 1;
                return;
            }
            if (b == v[3])
            {
                x = x1;
                y = y1 + 1;
            }
        }

        private void GetPaths(ref int x1, ref int y1)
        {
            int ni = 0;
            const int nk = 64;
            do
            {
                for (int index1 = 1; index1 < Config.XCOUNT + 1; index1++)
                {
                    for (int index2 = 1; index2 < Config.YCOUNT + 1; index2++)
                    {
                        if (_pathFind[index1][index2] == ni)
                        {
                            int c1 = _pathFind[index1 - 1][index2];
                            int c2 = _pathFind[index1 + 1][index2];
                            int c3 = _pathFind[index1][index2 - 1];
                            int c4 = _pathFind[index1][index2 + 1];
                            if (c1 == 254)
                            {
                                _pathFind[index1 - 1][index2] = ni + 1;
                            }
                            if (c2 == 254)
                            {
                                _pathFind[index1 + 1][index2] = ni + 1;
                            }
                            if (c3 == 254)
                            {
                                _pathFind[index1][index2 - 1] = ni + 1;
                            }
                            if (c4 == 254)
                            {
                                _pathFind[index1][index2 + 1] = ni + 1;
                            }
                            if (c1 == 253)
                            {
                                MinValue(index1 - 1, index2, ref x1, ref y1);
                                return;
                            }
                            if (c2 == 253)
                            {
                                MinValue(index1 + 1, index2, ref x1, ref y1);
                                return;
                            }
                            if (c3 == 253)
                            {
                                MinValue(index1, index2 - 1, ref x1, ref y1);
                                return;
                            }
                            if (c4 == 253)
                            {
                                MinValue(index1, index2 + 1, ref x1, ref y1);
                                return;
                            }
                        }
                    }
                }
                ni++;
            }
            while (ni <= nk);
        }

        public void Wave(ref int x1, ref int y1, int x2, int y2)
        {
            for (int i = 0; i < Config.XCOUNT + 2; i++)
            {
                for (int j = 0; j < Config.YCOUNT + 2; j++)
                {
                    _pathFind[i][j] = _path[i][j];
                }
            }
            x1++;
            y1++;
            x2++;
            y2++;
            _pathFind[x1][y1] = 253;
            _pathFind[x2][y2] = 0;
            GetPaths(ref x1, ref y1);
            x1--;
            y1--;
        }

        public void SelectRoom(int rx, int ry)
        {
            _rx = rx;
            _ry = ry;
            SetPaths();
        }

        public void AddRoom(int rx, int ry, Room room)
        {
            _rooms[rx][ry] = room;
        }

        public Room CurrentRoom => _rooms[_rx][_ry];
    }
}
