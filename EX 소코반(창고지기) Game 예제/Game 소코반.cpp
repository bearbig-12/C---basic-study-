#include <iostream>

const char gStageData[] = "\
########\n\
# .. p #\n\
# oo   #\n\
#      #\n\
########";

const int gStageWidth{ 8 };
const int gStageHeight{ 5 };

enum Object
{
	OBJ_SPACE,
	OBJ_WALL,
	OBJ_GOAL,
	OBJ_BLOCK,
	OBJ_BLOCK_ON_GOAL,
	OBJ_PLAYER,
	OBJ_PLAYER_ON_GOAL,

	OBJ_UNKNOWN	// 열거형이 UNKNOWN 보다 큰 경우 데이터가 잘못된것이다.
};

void Initialize(Object* state, int w, int h, const char* gStageData);
void DrawScene(const Object* state, int w, int h);
bool CheckClear(const Object* state, int w, int h);
void Update(Object* state, char input, int w, int h);


int main()
{
	Object* state = new Object[gStageWidth * gStageHeight];

	Initialize(state, gStageWidth, gStageHeight, gStageData);

	while (true)
	{
		DrawScene(state, gStageWidth, gStageHeight);
		if (CheckClear(state, gStageWidth, gStageHeight))
		{
			std::cout << "Well Done !" << std::endl;
			break;
		}
		std::cout << "a : Left, d : Right, w : Up, s : Down. Command?" << std::endl;
		char input;
		std::cin >> input;

		Update(state, input, gStageWidth, gStageHeight);
	}


	delete[] state;
}

void Initialize(Object* state, int w, int h, const char* gStageData)
{
	const char* d = gStageData;
	int x{ 0 }, y{ 0 };

	while (*d != '\0')
	{
		Object t;
		
		switch (*d)
		{
		case'#':
			t = OBJ_WALL;
			break;

		case' ':
			t = OBJ_SPACE;
			break;

		case'o':
			t = OBJ_BLOCK;
			break;

		case'O':
			t = OBJ_BLOCK_ON_GOAL;
			break;

		case'.':
			t = OBJ_GOAL;
			break;

		case'p':
			t = OBJ_PLAYER;
			break;

		case'P':
			t = OBJ_PLAYER_ON_GOAL;
			break;

		case'\n':
			x = 0;
			++y;
			t = OBJ_UNKNOWN;
			break;

		default:
			t = OBJ_UNKNOWN;
			break;
		}
		if (t != OBJ_UNKNOWN)
		{
			state[y * w + x] = t;	// 1차배열 2차로 변경
			x++;
		}
		++d;
	}
}

void DrawScene(const Object* state, int w, int h)
{
	const char font[]{ ' ', '#', '.', 'o', 'O', 'p', 'P' };

	for (int y = 0; y < h; ++y)
	{
		for (int x = 0; x < w; ++x)
		{
			Object o = state[y * w + x];
			std::cout << font[o];
		}
		std::cout << std::endl;
	}
}

bool CheckClear(const Object* state, int w, int h)
{
	for (int i = 0; i < w * h; ++i)
	{
		if (state[i] == OBJ_BLOCK)
		{
			return false;
		}
	}
	return true;
}

void Update(Object* state, char input, int w, int h)
{
	int dx{}, dy{};

	switch (input)
	{
	case'a':
		dx = -1;
		break;

	case'd':
		dx = 1;
		break;

	case'w':
		dy = -1;
		break;
		
	case's':
		dy = 1;
		break;
	
	}
	//플레이어 현재 위치 인덱스
	int i;
	for (i = 0; i < w * h; ++i)
	{
		if (state[i] == OBJ_PLAYER || state[i] == OBJ_PLAYER_ON_GOAL)
		{
			break;
		}
	}
	//현재위치
	int x = i % w;
	int y = i / w;

	//이동할 위치
	int tx = x + dx;
	int ty = y + dy;

	if (tx < 0 || ty < 0 || tx >= w || ty >= h)
	{
		return;
	}

	int p = y * w + x;
	int tp = ty * w + tx;

	if (state[tp] == OBJ_SPACE || state[tp] == OBJ_GOAL)
	{
		state[p] = (state[p] == OBJ_PLAYER_ON_GOAL ) ? OBJ_GOAL : OBJ_SPACE;
		state[tp] = (state[tp] == OBJ_GOAL) ? OBJ_PLAYER_ON_GOAL : OBJ_PLAYER;
	}
	else if (state[tp] == OBJ_BLOCK || state[tp] == OBJ_BLOCK_ON_GOAL)
	{
		int tx2 = tx + dx;
		int ty2 = ty + dy;

		if (tx2 < 0 || ty2 < 0 || tx2 >= w, ty2 >= h)
		{
			return;
		}

		int tp2 = ty2 * w + tx2;

		if (state[tp2] == OBJ_SPACE || state[tp2] == OBJ_GOAL)
		{
			state[tp2] = (state[tp2] == OBJ_GOAL) ? OBJ_BLOCK_ON_GOAL : OBJ_BLOCK;
			state[tp] = (state[tp] == OBJ_BLOCK_ON_GOAL) ? OBJ_PLAYER_ON_GOAL : OBJ_PLAYER;
			state[p] = (state[p] == OBJ_PLAYER_ON_GOAL) ? OBJ_GOAL : OBJ_SPACE;
		}
	}
	
}
