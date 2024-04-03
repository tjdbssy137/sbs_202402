#pragma once
//매크로 추가해줄거에요.

#define SAFE_DELETE(p) {if(p) delete (p); (p) = NULL;}
#define SAFE_DELETE_ARRAY(p) {if(p) delete[] (p); (p) = NULL;}

#define DECLARE_SINGLE(ClassName)			\
private:									\
	ClassName() {}							\
	~ClassName() {}							\
public:										\
	static ClassName* GetInstance()			\
	{										\
		static ClassName instance;			\
		return &instance;					\
	}


#define GET_SINGLE(ClassName)	ClassName::GetInstance()

#define Input GET_SINGLE(InputManager)
#define Time GET_SINGLE(TimeManager)