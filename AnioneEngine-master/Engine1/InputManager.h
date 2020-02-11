#pragma once

#include <vector>
#include <d3dx9.h>

class KeyState
{
public:

	int vkCode;
	bool isOn;		//키가 눌린 상태일때
	bool isDown;	//키가 한번 눌렸을때
	bool isUp;		//키가 올라 왔을떄

	KeyState(int vkCode) : vkCode(vkCode), isOn(false), isDown(false), isUp(false)
	{

	}
};


static class InputManager
{
public:
	InputManager();
	~InputManager();

	static D3DXVECTOR2 mousePosition;

	static void Init(HWND hWnd);

	enum class KeyCode {W,A,S,D,mouse0,mouse1,space,MAX};

	static bool GetKey(KeyCode keycode);
	static bool GetKeyDown(KeyCode keycode);
	static bool GetKeyUp(KeyCode keycode);
	static HWND hWnd;
	static void Update();

	static std::vector<KeyState *> keyStateVector;
	
	static void AddKey(KeyCode keyCode,int vkCode);
};

