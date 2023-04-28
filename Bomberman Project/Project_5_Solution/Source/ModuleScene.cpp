#include "ModuleScene.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"

#include<iostream>


using namespace std;
/*{	-,-,-,X,X,-,-,-
	-,-,-,X,X,-,-,-
	0,0,0,0,0,0,0,0
	0,0,0,0,0,0,0,0
	0,0,0,0,0,0,0,0
	0,0,0,0,0,0,0,0
	0,0,0,0,0,0,0,0
	0,0,0,0,0,0,0,0
	0,0,0,0,0,0,0,0
	0,0,0,0,0,0,0,0
	0,0,0,0,0,0,0,0
	0,0,0,0,0,0,0,0 }
*/
ModuleScene::ModuleScene()
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			map[i][j] = '0';
		}
	}
}

ModuleScene::~ModuleScene()
{

}

bool ModuleScene::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	bgTexture = App->textures->Load("Assets/background.png");
	bgTexture2 = App->textures->Load("Assets/FondoIzquierdaLimpio.png");
	App->audio->PlayMusic("Assets/audio/08_stage_1.ogg", 1.0f);
	return ret;
}

update_status ModuleScene::Update()
{

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 8; j++) {
			cout << "[" << map[i][j] << "] ";
		}
		cout << endl;
	}
	cout << endl; cout << endl; cout << endl; cout << endl;
	return update_status::UPDATE_CONTINUE;
}

update_status ModuleScene::PostUpdate()
{
	App->render->Blit(bgTexture, -231, 0, 0, 10);
	App->render->Blit(bgTexture2, 0, 0, 0, 10);

	return update_status::UPDATE_CONTINUE;
}

void ModuleScene::SetTile(int x, int y, char value)
{
	map[y][x] = value;
}

bool ModuleScene::ReadTile(int x, int y) {
	if (map[y][x]=='0')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ModuleScene::isLeftEmpty(int x, int y)
{
	if (map[y+1][x-1] == '0' && x > 0)
	{
		return true;
	}

	else
	{
		return false;
	}
}

bool ModuleScene::isRightEmpty(int x, int y)
{
	if (map[y+1][x+1] == '0' && x < 7)
	{
		return true;
	}

	else
	{
		return false;
	}
}

bool ModuleScene::isDownEmpty(int x, int y)
{
	if (map[y+2][x] == '0' && y < 10)
	{
		return true;
	}

	else
	{
		return false;
	}
}

//void ModuleScene::DestroyLines() {
//	{
//		for (int i = 0; i < 12; i++)
//		{
//			for (int j = 0; j < 8; j++)
//			{
//
//				if (map[i][j] == '0')
//				{
//				}
//
//				else if (map[i][j] == 'A')
//				{
//					if (map[i][j+1]=='A')
//					{
//						if (map[i][j+2]=='A')
//						{
//							Score += 100;
//						}
//						if (map[i][j -1] == 'A')
//						{
//							Score += 100;
//
//							if (map[i][j - 2] == 'A')
//							{
//								Score += 100;
//							}
//						}
//					}
//
//					else if (map[i][j - 1] == 'A')
//					{
//						if (map[i][j - 2] == 'A')
//						{
//							Score += 100;
//						}
//					}
//
//					else if (map[i+1][j] == 'A')
//					{
//						if (map[i+2][j] == 'A')
//						{
//							Score += 100;
//						}
//						if (map[i-1][j] == 'A')
//						{
//							Score += 100;
//
//							if (map[i-2][j] == 'A')
//							{
//								Score += 100;
//							}
//						}
//					}
//
//					else if (map[i-1][j] == 'A')
//					{
//						if (map[i-2][j] == 'A')
//						{
//							Score += 100;
//						}
//					}
//
//					else if (map[i + 1][j+1] == 'A')
//					{
//						if (map[i + 2][j+2] == 'A')
//						{
//							Score += 100;
//						}
//						if (map[i - 1][j-1] == 'A')
//						{
//							Score += 100;
//
//							if (map[i - 2][j-2] == 'A')
//							{
//								Score += 100;
//							}
//						}
//					}
//
//					else if (map[i - 1][j-1] == 'A')
//					{
//						if (map[i - 2][j-2] == 'A')
//						{
//							Score += 100;
//						}
//					}
//
//					else if (map[i - 1][j+1] == 'A')
//					{
//						if (map[i - 2][j+2] == 'A')
//						{
//							Score += 100;
//						}
//						if (map[i + 1][j-1] == 'A')
//						{
//							Score += 100;
//
//							if (map[i - 2][j+2] == 'A')
//							{
//								Score += 100;
//							}
//						}
//					}
//
//					else if (map[i + 1][j-1] == 'A')
//					{
//						if (map[i + 2][j-2] == 'A')
//						{
//							Score += 100;
//						}
//					}
//				}
//			}
//		}
//	}
//}