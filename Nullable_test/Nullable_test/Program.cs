using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Nullable_test
{
    class Program
    {
        static void Main(string[] args)
        {
            int? num1 = null;
            Console.WriteLine("does num1 has a value? {0}",(num1.HasValue));
            num1 = 10;
            Console.WriteLine("does num1 has a value? {0}", (num1.HasValue));
            int ? num2 = 10;
            Console.WriteLine(num1.Value);
            Console.WriteLine(num2.Value);
            Console.WriteLine(num1.Equals(num2));
           

        }
    }
}
