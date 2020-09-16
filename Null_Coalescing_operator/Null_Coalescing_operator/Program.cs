using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Null_Coalescing_operator
{
    class Program
    {
        static void Main(string[] args)
        {
            string str1 = null;
            Console.WriteLine(str1 ?? "str1 is Null");
            str1 = "str1 is not Null anymore";
            Console.WriteLine(str1 ?? "str1 is Null");

        }
    }
}
