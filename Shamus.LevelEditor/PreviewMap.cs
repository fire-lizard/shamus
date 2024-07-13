using System.Drawing;
using System.Windows.Forms;

namespace Shamus.LevelEditor
{
    public partial class PreviewMap : Form
    {
        private readonly Pen _pen = new Pen(Color.Black);
        private readonly Brush _blackBrush = new SolidBrush(Color.Black);
        private readonly Brush _blueBrush = new SolidBrush(Color.Blue);
        private readonly Brush _greenBrush = new SolidBrush(Color.Green);
        private readonly Brush _redBrush = new SolidBrush(Color.Red);

        public Maze Maze { get; set; }
        
        public PreviewMap()
        {
            InitializeComponent();
        }

        private void DrawGrid(PictureBox pictureBox, Graphics graphics, Pen pen)
        {
            float w = pictureBox.Width / (float)Config.MAX_ROOM_X;
            float h = pictureBox.Height / (float)Config.MAX_ROOM_Y;
            for (int i = 0; i < Config.MAX_ROOM_X; i++)
            {
                graphics.DrawLine(pen, i * w, 0, i * w, pictureBox.Height - 1);
            }
            for (int j = 0; j < Config.MAX_ROOM_Y; j++)
            {
                graphics.DrawLine(pen, 0, j * h, pictureBox.Width - 1, j * h);
            }
            graphics.DrawLine(pen, 0, pictureBox.Height - 1, pictureBox.Width - 1, pictureBox.Height - 1);
            graphics.DrawLine(pen, pictureBox.Width - 1, 0, pictureBox.Width - 1, pictureBox.Height - 1);
        }

        private void DrawMaze(PictureBox pictureBox, Graphics graphics)
        {
            float w = pictureBox.Width / (float)Config.MAX_ROOM_X;
            float h = pictureBox.Height / (float)Config.MAX_ROOM_Y;
            for (int i = 0; i < Config.MAX_ROOM_X; i++)
            {
                for (int j = 0; j < Config.MAX_ROOM_Y; j++)
                {
                    if (!Maze.IsEmptyRoom(i, j))
                    {
                        RectangleF rectangle = new RectangleF(i * w + 1, j * h + 1, w - 2, h - 2);
                        if (i <= 13 && j <= 4)
                        {
                            graphics.FillRectangle(_blackBrush, rectangle);
                        }
                        else if (i <= 22 && j <= 6)
                        {
                            graphics.FillRectangle(_blueBrush, rectangle);
                        }
                        else if (i <= 31 && j <= 10)
                        {
                            graphics.FillRectangle(_greenBrush, rectangle);
                        }
                        else
                        {
                            graphics.FillRectangle(_redBrush, rectangle);
                        }
                    }
                }
            }
        }


        private void previewBox_Paint(object sender, PaintEventArgs e)
        {
            DrawGrid(previewBox, e.Graphics, _pen);
            DrawMaze(previewBox, e.Graphics);
        }

        private void previewBox_MouseClick(object sender, MouseEventArgs e)
        {
            var levelEditor = Application.OpenForms["LevelEditor"] as LevelEditor;
            levelEditor.numericX.Value = e.X * Config.MAX_ROOM_X / previewBox.Width + 1;
            levelEditor.numericY.Value = e.Y * Config.MAX_ROOM_Y / previewBox.Height + 1;
            Close();
        }
    }
}
