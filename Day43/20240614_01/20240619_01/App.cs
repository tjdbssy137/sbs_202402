using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20240619_01
{
    public class App
    {
        public void Run()
        {
            Console.Write("문자를 입력하세요 : ");

            string testString = Console.ReadLine();
            if (int.TryParse(testString, out int temp))
            {
                Console.WriteLine($"성공, 값 : {temp}");
            }
            else
            {
                Console.WriteLine("실패");
            }
        }

        public void CallByReference01(ref int reference)
        {
            reference++;
        }

        public void CallByReference02(out int reference)
        {
            reference = 0;
        }
    }
}
