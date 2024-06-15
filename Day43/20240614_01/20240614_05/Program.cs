namespace _20240614_05
{
    public enum EnumTest
    {
        Rock,
        Scissor,
        Paper,
        None,
    }
    public class Program
    {
        public static void Main(string[] args)
        {
            EnumTest test = EnumTest.Rock;

            // new로 생성하면
            // Heap 영역에 생성되고, delete도 나중에 써줘야하는 거 아닌지?

            // 무조건 stack영역에 생성
            // 하지만 무조건 delete를 할 필요는 없음.(적어도 여기선)
            Console.WriteLine($"Rock Scissor Paper : {test.ToString()}");
            // C#만의 특징.
            // test.ToString()해주면 int가 아니라 enum명으로 나옴
        }
    }
}

// C# 접근 제어자 4개
// internal : 해당 프로젝트에서 모두 사용 가능 
// private : 자기 자신만 사용 가능
// public : 누구나 사용 가능
// protected : 나를 상속받은 애만 사용 가능