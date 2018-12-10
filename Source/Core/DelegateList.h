#pragma once

#include "Delegate.h"
#include "Array.h"

//=============================================================================
SE_NAMESPACE_BEGIN

template <typename T> 
class DelegateList;

template <typename R, typename... Args> 
class DelegateList<R(Args...)>
{
public:
	explicit DelegateList(IAllocator &allocator) : m_delegates(allocator) {}

	template <typename C, R(C::*Function)(Args...)> 
	void Bind(C* instance)
	{
		Delegate<R(Args...)> cb;
		cb.template bind<C, Function>(instance);
		m_delegates.Push(cb);
	}

	template <R(*Function)(Args...)> 
	void Bind()
	{
		Delegate<R(Args...)> cb;
		cb.template bind<Function>();
		m_delegates.Push(cb);
	}

	template <typename C, R(C::*Function)(Args...)> 
	void Unbind(C *instance)
	{
		Delegate<R(Args...)> cb;
		cb.template bind<C, Function>(instance);
		for (int i = 0; i < m_delegates.size(); ++i)
		{
			if (m_delegates[i] == cb)
			{
				m_delegates.EraseFast(i);
				break;
			}
		}
	}

	void Invoke(Args... args)
	{
		for (auto &i : m_delegates) i.Invoke(args...);
	}

private:
	Array<Delegate<R(Args...)>> m_delegates;
};

SE_NAMESPACE_END
//=============================================================================