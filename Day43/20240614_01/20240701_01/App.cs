using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20240701_01
{
    public class Data
    {
        public string Name { get; set; }
        public string Program {  get; set; }
    }
    internal class App
    {
        private List<Data> _datas =new List<Data>();

        public void Run()
        {
            AddData("Apple", "A");
            AddData("Bubble", "B");
            AddData("Carrot", "C");
            AddData("Disable", "D");
            AddData("Friend", "F");
            AddData("Great", "G");
            AddData("Apple", "G");
            AddData("Bubble", "F");
            AddData("Carrot", "D");
            AddData("Disable", "C");
            AddData("Friend", "A");
            AddData("Apple", "F");
            AddData("Bubble", "A");
            AddData("Carrot", "G");
            AddData("Disable", "C");
            AddData("Friend", "B");
            AddData("Great", "A");
            
            //Display();

            // Group By : 데이터 컬럼을 리스트로 묶는 법
            var query = from d in _datas            // _datas에서 d라는 이름으로 가져와서
                        group d by d.Name into g    // d요소를 Name이라는 단위로 가져와서 그룹핑해줄 것이다
                        select g;                   // 그래서 g를 꺼낼 것이다

            // _datas에 들어간 정보중에서 Name별로 묶어서 데이터 좀 예쁘게 보고싶다.
            foreach (var item in query)
            { 
                Console.WriteLine($"{item.Key} : ");
                foreach(var item2 in item)
                {
                    Console.WriteLine($"{item2.Name}, {item2.Program}");
                }
            }

            // 1. 챔피언별로 스킬 리스트 가져오기 (이름 포함)
            // 2. 챔피언별로 아이템 리스트 가져오기
            // 3. 챔피언별로 레벨 가져오기
        }

        private void AddData(string name, string program)
        {
            _datas.Add(new Data { Name = name, Program = program });
        }

        private void Display()
        {
            foreach (Data data in _datas) 
            { 
                Console.WriteLine($"Name : {data.Name},\t Program : {data.Program}");
            }
        }

    }
}
