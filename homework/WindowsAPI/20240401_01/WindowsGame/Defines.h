#pragma once
//��ũ�� �߰����ٰſ���.

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