using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
// Chat GPT 쓰는 습관 들이기
// 모르는 내용 검색하는 습관은 비추
// 써야할 때!
// 아는데 이거 이렇게 하면 노가다를 줄이고 좀 빨리할 수 있을거 같을 때! 사용.

// 회사에서 평가하는 잘하는 사람의 기준
//  - 친한사람이 잘하는 사람 (평가하는 사람 기준에서.. 내가 보기에 꼬운 인간 -> 객관적 평가 불가)
//      - 최대한 적만들지 말고, 유하게 넘어가야함.. 웬만한 상황에서..
//      - 그리고 사실, 커뮤니케이션을 잘하면 친한 사람이 많을 수밖에 없음.
//  - 생산성이 높은 사람
//      - 어떤 일을 시켰을 때 빨리하는 사람.
//      - 느리게 하는데 버그 있을 수 있음.. 하지만 개발 속도와 버그는 비례하지 않음.

// => 일잘한다고 평가 받는 사람과 일 잘하는 사람은 다를 수 있음.
namespace _20240628_01
{
    internal class App
    {
        public void Run()
        {
            //LINQ 코드쿼리 (Language-Integrated Query)
            // 데이터 테이블이 되게 많음
            // 테이블을 컨트롤 할 수 있는 무언가가 있으면 편리하다.
            // 테이블을 컨트롤 하는 일
            //      - DB에서는 Query라고 부름

            // LINQ를 제공하지 않는 언어도 존재..
            // C#에서의 가장 강력한 기능 중 하나는 LINQ가 잘 되어있다는 것.
            // Unity는 .net framework

            List<int> intList = new List<int>();
           

            for(int i = 0; i < 1000; i++)
            {
                intList.Add(i);
            }

            // 기본적으로 데이터를 뽑을 떄 Filter 기능을 많이 씀 (Where) (DB : Where)
            // 예를 들면 데이터 중 어떤 값을 가진 애들만 추출하고 싶다~!


            // LINQ 사용법

            // Where의 즉시실행버전은 Find임.
            var result1 = intList.Where(x => x % 2 == 0);
            
            // DB Query 문법이랑 되게 유사하게 생김
            // DB 내용을 그대로 써야하는 경우에 자주 씀
            var result2 = (from x in intList
                            where x % 2 == 0
                            select x);
            // IEnumerable<int>가 반환 됨
            //      -> IEnumerable은 잠재적 리스트.
            //      -> 나는 intList라는 애에서 x % 2 == 0 이것만 추출할 거야
            //      -> 뽑아오는 코드를 실행해야 그때 실행이 됨
            //      -> 뽑아오는 코드 : ToList()


            result1.ToList();


        }
    }
}
