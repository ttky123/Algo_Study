using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static void Swap<T>(ref T left, ref T right)
        {
            T temp;
            temp = left;
            left = right;
            right = temp;
        }
        static void Main(string[] args)
        {
            int a = 1;
            int b = 2;
            double d1 = 0.1;
            double d2 = 0.2;
            char c1 = 'A';
            char c2 = 'B';

            Swap<int>(ref a, ref b);
            Console.WriteLine("{0} {1}", a, b);

            Swap<double>(ref d1, ref d2);
            Console.WriteLine("{0} {1}", d1, d2);

            Swap<char>(ref c1, ref c2);
            Console.WriteLine("{0} {1}", c1, c2);

        }
    }
}
