using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20240619_02
{
    public class Student
    {


    }

    public enum MyEnum
    {
        A = 1, 
        B = 2,
    }
    

    public class App
    {
        public void Run()
        {
            GC.Collect(); // 가비지컬렉터 요청. 100%되진 않음

            int a = 5; // struct System.Int32 -> 즉 stack 영역. struct는 stack영역이기에
            float b = 0.0f; // struct System.Single -> 즉 stack 영역

            object o = a; // class -> 즉 heap 영역 // boxing : 값 형식을 객체로 변환
            int c = (int)o; // unboxing : 객체를 다시 값 형식으로 변환

            // heap 영역은 stack의 포인터를 가져올 수 있지만
            // stack 영역은 heap 영역에서 포인터를 가져올 수 없음

            // <Boxing>
            //Boxing은 값 형식을 참조 형식으로 변환하는 과정입니다.
            //C#에서는 값 형식(예: int, double, struct 등)을 객체로 취급해야 할 때가 있습니다. 
            //이때 값 형식을 객체로 변환하는 것을 boxing이라고 합니다.
            //이 변환은 값 형식을 힙(heap)에 저장된 객체로 감싸는 것을 의미합니다.

            // <Unboxing>
            //Unboxing은 참조 형식을 다시 값 형식으로 변환하는 과정입니다.
            //boxing된 객체에서 원래의 값 형식을 추출하는 것을 의미합니다.

            // C# 변수 특징
            // 1. 모든 변수는 Struct or Class 다.
            // 2. 모든 변수는 object로 변환이 가능하다.
            //      - 그렇기에 ToString과 GetType, GetHashCode, Equals 함수를 모든 변수에서 사용 가능하다.


            // boxing unboxing
            // 주로 할 수 있는 실수
            // 1. 가장 쉬운 실수
            // Test02();

            // 2. enum ( C# 특정 버전 이후부터는 고쳐진거로 아는데, 아마 Unity는 안 고쳐진걸로 알고 있음)
            // Test03();


            // 면접용 외울 내용 한줄 요약!
            // 1. unboxing은 힙에 쓰레기가 남는다 그래서 GC 때문에 좋지 않다. 안 쓰는게 좋다.
            //                                          GC -> Garbage Collector
            // 2. boxing도 느리다. 지양하는 게 좋다.
        }

        private void Test03()
        {
            MyEnum a = MyEnum.A;
            MyEnum b = MyEnum.B;

            // boxing이 발생
            // equals보단 == 을 쓰는 걸 지향
            if(a.Equals(b))
            {

            }
        }
        private void Test02()
        {
            List<object> list = new List<object>();
            list.Add(0);
            list.Add(new Student());
            list.Add(5);

            foreach (object o in list)
            {
                if (o is Student)
                {
                    Student student = (Student)o;
                }
                else if (o is int)
                {
                    int value = (int)o; // object => int (unboxing)
                   // 반복문이기에 요소가 백개면 백번의 unboxing이 일어남. -> 성능 저하
                }
            }
        }
        private void Test01()
        {
            ArrayList list = new ArrayList();
            int myValue = 123;

            // Boxing
            list.Add(myValue);

            // Unboxing
            int unboxedValue = (int)list[0];
            Console.WriteLine(list[0]); // 성능부담, 타입안정성이 보장 안 됨
        }
    }
}
