using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Windows.Forms;

namespace DataEncrypt
{
    public partial class FormMain : Form
    {
        public FormMain()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            DecryptFromFile();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int i;
            string path = Directory.GetCurrentDirectory()+ "\\"+"MyData.txt";
            FileInfo fi = new FileInfo(path);
            StreamWriter writer = null;
            writer = new StreamWriter(path, false,System.Text.Encoding.Default);
            char[] data = textBox1.Text.ToCharArray();
            char[] key = Guid.NewGuid().ToString("N").ToCharArray();//GUID (Globally Unique Identifier) 全球唯一标识符
            Random rd = new Random();
            int RandomKey = rd.Next(65, 90);
            for (i = 0; i < key.Length; i++)
            {
                RandomKey = rd.Next(1, 10);
                writer.Write(key[i]);
                writer.Write(RandomKey);
            };
            for (i = 0; i < data.Length; i++)
            {
                data[i] ^= key[i % key.Length];
                writer.Write(data[i]);
            }
            writer.Close();
        }
        public void DecryptFromFile()
        {
            textBox1.Text = "";
            int i;
            string path = Directory.GetCurrentDirectory() + "\\" + "MyData.txt";
            FileInfo fi = new FileInfo(path);
            StreamReader reader = null;
            reader = new StreamReader(path, System.Text.Encoding.Default);
            char []key=new char[64]  ;//GUID (Globally Unique Identifier) 全球唯一标识符
            for (i = 0; i < 32; i++)
            {
                key[i]=(char)reader.Read();
                reader.Read();
            };
            string tmp;
            int ascii=reader.Read();
            char ch=(char)ascii;
            tmp = ch.ToString();
            i = 0;
            while (ascii!=-1)
            {
                ascii =reader.Read();
                ch = (char)ascii;
                if(ascii!=-1)
                tmp += ch.ToString();
            }
            char[] data=tmp.ToCharArray();
            for (i = 0; i < data.Length; i++)
            {
                data[i] ^= key[i % key.Length];
                textBox1.Text += data[i].ToString();
            }
            reader.Close();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            DecryptFromFile();
        }
    }
}
