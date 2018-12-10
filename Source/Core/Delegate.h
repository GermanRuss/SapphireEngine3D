#pragma once

//=============================================================================
SE_NAMESPACE_BEGIN

template <typename T> 
class Delegate;

template <typename R> 
class Delegate
{
private:
	typedef void *InstancePtr;
	typedef R(*InternalFunction)(InstancePtr);
	struct Stub
	{
		InstancePtr first;
		InternalFunction second;
	};

	template <R(*Function)()> 
	static SE_FORCE_INLINE R FunctionStub(InstancePtr) { return (Function)(); }

	template <class C, R(C::*Function)()> 
	static SE_FORCE_INLINE R ClassMethodStub(InstancePtr instance)
	{
		return (static_cast<C*>(instance)->*Function)();
	}

	template <class C, R(C::*Function)() const> 
	static SE_FORCE_INLINE R ClassMethodStub(InstancePtr instance)
	{
		return (static_cast<C*>(instance)->*Function)();
	}

public:
	Delegate()
	{
		m_stub.first = nullptr;
		m_stub.second = nullptr;
	}

	template <R(*Function)()> 
	void Bind()
	{
		m_stub.first = nullptr;
		m_stub.second = &FunctionStub<Function>;
	}

	template <class C, R(C::*Function)()> 
	void Bind(C *instance)
	{
		m_stub.first = instance;
		m_stub.second = &ClassMethodStub<C, Function>;
	}

	template <class C, R(C::*Function)() const> 
	void Bind(C *instance)
	{
		m_stub.first = instance;
		m_stub.second = &ClassMethodStub<C, Function>;
	}

	R Invoke() const
	{
		Assert(m_stub.second != nullptr);
		return m_stub.second(m_stub.first);
	}

	bool operator==(const Delegate<R> &rhs)
	{
		return m_stub.first == rhs.m_stub.first && m_stub.second == rhs.m_stub.second;
	}

private:
	Stub m_stub;
};

template <typename R, typename... Args> 
class Delegate<R(Args...)>
{
private:
	typedef void *InstancePtr;
	typedef R(*InternalFunction)(InstancePtr, Args...);
	struct Stub
	{
		InstancePtr first;
		InternalFunction second;
	};

	template <R(*Function)(Args...)> 
	static SE_FORCE_INLINE R FunctionStub(InstancePtr, Args... args)
	{
		return (Function)(args...);
	}

	template <class C, R(C::*Function)(Args...)>
	static SE_FORCE_INLINE R ClassMethodStub(InstancePtr instance, Args... args)
	{
		return (static_cast<C*>(instance)->*Function)(args...);
	}

	template <class C, R(C::*Function)(Args...) const>
	static SE_FORCE_INLINE R ClassMethodStub(InstancePtr instance, Args... args)
	{
		return (static_cast<C*>(instance)->*Function)(args...);
	}

public:
	Delegate()
	{
		m_stub.first = nullptr;
		m_stub.second = nullptr;
	}

	bool IsValid() { return m_stub.second != nullptr; }

	template <R(*Function)(Args...)> 
	void Bind()
	{
		m_stub.first = nullptr;
		m_stub.second = &FunctionStub<Function>;
	}

	template <class C, R(C::*Function)(Args...)> 
	void Bind(C *instance)
	{
		m_stub.first = instance;
		m_stub.second = &ClassMethodStub<C, Function>;
	}

	template <class C, R(C::*Function)(Args...) const> 
	void Bind(C *instance)
	{
		m_stub.first = instance;
		m_stub.second = &ClassMethodStub<C, Function>;
	}

	R Invoke(Args... args) const
	{
		Assert(m_stub.second != nullptr);
		return m_stub.second(m_stub.first, args...);
	}

	bool operator==(const Delegate<R(Args...)>& rhs)
	{
		return m_stub.first == rhs.m_stub.first && m_stub.second == rhs.m_stub.second;
	}

private:
	Stub m_stub;
};

SE_NAMESPACE_END
//=============================================================================