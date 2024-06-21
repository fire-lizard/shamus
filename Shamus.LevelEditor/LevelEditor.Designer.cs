namespace Shamus.LevelEditor
{
    partial class LevelEditor
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(LevelEditor));
            this.editorBox = new System.Windows.Forms.PictureBox();
            this.previewBox = new System.Windows.Forms.PictureBox();
            this.images = new System.Windows.Forms.ImageList(this.components);
            this.toolStrip = new System.Windows.Forms.ToolStrip();
            this.toolStripButton1 = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton2 = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton3 = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton4 = new System.Windows.Forms.ToolStripButton();
            this.objects = new System.Windows.Forms.ComboBox();
            this.numericX = new System.Windows.Forms.NumericUpDown();
            this.numericY = new System.Windows.Forms.NumericUpDown();
            this.itemBox = new System.Windows.Forms.PictureBox();
            this.saveFileDialog = new System.Windows.Forms.SaveFileDialog();
            this.openFileDialog = new System.Windows.Forms.OpenFileDialog();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.coordLabel = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.editorBox)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.previewBox)).BeginInit();
            this.toolStrip.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericX)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericY)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.itemBox)).BeginInit();
            this.SuspendLayout();
            // 
            // editorBox
            // 
            this.editorBox.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.editorBox.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.editorBox.Location = new System.Drawing.Point(12, 28);
            this.editorBox.Name = "editorBox";
            this.editorBox.Size = new System.Drawing.Size(337, 354);
            this.editorBox.TabIndex = 0;
            this.editorBox.TabStop = false;
            this.editorBox.Paint += new System.Windows.Forms.PaintEventHandler(this.editorBox_Paint);
            this.editorBox.MouseClick += new System.Windows.Forms.MouseEventHandler(this.editorBox_MouseClick);
            this.editorBox.MouseMove += new System.Windows.Forms.MouseEventHandler(this.editorBox_MouseMove);
            // 
            // previewBox
            // 
            this.previewBox.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.previewBox.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.previewBox.Location = new System.Drawing.Point(355, 28);
            this.previewBox.Name = "previewBox";
            this.previewBox.Size = new System.Drawing.Size(125, 100);
            this.previewBox.TabIndex = 1;
            this.previewBox.TabStop = false;
            this.previewBox.Click += new System.EventHandler(this.previewBox_Click);
            this.previewBox.Paint += new System.Windows.Forms.PaintEventHandler(this.previewBox_Paint);
            // 
            // images
            // 
            this.images.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("images.ImageStream")));
            this.images.TransparentColor = System.Drawing.Color.Transparent;
            this.images.Images.SetKeyName(0, "extra1.png");
            this.images.Images.SetKeyName(1, "mistery.png");
            this.images.Images.SetKeyName(2, "door.png");
            this.images.Images.SetKeyName(3, "line1.png");
            this.images.Images.SetKeyName(4, "line2.png");
            this.images.Images.SetKeyName(5, "line3.png");
            this.images.Images.SetKeyName(6, "line4.png");
            this.images.Images.SetKeyName(7, "line5.png");
            this.images.Images.SetKeyName(8, "wall1.png");
            this.images.Images.SetKeyName(9, "wall2.png");
            this.images.Images.SetKeyName(10, "wall3.png");
            this.images.Images.SetKeyName(11, "wall4.png");
            this.images.Images.SetKeyName(12, "wall5.png");
            this.images.Images.SetKeyName(13, "wall6.png");
            this.images.Images.SetKeyName(14, "wall7.png");
            this.images.Images.SetKeyName(15, "wall8.png");
            this.images.Images.SetKeyName(16, "wall9.png");
            this.images.Images.SetKeyName(17, "blue_key.png");
            this.images.Images.SetKeyName(18, "blue_lock.png");
            this.images.Images.SetKeyName(19, "brown_key.png");
            this.images.Images.SetKeyName(20, "brown_lock.png");
            this.images.Images.SetKeyName(21, "cyan_key.png");
            this.images.Images.SetKeyName(22, "cyan_lock.png");
            this.images.Images.SetKeyName(23, "green_key.png");
            this.images.Images.SetKeyName(24, "green_lock.png");
            this.images.Images.SetKeyName(25, "orange_key.png");
            this.images.Images.SetKeyName(26, "orange_lock.png");
            this.images.Images.SetKeyName(27, "purple_key.png");
            this.images.Images.SetKeyName(28, "purple_lock.png");
            this.images.Images.SetKeyName(29, "red_key.png");
            this.images.Images.SetKeyName(30, "red_lock.png");
            // 
            // toolStrip
            // 
            this.toolStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripButton1,
            this.toolStripButton2,
            this.toolStripButton3,
            this.toolStripButton4});
            this.toolStrip.Location = new System.Drawing.Point(0, 0);
            this.toolStrip.Name = "toolStrip";
            this.toolStrip.Size = new System.Drawing.Size(492, 25);
            this.toolStrip.TabIndex = 2;
            this.toolStrip.Text = "toolStrip1";
            // 
            // toolStripButton1
            // 
            this.toolStripButton1.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton1.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton1.Image")));
            this.toolStripButton1.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton1.Name = "toolStripButton1";
            this.toolStripButton1.Size = new System.Drawing.Size(23, 22);
            this.toolStripButton1.Text = "New";
            this.toolStripButton1.Click += new System.EventHandler(this.toolStripButton1_Click);
            // 
            // toolStripButton2
            // 
            this.toolStripButton2.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton2.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton2.Image")));
            this.toolStripButton2.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton2.Name = "toolStripButton2";
            this.toolStripButton2.Size = new System.Drawing.Size(23, 22);
            this.toolStripButton2.Text = "Open";
            this.toolStripButton2.Click += new System.EventHandler(this.toolStripButton2_Click);
            // 
            // toolStripButton3
            // 
            this.toolStripButton3.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton3.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton3.Image")));
            this.toolStripButton3.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton3.Name = "toolStripButton3";
            this.toolStripButton3.Size = new System.Drawing.Size(23, 22);
            this.toolStripButton3.Text = "Save";
            this.toolStripButton3.Click += new System.EventHandler(this.toolStripButton3_Click);
            // 
            // toolStripButton4
            // 
            this.toolStripButton4.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton4.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton4.Image")));
            this.toolStripButton4.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton4.Name = "toolStripButton4";
            this.toolStripButton4.Size = new System.Drawing.Size(23, 22);
            this.toolStripButton4.Text = "Exit";
            this.toolStripButton4.Click += new System.EventHandler(this.toolStripButton4_Click);
            // 
            // objects
            // 
            this.objects.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.objects.FormattingEnabled = true;
            this.objects.Location = new System.Drawing.Point(355, 134);
            this.objects.Name = "objects";
            this.objects.Size = new System.Drawing.Size(125, 21);
            this.objects.TabIndex = 3;
            this.objects.SelectedIndexChanged += new System.EventHandler(this.objects_SelectedIndexChanged);
            // 
            // numericX
            // 
            this.numericX.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.numericX.Location = new System.Drawing.Point(355, 336);
            this.numericX.Maximum = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.numericX.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericX.Name = "numericX";
            this.numericX.ReadOnly = true;
            this.numericX.Size = new System.Drawing.Size(125, 20);
            this.numericX.TabIndex = 4;
            this.numericX.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericX.ValueChanged += new System.EventHandler(this.numericX_ValueChanged);
            // 
            // numericY
            // 
            this.numericY.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.numericY.Location = new System.Drawing.Point(355, 362);
            this.numericY.Maximum = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.numericY.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericY.Name = "numericY";
            this.numericY.ReadOnly = true;
            this.numericY.Size = new System.Drawing.Size(125, 20);
            this.numericY.TabIndex = 5;
            this.numericY.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericY.ValueChanged += new System.EventHandler(this.numericY_ValueChanged);
            // 
            // itemBox
            // 
            this.itemBox.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.itemBox.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.itemBox.Location = new System.Drawing.Point(355, 161);
            this.itemBox.Name = "itemBox";
            this.itemBox.Size = new System.Drawing.Size(125, 119);
            this.itemBox.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.itemBox.TabIndex = 7;
            this.itemBox.TabStop = false;
            // 
            // saveFileDialog
            // 
            this.saveFileDialog.DefaultExt = "dat";
            this.saveFileDialog.Filter = "DAT files|*.dat";
            // 
            // openFileDialog
            // 
            this.openFileDialog.DefaultExt = "dat";
            this.openFileDialog.Filter = "DAT files|*.dat";
            // 
            // button1
            // 
            this.button1.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.button1.Image = ((System.Drawing.Image)(resources.GetObject("button1.Image")));
            this.button1.Location = new System.Drawing.Point(355, 307);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(25, 23);
            this.button1.TabIndex = 8;
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.button2.Image = ((System.Drawing.Image)(resources.GetObject("button2.Image")));
            this.button2.Location = new System.Drawing.Point(448, 307);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(25, 23);
            this.button2.TabIndex = 9;
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // button3
            // 
            this.button3.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.button3.Image = ((System.Drawing.Image)(resources.GetObject("button3.Image")));
            this.button3.Location = new System.Drawing.Point(386, 307);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(25, 23);
            this.button3.TabIndex = 10;
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // button4
            // 
            this.button4.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.button4.Image = ((System.Drawing.Image)(resources.GetObject("button4.Image")));
            this.button4.Location = new System.Drawing.Point(417, 307);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(25, 23);
            this.button4.TabIndex = 11;
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // coordLabel
            // 
            this.coordLabel.AutoSize = true;
            this.coordLabel.Location = new System.Drawing.Point(356, 287);
            this.coordLabel.Name = "coordLabel";
            this.coordLabel.Size = new System.Drawing.Size(0, 13);
            this.coordLabel.TabIndex = 12;
            // 
            // LevelEditor
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(492, 394);
            this.Controls.Add(this.coordLabel);
            this.Controls.Add(this.button4);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.itemBox);
            this.Controls.Add(this.numericY);
            this.Controls.Add(this.numericX);
            this.Controls.Add(this.objects);
            this.Controls.Add(this.toolStrip);
            this.Controls.Add(this.previewBox);
            this.Controls.Add(this.editorBox);
            this.Name = "LevelEditor";
            this.Text = "Level Editor";
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            this.Load += new System.EventHandler(this.LevelEditor_Load);
            ((System.ComponentModel.ISupportInitialize)(this.editorBox)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.previewBox)).EndInit();
            this.toolStrip.ResumeLayout(false);
            this.toolStrip.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericX)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericY)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.itemBox)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox editorBox;
        private System.Windows.Forms.PictureBox previewBox;
        private System.Windows.Forms.ImageList images;
        private System.Windows.Forms.ToolStrip toolStrip;
        private System.Windows.Forms.ToolStripButton toolStripButton1;
        private System.Windows.Forms.ToolStripButton toolStripButton2;
        private System.Windows.Forms.ToolStripButton toolStripButton3;
        private System.Windows.Forms.ToolStripButton toolStripButton4;
        private System.Windows.Forms.ComboBox objects;
        private System.Windows.Forms.NumericUpDown numericX;
        private System.Windows.Forms.NumericUpDown numericY;
        private System.Windows.Forms.PictureBox itemBox;
        private System.Windows.Forms.SaveFileDialog saveFileDialog;
        private System.Windows.Forms.OpenFileDialog openFileDialog;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Label coordLabel;
    }
}

