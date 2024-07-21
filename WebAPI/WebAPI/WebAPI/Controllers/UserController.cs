using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using System.Runtime.InteropServices;
using WebApi.Data;
using WebApi.Models.DB;
using WebApi.Models.Dto;
using static Microsoft.EntityFrameworkCore.DbLoggerCategory;

namespace WebApi.Controllers
{
    [ApiController]
    [Route("[controller]")]
    public class UserController : ControllerBase
    {
        private static int _newUserId = 1;
        private static List<User> _users = new List<User>();
        private readonly Context _context;

        //Get Method
        //id를 통해서 User정보 조회

        //Post Method
        //유저를 새롭게 추가

        //Put Method
        //Id와 Email을 넣으면
        //해당 Id의 Email이 변경되도록 수정

        //Delete Method
        //Id를 넣으면
        //해당 유저가 삭제되게 수정

        private readonly ILogger<UserController> _logger;
        public UserController(ILogger<UserController> logger, Context context) 
        { 
            _logger = logger;
            _context = context;
        }

        /*[HttpGet("TestGet")]
        public async Task<object> GetBsyTblUsers()
        {
            object rv;
            rv = await _context.BsyTblUsers
                .Include(user => user.ChampionKeyNavigation)
                .Select(user => new
                {
                    UserKey = user.Key,
                    ChampionName = user.ChampionKeyNavigation.Name,
                    UserLevel = user.Level
                })
                .ToListAsync();

            return rv;
        }*/

        [HttpGet("GetChampionInfoByUserKey")]
        public async Task<CommonResult<ResponseDtoGetChampionInfoByUserKey>> 
            GetChampionInfoByUserKey([FromQuery] RequestDtoGetChampionInfoByUserKey requestDto)
        {
            CommonResult<ResponseDtoGetChampionInfoByUserKey> rv = new ();
            try
            {
                _context.BsyTblUsers.Include(user => user.ChampionKeyNavigation);

                var query = await (
                    from user in _context.BsyTblUsers
                    where user.Key == requestDto.UserKey
                    select new ResponseDtoGetChampionInfoByUserKey
                    {
                        UserKey = user.Key,
                        ChampionName = user.ChampionKeyNavigation.Name,
                        ChampionLevel = user.Level ?? 0
                    }).ToListAsync();

                if (query.Count < 1)
                {
                    throw new CommonExeption(EStatusCode.NotFoundEntity, 
                        "해당 키를 가진 유저가 없습니다."); // try문 밖으로 던짐
                }
                var selectUser = query.First();

                rv.StatusCode = EStatusCode.OK;
                rv.Message = "";
                rv.IsSuccess = true;
                rv.Data = selectUser;
                /*SELECT `b`.`_key` AS `UserKey`, `b`.`_level` AS `ChampionLevel`, `b0`.`_name` AS `ChampionName`
                FROM `BSY_TblUser` AS `b`
                LEFT JOIN `BSY_TblChampion` AS `b0` ON `b`.`_championKey` = `b0`.`_key`
                WHERE `b`.`_key` = @__userKey_0*/
            }
            catch(CommonExeption ex)
            {
                rv.StatusCode = (EStatusCode)ex.StatusCode;
                rv.Message = ex.ToString();
                rv.IsSuccess = false;
                rv.Data = null; // selectUser

                return rv;
            }

            catch (Exception ex)
            {
                rv.StatusCode = EStatusCode.ServerException;
                rv.Message = ex.ToString();
                rv.IsSuccess = false;
                rv.Data = ex.Data as ResponseDtoGetChampionInfoByUserKey;

                return rv;
            }
            return rv;
        }

        [HttpGet("GetItemListByUserKey")]
        public async Task<ResponseDtoGetItemListByUserKey> // List 반환 형식
            GetItemListByUserId([FromQuery] RequestDtoGetItemListByUserKey requestDto)
        {
            ResponseDtoGetItemListByUserKey rv = new ();

            rv.List = await (
                from userItem in _context.BsyTblUserItems
                where userItem.UserKey == requestDto.UserKey
                select new ResponseDtoGetItemListByUserKeyElement
                {
                    ItemKey = userItem.Key,
                    ItemName = userItem.ItemKeyNavigation.Name
                }).ToListAsync();
         
            return rv;
        }

        /*[HttpGet("GetItemListByUserId")]
        public async Task<object> GetItemListByUserId([FromQuery] int userKey)
        {
            object rv;

            var query = await (
                from userItem in _context.BsyTblUserItems
                where userItem.UserKey == userKey
                select new
                {
                    ItemKey = userItem.Key,
                    ItemName = userItem.ItemKeyNavigation.Name
                }).ToListAsync();
              *//*SELECT `b`.`_key` AS `ItemKey`, `b0`.`_name` AS `ItemName`
              FROM `BSY_TblUserItem` AS `b`
              LEFT JOIN `BSY_TblItem` AS `b0` ON `b`.`_itemKey` = `b0`.`_key`
              WHERE `b`.`_userKey` = @__userKey_0*//*
            return query;
        }*/


        [HttpGet("GetSkillListByUserKey")]
        public async Task<ResponseDtoGetSkillListByUserKey> // 애초에 List로 만듦
            GetSkillListByUserId([FromQuery] RequestDtoGetSkillListByUserKey requestDto) // List 반환 형식
        {
            ResponseDtoGetSkillListByUserKey rv = new ();

            rv.List = await (
                from userSkill in _context.BsyTblUserSkills
                where userSkill.UserKey == requestDto.UserKey
                select new ResponseDtoGetSkillListByUserKeyElement
                {
                    SkillKey = userSkill.Key,
                    SkillName = userSkill.SkillKeyNavigation.Name
                }).ToListAsync();

            //1. List<Dto> 형태로 리턴한다.
            //  서버, 클라이언트 둘다하는 사람이 많이 적습니다.
            //  서버입장에서는 List<Dto>로 리턴하는게 상당히 많이 편합니다.
            //  클라이언트 입장에서는 저렇게 Return해줬을때 코드로 파싱하는 경우에서 많이 까다로울떄가 많아요.

            //2. Dto에 리스트를 포함한다.

            return rv;
        }


        [HttpGet()]
        public User Get([FromQuery]int id)
        {
            //foreach(var user in _users)
            //{
            //    if(user.Id == id)
            //    {
            //        return user;
            //    }
            //}

            //linq

            //users 안에 있는 리스트를
            //u라는 이름으로 순회하면서
            //u.Id == id 이면
            //배열이 나오는데,
            //그중에서 첫번째 요소를 가져오겠다.
            //첫번째요소 조차없으면 Default 값으로 가져오겠다.
            var rv = _users.Where(u => u.Id == id).FirstOrDefault();

            if (rv == null)
            {
                throw new Exception("Bad Request");
            }

            return rv;
        }

        [HttpPost()]
        public bool Create([FromQuery] string name, string email, string password)
        {
            User newUser = new User()
            {
                Id = _newUserId,
                Email = email,
                Password = password,
                Name = name
            };

            _users.Add(newUser);

            _newUserId++;

            return true;
        }

        [HttpPut()]
        public bool Update([FromQuery] int id, string email)
        {
            var user = _users.Where(u => u.Id == id).FirstOrDefault();

            if (user == null)
            {
                return false;
            }

            user.Email = email;

            return true;
        }

        [HttpDelete()]
        public bool Delete([FromQuery]int id)
        {
            User deleteUser = _users.Where(u => u.Id == id).FirstOrDefault();

            if (deleteUser == null)
            {
                return false;
            }

            _users.Remove(deleteUser);
            return true;

        }


    }
}
