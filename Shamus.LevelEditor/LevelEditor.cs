using System;
using System.Drawing;
using System.IO;
using System.Text;
using System.Windows.Forms;
using System.Xml;

namespace Shamus.LevelEditor
{
    public partial class LevelEditor : Form
    {
        private readonly Pen blackPen;

        private readonly MazeBuilder mazeBuilder = new MazeBuilder();
        private Maze maze;
        private Room room;

        public LevelEditor()
        {
            InitializeComponent();

            numericX.Minimum = 1;
            numericX.Maximum = Config.MAX_ROOM_X;

            numericY.Minimum = 1;
            numericY.Maximum = Config.MAX_ROOM_Y;

            blackPen = new Pen(Color.Black);

            byte[] data = new byte[Config.DATA_SIZE];
            CreateNewMaze(data);
        }

        private void toolStripButton4_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            byte[] data = new byte[Config.DATA_SIZE];
            CreateNewMaze(data);
            Refresh();
        }

        private void CreateNewMaze(byte[] data)
        {
            mazeBuilder.BuildMaze(data);
            maze = mazeBuilder.CurrentMaze;
            maze.SelectRoom(0, 0);
            room = maze.CurrentRoom;
            numericX.Value = 1;
            numericY.Value = 1;
        }

        private void toolStripButton2_Click(object sender, EventArgs e)
        {
            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                byte[] data;
                using (XmlTextReader xmlTextReader = new XmlTextReader(openFileDialog.FileName))
                {
                    xmlTextReader.ReadStartElement();
                    xmlTextReader.ReadStartElement();
                    char[] chars = xmlTextReader.ReadString().ToCharArray();
                    data = new byte[chars.Length];
                    for (int index = 0; index < chars.Length; index++)
                    {
                        data[index] = (byte) (chars[index] - 48);
                    }
                }
                CreateNewMaze(data);
                Refresh();
            }
        }

        private void toolStripButton3_Click(object sender, EventArgs e)
        {
            if (saveFileDialog.ShowDialog() == DialogResult.OK)
            {
                using (TextWriter textWriter = File.CreateText(saveFileDialog.FileName))
                {
                    XmlTextWriter xmlTextWriter = new XmlTextWriter(textWriter);
                    xmlTextWriter.WriteStartElement("XnaContent");
                    xmlTextWriter.WriteStartElement("Asset");
                    xmlTextWriter.WriteAttributeString("Type", "System.String");
                    StringBuilder str = new StringBuilder();
                    byte[] data = mazeBuilder.Data(maze);
                    foreach (byte t in data)
                    {
                        str.Append(t);
                    }
                    xmlTextWriter.WriteString(str.ToString());
                    xmlTextWriter.WriteEndElement();
                    xmlTextWriter.WriteEndElement();
                    xmlTextWriter.Close();
                }
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
                    Item item = room.GetObject(i, j);
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
            maze.SelectRoom((int) numericX.Value - 1, (int) numericY.Value - 1);
            room = maze.CurrentRoom;
            Refresh();
        }

        private void LevelEditor_Load(object sender, EventArgs e)
        {
            Array memberInfos = typeof (Item).GetEnumValues();
            foreach (var memberInfo in memberInfos)
            {
                objects.Items.Add(memberInfo);
            }
            objects.SelectedIndex = 0;
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

        private void objects_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (objects.SelectedIndex > 0)
            {
                itemBox.Image = images.Images[objects.SelectedIndex - 1];
            }
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
            if (numericY.Value < Config.MAX_ROOM_Y)
            {
                numericY.Value++;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (numericX.Value < Config.MAX_ROOM_X)
            {
                numericX.Value++;
            }
        }

        private void editorBox_MouseClick(object sender, MouseEventArgs e)
        {
            int i = (e.X * Config.XCOUNT) / editorBox.Width;
            int j = (e.Y * Config.YCOUNT) / editorBox.Height;
            room.SetObject(i, j, (Item)objects.SelectedIndex);
            Refresh();
        }

        private void editorBox_MouseMove(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                int i = (e.X * Config.XCOUNT) / editorBox.Width;
                int j = (e.Y * Config.YCOUNT) / editorBox.Height;
                room.SetObject(i, j, (Item)objects.SelectedIndex);
                Refresh();
            }
        }
    }
}
