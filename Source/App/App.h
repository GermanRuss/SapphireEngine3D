#pragma once

//=============================================================================
SE_NAMESPACE_BEGIN

class App
{
public:
	App();
	virtual ~App();

	void Start();

private:
	static App *m_self;
};

SE_NAMESPACE_END
//=============================================================================