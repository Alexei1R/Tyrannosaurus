#pragma once
#include "event.h"


namespace Core {
	class MauseMuvedEvent : public Event {
	private:
		double x, y;

	public:
		MauseMuvedEvent(double x, double y)
			:Event("Mause muved Event", EventType::MAUSE_MUVED_EVENT), x(x), y(y) {}
	public:
		std::string format() const override {
			std::string formatted = name + " : " + std::to_string(x) + " : " + std::to_string(y);
			return formatted;
		}
	};

	class MauseScroolledEvent : public Event {
	private:
		int offset;
	public:
		MauseScroolledEvent(int offset)
			:Event("Mause Scroll Event ", EventType::MAUSE_SCROLLED_EVENT), offset(offset) {}

	public:
		std::string format() const override {
			std::string formatted = "";
			return (offset>0?formatted = name + " : " + " to bottom" : name + " : " + " to top");
		}

	};



}

