#pragma once
#include <string>


struct EventValue {
	int button = 0;
	int key = 0;
	double MousePosX = 0;
	double MousePosY = 0;
	int offset = 0;
	bool window = false;
	double width = 0;
	double height = 0;

};



namespace CoreNative
{
	class Event
	{
	public:
		enum class EventType : int8_t
		{
			MOUSE_MOVED_EVENT = 1,
			MOUSE_SCROLLED_EVENT,
			MOUSE_BUTTON_PRESSED_EVENT,
			MOUSE_BUTTON_RELEASED_EVENT,
			KEY_PRESSED_EVENT,
			//KEY_RELEASED_EVENT,
			//KEY_REPEATED_EVENT,
			WINDOW_RESIZED_EVENT,
			WINDOW_CLOSED_EVENT,
		};
	protected:
		EventType type;
		std::string name;
	protected:
		Event(const std::string& name, EventType type)
			:
			name(name),
			type(type) {}
	public:
		virtual ~Event() = default;
	public:
		inline std::string getName() const { return name; }
		inline EventType getType() const { return type; }
		virtual EventValue format() const = 0;
	};
}