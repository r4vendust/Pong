#include "Button.h"

Button::Button(Vector2 buttonPos, std::string text)
	: buttonPos(buttonPos),
	buttonWidth(buttonWidth),
	buttonHeight(buttonHeight),
	text(text),
	state(0),
	normalColor(normalColor),
	hoverColor(hoverColor),
	pressedColor(pressedColor),
	normalTextColor(normalTextColor),
	hoverTextColor(hoverTextColor),
	pressedTextColor(pressedTextColor)
{

	button = { buttonPos.x , buttonPos.y, buttonWidth, buttonHeight };
	isButtonResizable = true;

	font = GetFontDefault();
	fontSize = 30;
	fontSpacing = 3;
	fontColor = WHITE;

	textSizeChar = MeasureTextEx(font, "C", fontSize, fontSpacing);

	//buttonHeight = GetTextSize().y * (2.0f * (GetTextSize().y / fontSize));

	ResizeButton();
	borderThickness = 1;
	borderColor = BLACK;
	hasBorder = true;
	buttonColor = GRAY;
	hasShadow = false;
	shadowThickness = 3;

	textPosition = { buttonPos.x + (buttonWidth - GetTextSize().x) / 2, buttonPos.y + (buttonHeight - GetTextSize().y) / 2 };
}

void Button::Draw()
{

	switch (state)
	{
		case 0:
			buttonColor = normalColor;
			break;
		case 1:
			buttonColor = hoverColor;
			break;
		case 2:
			buttonColor = pressedColor;
			break;
	}

	if (hasShadow)
	{
		DrawShadow();
	}
	// Update text position
	this->textPosition = { buttonPos.x + (buttonWidth - GetTextSize().x) / 2, buttonPos.y + (buttonHeight - GetTextSize().y) / 2 };

	DrawRectangleV(buttonPos, { static_cast<float>(buttonWidth), static_cast<float>(buttonHeight) }, buttonColor);
	DrawTextEx(font, text.c_str(), textPosition, fontSize, fontSpacing, fontColor);



	if (hasBorder)
	{
		DrawBorder();
	}
	//DrawRectangleLinesEx({buttonPos.x, buttonPos.y, buttonWidth, buttonHeight}, borderThickness, borderColor);
}

bool Button::IsMouseOver() const
{
	Vector2 mousePos = GetMousePosition();

	return (mousePos.x >= buttonPos.x && mousePos.x <= (buttonPos.x + buttonWidth) &&
		mousePos.y >= buttonPos.y && mousePos.y <= (buttonPos.y + buttonHeight));
}

bool Button::IsClicked() const
{
	return (IsMouseOver() && IsMouseButtonPressed(MOUSE_LEFT_BUTTON));
}

void Button::Update()
{
	if (IsMouseOver())
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) || IsMouseButtonDown(MOUSE_LEFT_BUTTON))
		{
			state = 2; // Pressed
		}
		else
		{
			state = 1; // Hover
		}
	}
	else
	{
		state = 0; // Not Pressed
	}
}

void Button::SetColors(Color normalColor, Color normalTextColor, Color hoverColor, Color hoverTextColor, Color pressedColor, Color pressedTextColor)
{
	this->normalColor = normalColor;
	this->hoverColor = hoverColor;
	this->pressedColor = pressedColor;
	this->normalTextColor = normalTextColor;
	this->hoverTextColor = hoverTextColor;
	this->pressedTextColor = pressedTextColor;
}

void Button::SetText(std::string text)
{
	this->text = text;
	this->textSize = GetTextSize();
	ResizeButton();
}

Vector2 Button::GetTextSize()
{
	return MeasureTextEx(font, text.c_str(), fontSize, fontSpacing);
}

void Button::DrawBorder()
{
	DrawRectangleLinesEx({ buttonPos.x, buttonPos.y, buttonWidth, buttonHeight }, borderThickness, borderColor);
}

void Button::SetBorderColor(Color color)
{
	this->borderColor = color;
}

void Button::ResizeButton()
{
	if (isButtonResizable)
	{
		this->buttonWidth = GetTextSize().x + 3.5f * textSizeChar.x;
		this->buttonHeight = GetTextSize().y * 2.0f;
	}
}

void Button::EnableBorder()
{
	this->hasBorder = true;
}

void Button::DisableBorder()
{
	this->hasBorder = false;
}

void Button::ToggleBorder()
{
	this->hasBorder = !hasBorder;
}

void Button::SetTextColor(Color color)
{
	this->fontColor = color;
}

void Button::SetButtonSize(float buttonWidth, float buttonHeight)
{
	this->buttonWidth = buttonWidth;
	this->buttonHeight = buttonHeight;
}

void Button::SetButtonColor(Color color)
{
	this->buttonColor = color;
}

void Button::DrawShadow()
{
	DrawRectangleV({ buttonPos.x + 5, buttonPos.y + 5}, {buttonWidth, buttonHeight}, GRAY);
}

void Button::ToggleShadow()
{
	this->hasShadow = !hasShadow;
}

void Button::SetFontSize(float fontSize)
{
	this->fontSize = fontSize;
}

void Button::DisableResize()
{
	this->isButtonResizable = false;
}