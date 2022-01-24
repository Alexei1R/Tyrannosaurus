#pragma once


#include "event.h"



namespace CoreNative
{
	class WindowResizedEvent : public Event
	{
	private:
		int width, height;
	public:
		WindowResizedEvent(int width, int height)
			:
			Event("Window resize event", Event::EventType::WINDOW_RESIZED_EVENT),
			width(width),
			height(height) {}
	public:
		EventValue format() const override
		{
			EventValue val;
			val.width = width;
			val.height = height;
			return val;
		}
	};

	class WindowClosedEvent : public Event
	{
	public:
		WindowClosedEvent()
			:
			Event("Window Close Event", Event::EventType::WINDOW_CLOSED_EVENT) {}
	public:
		EventValue format() const override
		{
			EventValue val;
			val.window = true;
			return val;
		}
	};
}
