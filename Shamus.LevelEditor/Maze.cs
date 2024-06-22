﻿using System.Collections.Generic;
using System.Linq;

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
        BROWN_KEY = 19,
        CYAN_KEY = 20,
        GREEN_KEY = 21,
        ORANGE_KEY = 22,
        PURPLE_KEY = 23,
        RED_KEY = 24,
        BLUE_LOCK = 25,
        BROWN_LOCK = 26,
        CYAN_LOCK = 27,
        GREEN_LOCK = 28,
        ORANGE_LOCK = 29,
        PURPLE_LOCK = 30,
        RED_LOCK = 31
    }

    public class Maze
    {
	    private readonly byte[,,,] _data;
	    private readonly int[][] _path;
	    private readonly int[][] _pathFind;
        private int _rx;
        private int _ry;

        public Maze()
        {
            _data = new byte[Config.MAX_ROOM_X, Config.MAX_ROOM_Y, Config.XCOUNT, Config.YCOUNT];
            _path = new int[Config.XCOUNT + 2][];
            _pathFind = new int[Config.XCOUNT + 2][];
            for (int index = 0; index < Config.XCOUNT + 2; index++)
            {
                _path[index] = new int[Config.YCOUNT + 2];
                _pathFind[index] = new int[Config.YCOUNT + 2];
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
                        Item item = GetObject(_rx, _ry, index1 - 1, index2 - 1);
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
