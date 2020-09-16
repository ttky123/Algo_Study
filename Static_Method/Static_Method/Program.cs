using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Static_Method
{
    public static class Student
    {
        private static int student_id;
        private static string name;
        private static string division;
        static Student()    //static 생성자
        {
            name = null;
            division = null;
            student_id = 0x00;
        }
        public static void set_info(string str1, string str2,int num)
        {
            name = str1;
            division = str2;
            student_id = num;
        }
        public static void print_info()
        {
            Console.WriteLine("Name: {0}", name);
            Console.WriteLine("Division: {0}", division);
            Console.WriteLine("ID: {0}", student_id);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            string myName = "Park Jae Won";
            int myId = 2015726030;
            string myDivision = "Computer Software";
            Student.set_info(myName, myDivision, myId);
            Student.print_info();

        }
    }
}
