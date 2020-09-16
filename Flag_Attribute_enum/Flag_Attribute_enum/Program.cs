using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Flag_Attribute_enum
{
    class Program
    {
        [Flags]
        enum Colours
        {
            Black = 0,
            Red = 1,
            Blue = 2,
            Green = 4
        };
        static void Main(string[] args)
        {
            for (int i = 0; i <8; i++)
            {
                Console.WriteLine("{0,3} - {1}", i, ((Colours)i).ToString());
            }
        }
    }
}
