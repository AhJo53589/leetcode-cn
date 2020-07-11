#pragma once

#include "TestCases.h"

//////////////////////////////////////////////////////////////////////////
// ������������Ĳ�������������
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
// �������б�չ��
// �����������������
// ���ú���
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
// ��ȡ�����ķ���ֵ�Ͳ����б�
template<typename T>
struct function_type;
template<typename R, typename ...Args>
struct function_type<std::function<R(Args...)>> : public type_warp<R, Args...>
{
    using return_type = R;
};

