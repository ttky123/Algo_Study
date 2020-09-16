using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace triant_operator
{
    class Program
    {
        static bool MyHasValue(int? num) => num == null ? false : true;
        static void Main(string[] args)
        {
            int? num = null;
            Console.WriteLine(MyHasValue(num));
            num = 10;
            Console.WriteLine(MyHasValue(num));

        }
    }
}
