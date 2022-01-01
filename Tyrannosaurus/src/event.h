#pragma once
#include <string>


namespace Core {
	class Event {


	public:
		enum class EventType : int8_t
		{
			MAUSE_MUVED_EVENT = 1,
			MAUSE_SCROLLED_EVENT,
			MAUSE_BUTTON_PRESS_EVENT,
			MAUSE_BUTTON_RELEASED_EVENT,
			KEYBOARD_PRESED_EVENT,
			KEIBOARD_RELEASED_EVENT,
			KEIBOARD_REPEATED_EVENT,
			WINDOW_RESIZED_EVENT,
			WINDOW_CLOSED_EVENT,
		};
	protected:
		EventType type;
		std::string name;
	protected:
		Event(std::string name, EventType type) :
			name(name), type(type) {}

	public:
		virtual ~Event() = default;
		inline std::string getName() const { return name; };
		inline EventType getType() const { return type; }
		virtual std::string format() const = 0;
 
	};

}