#pragma once
#include <stdexcept>
#include <cstring>
#include <sstream>

class RendererError:public std::runtime_error
{
private:
	std::string message; 
public:
	RendererError(const char* error) :runtime_error("Renderer error")
	{
		std::stringstream ss(message);
		ss << error;
		message = ss.str();
	}
	const char* what() const noexcept
	{
		return message.c_str();
	}
};

