using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Var_test
{
    class Program
    {
        static void Main(string[] args)
        {
            var var1 = "Hello World!";
            var var2 = 1;
            var var3 = 1.1;
            Console.WriteLine("var1");
            Console.WriteLine("type: {0} value: {1}", var1.GetType(),var1);

            Console.WriteLine("var2");
            Console.WriteLine("type: {0} value: {1}", var2.GetType(), var2);

            Console.WriteLine("var3");
            Console.WriteLine("type: {0} value: {1}", var3.GetType(), var3);

        }
    }
}
