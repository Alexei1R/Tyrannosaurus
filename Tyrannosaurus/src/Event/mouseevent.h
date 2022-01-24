#pragma once
#include "event.h"



namespace CoreNative
{
	class MouseMovedEvent : public Event
	{
	private:
		int x, y;
	public:
		MouseMovedEvent(int x, int y)
			:
			Event("Mouse moved Event", Event::EventType::MOUSE_MOVED_EVENT),
			x(x),
			y(y) {}


	public:
		EventValue format() const override
		{
			EventValue val;
			val.MousePosX = x;
			val.MousePosY = y;
			return val;
		}
	};



	class MouseScrolledEvent : public Event
	{
	private:
		int offset;
	public:
		MouseScrolledEvent(int offset)
			:
			Event("Mouse Scrolled Event", Event::EventType::MOUSE_SCROLLED_EVENT),
			offset(offset) {}
	public:
		EventValue format() const override
		{
			EventValue val;
			val.offset = offset;
			return val;
		}
	};



	class MouseButtonPressed : public Event
	{
	private:
		int button;
	public:
		MouseButtonPressed(int button)
			:
			Event("Mouse button pressed", Event::EventType::MOUSE_BUTTON_PRESSED_EVENT),
			button(button) {}
	public:
		EventValue format() const override
		{
			EventValue val;
			val.button = button;
			return val;
		}

	};


	class MouseButtonReleased : public Event
	{
	private:
		int button;
	public:
		MouseButtonReleased(int button)
			:
			Event("Mouse button released", Event::EventType::MOUSE_BUTTON_RELEASED_EVENT),
			button(button) {}
	public:
		EventValue format() const override
		{
			EventValue val;
			val.button = button;
			return val;
		}

	};


}