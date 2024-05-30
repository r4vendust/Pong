#pragma once

#include <raylib.h>
#include <string>

class Button
{
public:
	Button(Vector2 buttonPos = {0, 0}, std::string text = "");
	void Draw();
	bool IsMouseOver() const;
	bool IsClicked() const;
	void Update();
	void SetColors(Color normalColor, Color normalTextColor, Color hoverColor, Color hoverTextColor, Color pressedColor, Color pressedTextColor);
	void SetText(std::string text);
	void SetButtonSize(float buttonWidth, float buttonHeight);
	void SetBorderColor(Color color);
	void ResizeButton();
	void DrawBorder();
	void EnableBorder();
	void DisableBorder();
	void ToggleBorder();
	void SetTextColor(Color color);
	void SetButtonColor(Color Color);
	void DrawShadow();
	void ToggleShadow();
	void SetFontSize(float fontSize);
	void DisableResize();

	// Test Methods
	Vector2 GetTextSize();
private:
	Rectangle button;
	Vector2 buttonPos;
	float buttonWidth;
	float buttonHeight;
	Color buttonColor;

	float borderThickness;
	Color borderColor;
	bool hasShadow;
	float shadowThickness;
	bool hasBorder;
	bool isButtonResizable;


	std::string text;
	Vector2 textPosition;
	Vector2 textSize;
	Vector2 textSizeChar;


	Font font;
	float fontSize;
	float fontSpacing;
	Color fontColor;

	// states

	int state;
	Color normalColor;
	Color hoverColor;
	Color pressedColor;
	Color normalTextColor;
	Color hoverTextColor;
	Color pressedTextColor;
};