#pragma once
class Quest
{
private:
	/*const int mID;
	const int mEXP;*/
	int mID;
	int mEXP;
public:
	// �ʱ�ȭ ����Ʈ(Initializer List)
	// <������> : �ʱ�ȭ��1, �ʱ�ȭ��2, �ʱ�ȭ��3 ...
	
	// Delegating Constructor : �븮 ������, ������ ����


	//Quest(int id = 1, int exp = 0) : mID{ id }, mEXP{ exp }	//��ü�� ��������� ������ �ʱ�ȭ �ϱ� ������ ������ �ص� �ʱ�ȭ ����.
	//{

	//}

	Quest() : mID{ 1 }, mEXP{ 0 }
	{

	}
	Quest(int id, int exp ) : Quest()	// �븮 ������
	{
		mID = id;
		mEXP = exp;
	}

	

	void Print();
	
};

