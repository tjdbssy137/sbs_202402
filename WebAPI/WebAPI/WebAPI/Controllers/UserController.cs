using IdentityServer4.Extensions;
using Microsoft.AspNetCore.Mvc;

namespace WebAPI.Controllers
{

    // 제대로 된 프레임워크나 
    // 제대로된 엔진
    // 블랙박스
    // -> 우리가 실제로 코드를 본순 없지만
    // 우리가 못보는 곳에서 무언가를 하는/..

    // builder.Service.AddController();
    // -> 컨트롤러를 쓰겠다

    // 모든 컨트롤러는 종속성이 생성됨
    // builder 안에 내가 원하는 서비스를 집어넣으면
    // 생성자에서 다 받을 수 있음
    // builder -> 모든 서비스를 알아서 잘 딱 맞게 생성자에 원하는 내용을 넣어줌

    // ILogger<객체> 가장 기본적인 ASP .NET 서버의 logger형태

    [ApiController]
    [Route("[controller]")]

    public class UserController : ControllerBase
    {
        private static int newUserId = 1;
        private static List<User> _users = new List<User>();
        // Get Method
        // id를 통해서 User 정보 조회

        // Post Method
        // 유저를 새롭게 추가
        
        // Put Method
        // Id와 Email을 넣으면
        // 해당 Id의 Email이 변경되도록 수정

        // Delete Method
        // Id를 넣으면 해당 유저 삭제
        private readonly ILogger<UserController> _logger;
        public UserController(ILogger<UserController> logger)
        {
            _logger = logger;
        }

        [HttpGet()]
        public User UserInfo([FromQuery] int id)
        {
            /*foreach (var user in _users) 
            {
                if (user.Id == id)
                {
                    return user;
                }
            }*/
            // linq
            // users 안에 있는 리스트를
            // u라는 이름으로 순회하면서
            // u.Id == id이면 배열이 나오는데
            var rv = _users.Where(u => u.Id == id).FirstOrDefault();
            if(rv == null)
            {
                throw new Exception("bad request");
            }
            return rv;
        }

        [HttpPost()]
        public bool AddUser([FromQuery] string name, string email, string password)
        {
            User newUser = new User()
            { 
                Id = newUserId,
                Name = name,
                Email = email,
                Password = password
            };
            _users.Add(newUser);
            newUserId++;
            return true;
        }

        [HttpPut()]
        public bool EditUserInfo([FromQuery] int id, string email)
        {
            var user = _users.Where(u => u.Id == id).FirstOrDefault();
            if(user == null)
            {
                return false;
            }    
            user.Email = email;

            // User => Class(heap)
            // List<User> => Class(heap)
            // List<User> 들고 있는 데이터 값은
            // 주소값
            // user를 찾은 시점에서 주소값에 변경
            return true;
        }

        [HttpDelete()]
        public bool DeleteUser([FromQuery] int id)
        {
            User deleteUser = _users.Where(u => u.Id == id).FirstOrDefault();
            if (deleteUser == null)
            {
                return false;
            }
            _users.Remove(deleteUser);
            return true;
        }

        // HTTP 통신 특징
        // Method를 같이 보내게 되어있음
        // URL + Method를 통해서 어떤 Controller의 어떤 함수로 접근할 건지
        // Method중에 하나가 GET
        // GET, POST
        // PUT, DELETE

        // 함수명을 GetItem으로 짓고 실제 동작이 다를 수 있다. 예를 들어 게임 종류가 된다든가..
        /* [HttpDelete("Test")]
         public List<int> Test()
         {
             return new List<int>() { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
         }*/

        // 좋은 코드는 함수명만 봐도 대충 뭐하는 앤지 알아야한다
        // GetUserData
        // UpdateUserData
        // 특정 데이터를 진짜진짜 극도로 아껴야하는 프로젝트에서는
        // 함수명의 글자수마저 데이터가 아깝다

        // Method에 의미를 담자

        // Method GET에 User Controller 함수를 호출하면
        // User 정보를 출력해주는 함수

        // Method POST에 User Controller 함수를 호출하면
        // User을 Create 해주는

        // Method PUT에 User Controller 함수를 호출하면
        // User을 Update 해주는

        // Method DELETE에 User Controller 함수를 호출하면
        // User을 Delete 해주는

        // API로 만들자 (REST Api 규약)

        // ---------------------------------
        //      축약 버전
        // ---------------------------------

        // Method GET에 User Controller 함수를 호출하면
        // User 정보를 출력해주는 함수

        // Method POST에 User Controller 함수를 호출하면
        // User을 정보가 변경되게 해주는

    }
}
