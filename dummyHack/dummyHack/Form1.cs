using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace dummyHack
{
    public partial class Form1 : Form
    {
        [DllImport("user32.dll")]
        static extern void keybd_event(byte vk, byte scan, int flags, ref int extrainfo);
        [DllImport("user32.dll")]
        static extern void mouse_event(uint dwFlags, uint dx, uint dy, uint dwData, int dwExtraInfo);

        private const uint MOUSEMOVE = 0x0001;   // 마우스 이동
        private const uint ABSOLUTEMOVE = 0x8000;   // 전역 위치
        private const uint LBUTTONDOWN = 0x0002;   // 왼쪽 마우스 버튼 눌림
        private const uint LBUTTONUP = 0x0004;   // 왼쪽 마우스 버튼 떼어짐

        private bool m_bStart = false;
        public Form1()
        {
            InitializeComponent();
        }
    }
}
