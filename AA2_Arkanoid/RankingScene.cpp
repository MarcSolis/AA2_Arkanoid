#include "RankingScene.h"



RankingScene::RankingScene() :
	rankingText(rankingPos, "Ranking", "B_sunspire", {255,255,255,255}),
	num1Text(num1Pos, "1  :", "S_sunspire", { 255,215,0,255}),
	num2Text(num2Pos, "2 :", "S_sunspire", { 192,192,192,255}),
	num3Text(num3Pos, "3 :", "S_sunspire", { 205, 127, 50,255 }),
	num4Text(num4Pos, "4 :", "S_sunspire", { 255,255,255,255 }),
	num5Text(num5Pos, "5 :", "S_sunspire", { 255,255,255,255 }),
	num6Text(num6Pos, "6 :", "S_sunspire", { 255,255,255,255 }),
	num7Text(num7Pos, "7 :", "S_sunspire", { 255,255,255,255 }),
	num8Text(num8Pos, "8 :", "S_sunspire", { 255,255,255,255 }),
	num9Text(num9Pos, "9 :", "S_sunspire", { 255,255,255,255 }),
	num10Text(num10Pos, "10 :", "S_sunspire", { 255,255,255,255 }),
	menuButton(menuButtPos, "Menu", "sunspire")
{
	Renderer::Instance()->LoadTexture("RankingBackground", "../res/Ranking.jpg");
}

void RankingScene::Update(const InputManager &input)
{
	Renderer::Instance()->PushImage("RankingBackground", bgRect);
	rankingText.Render();

	num1Text.Render();
	num2Text.Render();
	num3Text.Render();
	num4Text.Render();
	num5Text.Render();
	num6Text.Render();
	num7Text.Render();
	num8Text.Render();
	num9Text.Render();
	num10Text.Render();

	menuButton.IsHover(input.mousePos);

	if (input.mouseClicked)
		menuButton.OnClick(false, [&]() {nextScene = MENU;});

	menuButton.Render();
}

void RankingScene::FixedUpdate()
{

}

void RankingScene::Render()
{
	Renderer::Instance()->Render();
}


RankingScene::~RankingScene()
{
}
