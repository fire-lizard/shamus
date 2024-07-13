using System;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Windows.Forms;

namespace Shamus.LevelEditor
{
    public partial class LevelEditor : Form
    {
        private readonly Pen blackPen;

        private readonly MazeBuilder mazeBuilder = new MazeBuilder();
        private readonly Item[,] copyArray = new Item[Config.XCOUNT, Config.YCOUNT];
        private Maze maze;

        public LevelEditor()
        {
            InitializeComponent();

            numericX.Minimum = 1;
            numericX.Maximum = Config.MAX_ROOM_X;

            numericY.Minimum = 1;
            numericY.Maximum = Config.MAX_ROOM_Y;

            blackPen = new Pen(Color.Black);

            coordLabel.Anchor = AnchorStyles.Top | AnchorStyles.Right;

            byte[] data = new byte[Config.DATA_SIZE];
            CreateNewMaze(data);
        }

        private void toolStripButton4_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            CreateNewMaze(new byte[Config.DATA_SIZE]);
            Refresh();
        }

        private void CreateNewMaze(byte[] data)
        {
            mazeBuilder.BuildMaze(data);
            maze = mazeBuilder.CurrentMaze;
            numericX.Value = 1;
            numericY.Value = 1;
        }

        private void toolStripButton2_Click(object sender, EventArgs e)
        {
            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                if (new FileInfo(openFileDialog.FileName).Length != Config.DATA_SIZE)
                {
                    MessageBox.Show("Invalid file size!");
                    return;
                }
                CreateNewMaze(File.ReadAllBytes(openFileDialog.FileName));
                Refresh();
            }
        }

        private void toolStripButton3_Click(object sender, EventArgs e)
        {
            if (saveFileDialog.ShowDialog() == DialogResult.OK)
            {
                File.WriteAllBytes(saveFileDialog.FileName, mazeBuilder.Data(maze));
            }
        }

        private void DrawGrid(PictureBox pictureBox, Graphics graphics, Pen pen)
        {
            float w = pictureBox.Width / (float)Config.XCOUNT;
            float h = pictureBox.Height / (float)Config.YCOUNT;
            for (int i = 0; i < Config.XCOUNT; i++)
            {
                graphics.DrawLine(pen, i * w, 0, i * w, pictureBox.Height - 1);
            }
            for (int j = 0; j < Config.YCOUNT; j++)
            {
                graphics.DrawLine(pen, 0, j * h, pictureBox.Width - 1, j * h);
            }
        }

        private void DrawMaze(PictureBox pictureBox, Graphics graphics)
        {
            float w = pictureBox.Width/(float) Config.XCOUNT;
            float h = pictureBox.Height/(float) Config.YCOUNT;
            for (int i = 0; i < Config.XCOUNT; i++)
            {
                for (int j = 0; j < Config.YCOUNT; j++)
                {
                    Item item = maze.GetObject((int)numericX.Value - 1, (int)numericY.Value - 1, i, j);
                    int imageIndex = (int) item;
                    if (imageIndex > 0 && imageIndex <= images.Images.Count)
                    {
                        RectangleF rectangle = new RectangleF(i*w + 1, j*h + 1, w - 2, h - 2);
                        graphics.DrawImage(images.Images[(int) item - 1], rectangle);
                    }
                }
            }
        }

        private void ChangeRoom()
        {
            Refresh();
        }

        private void LevelEditor_Load(object sender, EventArgs e)
        {
            Array memberInfos = typeof (Item).GetEnumValues();
            foreach (var memberInfo in memberInfos)
            {
                objectlist.Items.Add(memberInfo);
            }
            objectlist.SelectedIndex = 0;
        }

        private void editorBox_Paint(object sender, PaintEventArgs e)
        {
            DrawGrid(editorBox, e.Graphics, blackPen);
            DrawMaze(editorBox, e.Graphics);
        }

        private void previewBox_Paint(object sender, PaintEventArgs e)
        {
            DrawGrid(previewBox, e.Graphics, blackPen);
            DrawMaze(previewBox, e.Graphics);
        }

        private void numericX_ValueChanged(object sender, EventArgs e)
        {
            ChangeRoom();
        }

        private void numericY_ValueChanged(object sender, EventArgs e)
        {
            ChangeRoom();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (numericX.Value > 1) numericX.Value--;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (numericY.Value > 1) numericY.Value--;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            if (numericY.Value < Config.MAX_ROOM_Y) numericY.Value++;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (numericX.Value < Config.MAX_ROOM_X) numericX.Value++;
        }

        private void editorBox_MouseClick(object sender, MouseEventArgs e)
        {
            int i = e.X * Config.XCOUNT / editorBox.Width;
            int j = e.Y * Config.YCOUNT / editorBox.Height;
            maze.SetObject((int)numericX.Value - 1, (int)numericY.Value - 1, i, j, (Item)objectlist.SelectedIndex);
            Refresh();
        }

        private void editorBox_MouseMove(object sender, MouseEventArgs e)
        {
            int i = e.X * Config.XCOUNT / editorBox.Width;
            int j = e.Y * Config.YCOUNT / editorBox.Height;
            coordLabel.Text = $"X = {i}; Y = {j}";
            if (e.Button == MouseButtons.Left)
            {
                maze.SetObject((int)numericX.Value - 1, (int)numericY.Value - 1, i, j, (Item)objectlist.SelectedIndex);
                Refresh();
            }
        }

        private void previewBox_Click(object sender, EventArgs e)
        {
            new PreviewMap { Maze = maze }.ShowDialog();
        }

        private void toolStripButton5_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < Config.XCOUNT; i++)
            {
                for (int j = 0; j < Config.YCOUNT; j++)
                {
                    var item = maze.GetObject((int)numericX.Value - 1, (int)numericY.Value - 1, i, j);
                    copyArray[i,j] = item;
                }
            }
        }

        private void toolStripButton6_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < Config.XCOUNT; i++)
            {
                for (int j = 0; j < Config.YCOUNT; j++)
                {
                    maze.SetObject((int)numericX.Value - 1, (int)numericY.Value - 1, i, j, copyArray[i, j]);
                }
            }
            Refresh();
        }

        private void toolStripButton7_Click(object sender, EventArgs e)
        {
            var walls = new[]
            {
                Item.WALL1, Item.WALL2, Item.WALL3, Item.WALL4,
                Item.WALL5, Item.WALL6, Item.WALL7,
                Item.WALL8, Item.WALL9, Item.WALL10
            };
            if (walls.Contains((Item)objectlist.SelectedIndex))
            {
                for (int i = 0; i < Config.XCOUNT; i++)
                {
                    for (int j = 0; j < Config.YCOUNT; j++)
                    {
                        var item = maze.GetObject((int)numericX.Value - 1, (int)numericY.Value - 1, i, j);
                        if (walls.Contains(item))
                        {
                            maze.SetObject((int)numericX.Value - 1, (int)numericY.Value - 1, i, j, (Item)objectlist.SelectedIndex);
                        }
                    }
                }
                Refresh();
            }
        }

        private void objectlist_SelectedIndexChanged(object sender, EventArgs e)
        {
            itemBox.Image = objectlist.SelectedIndex > 0 ? images.Images[objectlist.SelectedIndex - 1] : null;
        }

        private void toolStripButton8_Click(object sender, EventArgs e)
        {
            var lines = new[]
            {
                Item.LINE1, Item.LINE2, Item.LINE3,
                Item.LINE4, Item.LINE5
            };
            if (lines.Contains((Item)objectlist.SelectedIndex))
            {
                for (int i = 0; i < Config.XCOUNT; i++)
                {
                    for (int j = 0; j < Config.YCOUNT; j++)
                    {
                        var item = maze.GetObject((int)numericX.Value - 1, (int)numericY.Value - 1, i, j);
                        if (lines.Contains(item))
                        {
                            maze.SetObject((int)numericX.Value - 1, (int)numericY.Value - 1, i, j, (Item)objectlist.SelectedIndex);
                        }
                    }
                }
                Refresh();
            }
        }

        private void toolStripButton9_Click(object sender, EventArgs e)
        {
            numericX.Value = 4;
            numericY.Value = 2;
            ChangeRoom();
        }

        private void toolStripButton10_Click(object sender, EventArgs e)
        {
            numericX.Value = 17;
            numericY.Value = 3;
            ChangeRoom();
        }

        private void toolStripButton11_Click(object sender, EventArgs e)
        {
            numericX.Value = 24;
            numericY.Value = 6;
            ChangeRoom();
        }

        private void toolStripButton12_Click(object sender, EventArgs e)
        {
            numericX.Value = 36;
            numericY.Value = 10;
            ChangeRoom();
        }
    }
}
