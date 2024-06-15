namespace _20240614_02
{
    public class Program
    {
        public static void Main(string[] args)
        {
            // 자료형 종류
            // 기본 자료형 : int, float, bool, string
            // 사용자 정의 자료형 : Enum, Struct, Class etc

            int a = 0;
            float b = 0.2f;
            bool c = false;
            string d = "Orange";//char d = 'a';

            // C# 변수 특징
            // object가 가장 베이스 (class)
            // object에 존재하는 함수 4개
            // GetType, GetHashCode, ToString, Equals
            // 어떤 자료형이든 있음.

            Console.WriteLine("a : " + a.ToString());
            Console.WriteLine("b : " + b.ToString());
            Console.WriteLine("c : " + c.ToString());
            Console.WriteLine("d : " + d);
            object e; // C++의 void*같은 역할


            // C++ 에서 auto를 웬만해서는 쓰지마라 -> 왜?
            // C++ 포인터의 특성
            // 그렇기에 우리가 주솟값을 넣는건지 아닌지, 주솟값의 주솟값을 넣는건지 애매할 때가 많음

            var aa = 6;
            Console.WriteLine("aa : " + aa);

            
        }
    }
}
