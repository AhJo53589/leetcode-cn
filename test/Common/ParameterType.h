#pragma once

#include "TestCases.h"

//////////////////////////////////////////////////////////////////////////
// 用来解决函数的参数有引用类型
template<class T>
struct remove_ref
{
	static T Get(TestCases& caster) { return caster.get<T>(); }
};

template<class T>
struct remove_ref<T&>
{
	static T Get(TestCases& caster) { return caster.get<T>(); }
};

//////////////////////////////////////////////////////////////////////////
// 将参数列表展开
// 将参数填入测试数据
// 调用函数
template<class R, class ...Params>
class type_warp;

template<class R, class Head, class... Tail>
class type_warp<R, Head, Tail...> : public type_warp<R, Tail...>
{
public:
	using Base = type_warp<R, Tail...>;
	template<class F, class... Args>
	static R call(F&& f, TestCases& caster, Args&&... args)
	{
		auto head = remove_ref<Head>::Get(caster);
		return Base::call(f, caster, std::forward<Args>(args)..., head);
	}
};

template<class R>
class type_warp<R>
{
public:
	template<class F, class... Args>
	static R call(F&& f, TestCases& caster, Args&&... args)
	{
		return f(std::forward<Args>(args)...);
	}
};

//////////////////////////////////////////////////////////////////////////
// 获取函数的返回值和参数列表
template<typename T>
struct function_type;
template<typename R, typename ...Args>
struct function_type<std::function<R(Args...)>> : public type_warp<R, Args...>
{
	using return_type = R;
};

