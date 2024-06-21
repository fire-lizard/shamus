using System.Drawing;
using System.Windows.Forms;

namespace Shamus.LevelEditor
{
    public partial class PreviewMap : Form
    {
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
                    //Item item = room.GetObject(i, j);
                    //int imageIndex = (int)item;
                    //if (imageIndex > 0 && imageIndex <= images.Images.Count)
                    {
                        RectangleF rectangle = new RectangleF(i * w + 1, j * h + 1, w - 2, h - 2);
                        //graphics.DrawImage(images.Images[(int)item - 1], rectangle);
                    }
                }
            }
        }


        private void previewBox_Paint(object sender, PaintEventArgs e)
        {
            DrawGrid(previewBox, e.Graphics, new Pen(Color.Black));
            DrawMaze(previewBox, e.Graphics);
        }
    }
}
