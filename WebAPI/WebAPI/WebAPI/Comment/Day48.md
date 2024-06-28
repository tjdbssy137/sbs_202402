# 배울 내용
## 1. 숙제 풀이 (예제 DB Table 구성)

- 관계형 DB에 대하여..
  - 관계형 DB는 기본적으로 1:1로밖에 못 적음
  - Excel로 적어야하는 Table이기에 (Key 한개당 동일한 컬럼의 데이터는 1개밖에 못 적음)
    - Key 1, Name : 박서윤, Subjects : 영어, 수학 <- 이런식으론 적을 수 없다.
  - 아 그럼 테이블을 두개로 분리하면 되겠다!
  - Subject Table, User Table로 나눠서
  - User 
    - Key : 1, Name : 박서윤
  - Subject 
    - Key : 1, Name : 영어,
    - Key : 2, Name : 수학
  - UserSubject Table
    - Key : 1, UserKey : 1, SubjectKey : 1
    - Key : 2, UserKey : 1, SubjectKey : 2


- 리그오브레전드
  - 티모 2레벨 신발, 단검 스킬은 (Q, W)
  - 가렌 1레벨 단검, 롱소드 스킬은 (Q)
  
1. Table 구성
    1. 사전느낌인지 / 유저가 갖고 있는 데이터 느낌인지에 따라 한 번 더 구분
        - ex) 1. Item Table인지(아이템 전체를 담고 있음)
        - ex) 2. UserItem Table인지 (어떤 유저가 어떤 아이템을 갖고 있는지에 대해)
    2. 가장 눈에 보이는 데이터부터 나눠줌     
        - 사전 느낌 Table
           - 챔피언 Table (티모, 가렌)
           - 아이템 Table (신발, 단검, 롱소드)
           - 스킬 Table (실명, 이속증가, 침묵)
        - 데이터 매핑 Table (게임을 진행하면서 내용이 바뀔 테이블)
          - User Table (가렌 유저, 티모 유저)
          - User Item Table (티모 - 단검, 신발) (가렌 - 단검, 롱소드)
          - User Skill Table (티모 - 실명, 이속증가) (가렌 - 침묵)
    3. 1:1 데이터가 아닌 것을 찾아서 방법을 모색한다.
        - 챔피언, 아이템 얘네들은 Key와 데이터가 명확
        - User Item Table 같은 경우에는 1:N 관계는 Mapping Table로 구성
        -  

**챔피언 Table** (사전 느낌 Table)
|Key|Name|
|---|---|
|1|티모|
|2|가렌|

**아이템 Table** (사전 느낌 Table)
|Key|Name|
|---|---|
|1|신발|
|2|단검|
|3|롱소드|

**스킬 Table** (사전 느낌 Table)
|Key|Name|
|---|---|
|1|실명|
|2|이속증가|
|3|침묵|

**User Table** (데이터 매핑 Table)
|Key|ChampionKey|Level|
|:---:|:---:|:---:|
|1|1|2|
|1|2|1|

**User Item Table** (데이터 매핑 Table) 
 - (1:N 관계 해결)
    - (1 : UserKey)
    - (N : ItemKey)

|Key|UserKey|ItemKey|
|:---:|:---:|:---:|
|1|1|1|
|2|1|2|
|3|2|1|
|4|2|3|

**User Skill Table** (데이터 매핑 Table) 
 - (1:N 관계 해결)
    - (1 : UserKey)
    - (N : SkillKey)

|Key|UserKey|SkillKey|
|:---:|:---:|:---:|
|1|1|1|
|2|1|2|
|3|2|3|


### Document DB
- 티모 2레벨 신발, 단검 스킬은 (Q, W)
- 가렌 1레벨 단검, 롱소드 스킬은 (Q)

```json
[
    {
        "Name" : "티모",
        "Level" : 2,
        "Item" : [
            "신발",
            "단검"
        ],
        "Skill" : [
            "실명",
            "이속증가"
        ]
    }
    {
        "Name" : "가렌",
        "Level" : 1,
        "Item" : [
            "단검",
            "롱소드"
        ],
        "Skill" : "침묵"
    }
]
```
1. 이 Document DB는 기본적으로 Excel로 쓸 수 없음
   - Excel로 쓸수없는 건, 기획자의 자원을 활용하지 못한다는 것
   - 프로그래머의 시간이 기획자의 시간이 더 중요,,
2. 결국엔 프로젝트가 커지면 Document DB가 말도 안되게 커지게 됨
   - 그래서 트래픽 100만을 가정하고 짜면 좋은 DB가 될 수 없다.

그래도 간결한 건 종종 Document DB로 함.

## 2. C#에서의 데이터 처리 방법(LINQ)
- Visual Studio 2022에서 코드로 설명
- 20240628_02
## 3. DB - MySQL, MariaDB


### 숙제!!
타워디펜스에 사용할 DB 스키마 구성해보기