namespace _20240617_01
{
    public class Program
    {
        public static void Main(string[] args)
        {
            List<int> list = new List<int>();
            list.Add(1);
            list.Add(2);
            list.Add(3);
            list.Add(4);
            list.Add(5);
            for (int i = 0; i < list.Count; i++) 
            {
                Console.WriteLine(list[i]);
            }

            // pop_back의 인덱스 버전
            list.RemoveAt(0);
            // pop_back의 Value 버전
            list.Remove(4);

            Console.WriteLine("-------------------------");
            Console.WriteLine("RemoveAt(0), Remove(4)");
            for (int i = 0; i < list.Count; i++)
            {
                Console.WriteLine(list[i]);
            }

            List<int> list2 = new List<int>();
            // 동적할당 정적할당에 대한 영상을 한 번 더 보고.. 나도 찾아보기 이해 못함.
            // https://blog.naver.com/eludien/221462352935

            // c#은 delete를 안해도 자동으로 동적해제를 함
            // class 일 경우만 동적 할당.

            Console.WriteLine("-------------------------");
            for(int i = 0;i < 100; i++)
            {
                list2.Add(i);
            }
            // 람다식
            list2.RemoveAll(x => x % 2 == 0);
            // 아래와 같은 의미
            /*for(int i = 0; i < list2.Count;i++) 
            {
                int x = list2[i];
                if(x % 2 == 0)
                {
                    list2.RemoveAt(i);
                }
            }*/

            list2.ForEach(x => Console.WriteLine(x));

            // map
            // 특징. key로 value를 빠르게 찾을 수 있다.
            // 대신, 모든 애들 순회가 살짝 어렵다.

            // C#에서의 map은 dictionary라고 함.

            Dictionary<int, string> dict = new Dictionary<int, string>();
            //dict.Add(0, "Orange");
            dict[0] = "Orange";

            // dict.ContainsKey => O(LogN)
            // dict.ContainsValue => O(N)

        }
    }
}
