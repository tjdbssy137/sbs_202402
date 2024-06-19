using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20240619_03
{
    public class MyClass
    {
        private int _number;
        public int Number // Only 프로퍼티, 초기화 안 됨
        {
            get
            {
                return _number;
            }
            set // protected set을 하면 이 class를 상속받은 객체만 set 가능
            {
                _number = value;
            }
        }

        // 변수이자 프로퍼티
        public int Money { get; private set; } = 20; // 선언과 동시에 초기화
        public override string ToString()
        {
            return $"_number : {_number}";
        }
    }

    public class App
    {
        public void Run()
        {
            // Class
            // - Property
            // - 변수 초기화
            // - 상속

            // 변수를 만들면 
            // getter와 setter을 (필요시) 만들어줬음

            MyClass myClass = new MyClass();
            myClass.Number = 3;
            Console.WriteLine(myClass.ToString());
            // Console.WriteLine($"myClass.Number : {myClass.Number}");

            // myClass.Money = 4; // private 으로 막아뒀기 때문에 사용 안됨

            // 클래스 상속과 인터페이스
            // 상속은 공통된 부모의 기능을 같이 쓰기 위해서 아키텍처를 만드는 것..
            // Actor -> SpriteActor -> MoleActor
            // Actor -> FlipbookActor -> CreatureActor

            // Actor를 부모 클래스로 둔 이유는
            // Actor들을 한 번에 관리하기 위해서. (씬에서 vector<Actor*>로 들고 컨트롤하기 위해서)

            // SpriteActor
            // -> 스프라이트를 출력하는 함수 기능을 같이 쓰기 위해서

            // C#에서는 기능을 같이 쓰기 위해서 상속을 받는건지,
            // 관리를 위해서 상속을 받는 건지에 따라 인터페이스가 더 효율적일때가 있음

        }
    }

    // 인터페이스는 함수만 선언 가능
    // 프로퍼티는 함수다
    // 정의(구현)는 불가능
    public interface IAttacker
    { 
        void Attack();
        public float Damage {  get; set; }
    }


    public class Hero : IAttacker
    {
        public string Name = "Dummy";
        public float Hp = 100;
        public float Attack = 30;

        public float Damage { get; set; } = 30;

        void IAttacker.Attack() // 인터페이스를 상속 받으면 무조건 상속받은 인터페이스의 함수를 정의해야함.
        { 
            
        }
    }



}
