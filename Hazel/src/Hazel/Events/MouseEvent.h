#pragma once
#include "Event.h"

namespace Hazel {
	class HAZEL_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y)
			: m_MouseX(x), m_MouseY(y) {}

		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		string ToString() const override
		{
			stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
			EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_MouseX, m_MouseY;
	};


	class HAZEL_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			: m_XOffset(xOffset), m_YOffset(yOffset) {}

		inline float GetXOffset() { return m_XOffset; }
		inline float GetYOffset() { return m_YOffset; }

		string ToString() const override
		{
			stringstream ss;
			ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled) 
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float m_XOffset, m_YOffset;
	};

	class HAZEL_API MouseBottonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	protected:
		MouseBottonEvent(int button): m_Button(button){}

		int m_Button;
	};




	class HAZEL_API MouseButtonPressedEvent : public MouseBottonEvent
	{
	public: 
		MouseButtonPressedEvent(int button)
			:MouseBottonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss; 
			ss << "MouseButtonPressedEvent: " << m_Button;;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class HAZEL_API MouseButtonReleasedEvent : public MouseBottonEvent
	{
	public:
		MouseButtonReleasedEvent(int button)
			:MouseBottonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};



};