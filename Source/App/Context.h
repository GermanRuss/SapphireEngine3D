#pragma once

//=============================================================================
SE_NAMESPACE_BEGIN

class Context
{
public:
	bool Init();
	bool Frame();
	void Close();
private:
	GLFWwindow *m_window = nullptr;
};

SE_NAMESPACE_END
//=============================================================================