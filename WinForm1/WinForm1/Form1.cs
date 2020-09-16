using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Timers;
using System.Windows.Input;
using System.Threading;

namespace WinForm1
{ 
    public partial class Form1 : Form
    {
        private int count = 0;
        private System.Timers.Timer aTimer;
        private Thread Th;

        public Form1()
        {
            InitializeComponent();
        }
        bool isRunning = true;

        private void timerFunction(object sender, System.Timers.ElapsedEventArgs e)

        {
            //txtBox1.AppendText("X - " + Cursor.Position.X.ToString() + "     ");
            //txtBox1.AppendText("Y - " + Cursor.Position.Y.ToString());
            txtBox1.Text += Environment.NewLine;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Th = new Thread(KeyboardCheck);
            Th.SetApartmentState(ApartmentState.STA);
            CheckForIllegalCrossThreadCalls = false;
            Th.Start();
        }
        void KeyboardCheck()
        {
            while(isRunning)
            {
                Thread.Sleep(40);
                if((Keyboard.GetKeyStates(Key.CapsLock) & KeyStates.Down) > 0)
                {
                    count++;
                    if (count % 2 == 1)
                    {
                        aTimer = new System.Timers.Timer(100);
                        aTimer.Elapsed += timerFunction;
                        aTimer.Enabled = true;
                        txtBox1.AppendText("X - " + System.Windows.Forms.Cursor.Position.X.ToString() + "     ");
                        txtBox1.AppendText("X - " + System.Windows.Forms.Cursor.Position.X.ToString() + "     ");
                        txtBox1.Text += Environment.NewLine;
                    }
                    else
                    {
                        aTimer.Enabled = false;
                        Th.Abort();
                        
                    }
                }
                else if ((Keyboard.GetKeyStates(Key.NumPad0) & KeyStates.Down) > 0)
                {
                    if (count % 2 == 0)
                    {
                        aTimer.Enabled = false;
                        txtBox1.Text = "";
                    }
                }
            }
            
            
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            
            aTimer.Enabled = false;
            isRunning = false;
        }
    }
}
